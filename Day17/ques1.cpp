#include<bits/stdc++.h>
using namespace std;

string reverseString(string s) {
  stack<char>st;
  for(int i = 0; i < s.size(); i++) {
    st.push(s[i]);
  }

  int i = 0;
  while(!st.empty()) {
    s[i] = st.top();
    st.pop();
    i++;
  }

  return s;
}

int main()
{
  string s;
  cout<<"Enter the string: ";
  getline(cin, s);

  s = reverseString(s);
  cout<<"Reversed string:\n";
  for(int i = 0; i < s.size(); i++) {
    cout<<s[i];
  }
  cout<<endl;
}