#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int NUM_USERS = 5;
const int NUM_ITEMS = 5;

double cosine_similarity(const vector<int>& vec1, const vector<int>& vec2) {
    int dot_product = 0;
    int norm_a = 0;
    int norm_b = 0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        dot_product += vec1[i] * vec2[i];
        norm_a += vec1[i] * vec1[i];
        norm_b += vec2[i] * vec2[i];
    }
    return dot_product / (sqrt(norm_a) * sqrt(norm_b));
}

vector<pair<int, double>> get_similar_users(int user_id, const vector<vector<int>>& ratings) {
    vector<pair<int, double>> similarities;
    for (size_t i = 0; i < ratings.size(); ++i) {
        if (i != user_id) {
            double sim = cosine_similarity(ratings[user_id], ratings[i]);
            similarities.push_back(make_pair(i, sim));
        }
    }
    sort(similarities.begin(), similarities.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    return similarities;
}

double predict_rating(int user_id, int item_id, const vector<vector<int>>& ratings, int k) {
    vector<pair<int, double>> similar_users = get_similar_users(user_id, ratings);
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < k && i < similar_users.size(); ++i) {
        int similar_user_id = similar_users[i].first;
        double similarity = similar_users[i].second;
        numerator += similarity * ratings[similar_user_id][item_id];
        denominator += abs(similarity);
    }
    return denominator == 0 ? 0 : numerator / denominator;
}

int main() {
    vector<vector<int>> ratings = {
        {4, 0, 0, 5, 1},
        {5, 5, 4, 0, 0},
        {0, 4, 0, 3, 3},
        {3, 0, 5, 2, 1},
        {1, 2, 3, 4, 0}
    };

    int user_id = 0;
    int item_id = 1;
    int k = 2;

    double predicted_rating = predict_rating(user_id, item_id, ratings, k);
    cout << "Predicted rating for user " << user_id << " for item " << item_id << " is " << predicted_rating << endl;

    return 0;
}
