#include <iostream>
using namespace std;


struct Item{
    int profit, weight;
     // Constructor
    Item(int profit, int weight)
     : profit(profit), weight(weight)
    {
    }
};

bool comparison(struct Item a, struct Item b)
{
    // Profit / weight <= capacity
    double ratio1  = (double)a.profit / a.weight;
    double ratio2 = (double)b.profit / b.weight;
    return  ratio1 > ratio2; // Taking bigger ratio
}

double KnapSackGreedy(struct Item arr[],  int capacity,  int size){
    sort(arr, arr+size, comparison);
    int currentWeight = 0;
    double ans = 0.0;
    for(int i = 0 ; i <size ; i++){
        if(currentWeight + arr[i].weight <= capacity){
            currentWeight += arr[i].weight;
            ans +=arr[i].profit;
        }else{
            int remain = capacity - currentWeight;
            ans += arr[i].profit * ((double)remain / arr[i].weight);

            break;
        }
    }
    return ans;
}

int main()
{
    int capacity = 60;

    Item arr[] = { { 100, 10 },
                   { 280, 40 },
                   { 120, 20 },
                   { 120, 24 } };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum profit: "
         << KnapSackGreedy(arr, capacity, size);
}