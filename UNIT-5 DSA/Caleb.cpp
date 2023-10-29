// SlickBack Onichan
#include <iostream>
using namespace std;

struct Process {
    int executionTime;
};

void swap(Process& a, Process& b) {
    Process temp = a;
    a = b;
    b = temp;
}

void insertProcess(Process heap[], int& heapSize, Process newProcess) {
    heapSize += 1;
    int smallest = heapSize;
    heap[smallest] = newProcess;
    
    while(smallest>1){
        int parent  = smallest/2;
        
        if(heap[smallest].executionTime<heap[parent].executionTime){
            swap(heap[smallest],heap[parent]);
            smallest = parent;
        }
        else return;
    }
}
void printHeap(Process heap[],int &heapSize){
        for(int i=1;i<=heapSize;i++){
            cout<<heap[i].executionTime<<" ";
        }
}

int main() {
    Process minHeap[100];
    int heapSize = 0;

    while (true) {
        Process newProcess;
        if (!(cin >> newProcess.executionTime)) {
            break;
        }

        insertProcess(minHeap, heapSize, newProcess);
    }
    printHeap(minHeap, heapSize);

    return 0;
}


    
// }
