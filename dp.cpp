#include <iostream>
#include <unordered_map>
using namespace std;

int gridTravel(int m, int n, unordered_map<string, int>&hash){
    //defining key
    string key = to_string(m) + " | " + to_string(n);
    if(hash.find(key) == hash.end()){
         // BaseCase of recursion
        if(m==0 || n==0)
            return hash[key] = 0;
        if(m==1 || n==1)
          return hash[key] = 1;
        // Storing value with its key
        return hash[key] = gridTravel(m-1, n, hash) + gridTravel(m, n-1, hash);
    }
    return hash[key];
}

int main() {
    int m, n;
    cout << "Give a path: ";
    cin >> m >> n;
    unordered_map<string, int> hash;
    int ans  = gridTravel(m,n,hash);
    cout << "Path is: " << ans;
}

