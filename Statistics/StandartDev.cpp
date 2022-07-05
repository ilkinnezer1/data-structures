#include <iostream>
#include <math.h>
using namespace std;

//Calculating standart deviation
float standartDeviation(float data[], int population){
    float sum = 0.0, standartDeviation = 0.0, mean;
    int i;

    //Calculate sum to find mean
    for(i=0;i<population; i++)
        sum+=data[i];
    
    //Find mean
        mean = sum / population;

    for(i=0; i< population; ++i)
        standartDeviation += pow(data[i] - mean, 2); // Calculating numerator

    return sqrt(standartDeviation / population); // Divided by population
}
int main(){
    int i;
    float data[10];

    int population = sizeof(data) / sizeof(data[0]);
    cout << "Enter elements: ";
    for(i = 0; i<population; i++)
        cin >> data[i];
    
    cout << "Standart Devation is: " << standartDeviation(data, population);
}

