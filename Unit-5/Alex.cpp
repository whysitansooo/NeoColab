// I hate cheese
#include <iostream>
using namespace std;

struct Bid {
    int bid_amount;
};

void swap(Bid& a, Bid& b) {
    Bid temp = a;
    a = b;
    b = temp;
}

void insertBid(Bid heap[], int& heapSize, Bid newBid) {
   heapSize+=1;
   int largest = heapSize;
   heap[largest] = newBid;
   
   while(largest>1){
       int parent = largest/2;
       if(heap[largest].bid_amount>heap[parent].bid_amount){
           swap(heap[largest],heap[parent]);
           largest = parent;
       }
       else return;
   }
}
void printHeap(Bid heap[],int size){
    for(int i=1;i<=size;i++){
        cout<<heap[i].bid_amount<<" ";
    }
}

int main() {
    int maxSize = 100;
    Bid binaryHeap[maxSize];
    int heapSize = 0;

    while (true) {
        Bid newBid;
        if (!(cin >> newBid.bid_amount)) {
            break;
        }

        if (heapSize < maxSize) {
            insertBid(binaryHeap, heapSize, newBid);
        } else {
            cout << "Heap is full. Cannot insert more bids." << endl;
        }
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}
