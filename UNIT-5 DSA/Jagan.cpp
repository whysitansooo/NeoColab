//SlickBack Onichan

#include <iostream>
using namespace std;
void max_heap(int *arr, int m, int n)
{ 
    int largest = m;
    int leftChild = 2*m;
    int rightChild =(2*m)+1;
    
    if(leftChild<=n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<=n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }
    
    if(largest!=m){
        swap(arr[largest],arr[m]);
        max_heap(arr,largest,n);
    }
    
    
}
void build_maxheap(int *a, int n) {
  int k;
  for(k = n/2; k >= 1; k--) {
      max_heap(a,k,n);
  }
}
int main() {
  int n, i;
  cin>>n;
  
  int a[n];
  for (i = 1; i <= n; i++) {
     cin>>a[i];
  }
  build_maxheap(a, n);
  for (i = 1; i <= n; i++) {
      cout<<a[i]<<" ";
  }
}
