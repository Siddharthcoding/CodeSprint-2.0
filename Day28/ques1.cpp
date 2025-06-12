#include<bits/stdc++.h>
using namespace std;

string find(string s) {
  unordered_map<char, int>freq;
  for(auto ch: s) {
    freq[ch]++;
  };
  
  priority_queue<pair<int, int>>pq;
  for(auto it: freq) {
    pq.push({it.second, it.first});
  }

  string ans = "";
  pair<int, char>prev = {0, '#'};
  
  while(!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    
    ans += curr.second;

    if(prev.first > 0)
      pq.push(prev);

    curr.first--;
    prev = curr;
  }

  if(ans.size() == s.size())
    return ans;
  else
    return "";
}

int main()
{
  string s;
  cout<<"Enter a string: ";
  cin>>s;

  cout<<find(s)<<endl;
}