// SlickBack Onichan
#include <iostream>
using namespace std;
void MaxHeapify(int arr[], int i, int N)
{

    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    
    if(leftChild<N && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<N && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        MaxHeapify(arr,largest,N);
    }
}

void convertMaxHeap(int arr[], int N)
{
    for (int i = (N-2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}


void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout<<endl;
}

int main()
{
    int arrayCount;
    cin>>arrayCount;
    int arr[arrayCount];
    for (int i=0;i<arrayCount;i++){
        cin>>arr[i];
    }

    convertMaxHeap(arr, arrayCount);

    printArray(arr, arrayCount);

    return 0;
}
