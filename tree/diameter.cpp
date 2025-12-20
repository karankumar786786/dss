#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int value = NULL;
  Node *left = NULL;
  Node *right = NULL;
  Node(int value) { this->value = value; }
};

int height(Node* root){
    if (root == nullptr) {
    return 0;
    };
    return 1 + max(height(root->left),height(root->right));
}

void diameter(Node* root,vector<int>& ans){
    if (root == NULL) {
        return;
    }
    int left = height(root->left);
    int right = height(root->right);
    ans.push_back(left+right);
    diameter(root->left, ans);
    diameter(root->right, ans);
}


int main() {
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  Node *f = new Node(6);
  Node *g = new Node(7);
  Node *h = new Node(8);
  Node *i = new Node(9);  
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  d->left = h;
  d->right = i;
    vector<int> ans;
    diameter(a, ans);
    int temp = INT_MIN;
    for (int i =0; i<ans.size(); i++) {
        if (temp<ans[i]) {
            temp = ans[i];
        }
    };
    cout<<temp;

  return 0;
}