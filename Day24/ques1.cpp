#include<bits/stdc++.h>
using namespace std;

string findNonRepeating(string s) {
  string ans = "";
  unordered_map<char, int>freq;
  queue<char>q;

  for(int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
    q.push(s[i]);

    while(!q.empty() && freq[q.front()] > 1)
      q.pop();

    if(!q.empty())
      ans += q.front();
    else
      ans += '#';
  }
  
  return ans;
}

int main()
{
  string s;
  cout<<"Enter the string: ";
  cin>>s;

  cout<<findNonRepeating(s)<<endl;
}