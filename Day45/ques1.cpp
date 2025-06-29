#include<bits/stdc++.h>
using namespace std;

int findGCD(int a, int b) {
  return b == 0 ? abs(a): findGCD(b, a % b);
}

vector<string> findFractions(string formula) {
  if(formula[0] != '+' && formula[0] != '-')
    formula = '+' + formula;

  vector<string>fractions;
  int i = 0;
  while(i < formula.size()) {
    char sign = formula[i];
    i++;
    string frac = string(1, sign);

    while(i < formula.size() && formula[i] != '+' && formula[i] != '-') {
      frac += formula[i];
      i++;
    }

    fractions.push_back(frac);
  }

  return fractions;
}

string evaluate(string formula) {  
  vector<string>fractions = findFractions(formula);

  int num = 0, den = 1;
  for(int i = 0; i < fractions.size(); i++) {
    int sign = (fractions[i][0] == '-') ? -1 : 1;
    int pos = fractions[i].find('/');
    int a = stoi(fractions[i].substr(1, pos-1));
    int b = stoi(fractions[i].substr(pos+1));
    a *= sign;

    num = num * b + den * a;
    den = den * b;

    int gcd = findGCD(num, den);
    num /= gcd;
    den /= gcd;
  }

  if(den < 0) {
    num *= -1;
    den *= -1;
  }

  return to_string(num) + "/" + to_string(den);
}

int main()
{
  string formula;
  cout<<"Enter the formula: ";
  cin>>formula;

  cout<<evaluate(formula)<<endl;
}