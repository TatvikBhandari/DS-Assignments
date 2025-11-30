#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class BST {
public:
    Node* root;
    BST(){ root = NULL; }
    Node* insertNode(Node* r, int x){
        if(r == NULL) return new Node(x);
        if(x < r->data) r->left = insertNode(r->left, x);
        else if(x > r->data) r->right = insertNode(r->right, x);
        return r;
    }
    void insert(int x){
        root = insertNode(root, x);
    }
    Node* findMin(Node* r){
        while(r->left) r = r->left;
        return r;
    }
    Node* deleteNode(Node* r, int x){
        if(r == NULL) return r;
        if(x < r->data) r->left = deleteNode(r->left, x);
        else if(x > r->data) r->right = deleteNode(r->right, x);
        else {
            if(r->left == NULL){
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL){
                Node* temp = r->left;
                delete r;
                return temp;
            }
            Node* temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
        return r;
    }
    void deleteVal(int x){
        root = deleteNode(root, x);
    }
    int maxDepth(Node* r){
        if(r == NULL) return 0;
        return 1 + max(maxDepth(r->left), maxDepth(r->right));
    }
    int minDepth(Node* r){
        if(r == NULL) return 0;
        if(r->left == NULL) return 1 + minDepth(r->right);
        if(r->right == NULL) return 1 + minDepth(r->left);
        return 1 + min(minDepth(r->left), minDepth(r->right));
    }
};
int main(){
    BST t;
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(15);
    t.insert(25);
    t.insert(35);

    t.deleteVal(10);
    cout << "Max Depth: " << t.maxDepth(t.root) << endl;
    cout << "Min Depth: " << t.minDepth(t.root) << endl;
    return 0;
}