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
    ofstream out("files/output.txt");
    for(int i=0;i<=length;i++)
    {
        cout<<arr[i]<<" ";
        out<<arr[i]<<" ";
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
    //Time best case: O(nlog(n)), worst case : O(n2) :When list is sorted
    // average=best case.
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


// DOWN SORTING ALGORITHMS ARE CALLED RECURSIVE ALGORITHMS, QUICKSORT AND MERGE SORTS

// I am going to hardly code MergeSort

void Sorts::merging(int l, int h)
{
    int mid=(l+h)/2;
    int i=l, j=mid+1, k=0;
    int* a=new int[h-l+5];
    while(i<=mid && j<=h)
    {
        if(arr[i]<arr[j])
        {
            a[k++]=arr[i++];
        }
        else
        {
            a[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++)
    {
        a[k++]=arr[i];
    }
    for(;j<=h;j++)
    {
        a[k++]=arr[j];
    }
    int sss=0;
    for(int hh=l;hh<=h;hh++)
    {
        arr[hh]=a[sss];
        sss++;
    }
}

void Sorts::mergeSort(int l, int h)
{
    if(l<h)
    {
        mergeSort(l,(l+h)/2);
        mergeSort(((l+h)/2)+1,h);
        merging(l,h);
    }
}

// BEING QUICK SORT DOES NOT MEAN THAT IT IS THE FASTEST SORTING ALGORITHM. NO, IT IS NOT
int Sorts::quickerPartition(int l, int h)
{
    // This is called partition function
    // what it does, it takes the first element as the pivot
    // i loops in array looking for element > pivot (if it finds it it stops)
    // k starts from behind finding element <= pivot (if it finds it, it stops)
    // Then, if j<k, I swap arr[k] and arr[j], bigger elements go right and smaller come left.
    // do this as long as j<k

    // After when j crosses k, swap element[j-1] with pivot.

    int pivot=arr[l];
    int i,j,k;
    i=l;
    j=l+1;
    k=h;
    while(j<k)
    {
        while(arr[j]<=pivot) // looking for bigger element
        {
            j++;
        }
        while(arr[k]>pivot) //looking for smaller element
        {
            k--;
        }

        if(j<k) // if j and k still in appropriate range, swap
        {
            int t=arr[j];
            arr[j]=arr[k];
            arr[k]=t;
            j++;
            k--;
        }
    }
    if(arr[j-1]<pivot) // if swap is needed, swap; this may not be true if array has two elements which are already sorted.
    {
        int temp=arr[j-1];
        arr[j-1]=arr[i];
        arr[i]=temp;
    }
    return j-1; // return where you left the pivot. Up to here, pivot is sorted.
}

void Sorts::quickerSort(int l, int h)
{
    // This quickSort is doing partition task on all sides of array, I mean left and right
    if(l<h) // if array has more than one element.
    {
        int m=quickerPartition(l,h);
        quickerSort(l,m-1);
        quickerSort(m+1,h);
    }
}
