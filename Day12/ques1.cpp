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

Node* sortList(Node *root) {
  if(!root || !root->next)
    return root;
  
  Node *curr = root;

  while(curr->next) {
    if(curr->next->data < 0) {
      Node *temp = curr->next;
      curr->next = temp->next;

      temp->next = root;
      root = temp;
    } else {
      curr = curr->next;
    }
  }

  return root;
}

void printList(Node *root) {
  Node *ptr = root;
  while(ptr) {
    cout<<ptr->data;
    if(ptr->next)
      cout<<" -> ";

    ptr = ptr->next;
  }
  cout<<endl;
}

int main()
{
  int n;
  cin>>n;

  Node *root = NULL;

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

  cout<<"Original list:\n";
  printList(root);
  
  root = sortList(root);

  cout<<"After sorting:\n";
  printList(root);
}