//time complexities
//insertion, deletion takes O(1) here extra pointer is used else O(n)
//indexing, search takes O(n)
//space complexity O(n)


// this code has insertathead, insertatmiddle, insetattail, deleteathead, deleteattail, deleteatmiddle;
//>> and << operators aur overloaded for input and output;
//reversing linked-list
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

void insertathead(node* &head, int data){//passing head as refrence variable
//else its value in main will be always null
//check it without & it will not work beacause it is case of pass by value
//which means head will be always NULL in main
    node * n= new node(data);
    n->next=head;
    head=n;
}

 int length(node *head){
     int l=1;
     node *temp= head;
     while(temp!=NULL){
         l+=1;
         temp=temp->next;
     }
     return l;

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

void insertInMiddle(node *&head, int data, int p){
    if (head==NULL || p==0 ){
        insertathead(head, data);
    }
    else if (p>length(head)){
        insertAtTail(head, data);
    }
    else{
        int jump=1;
        node * temp=head;
        while (jump<=p-1){
            jump += 1;
            temp=temp->next;
        }
        node *n= new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

 void deleteAtHead(node *&head){
        if (head==NULL)  return;
        else{
            node*temp=head;
            head=head->next;
            delete temp;
            return;
        }
    }


    void deleteAtTail(node *&head){
         node *prev=NULL;
         node *temp=head;
         while(temp->next!=NULL){
             prev=temp;
             temp=temp->next;
         }
         delete temp;
         prev->next=NULL;
         
    }

    void deleteAtMiddle(node *&head, int p){
        if(head==NULL || p==0)  return;
        else if(p==1)   deleteAtHead(head);
        else if (p>length(head))  deleteAtTail(head);
        else{
            int jump=1;
            node *prev;
            node *temp=head;
            while(jump<p){
                prev=temp;
                temp=temp->next;
                jump+=1;
            }
            prev->next=temp->next;
            delete temp;

        }

    }


void buildlist(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}


/*istream& operator>>(istream &is, node *&head){
    buildlist(head);
    return is;
}

ostream& operator<<(ostream &os, node *&head){
    print(head);
    return os;
}*/

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

int main(){
    node *head=NULL;
   insertathead(head,5);
   insertathead(head,2);
   /*insertathead(head,1);
   insertathead(head,8);
   insertathead(head,7);
   insertathead(head,5);
   insertAtTail(head,999);*/
   //insertInMiddle(head,66666,3);
   print(head);
   //deleteAtHead(head);
   //print(head);
   //deleteAtTail(head);
   //print(head);
   //deleteAtMiddle(head,1);
  // print(head);
   //node *head1=NULL;
   //cin>>head;
   //reverseList(head1);
   //cout<<head<<endl;
   node*m=findmid(head);
   cout<<m->data<<endl;
   node *kth=kthnumberfromend(head,3);
   cout<<kth->data<<endl;

return 0;
}




//searching(recursive and iterative)
//inputing to make linkedlist

