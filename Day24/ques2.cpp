#include<bits/stdc++.h>
using namespace std;

void reverseOrder(queue<int>&q) {
  stack<int>st;

  while(!q.empty()) {
    st.push(q.front());
    q.pop();
  }

  while(!st.empty()) {
    q.push(st.top());
    st.pop();
  }
}

int main()
{
  int n;
  cout<<"Enter the total no. of citizens: ";
  cin>>n;

  queue<int>q;
  int val;
  cout<<"Enter the order of citizens IDs:\n";
  for(int i = 0; i < n; i++) {
    cin>>val;
    q.push(val);
  }

  reverseOrder(q);
  while(!q.empty()) {
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
}