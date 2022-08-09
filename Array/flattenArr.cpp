#include <iostream>
#include <vector>

class FlattenArray {
    public:
    int size;
    int currIndex = 0;
    std::vector<std::vector<int>::iterator>StartIndex;
    std::vector<std::vector<int>::iterator>EndIndex;
    void StoreFlattenArray(vector<vector<int> > &arr);
    bool hasDepth();
    int nextValue();
}

void FlattenArray::StoreFlattenArray(std::vector<std::vector<int> > &arr)
{
    size = arr.size();
    StartIndex.resize(size);
    EndIndex.resize(size);

    for(int i = 0; i < size; ++i)
    {
        StartIndex[i] = arr[i].begin();
        EndIndex[i] = arr[i].end();
    }
}

bool FlattenArray::hasDepth(){
    for(int i = 0; i < size; i++){
        if(StartIndex[i] != EndIndex[i])
            return true;
    }
    return false;
}

int FlattenArray::nextValue(){
    if(StartIndex[currIndex] == EndIndex[currIndex]){
        currIndex++;
        return nextValue();
    }else{
         return *StartIndex[currIndex]++;
    }   
    
}

int main()
{
    std::vector<std::vector<int> > arr{ { 1, 2 },
           { 3 },
           { 4, 5, 6 },
           { 7, 8, 9, 10 } };

    FlattenArray iter(arr);
  
    while (iter.hasDepth())
       std::cout << iter.nextValue() << " ";
  
    return 0;
}
