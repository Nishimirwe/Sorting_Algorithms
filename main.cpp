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
    s.append(-90);
    s.append(300);
    s.append(123);
    s.append(232);
    s.append(-45);
    s.append(324);
    s.append(-23);
    s.append(55);
    s.append(3);
    s.append(39);
    //s.bubbleSort();
    //s.insertionSort();
    //s.selectionSort();
    //s.selectionSortVersion2();
    //cout<<"Quick sort: "<<endl;
    //s.quickSort(0,s.getIndex());
    int si=s.getIndex();
    //cout<<"Merge Sort: "<<endl;
    //s.mergeSort(0,si);
    cout<<"Quick Sort: "<<endl;
    s.quickerSort(0,si);
    s.show();
    cout<<"--------------------------------------------"<<endl;

    // AMA GONNA START RADIX SORT, COUNT SORT, BIN/BUCKET SORT AND SHELL SORT
    // Let me create another Sorts variable and use it.
    Sorts srt(50);
    srt.append(3);
    srt.append(6);
    srt.append(8);
    srt.append(12);
    srt.append(10);
    srt.append(15);
    srt.append(6);
    srt.append(6);
    srt.append(3);
    srt.append(9);
    srt.countSort();
    return 0;
}
