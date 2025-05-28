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

vector<vector<int>> splitNodes(Node *root, int n, int k) {
  vector<vector<int>>ans;
  int length = n / k;
  int extra = n % k;

  Node *ptr = root;
  for(int i = 0; i < k; i++) {
    int currSize = (i < extra) ? length+1 : length;
    vector<int>temp;

    for(int j = 0; j < currSize && ptr != NULL; j++) {
      temp.push_back(ptr->data);
      ptr = ptr->next;
    }
    ans.push_back(temp);
  }

  return ans;
}

int main()
{
  int n;
  cout<<"Enter the size of the linked list: ";
  cin>>n;

  int total = n;
  Node *root = NULL;
  cout<<"Enter the nodes of the linked list:\n";
  while(n--) {
    int val;
    cin>>val;

    Node *temp = new Node(val);
    if(!root) {
      root = temp;
    } else{
      Node *ptr = root;
      while(ptr->next) {
        ptr = ptr->next;
      }
      ptr->next = temp;
    }
  }

  int k;
  cout<<"Enter the value of k: ";
  cin>>k;

  vector<vector<int>>ans = splitNodes(root, total, k);
  for(int i = 0; i < ans.size(); i++) {
    auto part = ans[i];
    
    if(part.empty()) {
      cout<<"[]";
    } else {
      cout<<"[ ";
      for(int i = 0; i < part.size(); i++) {
        cout<<part[i];
        if(i < part.size()-1)
          cout<<", ";
      }
      cout<<" ]";
    }
    if(i < ans.size()-1)
    cout<<", ";
  }
}