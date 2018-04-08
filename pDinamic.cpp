using namespace std;


bool isEmpty(maxCombo emptyToCheck){
    if (emptyToCheck.conjunto.size() == 0 && emptyToCheck.totalProfit == 0 && emptyToCheck.totalWeight == 0){
        //cout << "holis" << endl;
        return true;
    }
    return false;
}

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
    
}

void initializeCache(maxCombo *cache, int amountElements, maxCombo &max){
    maxCombo empty;

    max.totalWeight = 0;
    max.totalProfit = 0;


    empty.totalWeight = 0;
    empty.totalProfit = 0;
    vector<entry> emptyVector;
    empty.conjunto = emptyVector;

    for(int i = 0; i < amountElements; i++){
        cache[i] = empty;
    }
}

maxCombo pDinamic(entry entries[], int maxWeight, int amountElements){
    int currentWeight = 0;
    int from = 0;
    list<vector<entry> > result;
    maxCombo actuals;
    entry *entries_ptr = entries;
    maxCombo max;
    maxCombo cache[amountElements];

    initializeCache(cache, amountElements, max);

    resolvePDinamic(actuals, from, amountElements, cache, max, maxWeight, entries_ptr);

    return max;
}