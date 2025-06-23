#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
  string curr = "";
  stack<int>nums;
  stack<string>words;

  int count = 0;
  for(char c: s) {
    if(isdigit(c)) {
      count = count * 10 + (c - '0');
    } else if(c == '[') {
      nums.push(count);
      words.push(curr);

      count = 0;
      curr = "";
    } else if(c == ']') {
      int repeat = nums.top();
      nums.pop();

      string prev = words.top();
      words.pop();

      for(int i = 0; i < repeat; i++) {
        prev += curr;
      }

      curr = prev;
    } else {
      curr += c;
    }
  }

  return curr;
}

int main()
{
  string s;
  cout<<"Enter the string: ";
  cin>>s;

  cout<<decodeString(s)<<endl;
}