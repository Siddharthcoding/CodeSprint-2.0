#include<bits/stdc++.h>
using namespace std;

int findArrangements(int n, vector<int>&cards) {
  set<pair<int, int>>ans;
  set<int>unique(cards.begin(), cards.end());

  vector<int>nums(unique.begin(), unique.end());

  for(int i = 0; i < nums.size(); i++) {
    for(int j = 0; j < nums.size(); j++) {
      if(nums[i] > nums[j])
        ans.insert({nums[i], nums[j]});
    }
  }

  return ans.size();
}

int main()
{
  int n;
  cout<<"Enter the total no. of cards: ";
  cin>>n;

  vector<int>cards(n);
  cout<<"Enter the number on each card:\n";
  for(int i = 0; i < n; i++) {
    cin>>cards[i];
  }

  cout<<findArrangements(n, cards)<<endl;
}