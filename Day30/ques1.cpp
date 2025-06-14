#include<bits/stdc++.h>
using namespace std;

int countSlips(string s) {
  int count = 0, x = 0, y = 0;
  set<pair<int, int>>visited;
  visited.insert({x, y});

  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'L')
      x--;
    else if(s[i] == 'R')
      x++;
    else if(s[i] == 'U')
      y++;
    else
      y--;

    if(visited.count({x, y}) == 0) {
      visited.insert({x, y});
    } else {
      count++;
    }
  }

  return count;
}

int main()
{
  string s;
  cout<<"Enter a string: ";
  cin>>s;

  cout<<countSlips(s)<<endl;
}