#include<bits/stdc++.h>
using namespace std;

int trappedRain(vector<int>&heights, int n) {
  int ans = 0;
  vector<int>preMax(n, 0), sufMax(n, 0);
  preMax[0] = heights[0];
  sufMax[n-1] = heights[n-1];

  for(int i = 1; i < n; i++) {
    preMax[i] = max(preMax[i-1], heights[i]);
  }

  for(int i = n-2; i >= 0; i--) {
    sufMax[i] = max(sufMax[i+1], heights[i]);
  }

  for(int i = 1; i < n-1; i++) {
    ans += min(preMax[i], sufMax[i]) - heights[i];
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>heights(n);
  cout<<"Enter the heights of the buildings:\n";
  for(int i = 0; i < n; i++) {
    cin>>heights[i];
  }

  cout<<trappedRain(heights, n)<<endl;
}