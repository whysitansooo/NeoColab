// SLICKBACK PANDA
#include <iostream>
using namespace std;

struct Location {
    int distance;
};

void swap(Location& a, Location& b) {
    Location temp = a;
    a = b;
    b = temp;
}

// Function to insert a new location into the binary heap
void insertLocation(Location* heap, int& heapSize, Location newLocation) {
   heapSize+= 1;
    int smallest = heapSize;
    heap[smallest] = newLocation;
    
    while(smallest>1){
        int parent  = smallest/2;
        if(heap[smallest].distance<heap[parent].distance){
            swap(heap[smallest],heap[parent]);
            smallest = parent;
        }
        else return;
    }
    
}

void printHeap(const Location* heap, int heapSize) {
    for (int i = 1; i <= heapSize; i++) {
        cout << heap[i].distance << " ";
    }
    cout << endl;
}

int main() {
    const int maxHeapSize = 100;
    Location* binaryHeap = new Location[maxHeapSize];
    int heapSize = 0;

    while (true) {
        Location newLocation;
        if (!(cin >> newLocation.distance)) {
            break;
        }

        insertLocation(binaryHeap, heapSize, newLocation);
    }

    printHeap(binaryHeap, heapSize);

    delete[] binaryHeap;

    return 0;
}
