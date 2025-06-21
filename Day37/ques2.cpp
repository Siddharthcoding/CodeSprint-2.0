#include<bits/stdc++.h>
using namespace std;

bool check(int n) {
  if(n == 1)
    return true;

  if(n <= 0 || n % 2 != 0)
    return false;

  return check(n / 2);
}

int main()
{
  int n;
  cout<<"Enter a number: ";
  cin>>n;

  if(check(n))
    cout<<"True\n";
  else
    cout<<"False\n";
}