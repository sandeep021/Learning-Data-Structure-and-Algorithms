//floyad warshell method
//slow and fast pointer method

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
        cout<<temp->data<<" >";
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


void detectCycle(node* root){
    node* slow=root;
    node*fast=root;
    int flag=0;
    while(fast!=NULL && fast->next!=NULL){
        if(slow->data==fast->data){
            flag=1;
            break;
            }
        else flag=0;
        slow=slow->next;
        fast=fast->next->next;              
    }
    slow=root;
    while(slow->data!=fast->data){
        slow=slow->next;
        fast=fast->next;
    }
    while(fast->next!=slow){
        fast=fast->next;
    }
    fast->next=NULL;
if (flag)  print(root);
else cout<<-1<<endl;

}

int main(){
    node * root=NULL;
    buildlist(root);
    detectCycle(root);
}