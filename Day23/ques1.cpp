#include<bits/stdc++.h>
using namespace std;

int findScore(int idx, int n, int k, vector<int>&scores, vector<int>&dp) {
  if(idx == n-1)
    return scores[idx];

  if(dp[idx] != -1)
    return dp[idx];

  int maxScore = INT_MIN;
  for(int i = 1; i <= k; i++) {
    if(idx + i < n)
    maxScore = max(maxScore, findScore(idx+i, n, k, scores, dp));
  }

  return dp[idx] = scores[idx] + maxScore;
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>scores(n);
  cout<<"Enter the scores of each room:\n";
  for(int i = 0; i < n; i++) {
    cin>>scores[i];
  }

  int k;
  cout<<"Enter the value of k: ";
  cin>>k;

  vector<int>dp(n, -1);

  cout<<findScore(0, n, k, scores, dp)<<endl;
}