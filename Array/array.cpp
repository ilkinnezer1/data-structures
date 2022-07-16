#include <iostream>
// Array data structure from scratch

class Array{
    private:
    int *A;
    int size;
    int length;
    void swap(int *a, int*b);
public:
    //Constructor
    Array(){
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int size){
        size = size;
        length = 0;
        A = new int[size];
    }
    // Destructor 
    ~Array()
    {
        delete []A;
    };
    void print();
    void append(int data);
    void insert(int index, int data );
    int get(int index);
    int max();
    int min();
    void set(int index, int data);
    int sum();
    float avg();
    void reverse();
    void reArrange();
    int isSorted();
    void reverse2();
    void insertionSortedArray( int data);
    int deleteElement(int index);
    int linearSearch(int key);
    int binarySearch(int key);
     Array* mergeArray(Array arr2);
};

void Array::swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Array::print(){
    std::cout << "Elements: "<< std::endl;
    for(int i =0; i < length; i++){
       std::cout << A[i] << " ";
    }
}
void Array:: append(int data){
    if(size > length){
        A[length++] = data;
    }
}
void Array:: insert(int index, int data){
    if(index >= 0 && index <= length){
        for(int i = length; i > index; --i){
            A[i] = A[i-1];
            A[index] = data;
            length++;
        }
    }
}
int Array::get(int index)
{
    //Validity
    if(index >= 0 && index < length)
        return A[index];
    return -1;
}

int Array:: max()
{
    int max =A[0] ;
    int i;

    for ( int i = 1; i < length; i++)
        if(A[i] > max)
            max = A[i];
    return max;
}

int Array:: min(){
    int min = A[0];
    int i;

for ( int i = 1; i < length; i++)
    {
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

void Array:: set(int index, int data){
    if(index >= 0 && index < length)
    {
        A[index] = data;
    }
}

int Array:: sum()
{
    int i;
    int sum;
    for(i = 0; i < length; ++i){
        sum += A[i];
    }
    return sum;
}
int Array::linearSearch(int key){
    for(int i = 0 ; i<length; ++i)
    {
        if(key == A[i])
            swap(&A[i], &A[0]);
            return i;
    }
    return -1;
}
int Array::binarySearch(int key)
{
    int low = 0, high = length - 1, midPoint;
    //Finding mid point

    while(low <= high){
        midPoint = (low + high) / 2;
        if(key == A[midPoint])
            return midPoint;
        else if(key < A[midPoint])
            high = midPoint - 1; // Search on the left side
        else
            low = midPoint + 1; // Search on the right side
    }

    return -1;
}

float Array::avg(){
   return (float)sum()/length;
}

void Array:: reverse(){
    int *P, i,j;
    P = (int*)malloc(length * sizeof(int));
    for(i=length - 1, j=0; i >=0; i--,j++){
        P[j] = A[i];
    }
    for(i =0; i < length; i++){
        A[i] = P[i];
    }

}

void Array:: reArrange(){
    int i=0, j=length - 1;
    while(i<j){
        while(A[i] < 0) // for negative value
            i++;
        while(A[i] >= 0) j--;

        if(i < j){
            swap(&A[i], &A[j]);
        }
    }
}
int Array::isSorted()
{

    for(int i =0 ; i < length -1; i++)
    {
        if(A[i] > A[i+1])
            return 0;
    }
    return 1;

}

void Array:: reverse2(){
    int i,j;

    for(i = 0, j=length-1; i<j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}


void Array:: insertionSortedArray(int data)
{
    int i =length-1;
    if(length == size) return; // no free space

    while(i>= 0 && A[i] > data)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = data;
    length++;

}

Array* Array::mergeArray(Array arr2)
        {    int i,j,k; 
            i=j=k=0;
           Array *arr3=new Array(length + arr2.length);
            while(i<length && j<arr2.length){
                if(A[i]<arr2.A[j])
                    arr3->A[k++]=A[i++];
                else
                    arr3->A[k++]=arr2.A[j++];
            }    for(;i<length;i++)
                arr3->A[k++]=A[i];
            for(;j<arr2.length;j++)
                arr3->A[k++]=arr2.A[j];
            arr3->length=length+arr2.length;
            arr3->size=14;
            return arr3;
        }

int Array:: deleteElement(int index){
    int x=0, i;
    if(index >= 0 && index < length){
        x = A[index];
        for(i=index; i < length - 1; ++i)
            A[i] = A[i+1]; // shifting
        length--;

      return x;
    }
    return 0;
}

int main()
{
   Array *arr1;
   int chosedOperation, size;
   int x, index;

   std::cout << "Enter the size of array: ";
   std:: scanf("%d",  &size);
   arr1 = new Array(size);

    do{
      std::cout<<"\n\nMenu\n";
      std::cout<<"1. Insert\n";
      std::cout<<"2. Delete\n";
      std::cout<<"3. Search\n";
      std::cout<<"4. Sum\n";
      std::cout<<"5. Display\n";
      std::cout<<"6. Exit\n";
      std::cout<<"enter you choice: ";
      std::cin>>chosedOperation;  

      switch (chosedOperation)
      {
         case 1: std::cout<<"Enter an element and index: ";
            std::cin>>x>>index;
            arr1->insert(index,x);
        break;
         case 2: std::cout<<"Enter index ";
            std:: cin>>index;
            x=arr1->deleteElement(index);
            std::cout<<"Deleted Element is"<< x;
         break;
        case 3: std::cout<<"Enter element to search: ";
            std::cin>>x;
            index=arr1->linearSearch(x);
            std::cout<<"Element index "<<index;
            break;
        case 4: std::cout<<"Sum is "<<arr1->sum();
            break;
        case 5:arr1->print();
      }
    }while(chosedOperation < 6);
   
return 0;

}