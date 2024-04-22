#pragma once

#include "vector"
#include "accidentNode.h"

class sorting {
private:
    // Copy of data for each sort
    vector<accidentNode> heapData;
    vector<accidentNode> quickData;

    int heapSize;

    // Internal Functions for Sorts
    void heapifyDown(int index);
    accidentNode extractMax();

    int partition(int start, int end);
public:
    // Constructors
    sorting() {
        heapSize = 0;
    }
    sorting(vector<accidentNode>& searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        heapSize = searchedData.size();
    }

    // Reset the Data 
    void setData(vector<accidentNode>& searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        heapSize = searchedData.size();
    }

    // Sorts
    void heapSort();
    void quickSort(int start, int end);
    
    // Printing all Nodes after being sorted
    void print(int type, int num);
};
