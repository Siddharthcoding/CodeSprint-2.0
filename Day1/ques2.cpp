#include<bits/stdc++.h>
using namespace std;

void goodOrBad(int n) {
  int good = 0, score;

  for(int i = 0; i < n; i++) {
    cin>>score;
    if(score >= 7)
      good++;
  }

  cout<<good<<" "<<n-good<<endl;
}

int main() {
  int n;
  cin>>n;

  goodOrBad(n);
}