#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>&ans, vector<vector<int>>&adj, vector<bool>&visited, int node) {
  visited[node] = true;
  ans.push_back(node);

  for(int i = 0; i < adj[node].size(); i++) {
    if(!visited[adj[node][i]]) {
      dfs(ans, adj, visited, adj[node][i]);
    }
  }
}

int main()
{
  int n;
  cout<<"Enter the total no. of castles: ";
  cin>>n;

  vector<vector<int>>adj(n);
  for(int i = 0; i < n; i++) {
    int m;
    cout<<"Enter the no. of neighbouring castles of "<<i<<": ";
    cin>>m;

    for(int j = 0; j < m; j++){
      int num;
      cin>>num;
      adj[i].push_back(num);
    }
  }

  vector<bool>visited(n, false);  
  vector<int>ans;
  
  dfs(ans, adj, visited, 0);
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}