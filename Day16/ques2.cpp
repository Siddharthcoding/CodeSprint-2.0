#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    string data;
    Node *next;
    Node(string val) {
      data = val;
      next = NULL;
    }
};

Node *reverseList(Node *root, int left, int right) {
  if(left == right)
    return root;
  
  Node *temp = new Node("temp");
  temp->next = root;
  Node *prev = temp;

  for(int i = 1; i < left; i++) {
    prev = prev->next;
  }

  Node *curr = prev->next, *fut = curr->next;
  for(int i = 0; i < right - left; i++) {
    curr->next = fut->next;
    fut->next = prev->next;
    prev->next = fut;
    fut = curr->next;
  }

  return temp->next;
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

  Node *root = NULL, *tail = NULL;
  cout<<"Enter the elements in the list:\n";
  while(n--) {
    string val;
    cin>>val;

    Node *temp = new Node(val);
    if(!root) {
      root = tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }
  }

  int left, right;
  cout<<"Enter the left and right index: ";
  cin>>left>>right;

  root = reverseList(root, left, right);
  Node *ptr = root;
  cout<<"\nList after reversing the segment:\n";
  while(ptr) {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}