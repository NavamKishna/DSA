#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) {
    if (root != NULL){
      traverseInOrder(root->left);
      cout << root->key ;
      traverseInOrder(root->right);
    }
}

// Insert a Node
struct Node *insertNode(struct Node *node, int key) {
    if (node == NULL) {
    node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
  } else if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }
    return node;
}

// Deleting a Node
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }
        struct Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
  struct Node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}