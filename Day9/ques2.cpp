#include<bits/stdc++.h>
using namespace std;

vector<int>findPattern(string &text, string &pattern) {
  int m = text.size(), n = pattern.size();
  vector<int>ans;

  if(m < n)
    return ans;
  
  for(int i = 0; i <= m - n; i++) {
    if(text.substr(i, n) == pattern)
      ans.push_back(i);
  }

  return ans;
}

int main()
{
  string text, pattern;
  cin>>text>>pattern;

  vector<int>ans = findPattern(text, pattern);
  for(int i = 0; i < ans.size(); i++)
    cout<<ans[i]<<" ";
  cout<<endl;
}