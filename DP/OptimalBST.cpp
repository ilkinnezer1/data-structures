#include <iostream>
using namespace std;

int sumOfArrayElements(int freq[], int i, int j);

int optimumCost(int freq[], int i, int j)
{
    // BaseCase - there is no element
    if(i > j) return 0;
    // Single element in array
    if(i == j) 
       return freq[i];

    int sumOfFrequencies = sumOfArrayElements(freq, i, j);
    int minValue = INT_MAX;

    for(int root = i; root <= j; ++root)
    {
        int costOfBST = optimumCost(freq, i , root-1)  + optimumCost(freq, root + 1, j);
        if(costOfBST < minValue)
             // Update min value when it's needed
             minValue = costOfBST;
    }
    return minValue + sumOfFrequencies;
}

int optimalBST(int keys[], int freq[], int n )
{
    return optimumCost(freq, 0 , n - 1);
}

int sumOfArrayElements(int freq[], int i, int j)
{
    int sum = 0;
    for(int k = i; k<=j; ++k)
       sum += freq[k];

    return sum;
}

int main()
{
    int keys[] = {10, 12, 20, 15, 13, 45};
    int freq[] = {34, 8, 50, 10, 5, 9, 8};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "
         << optimalBST(keys, freq, n);
}