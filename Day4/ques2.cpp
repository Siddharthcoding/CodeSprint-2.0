#include<bits/stdc++.h>
using namespace std;

void printZigZag(int n) {
  int count = 0;
  for(int i = 1; i <= n; i++) {
    if(i % 2 != 0) {
      for(int j = 1; j <= i; j++) {
        cout<<j<<"   ";
        count++;
      }
      cout<<endl;
    } else {
      for(int j = i; j >= 1; j--) {
          cout<<j<<"   ";
          count++;
      }
      cout<<endl;
    }
  }

  cout<<"Total numbers printed: "<<count<<endl;
}

int main()
{
  int n;
  cin>>n;

  if(n > 10)
    cout<<"Every expert was once a beginner. Embrace the journey\n";

  printZigZag(n);
}