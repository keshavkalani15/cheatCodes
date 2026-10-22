#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
  int number;
  double weight;
  double value;
  double ratio;
};

bool compareRatio(Item a, Item b) { return a.ratio > b.ratio; }

int main() {
  int n;
  cout << "Enter Number of Items: ";
  cin >> n;
  cout << "\n";

  if (n <= 0) {
    cout << "Enter Positive Number!! Try again!!" << endl;
    return 0;
  }

  vector<Item> items(n);

  cout << "Enter Weight and Value for each item: " << endl;
  for (int i = 0; i < n; i++) {
    items[i].number = i + 1;
    cin >> items[i].weight >> items[i].value;
    items[i].ratio = items[i].value / items[i].weight;
  }

  double capacity;
  cout << "Enter Knapsack Capacity: ";
  cin >> capacity;
  cout << "\n";

  sort(items.begin(), items.end(), compareRatio);

  double totalProfit = 0;

  cout << "\nItems taken (item number: fraction):" << endl;

  for (int i = 0; i < n && capacity > 0; i++) {
    if (items[i].weight < capacity) {
      capacity -= items[i].weight;
      totalProfit = items[i].value;

      cout << items[i].number << ": 1.0 (whole item)" << endl;
    } else {
      double fraction = capacity / items[i].weight;
      totalProfit += fraction * items[i].value;

      cout << items[i].number << ": " << fraction << " (fraction)" << endl;

      capacity = 0;
    }
  }
  cout << "Maximum Profit: " << totalProfit << endl;
  return 0;
}