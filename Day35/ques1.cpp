#include<bits/stdc++.h>
using namespace std;

bool canDivide(int sum, int n, int k, vector<int>&weights) {
  int count = 1, curr = 0;

  for(int i = 0; i < n; i++) {
    if(weights[i] > sum)
      return false;

    if(curr + weights[i] > sum) {
      count++;
      curr = weights[i];
    } else {
      curr += weights[i];
    }
  }

  return count <= k;
}

int smallestWeight(int n, int k, vector<int>&weights) {
  int minWeight = *max_element(weights.begin(), weights.end());
  int maxWeight = accumulate(weights.begin(), weights.end(), 0);

  int i = minWeight, j = maxWeight;
  while(i <= j) {
    int mid = i + (j-i) / 2;

    if(canDivide(mid, n, k, weights))
      j = mid - 1;
    else 
      i = mid + 1;
  }

  return i;
}

int main()
{
  int n, k;
  cout<<"Enter the total no. of parcels: ";
  cin>>n;

  cout<<"Enter the maximum boxes allowed: ";
  cin>>k;

  vector<int>weights(n);
  cout<<"Enter the weights of each parcel:\n";
  for(int i = 0; i < n; i++) {
    cin>>weights[i];
  }

  cout<<smallestWeight(n, k, weights)<<endl;
}