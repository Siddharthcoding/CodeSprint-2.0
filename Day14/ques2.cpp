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

Node *reverseList(Node *root) {
  Node *prev = NULL, *curr = root;
  while(curr) {
    Node *fut = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fut;
  }

  return prev;
}

Node *doubledList(Node *root) {
  root = reverseList(root);
  Node *dummy = new Node(-1);
  Node *ptr = root, *tail = dummy;

  int carry = 0;
  while(ptr) {
    int val = ptr->data * 2 + carry;
    carry = val/10;

    tail->next = new Node(val % 10);
    tail = tail->next;
    ptr = ptr->next;
  }

  if(carry > 0) {
    tail->next = new Node(carry);
  }

  return reverseList(dummy->next); 
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

  Node *root = NULL;
  cout<<"Enter the elements of the linked list:\n";
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

  Node *ans = doubledList(root);
  cout<<"Doubled value:\n";
  Node *ptr = ans;
  while(ptr) {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}