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

    int partition(int start, int end);
public:
    sorting() {
        heapSize = 0;
    }
    sorting(vector<accidentNode>& searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        heapSize = searchedData.size();
    }
    void setData(vector<accidentNode>& searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        heapSize = searchedData.size();
    }
    void heapSort();
    void quickSort(int start, int end);
    
    void print(int type, int num);
};
