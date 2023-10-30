Huge fat strawberry
#include <iostream>
using namespace std;

#define MAX_SIZE  100

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int rightChild = 2*i+2;
    int leftChild = 2*i+1;
    
    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest  = rightChild;
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

int extractMax(int arr[], int& n) 
{
    int Max = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr,n,0);
    return Max;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;


    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    int maxElement = extractMax(arr, n);
    if (maxElement != -1) {
        cout << maxElement << endl;
    }

    printArray(arr, n);

    return 0;
}
