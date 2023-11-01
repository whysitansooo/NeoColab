Try hard on this a lot
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    
    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 -1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteAllMaxOccurrences(int arr[], int& n) 
{   
    static int max = arr[0];
    int lastElement = arr[n-1];
    arr[0] = lastElement;
    n--;
    
    heapify(arr,n,0);
    if(arr[0]==max){
        deleteAllMaxOccurrences(arr,n);
    }
     
}




void displayHeap(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

   deleteAllMaxOccurrences(arr, n);
    displayHeap(arr, n);

    return 0;
}
