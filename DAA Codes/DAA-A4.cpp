// 0/1 knapsack

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of Items: ";
    cin>>n; cout<<"\n";

    vector<int> weight(n);
    vector<int> value(n);

    cout<<"Enter weight and value of each item: "<<endl;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>value[i];
    }

    int capacity;
    cout<<"Enter capacity of knapsack: ";
    cin>>capacity; cout<<"\n";

    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1; i<=n; i++){
        for(int w=0; w<=capacity; w++){
            //option 1: do not take this item
            dp[i][w] = dp[i-1][w];

            //option 2: take the item if it fits
            if(weight[i-1] <= w){
                int takeValue = value[i-1] + dp[i-1][w-weight[i-1]];

                if(takeValue > dp[i][w]){
                    dp[i][w] = takeValue;
                }
            }
        }
    }

    cout<<"Maximum value: "<<dp[n][capacity]<<endl;
    cout<<"\n";
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<capacity+1; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    int remainingCapacity = capacity;
    vector<int> selectedItems;

    for (int i = n; i > 0; i--) {
        if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity]) {
            selectedItems.push_back(i);  
            remainingCapacity -= weight[i - 1];
        }
    }

    cout << "Included items: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;

    return 0;
}