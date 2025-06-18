#include<bits/stdc++.h>
using namespace std;

bool check(int r, vector<int>&houses, vector<int>&heaters) {
  for(int house: houses) {
    auto it = lower_bound(heaters.begin(), heaters.end(), house);
    int distance = INT_MAX;

    if(it != heaters.end())
      distance = min(distance, abs(*it-house));
    if(it != heaters.begin())
      distance = min(distance, abs(*prev(it) - house));

    if(distance > r)
      return false;
  }

  return true;
}

int findRadius(vector<int>&houses, vector<int>&heaters) {
  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());

  int i = 0, j = INT_MAX, ans = -1;
  while(i <= j) {
    int mid = i + (j-i)/2;

    if(check(mid, houses, heaters)) {
      ans = mid;
      j = mid-1;
    } else {
      i = mid+1;
    }
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the total no. of houses: ";
  cin>>n;

  vector<int>houses(n);
  cout<<"Enter the positon of each house:\n";
  for(int i = 0; i < n; i++) {
    cin>>houses[i];
  }

  int m;
  cout<<"Enter the total no. of heaters: ";
  cin>>m;

  vector<int>heaters(m);
  for(int i = 0; i < m; i++) {
    cin>>heaters[i];
  }

  cout<<findRadius(houses, heaters)<<endl;
}