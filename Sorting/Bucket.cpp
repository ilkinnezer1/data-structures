#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BucketSort(float arr[], int n){
    vector<float> v[n];  // N size bucket list

    for( int i = 0; i < n; ++i){
        int bI = n*arr[i]; //Bucket index
        v[bI].push_back(arr[i]); // pushing value to bucket index
    }
    //Sort individual elements
    for(int i = 0; i < n ; ++i)
    {
        sort(v[i].begin(), v[i].end());
    }
    int index = 0;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            arr[index++] = v[i][j];
        }
    }
}

int main(){

    float arr[] = {0.25, 0.58,0.41, 0.29, 0.22, 0.45, 0.79, 0.01,0.69};
    int n = sizeof(arr) / sizeof(arr[0]);

    BucketSort(arr, n);

    for(int i =0; i < n; ++i){
        cout << "Bucket list is: " <<endl;
        cout << arr[i] << " ";
    }
}
