#include<bits/stdc++.h>
using namespace std;

int countOverstock(vector<vector<int>>&warehouse, int r, int c) {
  int count = 0;

  for(int i = 0; i < r; i++) {
    int curr = 0;
    for(int j = 0; j < c; j++) {
      if(warehouse[i][j] >= 100)
        curr++;
    }

    if(curr >= 3)
      count++;
  }

  return count;
}

int main()
{
  int r, c;
  cin>>r>>c;

  vector<vector<int>>warehouse(r, vector<int>(c));
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      cin>>warehouse[i][j];

  cout<<countOverstock(warehouse, r, c)<<endl;
}