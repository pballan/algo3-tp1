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


    cout << endl;
    cout << endl;


    auto start = chrono::system_clock::now();    
    maxCombo bruteForceResult = bruteForce(dataset, maxWeight, amountElements);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << "Fuerza Bruta: " << elapsed_seconds.count() << "s\n";
    cout << "Max: " << bruteForceResult.totalProfit << endl;
    
    //printResult(bruteForceResult);

    cout << endl;
    cout << endl;


    start = chrono::system_clock::now();    
    maxCombo backTrackingResult = backTrackingF(dataset, maxWeight, amountElements);    
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;

    end_time = chrono::system_clock::to_time_t(end);
    cout << "BT: " << elapsed_seconds.count() << "s\n";
    cout << "Max: " << backTrackingResult.totalProfit << endl;
    //printResult(backTrackingResult);

    cout << endl;
    cout << endl;

    start = chrono::system_clock::now();    
    int pDinamicResult = pDinamic(dataset, maxWeight, amountElements);   
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "Max: " << pDinamicResult << endl;

    end_time = chrono::system_clock::to_time_t(end);
    cout << "PD: " << elapsed_seconds.count() << "s\n";
    



    return 0;
}
