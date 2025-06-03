#include<bits/stdc++.h>
using namespace std;

void countGifts(vector<string>&op, int n) {
  unordered_map<string, int>freq;
  stack<string>st;
  
  for(int i = 0; i < n; i++) {
    stringstream ss(op[i]);
    string cmd;
    ss >> cmd;

    if(cmd == "PUSH") {
      string val;
      ss >> val;
      
      st.push(val);
      freq[val]++;
    } else if(cmd == "POP") {
      if(!st.empty()) {
        string val = st.top();
        st.pop();
        
        freq[val]--;
      } 
    } else if(cmd == "COUNT") {
      if(st.empty()) {
        cout<<"EMPTY\n";
      } else {
        cout<<freq[st.top()]<<endl;
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

  countGifts(op, n);
}