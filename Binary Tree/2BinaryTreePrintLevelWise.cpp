//IT CONTAINS.... 
//1.levewise print in o(n2) recursion
//2.bfs to print in O(n) iterative using q
//push root node in q then pop front and push the children of front
//repeat untill the stack is empty
//3.count of node
//4.sum of nodes

#include <iostream>
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
    cin>>d;
    if (d==-1)   return NULL;
    node * root=new node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;
}


int height(node *root){
    if (root==NULL)  return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return (max(ls,rs)+1);//root ki height is maxof(leftheight, rightheight)+1;
}


void PrintKthLevel(node *root, int k){
    if (root==NULL) return;
    if (k==1){
        cout<<root->data<<" ";
        return;
    }
    PrintKthLevel(root->left,k-1);
    PrintKthLevel(root->right,k-1);
    return;

}

void PrintAllLevel(node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        PrintKthLevel(root,i);
        cout<<endl;
    }
    return;
}
//bfs traversal to print levelwise.
void bfs(node * root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);//insted of NULL pushing i can use size of queue
    //eache level size will be poped and new level will be pushed......
   //another way is make pair of node data and node level and push it in queue
   //and change line according to queue level data. 
    while(!q.empty()){
        node *f=q.front();
        if (f==NULL){//when we find NULL in queue we will do line change and also pop NULL
        // and again push the null because all nodes of next level will be in queue already.
            cout<<endl;
            q.pop();
            if(!q.empty())  q.push(NULL);
              //last me nhi push krenge kuki ab line change nhi krni
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

int count(node *root){
    if (root==NULL) return 0;//base case
    return 1+count(root->left)+count(root->right);///recursive call
}

int Sum(node *root){
    if (root==NULL) return 0;//base case
    return root->data+Sum(root->left)+Sum(root->right);///recursive call
}

int diameter(node * root){//diameter is max distance between two nodes
//means max no of edges between two nodes
    if (root==NULL)  return 0;//here Time taken is O(n2) bacause
    //hr node ka height calculate hoga aur height khud O(n) leta hai. 
    int h1=height(root->left);
    int h2=height(root->right);
    int opt1=h1+h2;//when diameter passes through root.
    int opt2=diameter(root->left);//when diameter is only in left subtree.
    //left side me sare node pe call hoga function.
    int opt3=diameter(root->right);//.......only in right subtree
    //right side me sare pe call hoga.
    return max(opt1,max(opt2,opt3));

}

class Pair{
    public :
        int first;
        int second;
        
};


Pair fatsDiameter(node* root){
    Pair p;
    if (root==NULL){
        p.first=p.second=0;
        return p;
    }
    else{
        Pair left=fatsDiameter(root->left);
        Pair right=fatsDiameter(root->right);
        p.first=max(left.first,right.first)+1;//first is height
        p.second=max((left.first+right.first),max(left.second,right.second));
        return p;
    }

}
//Q. replace all the node with sum of its all decendent nodes.
int ReplaceSum(node *root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL)  return root->data;//because leaf ko bhi vhange nhi krna hai
    int leftSum=ReplaceSum(root->left);
    int rightSum=ReplaceSum(root->right);
    int temp=root->data;
    root->data=leftSum+rightSum;
    return temp+root->data;
}

class HBPair{
    public:
        int height;
        bool balance;
};
HBPair IsHeightBalance(node* root){
    HBPair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    HBPair left = IsHeightBalance(root->left);
    HBPair right= IsHeightBalance(root->right); 
    p.height=max(left.height,right.height)+1;
    if (abs(left.height-right.height) && left.balance && right.balance){
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;
}

node * BuildTreeFromArray(int *a, int start, int end){//bich se todo root bna do subtree ke liye
    if (start>end)  return NULL;
    //RECURSIVE CASE
    int mid=(start+end)/2;
    node*root=new node(a[mid]);
    root->left=BuildTreeFromArray(a,start,mid-1);
    root->right=BuildTreeFromArray(a,mid+1,end);
    return root;
}

node * CreateTreeFromTrav(int * ino, int*preo, int start, int end){
    static int i=0;
    if (start>end) return NULL;
    node *root= new node(preo[i]);
    int index=-1;
    //instead of this loop kan use map to save the index of preorder elements.
    for (int j=start;j<=end;j++){
        if (ino[j]==preo[i]){
            index= j;
            break;
        }
    }
    i++;
    root->left=CreateTreeFromTrav(ino, preo,start,index-1);
    root->right=CreateTreeFromTrav(ino,preo,index+1,end);
    return root;
}

/*
TreeNode* trav(vector<int> &in, vector<int> &pre, int s, int e, int&i, unordered_map<int, int> &map){
     //int i=0;
     if(s>e) return NULL;
     TreeNode* root=new TreeNode(pre[i]);
     int mid=map[pre[i]];
    //  for(int j=s;j<=e;j++){
    //      if(in[j]==pre[i]){
    //          mid=j;
    //          break;
    //      }
    //  }
     i++;
     root->left=trav(in, pre, s, mid-1, i, map);
     root->right=trav(in, pre, mid+1, e, i, map);
     return root;
 }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int  i=0;
    unordered_map<int, int> map;
    for(int j=0;j<A.size();j++) map[B[j]]=j;
    return trav(B, A, 0, A.size()-1, i, map);
}
*/


int main(){
    //node* root=BuildTree();
    //cout<<height(root);
    //cout<<endl;
    //PrintKthLevel(root,2);
    //PrintAllLevel(root);
    //cout<<endl;
    //bfs(root);
    /*cout<<endl;
    cout<<"count "<<count(root)<<endl;
    cout<<"SUM "<<Sum(root)<<endl;
    cout<<"diameter "<<diameter(root)<<endl;*/
    //Pair pa = fatsDiameter(root);
    //cout<<pa.first<<"  "<<pa.second<<endl;
    //ReplaceSum(root);
    //bfs(root);
    //HBPair hp=IsHeightBalance(root);
    //cout<<hp.height<<"     "<<hp.balance<<endl;
    int a[]={1,2,3,4,5,4,7};
    int n=7;
    //node*root1=BuildTreeFromArray(a,0,n-1);
    //bfs(root1);

    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int lent=sizeof(in)/sizeof(int);
    node * root2=CreateTreeFromTrav(in,pre,0,lent-1);
    bfs(root2);
    return 0;
}