#include <bits/stdc++.h>
using namespace std;

class Node{//class node which contain dta, map of char and pointer
//and boolean terminal to check for pointer
    public:
        char data;
        unordered_map<char, Node*> children;
        bool terminal;
        Node(char d){
            data=d;
            terminal = false;
        }
};

class Trie{
    Node *root;
    int cnt;
    public:
        Trie(){
            root = new Node('\0');
            cnt=0;
        }
        void insert(char *w){
            Node *temp = root;
            for(int i=0;w[i]!='\0';i++){//travellig word  and checking it in tire
            //1. if present then we will move ahed;
            //2 else we will create new node and attach it to previous node. 
                char ch=w[i];
                if (temp->children.count(ch)){
                    temp=temp->children[ch];
                }
                else{
                    Node* n= new Node(ch);
                    temp->children[ch]=n;
                    temp=n;
                }
            }
            temp->terminal=true;
        }


        bool find(char *w){
            Node* temp=root;
            for(int i=0;w[i]!='\0';i++){
                char ch=w[i];
                if(temp->children.count(ch)==0){
                    return false;
                }
                else {
                    temp=temp->children[ch];
                }
            }
            return temp->terminal;
        }
};


int main(){
    char arr[][10]={"a","hello","news", "not","newck"};
    Trie t;
    for(int i=0;i<5;i++){
        t.insert(arr[i]);
    }
    char test[10]="newck";

    if (t.find(test)) cout<<"present"<<endl;
    else cout<<"Not present"<<endl;

}