#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

/* Build tree from level order */
Node* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

/* Height of tree */
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

/* Print nodes at a given level */
void displayNthLevel(Node* root, int curr, int level) {
    if (!root) return;
    if (curr == level) {
        cout << root->value << " ";
        return;
    }
    displayNthLevel(root->left, curr + 1, level);
    displayNthLevel(root->right, curr + 1, level);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,-1};

    Node* root = buildTree(arr);

    int h = height(root);
    for (int i = 1; i <= h; i++) {
        displayNthLevel(root, 1, i);
        cout << endl;

        cout<<"hello";
    }

    return 0;
}
