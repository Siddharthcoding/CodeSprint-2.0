#include<bits/stdc++.h>
using namespace std;

double findSum(int n) {
  double sum = 0;
  double i = 0;
  while(i <= n) {
    sum += (double)1 / pow(3, i);
    i++;
  }

  return sum;
}

int main()
{
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  cout<<findSum(n)<<endl;
}