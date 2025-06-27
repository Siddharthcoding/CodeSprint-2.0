#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>&adj) {
  vector<int>ans;
  vector<bool>visited(adj.size(), false);

  queue<int>q;
  q.push(0);
  visited[0] = true;

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    
    for(int i = 0; i < adj[node].size(); i++) {
      if(!visited[adj[node][i]]) {
        q.push(adj[node][i]);
        visited[adj[node][i]] = true;
      }
    }
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the no. of vertices: ";
  cin>>n;

  vector<vector<int>>adj(n);
  for(int i = 0; i < n; i++) {
    int m;
    cout<<"Enter no. of neighbours of node "<<i<<": ";
    cin>>m;

    for(int j = 0; j < m; j++) {
      int num;
      cin>>num;
      adj[i].push_back(num);
    }
  }

  vector<int>ans = bfs(adj);
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}