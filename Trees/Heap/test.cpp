#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BinaryHeap{
    private:
        vector<int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyUp(int index);
        void heapifyDown(int index);

        public:
        BinaryHeap() = default;
        void Insertion(int data);
        void Remove();
        int PrintMinData();
        void PrintHeap();
        void HeapSort();
        int HeapSize();
}

int BinaryHeap::HeapSize(){
    return heap.size();
}

void BinaryHeap::Insertion(int data){
    heap.push_back(data);
    heapifyUp(heap.size() - 1);
}

void BinaryHeap::heapifyUp(int index){
    if(index >= 0 && parent(index) >= heap[parent(index) > heap[index]]){
        int temp = heap[index];
        heap[index] = heap[parent(index)];
        heap[parent(index)] = temp;
        heapifyUp(parent(index));
    }
}

void BinaryHeap::heapifyDown(int index){
    int leftChild = left(index);
    int rightChild = right(index);

    if(leftChild >= && rightChild >=0 && heap[leftChild] > heap[rightChild]){
        leftChild = rightChild;
    }
    if(leftChild > 0 && heap[index] > heap[leftChild] ){
        int temp = heap[index];
        heap[index] = heap[leftChild];
        heap[leftChild] = heap[index];

        heapifyDown(leftChild)
    }

}

int BinaryHeap::left(int parent){
    int leftChild = 2*parent + 1;
    if(leftChild < HeapSize()){
        return 1;
    }
        else return -1;
}

int BinaryHeap::right(int parent){
    int rightChild = 2*parent + 2;
    if(right < HeapSize()){
        return 1;
    } else return -1;
}
int BinaryHeap::parent(int child){
    int parentData = floor((child - 1) / 2);
    if(child == 0){
        return -1;
    }else return parentData;
}

void BinaryHeap::Remove(){
    if(heap.empty){
        cout << "Heap is empty" <<endl;
        return;
    }

    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifyDown(0);
    cout << "Data has been removed"<<endl;

}

int BinaryHeap::PrintMinData(){
    return heap.empty() ? -1 : heap.front();
}

void BinaryHeap::HeapSort(){
    for(int i = heap.size() - 1; i >= 0; --i){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapifyUp(i);
    }
}

void BinaryHeap::PrintHeap(){
    auto itr = heap.begin();
    cout << "Heap ->> " ;
    while(itr != heap.end()){
        cout<< *itr << " ";
        itr++;
    }
}