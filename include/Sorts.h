#ifndef SORTS_H
#define SORTS_H
#include<iostream>
#include<fstream>
using namespace std;

class Sorts
{
    private:
        int* arr;
        int size;
        int length;

    public:
        Sorts(int s);
        void bubbleSort(); // Bubble sort is adaptive sorting algorithm, because, when the
        //array is sorted, the cost is reduced.
        void append(int d);
        void show();
        void insertionSort();
        void selectionSort();
        void selectionSortVersion2();
        int quickSortPartition(int start,int end);
        void quickSort(int start,int end);
        int getIndex(){return this->length;}
        void merging(int low,int high);
        void mergeSort(int low, int high);
        int quickerPartition(int l, int h);
        void quickerSort(int l,int h);
};

#endif // BUBBLESORT_H
