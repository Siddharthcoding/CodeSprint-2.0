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

int findDepth(Node *root) {
  int depth = 0;
  while(root != NULL) {
    depth++;
    root = root->left;
  }

  return depth;
}

int countNodes(Node *root) {
  if(root == NULL)
    return 0;

  int left = findDepth(root->left);
  int right = findDepth(root->right);

  if(left == right)
    return (1 << left) + countNodes(root->right);
  else
    return (1 << right) + countNodes(root->left);
}

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

int main()
{
  string line;
  vector<string>nodes;
  cout<<"Enter the nodes value and null for absent nodes:\n";
  getline(cin, line);

  istringstream s(line);
  string val;

  while(s >> val)
    nodes.push_back(val);

  Node *root = create(nodes);
  cout<<countNodes(root)<<endl;
}