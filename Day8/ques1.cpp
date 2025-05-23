#include<bits/stdc++.h>
using namespace std;

int findMin(int target, int n, vector<int>&sessions) {
  int ans = INT_MAX, l = 0;
  int curr = 0;
  for(int r = 0; r < n; r++) {
    curr += sessions[r];

    while(curr >= target) {
      ans = min(ans, r-l+1);
      curr -= sessions[l];
      l++;
    }
  }

  return (ans == INT_MAX) ? 0 : ans;
}

int main()
{
  int target, n;
  cin>>target>>n;

  vector<int>sessions(n);
  for(int i = 0; i < n; i++) {
    cin>>sessions[i];
  }

  cout<<findMin(target, n, sessions)<<endl;
}