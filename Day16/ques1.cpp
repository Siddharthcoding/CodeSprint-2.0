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

Node *mergeList(Node *root1, Node *root2) {
  Node *ans = new Node(-1);
  Node *tail = ans;

  while(root1 && root2) {
    if(root1->data <= root2->data) {
      tail->next = root1;
      root1 = root1->next;
    } else {
      tail->next = root2;
      root2 = root2->next;
    }
    tail = tail->next;
  }

  if(root1) {
    tail->next = root1;
  }

  if(root2) {
    tail->next = root2;
  }

  return ans->next;
}

Node *createList(Node *root, int n) {
  Node *tail = NULL;
  while(n--) {
    int val;
    cin>>val;

    Node *temp = new Node(val);
    if(!root) {
      root = tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }
  }

  return root;
}

int main() {
  int m, n;
  cout<<"Enter the size of both lists: ";
  cin>>m>>n;

  Node *root1 = NULL, *root2 = NULL;

  cout<<"Enter the elements of the first list:\n";
  root1 = createList(root1, m);
  cout<<"Enter the elements of the second list:\n";
  root2 = createList(root2, n);

  Node *ans = NULL;
  ans = mergeList(root1, root2);
  cout<<"Merged list:\n";
  Node *ptr = ans;

  while(ptr) {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}