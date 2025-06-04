#include<bits/stdc++.h>
using namespace std;

string printPrimitives(string &s) {
  string ans = "";
  int count = 0;

  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') {
      if(count > 0) {
        ans += '(';
      }
      count++;
    } else {
      count--;
      if(count > 0) {
        ans += ')';
      }
    }
  }

  return ans;
}

int main()
{
  string s;
  cout<<"Enter the valid parentheses string: ";
  cin>>s;

  cout<<printPrimitives(s)<<endl;
}