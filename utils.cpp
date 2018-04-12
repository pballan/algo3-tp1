using namespace std;

void printResult(maxCombo &result){

    cout << "totalWeight: " << result.totalWeight << endl;
    cout << "totalProfit: " << result.totalProfit << endl;
    cout << endl;
    cout << "[";
    for(int i = 0; i < result.conjunto.size(); i++){
            cout << "{profit: " << result.conjunto[i].profit << ", weight: " << result.conjunto[i].weight << "}";
            if (i < result.conjunto.size() - 1){
                cout << ", ";
            }
        }
    cout << "]" << endl;
}


void readTxt(entry *dataset, string line, ifstream &input, int amountElements, int maxWeight){
      
    int cant = 0;

    while (!input.eof())
    {
        int data;
        getline(input, line); //read number
        string concat;
        int actualNumber = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ')
            {
                concat += line[i];
            }
            else
            {
                if (actualNumber == 0)
                {
                    dataset[cant].weight = atoi(concat.c_str());
                    actualNumber++;
                }
                else
                {
                    dataset[cant].profit = atoi(concat.c_str());
                    actualNumber = 0;
                }
                concat.clear();
            }
        }
        line.clear();
        cant++;
    }
    input.close();
    for (int i = 0; i < amountElements; i++)
    {
        cout << "profit: " << dataset[i].profit << endl;
        cout << "weight: " << dataset[i].weight << endl;
        cout << endl;
    }

}