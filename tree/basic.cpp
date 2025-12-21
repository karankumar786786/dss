#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
  int value = NULL;
  Node *left = NULL;
  Node *right = NULL;
  Node(int value) { this->value = value; }
};

void display(Node *root) {
  if (root == NULL)
    return;
  cout << root->value << "    ";
  display(root->left);
  display(root->right);
}

int Sum(Node* root){
  if (root == NULL) {
    return 0;
  }
  return root->value + Sum(root->left) + Sum(root->right);
}

int size(Node* root){
  if(root == NULL) return 0;
  return 1 + size(root->left) + size(root->right);
}
int maxi(Node* root){
  if (root == NULL) {
    return INT_MIN;
  };
  return max(root->value,max(maxi(root->left),maxi(root->right)));
}
int product(Node* root){
  if (root == NULL) {
    return  1;
  };
  return root->value*product(root->left)*product(root->right);
}

// lets try to make pull request

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
  display(a);
  cout<<Sum(a)<<endl;
  cout<<size(a)<<endl;
  cout<<maxi(a)<<endl;
  cout<<product(a)<<endl;
  return 0;
}