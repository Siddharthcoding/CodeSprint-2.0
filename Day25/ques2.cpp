#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
  return a+b > b+a;
}

string largestNum(int n, vector<int>vals) {
  vector<string>nums(n);
  for(int i = 0; i < n; i++) {
    nums[i] = to_string(vals[i]);
  }

  sort(nums.begin(), nums.end(), comp);

  string ans = "";
  for(int i = 0; i < nums.size(); i++) {
    ans += nums[i];
  }

  return ans;
}

int main()
{
  int n; 
  cout<<"Enter the total no. of tiles: ";
  cin>>n;

  vector<int>vals(n);
  for(int i = 0; i < n; i++) {
    cin>>vals[i];
  }

  cout<<largestNum(n, vals)<<endl;
}