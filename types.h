#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <vector>
#include <typeinfo>
#include <chrono>
#include <algorithm>
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

struct maxProfit 
{
    int totalWeight;
    int totalProfit;
};

