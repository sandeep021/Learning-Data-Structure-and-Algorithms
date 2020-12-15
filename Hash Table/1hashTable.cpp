//Note: not usefull is maintaining and retrieving data in some particular
//support insert, search, delete in O(1) time.
//SIMILAR TO DICTIONARY IN Python.
//unique key related to its value.
//hash function: it convert string(key) to integer address
//collison occurs when hash function allocates same location to two or more values.
//collison can be handelled by adding fixed length linkd list 
//to the index which have multiple keys.
//rehash not working
#include <iostream>
using namespace std;

template<typename T>
class node{
    public:
        string key;
        T value;//1
        node<T> * next;
        node(string k, T value){
        key=k;
        this->value=value;//this wala jo h wo class ki key hai(1)
        //agr dono nam same honge to compiler confuse ho jaega
        //tb this pointer ka use krte hai
        next=NULL;
        }
        ~node(){
            if (next!=NULL){
                delete next;
            }
        }

};
template<typename T>
class HashTable{
    int cs;//current size
    int ts;//table size
    node<T> ** bucket;//pointer to hash table which have array of pointer to all
    //the linked list.


    void rehash(){
            node<T>** oldbuckets=bucket;
            int oldts=ts;
            ts=ts*2;
            cs=0;
            bucket=new node<T>*[ts];
            for(int i=0;i<ts;i++)
                bucket[i]=NULL;
            //copy old members
            for (int i=0;i<oldts;i++){
                node<T>* temp=oldbuckets[i];
                if (temp!=NULL){
                    while (temp!=NULL){
                        insert(temp->key, temp->value);
                        temp=temp->next;
                        }
                    //delete oldtable row
                    delete oldbuckets[i];
                }
                delete [] oldbuckets;//finally array is deleted  
            }

        }

    int HashFunction(string key){
        int L=key.length();
        int ans=0;
        int p=1;
        for (int i=0;i<L;i++){
            ans+=key[L-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }

    public:
        HashTable(int ds=7){
            cs=0;
            ts=ds;
            bucket= new node<T>*[ts];
            for(int i=0;i<ts;i++){
            bucket[i] = NULL;
            }
            
        }        
       
    void insert(string key, T value){
        int i=HashFunction(key);
        node<T>*n=new node<T>(key,value);
        n->next=bucket[i];//1
        bucket[i]=n;//2 these two lines to add new node to head of the list.
        cs++;
        float load_factor=(float)cs/ts;
        if (load_factor>0.7){
             rehash();
             cout<<"rehash..";
            }
                
        }


    void Print(){
        for(int i=0;i<ts;i++){
           node<T>*temp=bucket[i];
           cout<<"Bucket"<<i<<" -> ";
           while(temp!=NULL){
               cout<<temp->key<<", ";
               temp=temp->next;
           }
           cout<<endl; 
        }
    }

    T search(string key){
        int i=HashFunction(key);
        node<T> *temp=bucket[i];
        while(temp!=NULL){
            if(temp->key==key) return temp->value;
        temp=temp->next;
        }
        return NULL;
    }

};

int main(){
    HashTable<int> hs(5);
    hs.insert("Mango",100);
    hs.insert("Apple",500);
    hs.insert("kiwi",100);
    hs.insert("papaya",500);
    hs.insert("Mango1",100);
    hs.insert("Apple1",500);
    hs.insert("kiwi1",100);
    hs.insert("papaya1",500);
    hs.Print();
    //cout<<hs.search("kiwi");
    //hs.Print()
}  





