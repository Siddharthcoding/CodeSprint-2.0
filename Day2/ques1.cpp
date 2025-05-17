#include<bits/stdc++.h>
using namespace std;

int magicDayCount(vector<int>&scores, int n) {
  int count = 0;
  for(int i = 1; i < n-1; i++) {
    if(scores[i] > scores[i-1] && scores[i] > scores[i+1])
      count++;
  }

  return count;
}

int main() {
  int n;
  cin>>n;

  vector<int>scores(n);
  for(int i = 0; i < n; i++)
    cin>>scores[i];

  cout<<magicDayCount(scores, n)<<endl;
}