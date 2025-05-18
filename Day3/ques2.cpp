#include<bits/stdc++.h>
using namespace std;

int findLength(vector<int>&temps, int n) {
  int ans = 1, curr = 1;
  for(int i = 1; i < n; i++) {
    if(temps[i] > temps[i-1])
      curr++;
    else
      curr = 1;

    ans = max(ans, curr);
  }

  return ans;
}

int main()
{
  int n;
  cin>>n;

  vector<int>temps(n);
  for(int i = 0; i < n; i++) 
    cin>>temps[i];

  cout<<findLength(temps, n)<<endl;
}