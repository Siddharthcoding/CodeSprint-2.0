#include<bits/stdc++.h>
using namespace std;

vector<long long> findEnergy(int n, vector<long long>&energy) {
  vector<long long>pre(n, 1), suf(n, 1), ans(n);

  for(int i = 1; i < n; i++) {
    pre[i] = pre[i-1] * energy[i-1];
  }

  for(int i = n-2; i >= 0; i--) {
    suf[i] = suf[i+1] * energy[i+1];
  }

  for(int i = 0; i < n; i++) {
    ans[i] = pre[i] * suf[i];
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the total no. of crystals: ";
  cin>>n;

  vector<long long>energy(n);
  cout<<"Enter the enery level of crystals:\n";
  for(int i = 0; i < n; i++) {
    cin>>energy[i];
  }

  vector<long long>transformed = findEnergy(n, energy);
  for(int i = 0; i < n; i++) {
    cout<<transformed[i]<<" ";
  }
  cout<<endl;
}