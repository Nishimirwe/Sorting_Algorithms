#ifndef SORTS_H
#define SORTS_H
#include<iostream>
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

};

#endif // BUBBLESORT_H
