//merging of two sorted linked list;
//mergesort implementation recursiveli
//circle detection using fast and slow runner method


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
        cout<<temp->data<<"-->";
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



 void buildlist(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}


istream& operator>>(istream &is, node *&head){
    buildlist(head);
    return is;
}

ostream& operator<<(ostream &os, node *&head){
    print(head);
    return os;
}



node* findmid(node*head){   //MID POINT RUNNER
    if (head==NULL || head->next==NULL) return head;
    node * fast=head->next;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


node * merge(node*a, node* b){
    if (a==NULL)  return b;
    else if (b==NULL)  return a;
    else{
        node *c;
        if(a->data<b->data){
            c=a;
            c->next=merge(a->next,b);
        }
        else{
            c=b;
            c->next=merge(a,b->next);
        }
        return c;
    }
    
}

node * mergeSort(node *head){

    //BASE CASE
    if (head==NULL || head->next==NULL)  return head;
// RECURSIVE CASE

    node* mid=findmid(head);
    node*a= head;
    node*b=mid->next;
    mid->next=NULL; //to make a and b two linked list

    a=mergeSort(a);
    b=mergeSort(b);
    node *c =merge(a,b);
    return c;
}

bool DetectCycle(node *head){  //
    node *slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slaow=slow->next;
        if (fast==slow)  return true;
    }
    return false;
}






int main(){
    //node * head=NULL;
    //node * head1=NULL;
    //cin>>head>>head1;
    //cout<<head<<endl<<head1<<endl;
    //node *head2;
    //head2=merge(head,head1);
    //cout<<head2<<endl;

    //for merge sort
    node * h=NULL;
    cin>>h;
    h=mergeSort(h);
    cout<<h<<endl;
    }


    //to do 
    //break the cylcle after detecting
