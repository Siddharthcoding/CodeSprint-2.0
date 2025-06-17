#include<bits/stdc++.h>
using namespace std;

int countOperations(int n, string s) {
  int operations = 0;
  int i = 0, j = n-1;

  while(i < j) {
    while(i < j && s[i] != '1')
      i++;
    while(i < j && s[j] != '0')
      j--;

    if(i < j) {
      operations++;
      i++;
      j--;
    }
  }
  
  return operations;
}

int main()
{
  int n;
  cout<<"Enter the length of the string: ";
  cin>>n;

  string s;
  cout<<"Enter the binary string: ";
  cin>>s;

  cout<<countOperations(n, s)<<endl;
}