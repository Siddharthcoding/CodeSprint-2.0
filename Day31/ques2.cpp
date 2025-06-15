#include<bits/stdc++.h>
using namespace std;

void printOrder(int n, vector<string>&words) {
  vector<string>visited;
  for(int i = 0; i < n; i++) {
    int count = lower_bound(visited.begin(), visited.end(), words[i]) - visited.begin();
    cout<<count<<" ";

    visited.insert(lower_bound(visited.begin(), visited.end(), words[i]), words[i]);
  }

  cout<<endl;
}

int main()
{
  int n;
  cout<<"Enter the total no. of words: ";
  cin>>n;

  vector<string>words(n);
  cout<<"Enter the words:\n";
  for(int i = 0; i < n; i++){
    cin>>words[i];
  }

  printOrder(n, words);
}