#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
int data;
struct node *next;
}*tail;

void insert_begin(int value)
{
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
	curr->data=value;
	if(tail==0)
    {
		curr->next=curr;
		tail=curr;
	}
	curr->next=tail->next;
	tail->next=curr;
}

void insert_end(int value)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    if (tail==0)
    {
        tail=new_node;
        tail->next=new_node;
    }
    else
    {
        new_node->next=tail->next;
        tail->next=new_node;
        tail=new_node;
    }
}

void del_begin()
{
    struct node *temp;
    temp=tail->next;
    cout<<"Deleted item: "<<temp->data<<endl;
    if (temp->next==temp)
    {
        tail=0;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        free(temp);
    }
}

void del_end()
{
    struct node *current,*prev;
    current=tail->next;
    if (current->next==current)
    {
        cout<<"Deleted item: "<<current->data<<endl;
        tail=0;
        free(current);
    }
    else
    {
        while (current->next!=tail->next)
        {
            prev=current;
            current=current->next;
        }
        cout<<"Deleted item: "<<current->data<<endl;
        prev->next=tail->next;
        tail=prev;
        free(current);
    }
}

void display()
{
    struct node *temp;
    temp=tail->next;
    cout<<"LIST: ";
    while (temp->next!=tail->next)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main ()
{
    int choice,val;
    tail=0;
    do{
        cout<<"1 for insert at beginning"<<endl;
        cout<<"2 for insert at end"<<endl;
        cout<<"3 for display"<<endl;
        cout<<"4 for delete from beginning"<<endl;
        cout<<"5 for delete from end"<<endl;
        cout<<"0 to exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the data: ";
                cin>>val;
                insert_begin(val);
                break;
            case 2:
                cout<<"Enter the data: ";
                cin>>val;
                insert_end(val);
                break;
            case 3:
                if (tail==0)
                    cout<<"List is Empty."<<endl;
                else
                    display();
                cout<<endl;
                break;
            case 4:
                if (tail==0)
                    cout<<"List is Empty."<<endl;
                else
                    del_begin();
                cout<<endl;
                break;
            case 5:
                if (tail==0)
                    cout<<"List is Empty."<<endl;
                else
                    del_end();
                cout<<endl;
                break;
            case 0:
                return 0;
        }
    }while (choice<6);
    return 0;
}


