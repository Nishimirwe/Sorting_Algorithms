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

void Sorts::bubbleSort() // adaptive sorting algorithm, but we made it using flag variable. By default it is not
// adaptive, but we can make it adaptive. So, it is known as an adaptive sorting algorithm
{
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


void Sorts::insertionSort(int d, int s) // insertion sort algorithm
{
   int index=s-1;
   while(arr[index]>d)
   {
       arr[index+1]=arr[index];
       index--;
   }

   if((index+1)<0)
   {
       arr[0]=d;
   }
   else
   {
       arr[index+1]=d;
   }

   length++;
}
