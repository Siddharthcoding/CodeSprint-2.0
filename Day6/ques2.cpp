#include<bits/stdc++.h>
using namespace std;

bool hasVowel(string name) {
  char ch = name[0];

  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
  int n;
  cin>>n;

  vector<string>patients(n);
  for(int i = 0; i < n; i++) {
    cin>>patients[i];
  }

  unordered_set<string>unique;
  vector<string>ans;

  for(int i = 0; i < n; i++) {
    if(hasVowel(patients[i]) && unique.find(patients[i]) == unique.end()) {
      unique.insert(patients[i]);
      ans.push_back(patients[i]);
    }
  }

  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}