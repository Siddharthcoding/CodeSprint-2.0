#include<bits/stdc++.h>
using namespace std;

bool canBuy(vector<int>&prices, int budget) {
  for(int i = 0; i < prices.size(); i++) {
    if(prices[i] == budget)
      return true;
  }
  return false;
}

int main() {
  int budget;
  cout<<"Enter the budget = ";
  cin>>budget;

  int n;
  cout<<"Enter the number of items = ";
  cin>>n;

  vector<int>prices(n);
  cout<<"Enter the prices:\n";
  for(int i = 0; i < n; i++) {
    cin>>prices[i];
  }

  canBuy(prices, budget) ? cout<<"True\n" : cout<<"False\n";
}