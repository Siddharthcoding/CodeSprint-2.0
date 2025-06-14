#include<bits/stdc++.h>
using namespace std;

int findMana(int n, int m, vector<int>&merlin, vector<int>&morgana) {
  int strongestSpell = *max_element(morgana.begin(), morgana.end());
  int mana = 0;

  for(int i = 0; i < n; i++) {
    if(merlin[i] <= strongestSpell)
      mana += (strongestSpell+1 - merlin[i]);
  }

  return mana;
}

int main()
{
  int n;
  cout<<"Enter the total no. of Merlin's spells: ";
  cin>>n;

  vector<int>merlin(n);
  cout<<"Enter the power levels of Merlin's spell:\n";
  for(int i = 0; i < n; i++) {
    cin>>merlin[i];
  }

  int m;
  cout<<"Enter the total no. of Morgana's spells: ";
  cin>>m;

  vector<int>morgana(m);
  cout<<"Enter the power levels of Morgana's spell\n";
  for(int i = 0; i < m; i++) {
    cin>>morgana[i];
  }

  cout<<findMana(n, m, merlin, morgana)<<endl;
}