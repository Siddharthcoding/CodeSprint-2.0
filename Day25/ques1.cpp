#include<bits/stdc++.h>
using namespace std;

bool findStones(int n, vector<int>&stones, int target) {
  sort(stones.begin(), stones.end());

  for(int i = 0; i < n-2; i++) {
      int l = i+1, r = n-1;

      while(l < r) {
        int sum = stones[i] + stones[l] + stones[r];
        if(sum == target)
          return true;
        else if(sum < target) 
          l++;
        else
          r--;
      }
  }

  return false;
}

int main()
{
  int n;
  cout<<"Enter the total no. of magical stones: ";
  cin>>n;

  vector<int>stones(n);
  cout<<"Enter the value of each stone:\n";
  for(int i = 0; i < n; i++) {
    cin>>stones[i];
  }

  int target;
  cout<<"Enter the target sum: ";
  cin>>target;

  if(findStones(n, stones, target)) {
    cout<<"true\n";
  } else {
     cout<<"false\n";
  }
}