using namespace std;

bool isEmpty(maxProfit emptyToCheck)
{
    if (emptyToCheck.totalProfit == 0 && emptyToCheck.totalWeight == 0)
    {
        //cout << "holis" << endl;
        return true;
    }
    return false;
}
/*
void resolvePDinamic(maxCombo actuals, int from, int to, maxCombo *cache, maxCombo &maxOne, int maxWeight, entry *entries){

    if (!isEmpty(cache[from])){
        for (int k = 0; k < cache[from].conjunto.size(); k++){
            actuals.conjunto.push_back(cache[from].conjunto[k]);
        }
        actuals.totalProfit += cache[from].totalProfit;
        actuals.totalWeight += cache[from].totalProfit; 
    }else{       
        resolvePDinamic(actuals, from + 1, to, cache, maxOne, maxWeight, entries);    
        if (actuals.totalProfit > maxOne.totalProfit && actuals.totalWeight <= maxWeight){
            maxOne = actuals;
        }         
        actuals.conjunto.push_back(entries[from]);
        actuals.totalProfit += entries[from].profit;
        actuals.totalWeight += entries[from].weight;
        resolvePDinamic(actuals, from + 1, to, cache, maxOne, maxWeight, entries);
        if (actuals.totalProfit > maxOne.totalProfit && actuals.totalWeight <= maxWeight){
            maxOne = actuals;
        }
    } 
}*/

int theMax(int A, int B)
{
    if (A > B)
    {
        return A;
    }
    return B;
}

int resolveDinamic(entry *entries, int from, int to, int *cache, maxProfit &maxOne, int maxWeight, int currentWeight, int currentProfit)
{
    if (from <= to)
    {
        if (cache[to] != 0)
        {
            if (cache[to] + currentProfit > maxOne.totalProfit && currentWeight <= maxWeight)
            {
                maxOne.totalProfit = cache[to] + currentProfit;
                maxOne.totalWeight = currentWeight;
            }
            return cache[to];
        }
        else
        {
            cache[to] = theMax(resolveDinamic(entries, from, to - 1, cache, maxOne, maxWeight, currentWeight + entries[to].weight, currentProfit + entries[to].profit) , resolveDinamic(entries, from, to - 1, cache, maxOne, maxWeight, currentWeight, currentProfit));
            if (cache[to] + currentProfit > maxOne.totalProfit && currentWeight <= maxWeight)
            {
                maxOne.totalProfit = cache[to] + currentProfit;
                maxOne.totalWeight = currentWeight;
            }
        
            return cache[to];
        }
    }else{
        return 0;
    }
}

void initializeCache(int *cache, int amountElements, maxProfit &max)
{

    max.totalWeight = 0;
    max.totalProfit = 0;

    for (int i = 0; i < amountElements; i++)
    {
        cache[i] = 0;
    }
}

maxProfit pDinamic(entry entries[], int maxWeight, int amountElements)
{
    int currentWeight = 0;
    int from = 0;
    list<vector<entry>> result;
    maxCombo actuals;
    entry *entries_ptr = entries;
    maxProfit max;
    int cache[amountElements];

    initializeCache(cache, amountElements, max);
    resolveDinamic(entries_ptr, from, amountElements - 1, cache, max, maxWeight, currentWeight, 0);

    return max;
}