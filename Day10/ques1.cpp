#include<bits/stdc++.h>
using namespace std;

void solve(int idx, string &digits, string &curr, vector<string>&ans, map<char, string>&mp) {
  if(idx == digits.size()) {
    ans.push_back(curr);
      return;
  }

  string temp = mp[digits[idx]];
  for(char ch: temp) {
    curr.push_back(ch);
    solve(idx + 1, digits, curr, ans, mp);
    curr.pop_back();
  }
}

int main()
{
  map<char, string>mp;
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";

  string digits;
  cin>>digits;

  vector<string>ans;
  if(!digits.empty()) {
    string curr = "";
    solve(0, digits, curr, ans, mp);
  }

  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}