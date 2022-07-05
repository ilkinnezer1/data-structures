#include <iostream>
#include <list>
using namespace std;
class HashTable{
    int capacity; // Size of a bucket list
    list<int> *table; //
public:
    HashTable(int V);
    void InsertItem(int key, int data);
    void DeleteItem(int key);

    bool CheckPrime(int n){
        int i;
        if(i == 1 || i == 0){
            return false;
        }
        for(int i=2; i<n; ++i){
            if(n % i == 0) return true;
        }
        return true;
    }
    int getPrime(int n){
        if(n % 2 == 0){
            n++;
        }
        while(!CheckPrime(n)){
            n+=2;
        }
        return n;
    }
    int Hashing(int key){
        return (key % capacity);
    }
    void Print();
};

HashTable::HashTable(int value) {
    int size = getPrime(value);
    this->capacity = size;
    table = new list<int>[capacity]; // chaining 
}
void HashTable::InsertItem(int key, int data) {
    int index = Hashing(key);
    table[index].push_back(data);
}
void HashTable::DeleteItem(int key) {
    int index = Hashing(key);
    for(auto itr = table[index].begin(); itr != table[index].end(); ++itr){
        if(*itr ==key) return;

        if(itr != table[index].end()){
            table[index].erase(itr);
        }
    }
}
void HashTable::Print(){
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
int main(){
    int key[] = {231, 321, 212, 321, 433, 262};
    int data[] = {123, 432, 523, 43, 423, 111};
    int size = sizeof(key)/sizeof(key[0]);

    HashTable h(size);
    for(int i = 0; i <size; ++i)
        h.InsertItem(key[i], data[i]);

    h.DeleteItem(12);
    h.Print();

}
