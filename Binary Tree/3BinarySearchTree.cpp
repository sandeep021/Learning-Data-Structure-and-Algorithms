#include <iostream>
using namespace std;
#include<climits>
#include<queue>
//Note : searchcomplexity of BST: best me O(logn) and worst me O(n)--jb skew tree hoga tab.
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};


node *InsertInBST(node *root,int data){
    if (root==NULL)  return new node(data);
    else{
        if (data<root->data)
            root->left=InsertInBST(root->left,data);
        else
            root->right=InsertInBST(root->right,data);
        return root;
    }
}
                                  
node *build(){
    int d;
    cin>>d;
    node * root= NULL;
    while(d!=-1){
        root=InsertInBST(root,d);
        cin>>d;
    }
    return root;

}

void bfs(node * root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node *f=q.front();
        if (f==NULL){//for make  print looklike levelwise
        //push null after each level or store level vale in queue and use that 
        //to change line
            cout<<endl;
            q.pop();
            if(!q.empty())  q.push(NULL);
              //level complete now go to next level
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
        
    }
    return;
}

void inorder(node*root){
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

bool searchInBST(node *root, int data){
    if (root==NULL)  return false;
    if(root->data==data) return true;
    else{
        if (data<=root->data)  return searchInBST(root->left,data);
        else  return searchInBST(root->right, data);
    }
}



node * deleteINBST(node*root, int data){
    if (root==NULL)  return NULL;
    if(data<root->data){
        root->left=deleteINBST(root->left,data);
        return root;
    }
    else if (data=root->data){
        //three cases
        //1. when deleted node has no child;
        if(root->left==NULL and root->right ==NULL){
        delete(root);
        return NULL;
        }
        //2. when node has one chile=d
        else if(root->left!=NULL && root->right == NULL){
            node * temp=root->left;
            delete(root);
            return temp;

        }
         else if(root->left==NULL && root->right != NULL){
            node * temp=root->right;
            delete(root);
            return temp;
        }
        // when it have both childs
        //then look for successor or predecessor relace it and delete;
        node * replace=root->right;
        while(root->left!=NULL);{//finding predecessor
            replace=replace->left;
        }
        root->data=replace->data;//swapping valuse
        root->right=deleteINBST(root->right, replace->data);//deleting replace from right of tree
    }
    else {
        root->right=deleteINBST(root->right, data);
        return root;
    }
    return NULL;
}

//Check for BST
//we have to check if left is BST and right is BST + root is between max value of left and min value of right;

bool isBST(node * root, int l=INT_MAX, int r=INT16_MIN){
    if(root==NULL) return true;
    if(l<=root->data && root->data<=r && isBST(root->left,l,root->data) && isBST(root->right, root->data, r)){
        return true;
    }
    return false;
}


int main(){
    node*root=build();
    //int s;
    //cin>>s;
    //inorder(root);
    //cout<<endl;
    //bfs(root);
    //cout<<searchInBST(root,s);
    cout<<isBST(root);
    return 0;
}
