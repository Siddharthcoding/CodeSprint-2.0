#include<bits/stdc++.h>
using namespace std;

bool canCure(int n, vector<int>&vaccine, vector<int>&patient) {
  bool cure = true;
  sort(vaccine.begin(), vaccine.end());
  sort(patient.begin(), patient.end());

  int i = 0, j = 0;
  while(i < n && j < n) {
    if(vaccine[i] <= patient[j]) {
      cure = false;
      break;
    }
    i++;
    j++;
  }

  return cure;
}

int main()
{
  int n;
  cout<<"Enter the total number of vaccines: ";
  cin>>n;

  vector<int>vaccine(n), patient(n);
  cout<<"Enter the midichlorian count of each vaccine:\n";
  for(int i = 0; i < n; i++) {
    cin>>vaccine[i];
  }

  cout<<"Enter the midichlorian count of each patient:\n";
  for(int i = 0; i < n; i++) {
    cin>>patient[i];
  }

  if(canCure(n, vaccine, patient))
    cout<<"yes\n";
  else
    cout<<"no\n";
}