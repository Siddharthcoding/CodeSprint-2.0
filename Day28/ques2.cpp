#include<bits/stdc++.h>
using namespace std;

int findScore(vector<int>&tokens, int power) {
  int maxScore = 0, currScore = 0;
  int i = 0, j = tokens.size()-1;
  sort(tokens.begin(), tokens.end());
  
  while(i <= j) {
    if(power >= tokens[i]) {
      power -= tokens[i];
      currScore++;
      i++;
    } else {
      if(currScore > 0) {
        currScore--;
        power += tokens[j];
        j--;
      } else {
        break;
      }
    }

    maxScore = max(maxScore, currScore);
  }

  return maxScore;
}

int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  vector<int>tokens(n);
  cout<<"Enter the power of each token:\n";
  for(int i = 0; i < n; i++) {
    cin>>tokens[i];
  }

  int power;
  cout<<"Enter the initial power: ";
  cin>>power;

  cout<<findScore(tokens, power)<<endl;
}