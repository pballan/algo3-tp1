using namespace std;

void resolveBruteForce(entry *entries, int currentWeight, int amountElements, int index, int actualProfit, int maxWeight, int &max)
{
    if (index < amountElements)
    { 
        if (actualProfit > max && currentWeight <= maxWeight){
            max = actualProfit;
        }  
        resolveBruteForce(entries, currentWeight, amountElements, index + 1, actualProfit, maxWeight, max);      
        
        if (actualProfit + entries[index].profit > max && currentWeight + entries[index].weight <= maxWeight){
            max = actualProfit + entries[index].profit;
        }
        resolveBruteForce(entries, currentWeight + entries[index].weight, amountElements, index + 1, actualProfit + entries[index].profit, maxWeight, max);
    }
}

int bruteForce(entry entries[], int maxWeight, int amountElements)
{

    int currentWeight = 0;
    int index = 0;
    entry *entries_ptr = entries;
    int max;
    resolveBruteForce(entries_ptr, currentWeight, amountElements, index, 0, maxWeight, max);

    return max;
}

