#include<bits/stdc++.h>
using namespace std;

int criticalCount(vector<int>&vehicles, int n) {
  int count = 0;

  for(int i = 1; i < n; i++) {
    if(vehicles[i] >= 50 && vehicles[i] > vehicles[i-1])
      count++;
  }

  return count;
}

int main() {
  int n;
  cin>>n;

  vector<int>vehicles(n);
  for(int i = 0; i < n; i++)
    cin>>vehicles[i];

  cout<<criticalCount(vehicles, n)<<endl;
}