#include<bits/stdc++.h>
using namespace std;

int findFact(int n) {
  if(n == 0 || n == 1)
    return 1;

  return n * findFact(n-1);
}

int nCr(int n, int r) {
  return findFact(n) / (findFact(r) * findFact(n-r));
}

int main()
{
  int n, r;
  cout<<"Enter the value of n & r: ";
  cin>>n>>r;

  cout<<nCr(n, r)<<endl;
}