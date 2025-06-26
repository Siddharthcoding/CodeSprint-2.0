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

Node *convertBST(vector<int>nums, int left, int right) {
  if(left > right)
    return NULL;

  int mid = left + (right - left) / 2;
  Node *root = new Node(nums[mid]);
  root->left = convertBST(nums, left, mid-1);
  root->right = convertBST(nums, mid + 1, right);

  return root;
}

vector<int>levelOrder(Node *root) {
  vector<int>ans;
  if(!root)
    return ans;

  queue<Node*>q;
  q.push(root);

  while(!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if(curr) {
      ans.push_back(curr->val);
      q.push(curr->left);
      q.push(curr->right);
    } else {
      ans.push_back(INT_MIN);
    }
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the total no. of nodes: ";
  cin>>n;

  vector<int>nums(n);
  cout<<"Enter the nodes value:\n";
  for(int i = 0; i < n; i++) {
    cin>>nums[i];
  }

  Node *root = convertBST(nums, 0, nums.size() - 1);

  vector<int>ans = levelOrder(root);
  for(int val: ans) {
    if(val == INT_MIN)
      cout<<"null ";
    else
      cout<<val<<" ";
  }
}