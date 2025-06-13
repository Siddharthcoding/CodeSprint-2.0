#include<bits/stdc++.h>
using namespace std;

vector<int> sortSquared(int n, vector<int>&nums) {
  vector<int>ans(n);
  int i = 0, j = n-1, pos = n-1;

  while(i <= j) {
    if(abs(nums[i]) > abs(nums[j])) {
      ans[pos] = nums[i]*nums[i];
      pos--;
      i++;
    } else {
      ans[pos] = nums[j]*nums[j];
      pos--;
      j--;
    }
  }
  
  return ans;
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>nums(n);
  cout<<"Enter the elements in non-decreasing order:\n";
  for(int i = 0; i < n; i++) {
    cin>>nums[i];
  }

  vector<int>ans = sortSquared(n, nums);
  for(int i = 0; i < n; i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}