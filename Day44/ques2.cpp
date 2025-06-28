#include<bits/stdc++.h>
using namespace std;

int findLength(int n, vector<string>&codeword) {
  int maxLen = 0;
  vector<int>masks(n);

  for(int i = 0; i < n; i++) {
    int mask = 0;
    for(char ch: codeword[i]) {
      mask |= (1 << (ch - 'a'));
    }
    masks[i] = mask;
  }

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if((masks[i] & masks[j]) == 0)
        maxLen = max(maxLen, (int)(codeword[i].size() * codeword[j].size()));
    }
  }

  return maxLen;
}

int main()
{
  int n;
  cout<<"Enter the no. of codewords: ";
  cin>>n;

  vector<string>codeword(n);
  cout<<"Enter the codewords:\n";
  for(int i = 0; i < n; i++) {
    cin>>codeword[i];
  }

  cout<<findLength(n, codeword)<<endl;
}