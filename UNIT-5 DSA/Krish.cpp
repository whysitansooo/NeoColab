// I hate some fat whales!
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root) 
{
    int smallest = root;
    int leftChild = 2*root+1;
    int rightChild = 2*root+2;
    
    if(leftChild<n && arr[leftChild]<arr[smallest]){
        smallest = leftChild;
    }
    if(rightChild<n && arr[rightChild]<arr[smallest]){
        smallest = rightChild;
    }
    if(smallest!=root){
        swap(arr[smallest],arr[root]);
        heapify(arr,n,smallest);
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

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildMaxHeap(arr,n);
   heapSort(arr, n);

    // for (int i = n - 1; i >= 0; i--) {
    //     cout << arr[i] << " ";
    // }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
