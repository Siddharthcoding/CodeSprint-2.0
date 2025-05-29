#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int val) {
      data = val;
      next = NULL;
    }
};

vector<int>findList(Node *root, int skip) {
  vector<int>ans;
  Node *ptr = root;

  while(skip > 0 && ptr) {
    skip--;
    ptr = ptr->next;
  }

  while(ptr) {
    ans.push_back(ptr->data);
    ptr = ptr->next;
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

  int skip = n/2;

  Node *root = NULL;
  cout<<"Enter the values of the nodes:\n";
  while(n--) {
    int val;
    cin>>val;

    Node *temp = new Node(val);
    if(!root) {
      root = temp;
    } else {
      Node *ptr = root;
      while(ptr->next) {
        ptr = ptr->next;
      }
      ptr->next = temp;
    }
  }

  vector<int>ans = findList(root, skip);
  for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}