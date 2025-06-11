#include<bits/stdc++.h>
using namespace std;

void printRank(vector<int>&scores) {
  vector<pair<int, int>>sorted;
  for(int i = 0; i < scores.size(); i++) {
    sorted.push_back({scores[i], i});
  }

  sort(sorted.rbegin(), sorted.rend());

  vector<string>ans(scores.size());
  for(int i = 0; i < scores.size(); i++) {
    int idx = sorted[i].second;
    
    if(i == 0) {
      ans[idx] = "Gold Medal";
    } else if(i == 1) {
      ans[idx] = "Silver Medal";
    } else if(i == 2) {
      ans[idx] = "Bronze Medal";
    } else {
      ans[idx] = to_string(i+1);
    }
  }

  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int n; 
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>scores(n);
  cout<<"Enter the score of each robot:\n";
  for(int i = 0; i < n; i++) {
    cin>>scores[i];
  } 

  printRank(scores);
}