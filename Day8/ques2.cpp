#include<bits/stdc++.h>
using namespace std;

string reversedSpeech(string speech) {
  string ans = "", curr = "";
  vector<string>words;

  for(int i = 0; i < speech.size(); i++) {
    if(speech[i] != ' ') {
      curr += speech[i];
    } else if(!curr.empty()) {
      words.push_back(curr);
      curr = "";
    }
  }

  if(!curr.empty())
    words.push_back(curr);

  reverse(words.begin(), words.end());

  for(int i = 0; i < words.size(); i++) {
    ans += words[i];
    
    if(i < words.size()-1)
      ans += ' ';
  }

  return ans;
}

int main()
{
  string speechLine;
  getline(cin, speechLine);

  cout<<reversedSpeech(speechLine)<<endl;
}