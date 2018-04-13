using namespace std;

void resolveBackTrackingF(entry *entries, int currentWeight, int amountElements, int index, list<vector<entry>> &result, int actualProfit, int maxWeight, int &max)
{
    if (index < amountElements)
    {
        if (actualProfit > max && currentWeight <= maxWeight)
        {
            max = actualProfit;
        }
        resolveBackTrackingF(entries, currentWeight, amountElements, index + 1, result, actualProfit, maxWeight, max);

        if (currentWeight + entries[index].weight <= maxWeight)
        {
            if (actualProfit + entries[index].profit > max && currentWeight + entries[index].weight <= maxWeight)
            {
                max = actualProfit + entries[index].profit;
            }
            resolveBackTrackingF(entries, currentWeight + entries[index].weight, amountElements, index + 1, result, actualProfit + entries[index].profit, maxWeight, max);
        }
    }
}

int backTrackingF(entry entries[], int maxWeight, int amountElements){
    int currentWeight = 0;
    int index = 0;
    list<vector<entry> > result;
    vector<entry> actuals;
    entry *entries_ptr = entries;
    int max;

    resolveBackTrackingF(entries_ptr, currentWeight, amountElements, index, result, 0, maxWeight, max);

    return max;
}