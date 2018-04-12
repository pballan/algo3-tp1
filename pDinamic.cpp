using namespace std;


/*
int resolveDinamic(entry *entries, int from, int to, int *cache, maxProfit &maxOne, int maxWeight, int currentWeight, int currentProfit)
{
    if (from <= to)
    {
        if (cache[to] != 0)
        {
            if (cache[to] + currentProfit >= maxOne.totalProfit && currentWeight <= maxWeight)
            {
                maxOne.totalProfit = cache[to] + currentProfit;
                maxOne.totalWeight = currentWeight;
            }
            return cache[to];
        }
        else
        {
            cache[to] = theMax(resolveDinamic(entries, from, to - 1, cache, maxOne, maxWeight, currentWeight + entries[to].weight, currentProfit + entries[to].profit) , resolveDinamic(entries, from, to - 1, cache, maxOne, maxWeight, currentWeight, currentProfit));
            if (cache[to] + currentProfit >= maxOne.totalProfit && currentWeight <= maxWeight)
            {
                maxOne.totalProfit = cache[to] + currentProfit;
                maxOne.totalWeight = currentWeight;
            }
        
            return cache[to];
        }
    }else{
        return 0;
    }
}*/

int reallyResolveDynamic(int amountElements, int maxWeight, vector<vector<int>> &cache, entry *entries, int fullProfit)
{
    int totalMax = 0;
    for (int i = 1; i <= amountElements; i++)
    {
        for (int j = 0; j < maxWeight + 1; j++)
        {
            int maxBetween2;
            int res1;
            int res2;
            
            if (j - entries[i - 1].weight >= 0)
            {
                res1 = cache[i - 1][j - entries[i - 1].weight] + entries[i - 1].profit;
                res2 = cache[i - 1][j];
                maxBetween2 = max(res1, res2);
            }
            else
            {
                maxBetween2 = cache[i - 1][j];
            }

            if (maxBetween2 >= totalMax)
            {
                totalMax = maxBetween2;
            }
            cache[i][j] = maxBetween2;
        }
    }

    for(int r = 0; r < amountElements; r++){
        for(int c = 0; c < maxWeight + 1; c++){
            //cout << cache[r][c] << " ";
            //cout << "R: " << r << " C:" << c;
        }
        //cout << endl;
    }

    return totalMax;
}


int pDinamic(entry entries[], int maxWeight, int amountElements)
{
    int currentWeight = 0;
    int from = 0;
    list<vector<entry>> result;
    maxCombo actuals;
    entry *entries_ptr = entries;
    maxProfit max;
    vector<vector<int>> cache(amountElements + 1);

    max.totalWeight = 0;
    max.totalProfit = 0;

    int fullProfit = 0;

    for (int i = 0; i < amountElements + 1; i++)
    {
        cache[i].resize(maxWeight + 1);
        fullProfit += entries[i].profit;
    }

    for (int i = 0; i < amountElements + 1; i++)
    {
        for (int j = 0; j < maxWeight; j++)
        {
            cache[i][j] = 0;
        }
    }

    int res = reallyResolveDynamic(amountElements, maxWeight, cache, entries_ptr, fullProfit);

    return res;
}