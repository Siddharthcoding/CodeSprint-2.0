#include<bits/stdc++.h>
using namespace std;

void countJewels(string &jewels, string &stones) {
  unordered_map<char, int>store;

  for(int i = 0; i < jewels.size(); i++) {
    store[jewels[i]]++;
  }

  int count = 0;
  for(int i = 0; i < stones.size(); i++){
    if(store.find(stones[i]) != store.end())
      count++;
  }

  cout<<count<<endl;
}

int main()
{
  string jewels, stones;
  cin>>jewels>>stones;

  countJewels(jewels, stones);
}