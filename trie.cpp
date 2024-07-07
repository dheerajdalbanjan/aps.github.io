#include <iostream>
#include <unordered_map>
using namespace std ;

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("laptop for gaming");
    trie.insert("gaming");
    trie.insert("laptop") ;

    cout << "Search 'gaming': " << trie.search("gaming") <<endl;  
    cout << "Search 'laptop': " << trie.search("laptop") <<endl;  
    cout << "Search 'laptop for gaming': " << trie.search("laptop for gaming") <<endl;  
    cout << "Search 'for': " << trie.search("for")<<endl ;


    return 0;
}
