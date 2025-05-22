#include<bits/stdc++.h>
using namespace std;

int countSegments(string log) {
  int count = 0;

  for(int i = 0; i < log.size();) {
    if(log[i] == '0') {
      i++;
      continue;
    }

    while(i < log.size() && log[i] == '1')
      i++;
    count++;
  }

  return count;
}

int main()
{
  string log;
  cin>>log;

  cout<<countSegments(log)<<endl;
}