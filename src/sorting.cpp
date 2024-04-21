
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

void sorting::quickSort(int start, int end) {

    // if (start >= end) {
    //     return;
    // }

    // int pivotPosition = partition(start, end);
    // quickSort(start, pivotPosition - 1);
    // quickSort(pivotPosition + 1, end);

    if (start < end) {
        int pivotPosition = partition(start, end);
        quickSort(start, pivotPosition - 1);
        quickSort(pivotPosition + 1, end);
    }

}

int sorting::partition(int start, int end) {

    // int pivotValue = quickData[start].getInjCount();

    // int count = 0;
    // for (int i = start + 1; i <= end; i++) {
    //     if (quickData[i].getInjCount() <= pivotValue) {
    //         count++;
    //     }
    // }
    
    // int pivotPosition = start + count;
    // swap(quickData.at(pivotPosition), quickData.at(start));

    // int i = start;
    // int j = end;

    // while (i < pivotPosition && j > pivotPosition) {

    //     while (quickData.at(i).getInjCount() <= pivotValue) {
    //         i++;
    //     }
 
    //     while (quickData.at(j).getInjCount() > pivotValue) {
    //         j--;
    //     }
 
    //     if (i < pivotPosition && j > pivotPosition) {
    //         swap(quickData.at(i++), quickData.at(j--));
    //     }

    // }

    // return pivotPosition;

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

// void sorting::quickPrint() {
//     for (int i = quickData.size() - 1; i >= 0; i--) {
//         quickData[i].printInfo();
//     }
//     cout << "searched size: " << quickData.size() << "\n";
// }

