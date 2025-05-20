#include<bits/stdc++.h>
using namespace std;

bool findFrequency(string s) {
  unordered_map<char, int>freq;
  
  for(int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
  }

  int count = freq.begin()->second;
  for(auto ch: freq) {
    if(ch.second != count)
      return false;
  }

  return true;
}

int main()
{
  string s;
  cin>>s;

  if(findFrequency(s))
    cout<<"Aashriya smiles: Emotional balance found.\n";
  else
    cout<<"Aashriya wonders: These thoughts were scattered.\n";
}