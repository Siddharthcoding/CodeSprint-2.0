#include<bits/stdc++.h>
using namespace std;

void performOperations(vector<string>&op, int n) {
  stack<int>st1, st2;

  for(int i = 0; i < n; i++) {
    stringstream ss(op[i]);
    string cmd;
    ss >> cmd;

    if(cmd == "PUSH") {
      int num;
      ss >> num;

      st1.push(num);
      if(st2.empty() || num <= st2.top()) {
        st2.push(num);
      }
    } else if(cmd == "POP") {
      if(!st1.empty()) {
        int val = st1.top();
        st1.pop();

        if(val == st2.top()) {
          st2.pop();
        }
      }
    } else if(cmd == "MIN") {
      if(st2.empty()) {
        cout<<"EMPTY\n";
      } else {
        cout<<st2.top()<<endl;
      }
    }
  }
  
}

int main()
{
  int n;
  cout<<"Enter the number of operations: ";
  cin>>n;
  cin.ignore();

  vector<string>op(n);
  for(int i = 0; i < n; i++) {
    getline(cin, op[i]);
  }

  performOperations(op, n);
}