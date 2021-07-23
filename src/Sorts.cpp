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

    //Again, Bubble sort is also a stable sorting Algorithm, as when elements are with same value
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
    cout<<"This is insertion Sort: ";
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

//----------------------------------------------------------------------------------------------------------------------
// UP TO HERE, I WOULD LIKE TO SAY THAT ONLY "BUBBLE SORT AND INSERTION" ARE EVER EXISTING ADAPTIVE SRTING ALGORITHMS |
// MEANS THAT WHEN ALL ARRAY ELEMENETS ARE ALREADY SORTED, THE PERFORMANCE IS POSITIVELY AFFECETD.                    |
//----------------------------------------------------------------------------------------------------------------------

void Sorts::selectionSort()
{
    // this is selection sort my version
    // Down this function I am going to write another logic
    // My logic says: select position (1),
    // pass through out the array, keep swapping the smallest array
    // to position 1. At one iteration, smallest element will be at the 1st position
    // but number of swapping is large, I will show the second version with small number of swapping


    // Here, we select the position and select through out the array, which element
    // should be in that position, then bring it.
    cout<<"This is selection sort: ";
    int index=length,j;
    for(int i=0;i<index;i++) // pass in array up to index -1
    {
        j=i+1; // j always start from i+1
        while(j<=index) // each iteration, move j up to last element
        {
            if(arr[i]>arr[j])
            {
                // if arr[j] is lesser than the i position
                // of the array, swap them
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
            j++;
        }
    }
}

void Sorts::selectionSortVersion2() // the first sorting algorithm that requires the minimum number of swaps
{
    // this selection sort passes through the array and
    // at each iteration, it saves the index of the smallest element
    // then swap it with i position. Look

    // Here, we select the position and select through out the array, which element
    // should be in that position, then bring it.
    cout<<"This is another selection sort version: ";
    int index=length;
    int k,j;
    for(int i=0;i<index;i++)
    {
        k=i;
        j=i+1;
        while(j<=index)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
            j++;
        }
        if(i!=k)
        {
            int t=arr[i];
            arr[i]=arr[k];
            arr[k]=t;
        }
    }

    //THIS SELECTION SORT MIGHT THE BEST BECAUSE THERE ARE MINIMUM NUMBER
    //OF SWAPPING

    //If you look at the implementation of selection sort, this sorting technique is not adaptive
    //because even though the list might be already sorted, the algorithm
    //perform the same number of comparison.

    // Again, this selection sort is not also stable because when we have two equal
    //elements, there is no guarantee that the order of those elements will be preserved.
}
