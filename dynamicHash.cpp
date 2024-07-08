#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template<typename K, typename V>
class DynamicHashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t size;
    size_t capacity;
    const float LOAD_FACTOR = 0.75;

    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

    void resize() {
        size_t newCapacity = capacity * 2;
        std::vector<std::list<std::pair<K, V>>> newTable(newCapacity);

        for (const auto& bucket : table) {
            for (const auto& pair : bucket) {
                size_t newIndex = std::hash<K>{}(pair.first) % newCapacity;
                newTable[newIndex].push_back(pair);
            }
        }

        table = std::move(newTable);
        capacity = newCapacity;
    }

public:
    DynamicHashTable() : size(0), capacity(16) {
        table.resize(capacity);
    }

    void insert(const K& key, const V& value) {
        if ((float)size / capacity >= LOAD_FACTOR) {
            resize();
        }

        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
        size++;
    }

    V get(const K& key) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::runtime_error("Key not found");
    }

    void remove(const K& key) {
        size_t index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                size--;
                return;
            }
        }
        throw std::runtime_error("Key not found");
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicHashTable<std::string, int> hashTable;

    hashTable.insert("laptop", 5);
    hashTable.insert("smartphone", 7);
    hashTable.insert("tws", 3);

    std::cout << "Size: " << hashTable.getSize() << std::endl;
    std::cout << "Capacity: " << hashTable.getCapacity() << std::endl;

    std::cout << "Value for 'smartphone': " << hashTable.get("smartphone") << std::endl;

    hashTable.remove("smartphone");
    std::cout << "Size after removal: " << hashTable.getSize() << std::endl;

    try {
        hashTable.get("smartphone");
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
