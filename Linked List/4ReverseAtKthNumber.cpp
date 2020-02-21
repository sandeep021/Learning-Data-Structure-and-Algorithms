//VERY GOOD QUESTION
//reverse list in size of k;
//input:  9 3
//        9 4 1 7 8 3 2 6 5
//output: 1 4 9 3 8 7 5 6 2

#include <iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }  
};


void Print(node* root){
  node*temp=root;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}


void InsertAtTail(node* &root, int data){
  if (root==NULL){
       root= new node(data);
       return;
  }
  node * temp=root;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  node*n=new node(data);
  temp->next=n;
  return;

}


node*  reverseList(node *head, int k){ //try recursive while revising
    node *current=head;
    node*prev=NULL;
    node*next=NULL;
    int count=0;
    while(count<k && current!=NULL){
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
      count++;
    
    }
    if(next!=NULL){
          
          head->next=reverseList(next,k);
        }
    //Print(next);
    return prev;
    
  }

int main(){
  int n,k1;
  
  cin>>n>>k1;
  int m=n;
  node* root=NULL;
  while(n>0){
    int d;
    cin>>d;
    InsertAtTail(root,d);
    n--;  
  }  
  //Print(root);
  //cout<<endl;
  //cout<<root->data<<endl;
  root=reverseList(root,k1);
  //cout<<root->data<<endl;
  Print(root);
  //Print(root);
  //Print(head);
  return 0;
  }
