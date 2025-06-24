#include<bits/stdc++.h>
using namespace std;

double findPower(double x, int n) {
  if(n == 0)
    return 1.0;

  if(x == 0)
    return 0.0;

  if(n < 0) 
    return 1.0 / findPower(x, -n);

  if(n % 2 == 0) {
    double ans = findPower(x, n/2);
    return ans * ans;
  } else {
    double ans = findPower(x, (n-1) / 2);
    return x * ans * ans;
  }
}

int main()
{
  double x;
  cout<<"Enter the base: ";
  cin>>x;

  int n;
  cout<<"Enter the exponent: ";
  cin>>n;

  cout<<findPower(x, n)<<endl;
}