#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d){
            data=d;
            next=NULL;
        }
};


void print(node *head){
    node*temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;//last ke liye
}

void insertAtNode(node *&head, int data){
    node *n = new node(data);
    n->next=head; //1.
    node*temp=head;
    if (head!=NULL){
    while(temp->next!=head){//to reach tail
        temp=temp->next;
    }
    temp->next=n;//2.tail to point new head
    }
    else{
        n->next=n;
    }
    head=n;//3.head to point new head
}


node * getNode(node * head, int data){
    node* temp=head;
    while(temp->next!=head){
        if(temp->data==data) return temp;
        temp=temp->next;
    }
    if (temp->data==data) return temp;//for tain node, loop me check nhi ho rha;
    else return NULL;
}

void deleteNode(node *head, int data){
    node * del= getNode(head, data);
    if (del==NULL){
        cout<<"data not in list"<<endl;
        return;
    }
    if (head==del){
        node *temp1=del;
        while(temp1->next!=head){
            temp1=temp1->next;
        }
        head=head->next;
        temp1=head;
    }
    
        node*temp=head;
        while(temp->next!=del){
            temp=temp->next;
            }
            temp->next=del->next;
    
    delete del;
}


int main(){
    node *head=NULL;
    insertAtNode(head,2);
    insertAtNode(head,5);
    insertAtNode(head,6);
    insertAtNode(head,1);
    insertAtNode(head,9);
    print(head);
    deleteNode(head,9);
    print(head);
}