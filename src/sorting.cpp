
#include "sorting.h"

accidentNode sorting::extractMax() {
    accidentNode temp = heapData[0];
    heapData[0] = heapData[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return temp;
}

void sorting::heapifyDown(int index) {
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    int largest = index;

    if (left < heapSize && heapData[left].getInjCount() > heapData[largest].getInjCount()) {
        largest = left;
    }
    if (right < heapSize && heapData[right].getInjCount() > heapData[largest].getInjCount()) {
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
    if (heapData.size() <= 1) return;
    for (int i = heapData.size()/2; i >= 0; i--) {
        heapifyDown(i);
    }
    
}

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

void sorting::quickSort(int start, int end) {
    
    if (start < end) {
        int pivotPosition = partition(start, end);
        quickSort(start, pivotPosition - 1);
        quickSort(pivotPosition + 1, end);
    }

}

void sorting::print(int type) {
    if (type == 0) {
        for (int i = 0; i < heapData.size(); i++) {
            //heapData[i].printInfo();
            extractMax().printWholeNode();
        }
    }
    else if (type == 1) {
        for (int i = 0; i < heapData.size(); i++) {
            //heapData[i].printInfo();
            extractMax().printInfo();
        }
    }
    else if (type == 2) {
        for (int i = 0; i < heapData.size(); i++) {
            //heapData[i].printInfo();
            extractMax().printImportantInfo();
        }
    }
    
}