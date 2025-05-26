#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&appointments) {
  int n = appointments.size();
  if(n < 2)
    return appointments;
  
  int start = 0, end = n-1;
  vector<int>ans;
  
  while(start <= end) {
    ans.push_back(appointments[start]);
    ans.push_back(appointments[end]);
    start++;
    end--;
  }

  return ans;
}

int main()
{
  int n;
  cin>>n;

  vector<int>appointments(n);
  for(int i = 0; i < n; i++) {
    cin>>appointments[i];
  }

  vector<int>zig_zag = solve(appointments);

  for(int i = 0; i < n; i++) {
    cout<<zig_zag[i]<<" ";
  }
  cout<<endl;
}