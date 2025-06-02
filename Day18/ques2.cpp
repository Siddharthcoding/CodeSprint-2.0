#include<bits/stdc++.h>
using namespace std;

int evaluate(vector<string>&arr) {
  stack<int>st;

  for(int i = 0; i < arr.size(); i++) {
    string ch = arr[i];

    if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
      int first = st.top();
      st.pop();
      int second = st.top();
      st.pop();

      if(ch == "+")
        st.push(second + first);
      else if(ch == "-")
        st.push(second - first);
      else if(ch == "*")
        st.push(second * first);
      else {
        if(first == 0) {
          cout<<"Error Divide by 0\n";
          return -1;
        }
        st.push(second / first);
      }
    } else {
      st.push(stoi(ch));
    }
  }

  return st.top();
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<string>arr(n);
  cout<<"Enter the elements of the expression:\n";
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }

  cout<<"Result: "<<evaluate(arr)<<endl;
}