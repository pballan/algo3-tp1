#include "types.h"
#include "bruteForce.cpp"
#include "utils.cpp"
#include "backTracking.cpp"
#include "pDinamic.cpp"

using namespace std;

// g++ -std=c++11 -o main main.cpp -ggdb

int main()
{

  /*  ifstream input("data.txt");

    string line;
    int data;
    getline(input, line); //read number
    amountElements = atoi(line.c_str());
    getline(input, line); //read number
    maxWeight = atoi(line.c_str());

    cout << "Amount Elements: " << amountElements << endl;
    cout << "Max Weight: " << maxWeight << endl;
*/
    //readTxt(dataset, line, input, amountElements, maxWeight);



    int maxWeight;
    int amountElements;
    cin >> amountElements;
    cin >> maxWeight;
    //cout << "cant,bf,bt,pd,worked" << endl;

    entry dataset[amountElements];

    for(int i = 0; i < amountElements; i++){
        cin >> dataset[i].profit;
        cin >> dataset[i].weight;
    }

    auto start = chrono::system_clock::now(); 
    int bruteForceResult = 0;  
    for(int i = 0; i < 5; i++) {
        bruteForceResult += bruteForce(dataset, maxWeight, amountElements);    
    }
    bruteForceResult = bruteForceResult/5;
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    time_t end_time = chrono::system_clock::to_time_t(end);
    //cout << bruteForceResult.totalProfit << endl;
    cout << amountElements << ",";       
    cout << elapsed_seconds.count() << ",";


    start = chrono::system_clock::now();    
    int backTrackingResult = 0;
    for(int i = 0; i < 5; i++){
        backTrackingResult += backTrackingF(dataset, maxWeight, amountElements);
    }
    backTrackingResult = backTrackingResult/5; 
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;

    end_time = chrono::system_clock::to_time_t(end);
    cout << elapsed_seconds.count() << ",";
    //cout << "Max: " << backTrackingResult.totalProfit << endl;

    start = chrono::system_clock::now();  
    int pDinamicResult;  
    for(int i = 0; i < 5; i++){
        pDinamicResult += pDinamic(dataset, maxWeight, amountElements);   
    }
    pDinamicResult = pDinamicResult/5;
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;

    end_time = chrono::system_clock::to_time_t(end);
    cout << elapsed_seconds.count() << ",";

    if ((pDinamicResult == backTrackingResult) && (pDinamicResult == bruteForceResult)){
        cout << "OK" << endl;
    }else{
        cout << "NOT_OK" << endl;
    }
    //cout << "Max: " << pDinamicResult << endl;


    return 0;
}
