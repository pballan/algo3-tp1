using namespace std;

void resolveBruteForce(entry *entries, vector<entry> actuals, int currentWeight, int amountElements, int index, list<vector<entry>> &result, int actualProfit, int maxWeight, maxCombo &max)
{
    if (index < amountElements)
    { 
        if (actualProfit > max.totalProfit && currentWeight <= maxWeight){
            max.conjunto = actuals;
            max.totalWeight = currentWeight;
            max.totalProfit = actualProfit;
        }  
        resolveBruteForce(entries, actuals, currentWeight, amountElements, index + 1, result, actualProfit, maxWeight, max);      
        
        actuals.push_back(entries[index]);
        if (actualProfit + entries[index].profit > max.totalProfit && currentWeight + entries[index].weight <= maxWeight){
            max.conjunto = actuals;
            max.totalWeight = currentWeight + entries[index].weight;
            max.totalProfit = actualProfit + entries[index].profit;
        }
        resolveBruteForce(entries, actuals, currentWeight + entries[index].weight, amountElements, index + 1, result, actualProfit + entries[index].profit, maxWeight, max);
    }else{
        result.push_front(actuals);    
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

    resolveBruteForce(entries_ptr, actuals, currentWeight, amountElements, index, result, 0, maxWeight, max);

    return max;
}

