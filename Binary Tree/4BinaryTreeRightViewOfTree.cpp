include <iostream>
#include <queue>
#include <utility>
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
    std :: cin>>d;
    if (d==-1)   return NULL;
    node * root=new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}

vector<int> ans;
int max_level=-1;
void helper(node * root, int level){
    if(root==NULL) return;
    if(level>max_level){
        ans.push_back(root->data);
        max_level=level;
    }
    helper(root->right,level+1);
    helper(root->left,level+1);
}

 void rightView(node* root){
    int level=0;
    helper(root,0);
    return ;
}

int main(){
    node * root=BuildTree();
    rightView(root);
    for(auto i: ans) std::cout<<i<<" ";
}
