//Priority queue hai following operation
//1. Insert
//2. Delete
//3. get

//there are many ways to implement priority queue
/* A. unsorted array
    1. O(1)
    2. O(n)
    3. O(n)


    B. sorted array
    1. O(n)
    2. O(n)
    3. O(1) or O(n)

    C.unsorted list
    1. O(1)
    2. O(n)
    3. O(n)

    D. sorted list
    1. O(n)
    2. O(n) or O(n)[for sprcific deletion]
    3. O(1) or O(n)

    E.  Binary Tree
    1. O(height)
    2. O(height)
    3. O(height)

    F. Binary Heap
    it is complete binary tree with condition that root has most or least
    priority than children
    in case of BST height is logn

    1.O(logn)
    2.O(logn)
    3.O(1)

    Q1. why we are not using random/generic tree or full tree or erfect tree
    for binary heap?
    Q2. why we r not using ternary or quadary treww?
    Ans: because in this case more childs so number of comparisons increase
    for binary tree: T(n)=O(1)+O(2logn base 2)
    for ternary tree: T(n)=O(1)+O(2logn base 3)
    2logn base 2 << 2logn base 3

    */


   /*HEAPS

   implemented using array whose indexing start at 0.[because accesing
   of parrent and child is easy, level wise traversal is produced
   , saving some space ]

   parrent is at i
   then
   left_child = 2*i+1
   right_child = 2*i+2

   child is at j 
   then
   parrent = floor((j-1)/2)
   */

  //insertion
  //step1.insert at left vacant place
  //heapify{i.e swap it with the parrent untill you find its 
  //correct position}

  #include <bits/stdc++.h>
  using namespace std;
  #define INF 1000000;

  void upHeapify(vector<int> &heap, int idx){
      if (idx==0)  return;
      int parentIdx=(idx-1)/2;
      if (heap[parentIdx]<heap[idx]){
          //swap
          int temp=heap[parentIdx];
          heap[parentIdx]=heap[idx];
          heap[idx]=temp;
          upHeapify(heap,parentIdx);//parentIdx is now the swapped parrent locatio
          //where our added key is now it will be copared to its new parrent recusively
      }
      else return;
  }

  void downHeapify(vector<int> &heap, int idx){
      //fing the largest among parrent and childs and swapping them to
      //satisfy heap property
      int leftIdx=2*idx+1;
      int rightIdx=2*idx+2;
      if (leftIdx>heap.size() && rightIdx>heap.size()) return;//size of left
      //child is greater than heap then it must be leaf
      int largestIdx=idx;
      if (leftIdx<heap.size() && heap[leftIdx]>heap[largestIdx])
         largestIdx=leftIdx;
      if (rightIdx<heap.size() && heap[rightIdx]>heap[largestIdx])
         largestIdx=rightIdx;
      if (largestIdx==idx) return;
      else{
          int temp=heap[largestIdx];
          heap[largestIdx]=heap[idx];
          heap[idx]=temp;
          downHeapify(heap,largestIdx);
      }
  }

  void deletePeak(vector<int> &heap){
      int temp=heap[0];//swaping the first and last element
      heap[0]=heap[heap.size()-1];
      heap[heap.size()]=temp;
      heap.pop_back();//now deleting the laat element
      downHeapify(heap, 0);
  }

  void insert(vector<int> &heap, int key){
      heap.push_back(key);
      upHeapify(heap, heap.size()-1);//heapsize-1 is current location of added key
  }

  void buildHeap(vector<int> &heap){ //time complexity is O(nlogn);
  //in this case we are doing more operations on last levels
  //and last levels nodes are more in number(n+1)/2
  //[i.e half of total nodes]
  // that is why complexity is more
  //we should reverse this to save time
  //i.e more operations on upper nodes 
      for (int i=0;i<heap.size();i++)
            upHeapify(heap,i);
  }

  void display(vector<int> &heap){
      for (int i=0;i<heap.size();i++)
            cout<<heap[i]<<" ";
  }

  void buildHeapFast(vector<int> &heap){//time complexity O(n)
      for (int i=heap.size()-1;i>=0;i--)
             downHeapify(heap,i);
  }

  void deleteAnyNode(vector<int> &heap, int idx){
      heap[idx]=INF;//put infinity in node ehich w want to remove
      upHeapify(heap,idx);//make it heap, now inf is root
      int temp=heap[0];
      heap[0]= heap[heap.size()-1];
      heap[heap.size()-1]=temp;//swap inf with last node
      heap.pop_back();//remove inf
      downHeapify(heap,0);//make it heap using downheap
        }

  int main(){
      //vector<int> heap;//start to check insert and delete
      /*int n;
      cin>>n;
      for(int i=0;i<n;i++){
          int key;
          cin>>key;
          insert(heap,key);
      }
      deletePeak(heap);*/ //end 
      int n1;//start to check build heap using upheapify and downheapify
      //deleteany node
      cin>>n1;
      vector<int> heap1;
      for(int i=0;i<n1;i++){
          int key1;
          cin>>key1;
          heap1.push_back(key1);
      }
      buildHeapFast(heap1);
      display(heap1);
      cout<<endl;
      deleteAnyNode(heap1,2);
      display(heap1);//end
      return 0;
  }