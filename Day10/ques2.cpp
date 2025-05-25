#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int value;
    Node *next;
    Node(int val) {
      value = val;
      next = NULL;
    }
};

void removeDuplicates(Node *root) {
  if(!root || !root->next)
    return;

  Node *curr = root, *fut = curr->next;
  while(fut) {
    if(curr->value == fut->value) {
      curr->next = fut->next;
      delete fut;
    } else {
      curr = curr->next;
    }
    fut = curr->next;
  }
}

int main()
{
  int n;
  cin>>n;

  Node *root = NULL;

  while(n--) {
    int num;
    cin>>num;

    Node *temp = new Node(num);
    if(!root) {
      root = temp;
    }else {
      Node *ptr = root;
      while(ptr->next != NULL) {
        ptr = ptr->next;
      }

      ptr->next = temp;
    }
  }

  removeDuplicates(root);
  Node *ptr = root;
  while(ptr) {
    cout<<ptr->value<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}