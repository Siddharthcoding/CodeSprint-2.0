#include<bits/stdc++.h>
using namespace std;

void printPattern(int n) {
  int diag = 1, antiDiag = n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) 
        cout<<diag++<<' ';
      else if(i+j == n-1)
        cout<<antiDiag--<<' ';
      else
        cout<<"- ";
    }
    cout<<endl;
  }
}

int main()
{
  int n;
  cin>>n;

  printPattern(n);
}