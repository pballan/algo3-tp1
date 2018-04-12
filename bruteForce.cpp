using namespace std;

void resolveBruteForce(entry *entries, int currentWeight, int amountElements, int index, list<vector<entry>> &result, int actualProfit, int maxWeight, maxCombo &max)
{
    if (index < amountElements)
    { 
        if (actualProfit > max.totalProfit && currentWeight <= maxWeight){
            max.totalWeight = currentWeight;
            max.totalProfit = actualProfit;
        }  
        resolveBruteForce(entries, currentWeight, amountElements, index + 1, result, actualProfit, maxWeight, max);      
        
        if (actualProfit + entries[index].profit > max.totalProfit && currentWeight + entries[index].weight <= maxWeight){
            max.totalWeight = currentWeight + entries[index].weight;
            max.totalProfit = actualProfit + entries[index].profit;
        }
        resolveBruteForce(entries, currentWeight + entries[index].weight, amountElements, index + 1, result, actualProfit + entries[index].profit, maxWeight, max);
    }
}

maxCombo bruteForce(entry entries[], int maxWeight, int amountElements)
{

    int currentWeight = 0;
    int index = 0;
    list<vector<entry> > result;
    vector<entry> actuals;
    entry *entries_ptr = entries;
    maxCombo max;

    resolveBruteForce(entries_ptr, currentWeight, amountElements, index, result, 0, maxWeight, max);

    return max;
}

