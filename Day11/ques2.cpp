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

bool findCycle(Node *root) {
  Node *slow = root, *fast = root;

  while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast) {
      slow = root;
      Node *prev = NULL;

      while(slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
      }

      while(fast->next != slow) {
        fast = fast->next;
      }

      fast->next = NULL;
      return true;
    }
  }

  return true;
}

void createCycle(Node *root, int pos) {
  if(pos == 0)
    return;

  Node *posNode = root;
  for(int i = 1; i < 1 && !posNode; i++) {
    posNode = posNode->next;
  }

  if(!posNode)
    return;

  Node *last = root;
  while(last->next) {
    last = last->next;
  }

  last->next = posNode;
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

  int pos;
  cin>>pos;

  createCycle(root, pos);

  if(findCycle(root)) {
    cout<<"true\n";
  } else {
    cout<<"false\n";
  }
}