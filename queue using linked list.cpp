#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
int data;
struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enQueue(int val)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=0;
    if (front==0 && rear==0)
    {
        front=new_node;
        rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
}

void peek()
{
    if (front==0)
        cout<<"List is empty."<<endl;
    else
        cout<<"Peeked value: "<<front->data<<endl;
}

void deQueue()
{
    struct node *temp;
    temp=front;
    cout<<"Deleted item: "<<front->data<<endl;
    front=front->next;
    free(temp);
}

void display()
{
    struct node *temp;
    temp=front;
    while(temp->next!=0)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int main ()
{
    int choice,value;
    do{
        cout<<"1 for enQueue"<<endl;
        cout<<"2 for deQueue"<<endl;
        cout<<"3 for peek"<<endl;
        cout<<"4 for display"<<endl;
        cout<<"0 to exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the data: ";
                cin>>value;
                enQueue(value);
                break;
            case 2:
                if (front==0)
                    cout<<"List is empty."<<endl;
                else
                    deQueue();
                cout<<endl;
                break;
            case 3:
                peek();
                cout<<endl;
                break;
            case 4:
                if (front==0)
                    cout<<"List is empty."<<endl;
                else
                    display();
                cout<<endl;
                break;
            case 0:
                return 0;
        }
    }while (choice<5);
    return 0;
}


