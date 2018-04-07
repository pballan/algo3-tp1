#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <vector>
#include <typeinfo>
using namespace std;

struct entry
{
    int profit;
    int weight;
};

struct maxCombo 
{
    vector<entry> conjunto;
    int totalWeight;
    int totalProfit;
};
