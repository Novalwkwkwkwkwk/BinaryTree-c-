#include <iostream>
using namespace std;

// Definisi struktur node
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan node ke dalam binary tree
void insertNode(Node** root, char value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else {
        if (value < (*root)->data) {
            insertNode(&((*root)->left), value);
        } else {
            insertNode(&((*root)->right), value);
        }
    }
}

// Fungsi untuk mencetak binary tree secara in-order
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Fungsi untuk mencetak binary tree secara pre-order
void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Fungsi untuk mencetak binary tree secara post-order
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;

    // Memasukkan node-node ke dalam binary tree
    insertNode(&root, 'N');
    insertNode(&root, 'O');
    insertNode(&root, 'V');
    insertNode(&root, 'A');
    insertNode(&root, 'L');

    // Mencetak binary tree
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
