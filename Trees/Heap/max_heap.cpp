#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() &&  heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(std::vector<int>& array) {
        heap = array;
        // start from the non-leaf node and heapify all nodes in reverse order
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    int getMax() {
        if (!heap.empty()) {
            return heap[0];
        }
        return -1;
    }
};

int main() {
    std::vector<int> arr = {10, 5, 8, 20, 3};
    MaxHeap maxHeap(arr);

    int maxNumber = maxHeap.getMax();

    if (maxNumber != -1) {
        std::cout << "The maximum number in the array is: " << maxNumber << std::endl;
    } else {
        std::cerr << "Error: The heap is empty." << std::endl;
    }
    return 0;
}
