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


int main()
{
    LinkedList li;
    int a[]={23,45,12,76,23,88,11,4,7,1,76,90};
    int s=sizeof(a)/sizeof(int);
    binSort(a,s);
    for(int i=0;i<s;i++)
    {
        li.addNode(a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
