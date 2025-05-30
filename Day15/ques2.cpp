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

Node *removeTarget(Node *root, int target) {
  Node *ptr = root;
  
  while(ptr) {
    Node *nextNode = ptr->next;
    
    if(ptr->data == target) {
      if(ptr == root) {
        root = root->next;
        if(root)
          root->prev = NULL;
      } else if(ptr->next) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
      } else {
        ptr->prev->next = NULL;
      }
    }

    ptr = nextNode;
  }

  return root;
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

  Node *root = NULL, *tail = NULL;
  while(n--) {
    int val;
    cin>>val;

    Node *temp = new Node(val);
    if(!root) {
      root = tail = temp;
    } else {
      tail->next = temp;
      temp->prev = tail;
      tail = tail->next;
    }
  }

  int target;
  cout<<"Enter the target node value: ";
  cin>>target;

  root = removeTarget(root, target);
  Node *ptr = root;
  cout<<"Resultant list:\n";
  while(ptr) {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}