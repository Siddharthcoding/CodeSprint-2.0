#include<bits/stdc++.h>
using namespace std;

vector<string>ones = {
  "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
  "Seventeen", "Eighteen", "Nineteen"
};

vector<string>tens = {
  "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
  "Ninety"
};

string find(int num) {
  string ans = "";

  if(num >= 1000000000) {
    ans += find(num / 1000000000) + " Billion";
    num %= 1000000000;
  }
  if(num >= 1000000) {
    ans += find(num / 1000000) + " Million";
    num %= 1000000;
  }
  if(num >= 1000) {
    ans += find(num / 1000) + " Thousand";
    num %= 1000;
  }
  if(num >= 100) {
    ans += " " + ones[num / 100] + " Hundred";
    num %= 100;
  }
  if(num >= 20) {
    ans += " " + tens[num / 10];
    num %= 10;
  }
  if(num > 0) {
    ans += " " + ones[num];
  }

  return ans;
}

string numToStr(int num) {
  if(num == 0)
    return "Zero";

  return find(num).substr(1);
}

int main()
{
  int num;
  cout<<"Enter a number: ";
  cin>>num;

  cout<<numToStr(num)<<endl;
}