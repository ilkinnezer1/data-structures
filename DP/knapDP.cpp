#include <iostream>
using namespace std;


int knapSackDp(int v[], int w[], int n , int W)
{
    int weight;
    int dp[n+1][W+1];

    for(int i =0 ; i<=n; i++){
        for(weight=0; weight <=W ; weight++){
            if(i==0 || weight ==0) {
                dp[i][weight] = 0;
            }else if(w[i-1] <= weight){
                dp[i][weight] = max(v[i-1] + dp[i-1][weight-w[i-1]], dp[i-1][weight]);
            }else{
                dp[i][weight] = dp[i-1][weight];
            }
        }
    }

    return dp[n][weight];
}

int main() {
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++) {
      cout << "Enter value and weight for item " << i << ":";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Enter the capacity of knapsack";
   cin >> W;
   cout << knapSackDp(v,w,n,W);
   return 0;
}