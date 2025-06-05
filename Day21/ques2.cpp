#include<bits/stdc++.h>
using namespace std;

vector<int>findOrder(vector<int>&cards, int n) {
  queue<int>q;
  for(int i = 0; i < n; i++) {
    q.push(cards[i]);
  }

  vector<int>ans;
  while(!q.empty()) {
    ans.push_back(q.front());
    q.pop();

    if(!q.empty()) {
      q.push(q.front());
      q.pop();
    }
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the no. of cards: ";
  cin>>n;

  vector<int>cards(n);
  cout<<"Enter the value on each card:\n";
  for(int i = 0; i < n; i++) {
    cin>>cards[i];
  }

  vector<int>ans = findOrder(cards, n);
  for(int i = 0; i < n; i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}