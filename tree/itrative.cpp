#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <queue>
#include<stack>

using namespace std;

class Node {
public:
  int value = NULL;
  Node *left = NULL;
  Node *right = NULL;
  Node(int value) { this->value = value; }
};


void levelOrderTra(Node* root){

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<temp->value<<"    ";
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
        
            q.push(temp->right);
        }
    }
}

void preOrder(Node* root){
    if (root == NULL) {
    return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->value<<"    ";
}


void ittrativePreOrder(Node* root){
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout<<temp->value<<"    ";
        if (temp->right) {
            s.push(temp->right);
        }
        if (temp->left) {
            s.push(temp->left);
        }
    }
}
void ittrativePostOrder(Node* root){
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        if (temp->right) {
            s.push(temp->right);
        }
        if (temp->left) {
            s.push(temp->left);
        }
        cout<<temp->value<<"    ";
    }
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
  preOrder(a);
  ittrativePostOrder(a);
  cout<<endl;
  return 0;
}