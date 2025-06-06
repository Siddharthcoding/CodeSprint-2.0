#include<bits/stdc++.h>
using namespace std;

int count(queue<int>students, stack<int>sandwiches) {
  int count = 0;

  while(!students.empty()) {
    if(students.front() == sandwiches.top()) {
      students.pop();
      sandwiches.pop();
      count = 0;
    } else {
      students.push(students.front());
      students.pop();
      count++;

      if(count == students.size())
        break;
    }
  }

  return students.size();
}

int main()
{
  int n;
  cout<<"Enter the total no of students: ";
  cin>>n;

  queue<int>students;
  int val;
  cout<<"Enter 0 or 1 for students preference:\n";
  for(int i = 0; i < n; i++) {
    cin>>val;
    students.push(val);
  }

  stack<int>sandwiches;
  cout<<"Enter 0 or 1 for sandwich's type:\n";
  for(int i = 0; i < n; i++) {
    cin>>val;
    sandwiches.push(val);
  }

  cout<<count(students, sandwiches)<<endl;
}