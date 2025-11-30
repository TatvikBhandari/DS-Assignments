#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class bst {
public:
    node *root;

    bst() {
        root = nullptr;
    }

    node* insert(node* root, int element) {
        if (root == nullptr) {
            return new node(element);
        }
        else if (element < root->data) {
            root->left = insert(root->left, element);
        }
        else {
            root->right = insert(root->right, element);
        }
        return root;
    }

    void insert(int element) {
        root = insert(root, element);
    }

    node* searchrec(node* r, int key) {
        if (r == nullptr || r->data == key) {
            return r;
        }
        if (key < r->data)
            return searchrec(r->left, key);
        else
            return searchrec(r->right, key);
    }

    node* searchnonrec(int key) {
        node* r = root;
        while (r != nullptr) {
            if (r->data == key) return r;
            else if (key < r->data) r = r->left;
            else r = r->right;
        }
        return nullptr;
    }

    node* maxelement(node* root) {
        if (root == nullptr) return nullptr;
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    node* minelement(node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    node* inorderSuccessor(node* r, node* x) {
        if (x->right != nullptr) {
            return minelement(x->right);
        }
        node* succ = nullptr;
        while (r != nullptr) {
            if (x->data < r->data) {
                succ = r;
                r = r->left;
            }
            else if (x->data > r->data) {
                r = r->right;
            }
            else break;
        }
        return succ;
    }

    node* inorderPredecessor(node* r, node* x) {
        if (x->left != nullptr) {
            return maxelement(x->left);
        }
        node* pred = nullptr;
        while (r != nullptr) {
            if (x->data > r->data) {
                pred = r;
                r = r->right;
            }
            else {
                r = r->left;
            }
        }
        return pred;
    }
};

int main() {
    bst t;
    int arr[] = {20,10,30,5,15,25,35};

    for (int x = 0; x < 7; x++) {
        t.insert(arr[x]);
    }

    node* s1 = t.searchrec(t.root, 10);
    node* s2 = t.searchnonrec(35);
    node* mx = t.maxelement(t.root);
    node* mn = t.minelement(t.root);
    node* succ = t.inorderSuccessor(t.root, t.searchrec(t.root, 15));
    node* pred = t.inorderPredecessor(t.root, t.searchrec(t.root, 15));

    cout << "Search Rec (10): " << s1->data << endl;
    cout << "Search Non-Rec (35): " << s2->data << endl;
    cout << "Max Element: " << mx->data << endl;
    cout << "Min Element: " << mn->data << endl;
    cout << "Inorder Successor of 15: " << succ->data << endl;
    cout << "Inorder Predecessor of 15: " << pred->data << endl;

    return 0;
}
