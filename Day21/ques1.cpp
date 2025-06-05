#include<bits/stdc++.h>
using namespace std;

int findTime(vector<int>&tickets, int k) {
  queue<int>q;
  for(int i = 0; i < tickets.size(); i++) {
    q.push(i);
  }

  int time = 0;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    tickets[curr]--;
    time++;

    if(curr == k && tickets[k] == 0)
      break;
    
    if(tickets[curr] > 0)
      q.push(curr);
  }

  return time;
}

int main()
{
  int n;
  cout<<"Enter the total no of tickets: ";
  cin>>n;

  vector<int>tickets(n);
  cout<<"Enter the tickets of each visitor:\n";
  for(int i = 0; i < n; i++) {
    cin>>tickets[i];
  }

  int k;
  cout<<"Enter the target visitor's index: ";
  cin>>k;

  cout<<findTime(tickets, k)<<endl;
}