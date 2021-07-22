#include "Sorts.h"
int main()
{
    Sorts s(50);
    s.append(3);
    s.append(7);
    s.append(9);
    s.append(10);
    s.append(5);
    s.append(12);
    s.append(4);
    s.append(11);
    s.append(2);
    //s.bubbleSort();
    //s.show();
    //s.insertionSort(0,9);
    s.insertionSort();
    s.append(34);
    s.show();
    return 0;
}
