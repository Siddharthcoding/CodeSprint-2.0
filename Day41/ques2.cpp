#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node *left, *right;
    Node(int v) {
      val = v;
      left = NULL;
      right = NULL;
    }
};

Node *create(vector<string>&nodes) {
  if(nodes.empty() || nodes[0] == "null")
    return NULL;

  Node *root = new Node(stoi(nodes[0]));
  queue<Node*>q;
  q.push(root);

  int i = 1;
  while(!q.empty() && i < nodes.size()) {
    Node *curr = q.front();
    q.pop();

    if(i < nodes.size() && nodes[i] != "null") {
      curr->left = new Node(stoi(nodes[i]));
      q.push(curr->left);
    }
    i++;

    if(i < nodes.size() && nodes[i] != "null") {
      curr->right = new Node(stoi(nodes[i]));
      q.push(curr->right);
    }
    i++;
  }

  return root;
}

bool checkMirror(Node *a, Node *b) {
  if(!a && !b)
    return true;

  if(!a || !b)
    return false;

  return (a->val == b->val) && checkMirror(a->left, b->right) && checkMirror(a->right, b->left);
}

bool isSymmetric(Node *root) {
  if(!root)
    return true;

  return checkMirror(root->left, root->right);
}

int main()
{
  string line;
  cout<<"Enter the nodes value and null for absent nodes:\n";
  getline(cin, line);

  istringstream s(line);
  vector<string>nodes;
  string val;

  while(s >> val) 
    nodes.push_back(val);

  Node *root = create(nodes);
  cout<<(isSymmetric(root) ? "True": "False")<<endl;
}