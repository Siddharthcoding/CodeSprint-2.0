#include<bits/stdc++.h>
using namespace std;

int count(int num, int p) {
  int ans = 1;
  while(p > 0) {
    if(p % 2 == 1)
      ans *= num;
    num *= num;
    p /= 2;
  }

  return ans;
}

int countGoodStrings(int n) {
  if(n == 0)
    return 1;

  int even = (n+1) / 2, odd = n / 2;

  return count(5, even) * count(4, odd);
}

int main()
{
  int n;
  cout<<"Enter the length: ";
  cin>>n;

  cout<<countGoodStrings(n)<<endl;
}