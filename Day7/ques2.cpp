#include<bits/stdc++.h>
using namespace std;

int findProfit(int n, vector<int>&prices) {
  int maxProfit = 0, minPrice = prices[0];

  for(int i = 1; i < n; i++) {
    int profit = prices[i] - minPrice;
    if(profit >= 2) {
      maxProfit = max(maxProfit, profit);
    }
    
    minPrice = min(minPrice, prices[i]);
  }

  return maxProfit;
}

int main()
{
  int n;
  cin>>n;

  vector<int>prices(n);
  for(int i = 0 ; i < n; i++) {
    cin>>prices[i];
  }

  cout<<findProfit(n, prices)<<endl;
}