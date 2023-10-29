// SlickBack Fat owl
#include <iostream>
using namespace std;

void min_heap(int *a, int m, int n) {
    int smallest = m;
    int leftChild = 2*m;
    int rightChild = 2*m+1;
    
    if(leftChild<=n && a[leftChild]<a[smallest]){
        smallest = leftChild;
    }
    if(rightChild<=n && a[rightChild]<a[smallest]){
        smallest = rightChild;
    }
    if(smallest !=m){
        swap(a[smallest],a[m]);
        min_heap(a,smallest,n);
    }
}

void build_minheap(int *a, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n);
    }
}

int main() {
    int n, i;
    cin >> n;

    int a[n + 1]; 
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int k;
    cin >> k;
    if (k < 1 || k > n) {
        cout << "Invalid entry";
        return 0;
    }
    
    build_minheap(a, n);
    cout << "Min heap is: ";
    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "The smallest crystal's size is " << a[k];
    
    return 0;
}
