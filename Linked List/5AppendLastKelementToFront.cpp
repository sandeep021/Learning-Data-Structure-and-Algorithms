//Easy Question
//Append last k element to front
//k can be graeter than n use modulus 


#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int d){//constructor of node
            data=d;
            next=NULL;
        }

};




void print(node *head){
    node *temp=head;
    // no need of temp cause because it is pass by valuse so the actual head is not changing
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtTail(node *&head, int data){
     if (head==NULL){
         head=new node(data);
         return;
     }
     node *temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     node *n=new node(data);
     temp->next=n;
     return;

 }

 node *kthnumberfromend(node*head, int k){
    node* slow =head;
    node* fast=head;
    while(k>1){
        fast=fast->next;
        k--;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void reverseList(node *&head){ //try recursive while revising
    node *current=head;
    node*prev=NULL;
    node* N;
    while(current!=NULL){
        //storing info of next node
        N=current->next;
        //reversing link
        current->next=prev;
        //updating previous and courrent;
        prev=current;
        current=N;

    }
    head=prev;
}

int main(){
    node* root=NULL;
    int n;
    cin>>n;
    int m=n;
    while(n>0){
        int d;
        cin>>d;
        insertAtTail(root,d);
        n--;
    }
    int k;
    cin>>k;
    if (m==k){
    reverseList(root);
    print(root);
    }
else if (m>k){
    node*s=kthnumberfromend(root,k+1);
    node*temp=s->next;
    node*temp1=s->next;
    s->next=NULL;
    
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=root;
    //cout<<temp->data<<endl;
    print(temp);
}
else{
    k=k%m;
    node*s=kthnumberfromend(root,k+1);
    node*temp=s->next;
    node*temp1=s->next;
    s->next=NULL;
    
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=root;
    //cout<<temp->data<<endl;
    print(temp);

}

}