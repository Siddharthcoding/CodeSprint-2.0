#include<bits/stdc++.h>
using namespace std;

int findPos(int n, vector<int>&nums, int target) {
  int i = 0, j = n-1;
  while(i <= j) {
    int mid = i + (j-i)/2;

    if(nums[mid] == target) {
      return mid;
    } else if(nums[mid] < target) {
      i = mid + 1;
    } else {
      j = mid - 1;
    }
  }

  return i;
}

int main()
{
  int n;
  cout<<"Enter the total no. of books: ";
  cin>>n;

  vector<int>nums(n);
  cout<<"Enter the book numbers:\n";
  for(int i = 0; i < n; i++) {
    cin>>nums[i];
  }

  int target;
  cout<<"Enter the target book no.: ";
  cin>>target;

  cout<<findPos(n, nums, target)<<endl;
}