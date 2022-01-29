#include <iostream>
using namespace std;
#define MAX 5

int arr[MAX];
int front=-1;
int rear=-1;

void enQueue ()
{
    int item;
    if (rear==MAX-1) //Queue is full
        cout<<"Queue is Full."<<endl;
    else if (front==-1 && rear==-1) //Queue is empty
    {
        front=0;
        rear=0;
        cout<<"Inset the element in queue : ";
        cin>>item;
        arr[rear]=item;
    }
    else
    {
        rear++;
        cout<<"Inset the element in queue : ";
        cin>>item;
        arr[rear]=item;
    }
}

void deQueue ()
{
    if (front==-1 && rear==-1) //Queue is empty
        cout<<"Queue is Empty."<<endl;
    else if (front==rear) // on;y one item present
    {
        cout<<"Deleted item: "<<arr[front]<<endl;
        front=-1;
        rear=-1;
    }
    else
    {
        cout<<"Deleted item: "<<arr[front]<<endl;
        front++;
    }
}

void peek ()
{
    if (front==-1 && rear==-1)
        cout<<"Queue is Empty."<<endl;
    else
        cout<<"Peeked value: "<<arr[front]<<endl;
}

void display ()
{
    int i;
    if (front==-1 && rear==-1)
        cout<<"Queue is Empty."<<endl;
    else
    {
        cout<<"Queue is:"<<endl;
        for (i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout<<"1.EnQueue"<<endl;
        cout<<"2.DeQueue"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                cout<<"Wrong choice.\n";
        }
    }while (choice<5);
    return 0;
}

