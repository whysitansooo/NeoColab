// I love berries
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) 
{
  int largest = i;
  int rightChild = 2*i+2;
  int leftChild = 2*i+1;
   
  if(leftChild<n && arr[leftChild]>arr[largest]){
      largest = leftChild;
  }
  if(rightChild<n&&arr[rightChild]>arr[largest]){
      largest = rightChild;
  }
  if(largest!=i){
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
  }
   
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) 
{
    int size = n;
    while(size>0){
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,size,0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);
    heapSort(arr,n);
    printArray(arr, n);

    return 0;
}
