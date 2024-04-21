#pragma once
#include "vector"
#include "accidentNode.h"

class sorting {
private:
    vector<accidentNode> heapData;
    vector<accidentNode> quickData;
    int dataSize;

public:
    sorting() {
        dataSize = 0;
    }
    sorting(vector<accidentNode> searchedData) {
        heapData = searchedData;
        quickData = searchedData;
        dataSize = searchedData.size();
    }
    void heapifyDown(int index);
    void heapSort(vector<accidentNode>& heapData);
    void quickSort(vector<accidentNode>& quickData);
};