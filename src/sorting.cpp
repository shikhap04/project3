
#include "sorting.h"

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

    if (left < dataSize && heapData[left].getInjCount() > heapData[index].getInjCount()) {
        largest = left;
    }
    if (right < dataSize && heapData[right].getInjCount() > heapData[index].getInjCount() 
        && heapData[right].getInjCount() > heapData[left].getInjCount()) {
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
    /*
    for (i = size/2; i >= 0; i--) {
        heapifydown(i)
    }
    */
    return;
}

void sorting::quickSort() {
    return;
}