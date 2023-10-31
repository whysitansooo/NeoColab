Almost at the verge of dying 
#include <iostream>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapifyDown(int *heap, int n, int i) {
    int smallest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    
    if(leftChild<n && heap[leftChild]<heap[smallest]){
        smallest = leftChild;
    }
    if(rightChild<n && heap[rightChild]<heap[smallest]){
        smallest = rightChild;
    }
    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapifyDown(heap,n,smallest);
    }
}

void deleteShortestSong(int *heap, int &n) {
    int size = n;
    heap[0] = heap[size-1];
    n--;
    heapifyDown(heap,size,0);
}

int main() {
    int *heap;
    int n;
    cin >> n;
    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, n, i);
    }

    deleteShortestSong(heap, n);

    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
    delete[] heap;
    return 0;
}
