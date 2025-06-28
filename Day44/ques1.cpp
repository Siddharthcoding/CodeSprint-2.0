#include<bits/stdc++.h>
using namespace std;

bool isValid(string s, string t) {
  if(s.size() != t.size())
    return false;
  
  unordered_map<char, char>LtoR, RtoL;
  
  for(int i = 0; i < s.size(); i++) {
    if(LtoR.count(s[i])) {
      if(LtoR[s[i]] != t[i])
        return false;
    } else {
      LtoR[s[i]] = t[i];
    }

    if(RtoL.count(t[i])) {
      if(RtoL[t[i]] != s[i])
        return false;
    } else {
      RtoL[t[i]] = s[i];
    }
  }

  return true;
}

int main()
{
  string s, t;
  cout<<"Enter the original message: ";
  cin>>s;

  cout<<"Enter the coded message: ";
  cin>>t;

  if(isValid(s, t))
    cout<<"True\n";
  else
    cout<<"False\n";
}