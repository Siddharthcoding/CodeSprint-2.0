#include<bits/stdc++.h>
using namespace std;

bool canSplit(int n, int k, vector<int>&themes) {
  unordered_map<int, int>freq;
  for(int i = 0; i < n; i++) {
    freq[themes[i]]++;
  }

  int common = 0, unique = 0;
  for(auto it: freq) {
    if(it.second >= 2)
      common++;
    else
      unique++;
  }

  int maxAssigned = common + min(k, unique);

  return maxAssigned >= k;
}

int main()
{
  int n;
  cout<<"Enter the total no. of students: ";
  cin>>n;

  int k;
  cout<<"Enter the no. of unique themes: ";
  cin>>k;

  vector<int>themes(n);
  cout<<"Enter each students favourite theme:\n";
  for(int i = 0; i < n; i++) {
    cin>>themes[i];
  }

  if(canSplit(n, k, themes))
    cout<<"YES\n";
  else
    cout<<"NO\n";
}