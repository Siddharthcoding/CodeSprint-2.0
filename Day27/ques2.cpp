#include<bits/stdc++.h>
using namespace std;

vector<int> findError(vector<int>&codes, int n) {
  unordered_map<int, int>freq;
  for(int i = 0; i < n; i++) {
    freq[codes[i]]++;
  }

  int duplicate = -1, missing = -1;
  for(int i = 1; i <= n; i++) {
    if(freq[i] == 2)
      duplicate = i;
    else if(freq[i] == 0)
      missing = i;
  }

  return {duplicate, missing};
}

int main()
{
  int n;
  cout<<"Enter the length of the array: ";
  cin>>n;

  vector<int>codes(n);
  cout<<"Enter the enchantment codes:\n";
  for(int i = 0; i < n; i++) {
    cin>>codes[i];
  }

  vector<int>ans = findError(codes, n);
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}