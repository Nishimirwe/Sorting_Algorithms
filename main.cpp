#include "Sorts.h"
int main()
{
    Sorts s(50);
    s.append(3);
    s.append(7);
    s.append(9);
    s.append(10);
    s.append(5);
    s.append(-1);
    s.append(44);
    s.append(31);
    s.append(17);
    s.append(12);
    s.append(4);
    s.append(11);
    s.append(2);
    s.append(34);
    //s.bubbleSort();
    //s.insertionSort();
    //s.selectionSort();
    //s.selectionSortVersion2();
    s.quickSort(0,s.getIndex());
    s.show();
    return 0;
}
