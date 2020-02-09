#include <iostream>
using namespace std;
#include<queue>

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
    }
    else {
        root->right=deleteINBST(root->right, data);
        return data;
    }
}


int main(){
    node*root=build();
    int s;
    cin>>s;
    inorder(root);
    //cout<<endl;
    //bfs(root);
    cout<<searchInBST(root,s);

    return 0;
}
