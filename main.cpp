#include "types.h"
#include "bruteForce.cpp"
#include "utils.cpp"
#include "backTracking.cpp"
#include "pDinamic.cpp"

using namespace std;

// g++ -std=c++11 -o main main.cpp -ggdb

int main()
{
    int maxWeight;
    int amountElements;

    ifstream input("data.txt");

    string line;
    int data;
    getline(input, line); //read number
    amountElements = atoi(line.c_str());
    getline(input, line); //read number
    maxWeight = atoi(line.c_str());

    cout << "Amount Elements: " << amountElements << endl;
    cout << "Max Weight: " << maxWeight << endl;

    entry dataset[amountElements];
    readTxt(dataset, line, input, amountElements, maxWeight);


    maxCombo bruteForceResult = bruteForce(dataset, maxWeight, amountElements);
    printResult(bruteForceResult);

    maxCombo backTrackingResult = backTrackingF(dataset, maxWeight, amountElements);
    printResult(bruteForceResult);

    maxCombo pDinamicResult = pDinamic(dataset);

    return 0;
}
