// // Approach 1:

// #include<bits/stdc++.h>
// using namespace std;

// void findAnagrams(string &logStream, string &pattern) {
//   int m = logStream.size(), n = pattern.size();
//   int l = 0, r = 0;
//   vector<int>ans;
  
//   string curr = "";
//   while(l < m) {
//     curr += logStream[r];

//     while(curr.size() == pattern.size()) {
//       string temp1 = curr, temp2 = pattern;
//       sort(temp1.begin(), temp1.end());
//       sort(temp2.begin(), temp2.end());
//       if(temp1 == temp2) {
//         ans.push_back(l);
//       }
//       curr.erase(0, 1);
//       l++;
//     }

//     r++;
//   }

//   for(int i = 0; i < ans.size(); i++)
//     cout<<ans[i]<<" ";
//   cout<<endl;
  
// }

// int main()
// {
//   string logStream, pattern;
//   cin>>logStream>>pattern;

//   findAnagrams(logStream, pattern);
// }

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string &logStream, string &pattern) {
  int m = logStream.size(), n = pattern.size();
  unordered_map<char, int>streamFreq, patternFreq;
  vector<int>ans;

  if(m < n) {
    return {};
  }

  for(char ch: pattern)
    patternFreq[ch]++;
    
  for(int i = 0; i < m; i++) {
    streamFreq[logStream[i]]++;

    if(i >= n) {
      char left = logStream[i-n];
      streamFreq[left]--;

      if(streamFreq[left] == 0)
        streamFreq.erase(left);
    }

    if(streamFreq == patternFreq)
      ans.push_back(i-n+1);
  }
  
  return ans;
}

int main()
{
  string logStream, pattern;
  cin>>logStream>>pattern;

  vector<int>ans = findAnagrams(logStream, pattern);

  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}