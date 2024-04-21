
#include "sorting.h"

accidentNode sorting::extractMax() {
    accidentNode temp = heapData[0];
    heapData[0] = heapData[heapData.size() - 1];
    heapSize--;
    heapifyDown(0);
    return temp;
}

void sorting::heapifyDown(int index) {
    /*
    if index is a leaf or children of index are greater than index -> stop
    Find the smallest child of node at index
    Swap node at index with smallest_child_index
    heapifyDown(smallest_child_index)
*/
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    int largest = index;

    if (left < heapSize - 1 && heapData[left].getInjCount() > heapData[largest].getInjCount()) {
        largest = left;
    }
    if (right < heapSize - 1 && heapData[right].getInjCount() > heapData[largest].getInjCount()) {
        largest = right;
    }
    if (largest != index) {
        swap(heapData[largest], heapData[index]);
        heapifyDown(largest);
    }

}

void sorting::heapSort() {
    // Need to heap build
    // function for heapify down
    if (heapSize <= 1) return;
    for (int i = heapSize/2; i >= 0; i--) {
        heapifyDown(i);
    }
    
}

void sorting::quickSort() {
    return;
}

void sorting::print(bool type) {
    if (type) {
        for (int i = 0; i < heapData.size(); i++) {
            extractMax().printInfo();
        }
    }
    else {
        for (int i = 0; i < heapSize; i++) {
            quickData[i].printInfo();
        }
    }
}