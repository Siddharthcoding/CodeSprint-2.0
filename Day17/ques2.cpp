#include<bits/stdc++.h>
using namespace std;

string convert(string postfix) {
  stack<string>st;

  for(int i = 0; i < postfix.size(); i++) {
    char ch = postfix[i];

    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      string first = st.top();
      st.pop();
      string second = st.top();
      st.pop();

      string expr = string(1, ch) + second + first;
      st.push(expr);
    } else {
      st.push(string(1, ch));
    }
  }

  return st.top();

}

int main()
{
  string postfix;
  cout<<"Enter the postfix expression: ";
  cin>>postfix;

  string prefix = convert(postfix);
  cout<<"Prefix expression: "<<prefix<<endl;
}