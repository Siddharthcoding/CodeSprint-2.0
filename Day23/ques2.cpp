#include<bits/stdc++.h>
using namespace std;

string findWinner(string senate) {
  queue<int>radiant, dire;
  for(int i = 0; i < senate.size(); i++) {
    if(senate[i] == 'R')
      radiant.push(i);
    else
      dire.push(i);
  }

  while(!radiant.empty() && !dire.empty()) {
    int i = radiant.front();
    radiant.pop();

    int j = dire.front();
    dire.pop();

    if(i < j) {
      radiant.push(i + senate.size());
    } else {
      dire.push(j + senate.size());
    }
    
  }

  return radiant.empty() ? "Dire" : "Radiant";
}

int main()
{
  string senate;
  cout<<"Enter the string consisiting of R & D: ";
  cin>>senate;

  cout<<findWinner(senate)<<endl;
}