#include <iostream>
#include <cmath>
#include <vector>

// Function to calculate Euclidean distance between two points
double euclideanDistance(const std::vector<double>& point1, const std::vector<double>& point2) {
    if (point1.size() != point2.size()) {
        std::cerr << "Error: Points must have the same dimension." << std::endl;
        return -1;
    }

    double sum = 0.0;
    for (size_t i = 0; i < point1.size(); ++i) {
        sum += pow(point1[i] - point2[i], 2);
    }
    
    return sqrt(sum);
}

int main() {
    // Example points
    std::vector<double> point1 = {1.0, 2.0, 3.0};
    std::vector<double> point2 = {4.0, 5.0, 6.0};

    double distance = euclideanDistance(point1, point2);
    if (distance != -1) {
        std::cout << "Euclidean Distance: " << distance << std::endl;
    }

    return 0;
}
