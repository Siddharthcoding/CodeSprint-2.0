#include<bits/stdc++.h>
using namespace std;

int findMissing(int n, vector<int>&arr) {
  int total = 0;
  for(int i = 0; i < arr.size(); i++) {
    total += arr[i];
  }

  int ans = (n*(n+1)/2) - total;
  
  return ans;
}

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>arr(n);
  cout<<"Enter the numbers between "<<0<<" to "<<n<<endl;
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }

  cout<<findMissing(n, arr);
}