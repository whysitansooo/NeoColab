// Khud se crow :( 
#include <iostream>
using namespace std;

void max_heap(int *a, int m, int n){

   int largest = m;
   int leftChild = 2*m;
   int rightChild = 2*m+1;
   
   if(leftChild<=n && a[leftChild]>a[largest]){
       largest = leftChild;
   }
   if(rightChild<=n && a[rightChild]>a[largest]){
       largest = rightChild;
   }
   if(largest!=m){
       swap(a[largest],a[m]);
       max_heap(a,largest,n);
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
   cout<<"Max heap"<<endl;
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<" ";
   }
   cout<<endl;
   cout<<"The maximum value is "<<a[1]<<endl;
}
