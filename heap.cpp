#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            std::swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int minIndex = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[minIndex])
            minIndex = left;

        if (right < heap.size() && heap[right] < heap[minIndex])
            minIndex = right;

        if (minIndex != index) {
            std::swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty())
            heapifyDown(0);

        return min;
    }

    void print() {
        for (int i : heap)
            std::cout << i << " ";
        std::cout << std::endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(1);
    heap.insert(5);
    heap.insert(4);

    std::cout << "Heap: ";
    heap.print();

    std::cout << "Extracted min: " << heap.extractMin() << std::endl;
    std::cout << "Heap after extraction: ";
    heap.print();

    return 0;
}
