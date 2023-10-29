//SlickBack Onichan
#include <iostream>
using namespace std;

struct RideRequest {
    int estimatedPickUpTime;
};

void swap(RideRequest& a, RideRequest& b) {
    RideRequest temp = a;
    a = b;
    b = temp;
}

void insertRideRequest(RideRequest heap[], int& heapSize, RideRequest newRequest) {
    heapSize = heapSize + 1;
    int smallest = heapSize;
    heap[smallest] = newRequest;
    while(smallest>1){
        int parent = smallest/2;
        
        if(heap[smallest].estimatedPickUpTime<heap[parent].estimatedPickUpTime){
           swap(heap[smallest].estimatedPickUpTime,heap[parent].estimatedPickUpTime);
           smallest = parent;
        }
        else return;
        
        
    }
    
}

void printHeap(RideRequest arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i].estimatedPickUpTime<<" ";
    }
}

int main() {
    RideRequest minHeap[100];
    int heapSize = 0;

    while (true) {
        RideRequest newRequest;
        if (!(cin >> newRequest.estimatedPickUpTime)) {
            break;
        }

        insertRideRequest(minHeap, heapSize, newRequest);
    }
    printHeap(minHeap, heapSize);

    return 0;
}
