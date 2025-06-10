#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second)
    return a.first < b.first;

  return a.second > b.second;
}

void sortLabels(int n, vector<int>&labels, unordered_map<int, int>&freq) {
  vector<pair<int, int>>crate;
  for(auto it: freq) {
    crate.push_back({it.first, it.second});
  }

  sort(crate.begin(), crate.end(), comp);

  vector<int>ans;
  for(auto it: crate) {
    int num = it.first, freq = it.second;
    while(freq--) {
      ans.push_back(num);
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
  cout<<"Enter the total no. of crates: ";
  cin>>n;

  vector<int>labels(n);
  unordered_map<int, int>freq;
  cout<<"Enter the label value of each crate\n";
  for(int i = 0; i < n; i++) {
    cin>>labels[i];
    freq[labels[i]]++;
  }

  sortLabels(n, labels, freq);
}