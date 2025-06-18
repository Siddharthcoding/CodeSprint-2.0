#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
  if(num < 2)
    return false;

  int i = 2;
  while(i < num) {
    if(num % i == 0)
      return false;
    i++;
  }

  return true;
}

int main()
{
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  int num = 1;
  vector<int>primes;
  while(num <= n) {
    if(isPrime(num)) {
      primes.push_back(num);
    }
    num++;
  }

  vector<int>ans;
  for(int i= 0; i < primes.size(); i++) {
    if(primes[i] < primes.size()) {
      ans.push_back(primes[primes[i]]);
    }
  }

  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}