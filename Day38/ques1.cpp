#include<bits/stdc++.h>
using namespace std;

string nextStr(string curr) {
  for(int i = 0; i < curr.size(); i++) {
    curr[i] = ((curr[i] - 'a' + 1) % 26) + 'a';
  }

  return curr;
}

char findLetter(int k) {
  string str = "a";
  while(str.size() < k) {
    str += nextStr(str);
  }

  return toupper(str[k-1]);
}

int main() 
{
  int k;
  cout<<"Enter the position to check: ";
  cin>>k;

  cout<<findLetter(k)<<endl; 
}