#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left = NULL, *right = NULL;
    Node(int x) : data(x) {}
};

Node* insert(Node* r, int x) {
    if (!r) return new Node(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}

bool search(Node* r, int x) {
    if (!r) return false;
    if (r->data == x) return true;
    return x < r->data ? search(r->left, x) : search(r->right, x);
}

Node* del(Node* r, int x) {
    if (!r) return NULL;
    if (x < r->data) r->left = del(r->left, x);
    else if (x > r->data) r->right = del(r->right, x);
    else {
        if (!r->left) return r->right;
        if (!r->right) return r->left;
        Node* t = r->right;
        while (t->left) t = t->left; // Find minimum in right subtree
        r->data = t->data;
        r->right = del(r->right, t->data);
    }
    return r;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int main() {
    Node* root = NULL;
    int ch, x;

    while (true) {
        cout << "\n1.Insert  2.Search  3.Delete  4.Display  5.Exit\n";
        cin >> ch;
        if (ch == 5) break;

        if (ch >= 1 && ch <= 3) {
            cout << "Enter value: ";
            cin >> x;
        }

        if (ch == 1) root = insert(root, x);
        else if (ch == 2) cout << (search(root, x) ? "Value found.\n" : "Value not found.\n");
        else if (ch == 3) { root = del(root, x); cout << "Deletion operation completed.\n"; }
        else if (ch == 4) { cout << "Inorder traversal: "; inorder(root); cout << endl; }
    }
    return 0;
}