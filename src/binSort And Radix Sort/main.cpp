#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        int size();
        void addNode(int value);
        Node* pop();
        void show();
        Node* getHead();
        Node* popFront();

    private:
        Node* head;
        Node* tail;
        int length;
};



LinkedList::LinkedList()
{
    //ctor
    head=NULL;
    tail=NULL;
    length=0;
}

LinkedList::~LinkedList()
{
    //dtor
    delete [] head;
    delete [] tail;
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::addNode(int value)
{
    Node* node=new Node(value);
    if(isEmpty())
    {
        head=tail=node;
        length++;
    }
    else
    {
        tail->next=node;
        tail=node;
        length++;
    }
}

bool LinkedList::isEmpty()
{
    if(head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedList::show()
{
    if(isEmpty())
    {
        cout<<"This is empty list\n";
        return;
    }
    Node* nav=head;
    while(nav!=NULL)
    {
        cout<<nav->data<<" :  ";
        nav=nav->next;
    }
    cout<<endl;
    cout<<"Size: "<<length<<endl;
}

int LinkedList::size()
{
    return length;
}

Node* LinkedList::popFront()
{
    if(isEmpty())
    {
        return NULL;
    }
    else if(head==tail && length==1)
    {
        Node* t=head;
        head=tail=NULL;
        length=0;
        return t;
    }
    else
    {
        Node* nav=head;
        head=head->next;
        length--;
        return nav;
    }
}

Node* LinkedList::pop()
{
    if(isEmpty())
    {
        return NULL;
    }
    else if(head==tail && length==1)
    {
        Node* t=head;
        head=tail=NULL;
        length=0;
        return t;
    }
    else
    {
        Node* nav=head;
        Node* t=head;
        while(nav!=tail)
        {
            t=nav;
            nav=nav->next;
        }
        t->next=NULL;
        tail=t;
        length--;
        return nav;
    }
}

int big(int* arr, int s)
{
    int m=arr[0];
    for(int i=0;i<s;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    return m;
}

void binSort(int *arr,int s)
{

    // bin Sort is much similar like count sort
    // They all use little time but they require additional array whose
    // size equals to the larges element in the array to be sorted.

    // The idea behind, you create an additional array and add each element
    // new array so that each element is placed in index equal to it(element).

    // Then Loop through the created array, adding non empty elements back in original array

    // eg: sort 5,4 1;
    // New created array is with 5 size:  - - - - -
    // add all elements in new array, that value equals its index: 1 - - 4 5
    // then loop through (1 - - 4 5) adding back in org array: 1 4 5 (Sorted)

    // it uses linked list to do so, while count sort uses array (usual arrays)
    LinkedList **li;
    int maxim=big(arr,s);
    li = new LinkedList*[maxim];
    for(int hh=0;hh<=maxim;hh++)
    {
        li[hh]=new LinkedList;
    }
    for(int i=0;i<s;i++)
    {
        li[arr[i]]->addNode(arr[i]);
    }
    int g=0;
    for(int k=0;k<=maxim;k++)
    {
        if(!li[k]->isEmpty())
        {
            while(!li[k]->isEmpty())
            {
                arr[g++]=li[k]->pop()->data;
            }
        }
    }
}


// I am going to hardly code radix sort, down here
//step 1: I have to extract the maximum number in array. Since I have coded the same
// function in above Bin sort, I am immediately calling the function without coding it again

//step 2: I have to count number of digits composes the bigger number
int countDigits(int number)
{
    int c=1;
    int res=number;
    while(res>9)
    {
        res=res/10;
        c++;
    }
    return c;
}

// let me code the function to find the power of a number
int pow(int base, int exp)
{
    int res=1;
    for(int i=1;i<=exp;i++)
    {
        res*=base;
    }
    return res;
}
void radixSort(int* arr, int s, int base)
{
    // I should have an array of base linked lists
    LinkedList **li;
    li=new LinkedList*[base];
    for(int k=0;k<base;k++)
    {
        li[k]=new LinkedList; // initialize all linked list to null (Default linked List class)
    }
    //Step and 2 are combined in below line
    int rounds=countDigits(big(arr,s)); // gte number of digits for maximum element

    //I am gon loop rounds times doing the same thing. Follow here
    int p=0,index;
    while(p<rounds) // do this rouds iteration, start from zero
    {
        for(int i=0;i<s;i++) // loop in array given
        {
            index=(arr[i]/pow(10,p))%10; // find index of linked list to store in based on round. Index = digits at
            // pth position
            li[index]->addNode(arr[i]); // add that number in linked list
        }
        int ii=0;
        for(int j=0;j<base;j++) // loop back in a linked list
        {
            if(!li[j]->isEmpty())
            {
                while(!li[j]->isEmpty())
                {
                    arr[ii++]=li[j]->popFront()->data; // add all data back in array
                }
            }
        }
        p++; // increment round count
    }

}

int main()
{
    int a[]={23,45,12,76,23,88,11,4,7,1,76,90};
    int s=sizeof(a)/sizeof(int);
    cout<<"BIN SORT"<<endl;
    binSort(a,s); // calling Bin sort function
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl<<endl<<endl;
    int b[]={23,45,12,76,23,88,11,4,7,1,76,90};
    s=sizeof(b)/sizeof(int);
    cout<<"RADIX SORT"<<endl;
    radixSort(b,s,10);
    for(int i=0;i<s;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl<<endl;
    return 0;
}

