#include<bits/stdc++.h>
using namespace std;

int findSymbol(int n, int k) {
  if(n == 1)
    return 0;

  int prev = findSymbol(n-1, (k+1) / 2);

  if(prev == 0)
    return (k % 2 == 1) ? 0 : 1;
  else
    return (k % 2 == 1) ? 1 : 0;
}

int main()
{
  int n, k;
  cout<<"Enter the row number: ";
  cin>>n;
  cout<<"Enter the position in "<<n<<"th row: ";
  cin>>k;

  cout<<findSymbol(n, k)<<endl;
}