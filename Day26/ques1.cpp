#include<bits/stdc++.h>
using namespace std;

int closestSum(int n, vector<int>crystal, int target) {
  sort(crystal.begin(), crystal.end());

  int ans = 0, closest = INT_MAX;
  for(int i = 0; i < n-2; i++) {
    int l = i+1, r = n-1;
    while(l < r) {
      int sum = crystal[i] + crystal[l] + crystal[r];
      int diff = abs(target - sum);

      if(diff < closest || (diff == closest && sum > target)) {
        closest = diff;
        ans = sum;
      }
      
      if(sum < target) {
        l++;
      } else {
        r--;
      }
    }
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the total no. of crystals: ";
  cin>>n;

  vector<int>crystal(n);
  cout<<"Enter the energy value of each crystal:\n";
  for(int i = 0; i < n; i++) {
    cin>>crystal[i];
  }

  int target;
  cout<<"Enter the target energy: ";
  cin>>target;

  cout<<closestSum(n, crystal, target)<<endl;
}