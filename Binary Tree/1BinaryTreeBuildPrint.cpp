#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node * BuildTree(){
    int d;
    cin>>d;
    if (d==-1)   return NULL;
    node * root= new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}


void Print(node *root){
    if (root==NULL)  return;
    cout<<root->data<<" ";
    Print(root->left);
    Print(root->right);
}

void PrintIn(node* root){
    if (root==NULL) return;
    PrintIn(root->left);
    cout<<root->data<<" ";
    PrintIn(root->right);
}

void PrintPost(node * root){
    if (root==NULL) return;
    PrintPost(root->left);
    PrintPost(root->right);
    cout<<root->data<<" ";
}


int main(){
    node * root = BuildTree();
    Print(root);
    cout<<endl;
    PrintIn(root);
    cout<<endl;
    //PrintPost(root);
    cout<<endl;
    return 0;
}