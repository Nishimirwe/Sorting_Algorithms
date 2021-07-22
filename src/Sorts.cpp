#include "Sorts.h"

Sorts::Sorts(int s)
{
    //ctor
    length=-1;
    size=s;
    arr=new int[size];
}

void Sorts::append(int d)
{
    if(length==size-1)
    {
        cout<<"Full array"<<endl;
    }
    else
    {
        length++;
        arr[length]=d;
    }
}

void Sorts::bubbleSort()
{
    // adaptive sorting algorithm, but we made it using flag variable. By default it is not
    // adaptive, but we can make it adaptive. So, it is known as an adaptive sorting algorithm

    //Again, Bubble sort is also a stable sorting Algorithm, as when element are with same value
    // bubble sort preserve the order of those similar elements.

    // This bubble sort algorithm is not applicable for linked list.
    int s=length+1;
    cout<<"This is Bubble Sort: ";
    int flag=0;
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                if(flag<2)
                    flag++;
            }
        }
        if(flag==0)
        {
            cout<<endl<<"Already sorted\n";
            break;
        }
    }
}

void Sorts::show()
{
    for(int i=0;i<=length;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void Sorts::insertionSort() // insertion sort algorithm
{
    // The insertion sort is adaptive sorting algorithm by its nature.
    // It means that when the array is already sorted, the insertion sort's performance
    // is positively affected without requiring us to do extra work.
    // because when it is sorted, there is no swapping made.


    // Another this is that the insertion sort is Stable because when the elements are equal
    // it keeps the order of those elements.

    //Insertions is very suitable for linked list than array. It is meant for linked list, because using arrays
    // it requires swapping elements for inserting. But for linked lists, no swapping is required, just insert a node where is appropriate.
    cout<<"This is insertion Sort"<<endl;
   int i=length;
   int start=1,j;
   for(int k=start;k<=i;k++)
   {
       j=k;
       int t=arr[j];
       while(t<arr[j-1] && j>0)
       {
           arr[j]=arr[j-1];
           arr[j-1]=t;
           t=arr[j-1];
           j--;
       }
   }
}
----------------------------------------------------------------------------------------------------------------------
// UP TO HERE, I WOULD LIKE TO SAY THAT ONLY "BUBBLE SORT AND INSERTION" ARE EVER EXISTING ADAPTIVE SRTING ALGORITHMS |
// MEANS THAT WHEN ALL ARRAY ELEMENETS ARE ALREADY SORTED, THE PERFORMANCE IS POSOTIVELY AFFECETD.                    |
----------------------------------------------------------------------------------------------------------------------
