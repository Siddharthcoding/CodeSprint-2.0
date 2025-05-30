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

Node *findSum(Node *root1, Node *root2) {
  Node *ans = new Node(-1);
  Node *ptr = ans;
  int carry = 0;

  while(root1 && root2) {
    int sum = root1->data + root2->data + carry;
    carry = sum / 10;

    Node *temp = new Node(sum % 10);
    ptr->next = temp;
    ptr = ptr->next;
    root1 = root1->next;
    root2 = root2->next;
  }

  while(root1) {
    int sum = root1->data + carry;
    carry = sum / 10;

    Node *temp = new Node(sum % 10);
    ptr->next = temp;
    ptr = ptr->next;
    root1 = root1->next;
  }

  while(root2) {
    int sum = root2->data + carry;
    carry = sum / 10;
    
    Node *temp = new Node(sum % 10);
    ptr->next = temp;
    ptr = ptr->next;
    root2 = root2->next;
  }

  if(carry > 0) {
    Node *temp = new Node(carry);
    ptr->next = temp;
    ptr = ptr->next;
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

int main()
{
  int m, n;
  cout<<"Enter the size of both linked list: ";
  cin>>m>>n;

  Node *root1 = NULL, *root2 = NULL;

  cout<<"Enter the elements of the first list:\n";
  root1 = createList(root1, m);

  cout<<"Enter the elements of the second list:\n";
  root2 = createList(root2, n);

  Node *ans = NULL;
  ans = findSum(root1, root2);

  Node *ptr = ans;
  cout<<"Resultant sum: ";
  while(ptr) {
    cout<<ptr->data<<" ";
    ptr = ptr->next;
  }
  cout<<endl;
}