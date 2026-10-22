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
    
    return 0;
}