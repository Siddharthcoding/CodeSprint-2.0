#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *prev, *next;
    Node(int val) {
      data = val;
      prev = NULL;
      next = NULL;
    }
};

Node *sortList(Node *root) {
  Node *ptr = root;
  while(ptr) {
    Node *curr = ptr->next;
    while(curr) {
      if(ptr->data > curr->data)
        swap(ptr->data, curr->data);
      
      curr = curr->next;
    }
    ptr = ptr->next;
  }

  return root;
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

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
      temp->prev = ptr;
    }
  }

  root = sortList(root);
  cout<<"Sorted List:\n";
  Node *ptr = root;
  while(ptr) {
    cout<<ptr->data;
    if(ptr->next)
      cout<<" <-> ";
    ptr = ptr->next;
  }
  cout<<endl;
}