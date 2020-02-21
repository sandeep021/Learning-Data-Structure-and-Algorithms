//not a stable algo, lost when we swap elements
//time : O(nlogn)[in all case], space: O(logn)
//it is not better than merge sort
//constant terms are more than merge sort which incrreses
//used when we have space constrained

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000;

void downHeapifyHelper(vector<int> &heap, int idx, int heapSize){
      //fing the largest among parrent and childs and swapping them to
      //satisfy heap property
      int leftIdx=2*idx+1;
      int rightIdx=2*idx+2;
      if (leftIdx>heapSize && rightIdx>heapSize) return;//size of left
      //child is greater than heap then it must be leaf
      int largestIdx=idx;
      if (leftIdx<heapSize && heap[leftIdx]>heap[largestIdx])
         largestIdx=leftIdx;
      if (rightIdx<heapSize && heap[rightIdx]>heap[largestIdx])
         largestIdx=rightIdx;
      if (largestIdx==idx) return;
      else{
          int temp=heap[largestIdx];
          heap[largestIdx]=heap[idx];
          heap[idx]=temp;
          downHeapifyHelper(heap,largestIdx, heapSize);
      }
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


  void buildHeapFast(vector<int> &heap){//time complexity O(n)
      for (int i=heap.size()-1;i>=0;i--)
             downHeapify(heap,i);
  }


  void heapSort(vector<int> &heap){
      int heapSize=heap.size();
      buildHeapFast(heap);
      for (int i=heap.size()-1;i>=0;i--){//i-- beacuse last wale apni jagah pe set ho rhe h
          swap(heap[0],heap[i]);
          heapSize--;
          downHeapifyHelper(heap,0,heapSize);
      }
  }

  void display(vector<int> &heap){
      for (int i=0;i<heap.size();i++)
            cout<<heap[i]<<" ";
  }

  int main(){
      vector <int> a={1,2,3,4,5,3,2,4,0};
      heapSort(a);
      display(a);
      
  }