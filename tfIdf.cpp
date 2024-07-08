#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

std::unordered_map<std::string, int> termFrequency(const std::string& document) {
    std::unordered_map<std::string, int> tf;
    std::stringstream ss(document);
    std::string word;

    while (ss >> word) {
        ++tf[word];
    }

    return tf;
}

std::unordered_map<std::string, double> inverseDocumentFrequency(const std::vector<std::string>& documents) {
    std::unordered_map<std::string, int> df;
    std::unordered_map<std::string, double> idf;
    int totalDocuments = documents.size();

    for (const auto& document : documents) {
        std::unordered_map<std::string, bool> seen;
        std::stringstream ss(document);
        std::string word;
        
        while (ss >> word) {
            if (!seen[word]) {
                ++df[word];
                seen[word] = true;
            }
        }
    }

    for (const auto& pair : df) {
        idf[pair.first] = log(static_cast<double>(totalDocuments) / (1 + pair.second));
    }

    return idf;
}

std::unordered_map<std::string, double> tfidf(const std::string& document, const std::vector<std::string>& documents) {
    auto tf = termFrequency(document);
    auto idf = inverseDocumentFrequency(documents);

    std::unordered_map<std::string, double> tfidfValues;
    for (const auto& pair : tf) {
        tfidfValues[pair.first] = pair.second * idf[pair.first];
    }

    return tfidfValues;
}

int main() {
    std::vector<std::string> documents = {
        "this is a sample document",
        "this document is a sample",
        "sample document is this"
    };

    std::string query = "sample document";
    auto tfidfValues = tfidf(query, documents);

    std::cout << "TF-IDF values for query \"" << query << "\":" << std::endl;
    for (const auto& pair : tfidfValues) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
