#include<bits/stdc++.h>
using namespace std;

void findNext(vector<int>&arr, int n) {
  vector<int>ans(n, -1);
  vector<int>ng(n, -1), ns(n, -1);
  stack<int>st;

  for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && arr[st.top()] <= arr[i]) {
      st.pop();
    }

    if(!st.empty()) {
      ng[i] = st.top();
    }

    st.push(i);
  }

  while(!st.empty())
    st.pop();

  for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }

    if(!st.empty()) {
      ns[i] = st.top();
    }

    st.push(i);
  }

  for(int i = 0; i < n; i++) {
    if(ng[i] != -1 && ns[ng[i]] != -1) {
      ans[i] = arr[ns[ng[i]]];
    } 
  }

  for(int i = 0; i < n; i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  cout<<"Enter the elements of the array:\n";
  vector<int>arr(n);
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }

  findNext(arr, n);
}