// Slickback Onichan!
#include <iostream>
using namespace std;

struct Player {
    int score;
};

void swap(Player& a, Player& b) {
    Player temp = a;
    a = b;
    b = temp;
}

void insertPlayer(Player heap[], int& heapSize, Player newPlayer) {
    heapSize +=1;
    int largest = heapSize;
    heap[largest] = newPlayer;
    
    while(largest>1){
        int parent  = largest/2;
        if(heap[largest].score>heap[parent].score){
            swap(heap[largest],heap[parent]);
            largest = parent;
        }
        else return;
    }
}
    
    void printHeap(Player Heap[],int size){
        for(int i=1;i<=size;i++){
            cout<<Heap[i].score<<" ";
        }
    }
    


int main() {
    Player maxHeap[100];
    int heapSize = 0;
    
    while (true) {
        Player newPlayer;
        if (!(cin >> newPlayer.score)) {
            break;
        }

        insertPlayer(maxHeap, heapSize, newPlayer);
    }

    printHeap(maxHeap, heapSize);

    return 0;
}
