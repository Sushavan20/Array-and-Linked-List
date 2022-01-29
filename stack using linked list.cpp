#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *top=0;

void push(int val)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=top;
    top=new_node;
}
void peek()
{
    if (top==0)
        cout<<"List is empty."<<endl;
    else
        cout<<"Peeked value: "<<top->data<<endl;
}

void pop()
{
    struct node *temp;
    temp=top;
    if (top==0)
        cout<<"List is empty."<<endl;
    else
    {
        cout<<"Popped item: "<<temp->data;
        top=temp->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=top;
    if (top==0)
        cout<<"List is empty."<<endl;
    else
    {
       while (temp->next!=0)
       {
           cout<<temp->data<<"->";
           temp=temp->next;
       }
       cout<<temp->data<<endl;
    }
}

int main ()
{
    int choice,value;
    do{
        cout<<"1 for push"<<endl;
        cout<<"2 for pop"<<endl;
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
                push(value);
                break;
            case 2:
                pop();
                cout<<endl;
                break;
            case 3:
                peek();
                cout<<endl;
                break;
            case 4:
                display();
                cout<<endl;
                break;
            case 0:
                return 0;
        }
    }while (choice<5);
    return 0;
}

