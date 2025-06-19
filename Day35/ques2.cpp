#include<bits/stdc++.h>
using namespace std;

int minPackets(int n, vector<int>&vals) {
  sort(vals.begin(), vals.end());
  priority_queue<int, vector<int>, greater<int>>pq;

  for(int i = 0; i < n; i++) {
    if(!pq.empty() && pq.top() < vals[i])
      pq.pop();

    pq.push(vals[i]);
  }

  return pq.size();
}

int main()
{
  int n;
  cout<<"Enter the total no. of packets: ";
  cin>>n;

  vector<int>vals(n);
  cout<<"Enter the highness value of each packet:\n";
  for(int i = 0; i < n; i++) {
    cin>>vals[i];
  }

  cout<<minPackets(n, vals)<<endl;
}