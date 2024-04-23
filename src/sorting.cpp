
#include "sorting.h"

// Extract Max from the heap to print in correct order
// Copy root, then set it to last entry, then reduce size of heap and heapify down the root
accidentNode sorting::extractMax() {
    accidentNode temp = heapData[0];
    heapData[0] = heapData[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return temp;
}

// Swap each node with its larger child and then recursively heapify down the new child
// Recursive continues until the node is no longer smaller than its children or it has no children
void sorting::heapifyDown(int index) {
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    int largest = index;

    if (left < heapSize && heapData[left].getInjCount() > heapData[largest].getInjCount()) { // left child is larger than index
        largest = left;
    }
    if (right < heapSize && heapData[right].getInjCount() > heapData[largest].getInjCount()) { // right child is larger than current largest (index or left)
        largest = right;
    }
    if (largest != index) {
        swap(heapData[largest], heapData[index]);
        heapifyDown(largest);
    }

}

// Heap Build in place, uses heapify down on second half of the heap data
void sorting::heapSort() {
    if (heapData.size() <= 1) return;
    for (int i = heapData.size()/2; i >= 0; i--) {
        heapifyDown(i);
    }
    
}

// Seperates the quick data into two partitions, 
// sets pivot position to the beginning of the quick data,
// and rearranges the nodes so nodes < pivot are in the left partition and nodes > pivot are in the right partition.
// Then swaps the pivot and node at down sorting the node
int sorting::partition(int start, int end) {
    int pivotValue = quickData[start].getInjCount();
    int up = start; 
    int down = end;

    while (up < down) {

        for (int j = up; j < end; j++) {
            if (quickData[up].getInjCount() > pivotValue) {
                break;
            }
            up++;
        }

        for (int j = end; j > start; j--) {
            if (quickData[down].getInjCount() < pivotValue) {
                break;
            }
            down--;
        }

        if (up < down) {
            swap(quickData.at(up), quickData.at(down));
        }

    }
    swap(quickData.at(start), quickData.at(down));
    return down;
}

// Runs parition and recursively calls quickSort on the left and right partitions to sort the array
void sorting::quickSort(int start, int end) {
    
    if (start < end) {
        int pivotPosition = partition(start, end);
        quickSort(start, pivotPosition - 1);
        quickSort(pivotPosition + 1, end);
    }
}

// Prints the inputted number of entries, if user wanted to print all data, then num is set to the size of the heap
// The type dictates style of printing: all information, basic info or important info
void sorting::print(int type, int num) {
    if (num == -1) num = heapData.size();
    if (type == 1) {
        for (int i = 0; i < num; i++) {
            //heapData[i].printInfo();
            extractMax().printWholeNode();
        }
    }
    else if (type == 2) {
        for (int i = 0; i < num; i++) {
            //heapData[i].printInfo();
            extractMax().printInfo();
        }
    }
    else if (type == 3) {
        for (int i = 0; i < num; i++) {
            //heapData[i].printInfo();
            extractMax().printImportantInfo();
        }
    }
    
}

