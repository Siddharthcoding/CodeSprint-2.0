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

Node *sortList(Node *root, int count0, int count1, int count2) {
  Node *ptr = root;
  while(count0--) {
    ptr->data = 0;
    ptr = ptr->next;
  }

  while(count1--) {
    ptr->data = 1;
    ptr = ptr->next;
  }

  while(count2--) {
    ptr->data = 2;
    ptr = ptr->next;
  }

  return root;
}

void printList(Node *root) {
  Node *ptr = root;
  while(ptr) {
    cout<<ptr->data;
    if(ptr->next) {
      cout<<" -> ";
    }
    ptr = ptr->next;
  }
  cout<<endl;
}

int main()
{
  int n;
  cin>>n;

  int count0 = 0, count1 = 0, count2 = 0;

  Node *root = NULL;
  while(n--) {
    int val;
    cin>>val;

    if(val == 0)
      count0++;
    else if(val == 1)
      count1++;
    else
      count2++;

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

  root = sortList(root, count0, count1, count2);

  cout<<"After sorting:\n";
  printList(root);
}