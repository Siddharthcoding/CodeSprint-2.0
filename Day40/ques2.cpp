#include<bits/stdc++.h>
using namespace std;

long long uniqueBST(int n) {
  if(n == 0)
    return 1;

  long long count = 0;
  for(int i = 1; i <= n; i++) {
    count += uniqueBST(i-1) * uniqueBST(n-i);
  }

  return count;
}

int main()
{
  int n;
  cout<<"Enter the no. of unique flowers: ";
  cin>>n;

  cout<<uniqueBST(n)<<endl;
}