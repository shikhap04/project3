#pragma once

#include "vector"
#include "accidentNode.h"

class sorting {
private:
    vector<accidentNode> heapData;
    vector<accidentNode> quickData;
    int heapSize;

    void heapifyDown(int index);
    accidentNode extractMax();


public:
    sorting() {
        heapSize = 0;
    }
    sorting(vector<accidentNode>& searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        heapSize = searchedData.size();
    }
    void print(bool type);
    void heapSort();
    void quickSort();
};