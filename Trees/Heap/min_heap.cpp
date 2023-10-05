#include <iostream>
#include <vector>
#include <algorithm>

class MinHeap {
private:
    std::vector<int> heap;

    void heapify(int index) {
        int minValue = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;


        if (left < heap.size() && heap[left] < heap[minValue]) {
           minValue = left;
        }
        if (right < heap.size() && heap[right] < heap[minValue]) {
            minValue = right;
        }
        if(minValue != index) {
            std::swap(heap[index], heap[minValue]);
            heapify(minValue);
        }
    };
public:
    MinHeap(std::vector<int>& array) {
        heap = array;

        for (int i = (heap.size() / 2) - 1; i >= 0; i--){
            heapify(i);
        }
    }

    int extractMinValue(){
        if(!heap.empty()) {
            int min = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);

            return min;
        }

        return -1;
    }
};

int main() {
    std::vector<int> arr = {10, 5, 8, 20, 3};
    MinHeap minHeap(arr);

    int minValue = minHeap.extractMinValue();

    if (minValue != -1) {
        std::cout << "The minimum value in the array is: " << minValue << std::endl;
    } else {
        std::cerr << "Error: The heap is empty." << std::endl;
    }

    return 0;
}