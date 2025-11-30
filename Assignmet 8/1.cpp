//question 1
#include <iostream>
using namespace std;

class node{
    public:
    node *left;
    node *right;
    int data;
    node(int d){
        this->data=d;
        left=right=nullptr;
    }
};
class bst{
    public:
    node *root;
    bst(){
        root=nullptr;
    }
    node *insert( node *root,int element){
        if(root==nullptr){
            root=new node(element);
        }
        else if(root->data>element){
            root->left=insert(root->left,element);
        }
        else{
            root->right=insert(root->right,element);
        }
        return root;
    }
    void inorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void preorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
};
int main() {
    bst t;
    t.root=t.insert(t.root,40);
    t.root=t.insert(t.root,20);
    t.root=t.insert(t.root,60);
    t.root=t.insert(t.root,50);
    t.root=t.insert(t.root,70);
    t.inorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.preorder(t.root);
    cout<<endl;
    return 0;
}