#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *head,*new_node,* temp;

void insert_beginning (int value)
{
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=head;
    head=new_node;
}
void insert_end (int value)
{
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=0;
    temp=head;
    while (temp->next!=0) // liked list traversal
        temp=temp->next;
    temp->next=new_node;
}
void delete_beginning ()
{
    struct node *del;
    del=head;
    head=head->next;
    cout<<"Deleted value: "<<del->data<<endl;
    free (del);
}
void delete_end()
{
    struct node *prev;
    temp=head;
    while (temp->next!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    cout<<"Deleted value: "<<temp->data<<endl;
    if (temp==head) // only one node present
        head=0;
    else
        prev->next=0;
    free(temp);
}
void delete_node(int key)
{
    temp=head;
    struct node *prev=0;
    if (temp!=0 && temp->data==key) //head node itself holds the key
    {
        head=temp->next;
        free(temp);
        return;
    }
    while (temp!=0 && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==0)
        return;
    prev->next=temp->next;
    free(temp);
}
int reverse()
{
    struct node *prev_node,*current_node,*next_node;
    prev_node=0;
    current_node=head;
    next_node=head;
    while (next_node!=0)
    {
        next_node=next_node->next;
        current_node->next=prev_node;
        prev_node=current_node;
        current_node=next_node;
    }
    head=prev_node;
}
int display(node *n)
{
    int count=0;
    cout<<"List: ";
    while (n->next!=0)
    {
        cout<<n->data<<"->";
        n=n->next;
        count++;
    }
    cout<<n->data<<endl;
    cout<<"Total nodes: "<<count+1<<endl;
}

int main ()
{
    int choice,val;
    head=0;
    do{
        cout<<"1 for insert at beginning"<<endl;
        cout<<"2 for insert at end"<<endl;
        cout<<"3 for display and count node"<<endl;
        cout<<"4 for delete from beginning"<<endl;
        cout<<"5 for delete from end"<<endl;
        cout<<"6 for delete any node"<<endl;
        cout<<"7 for reverse linked list"<<endl;
        cout<<"0 to exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the data: ";
                cin>>val;
                insert_beginning(val);
                break;
            case 2:
                cout<<"Enter the data: ";
                cin>>val;
                insert_end(val);
                break;
            case 3:
                if(head==0)
                    cout<<"List is Empty."<<endl;
                else
                {
                    display(head);
                    cout<<endl;
                }
                break;
            case 4:
                if (head==0)
                    cout<<"List is Empty."<<endl;
                else
                    delete_beginning();
                break;
            case 5:
                if (head==0)
                    cout<<"List is Empty."<<endl;
                else
                    delete_end();
                break;
            case 6:
                if (head==0)
                    cout<<"List is Empty."<<endl;
                else
                {
                    int val;
                    cout<<"Enter the value: ";
                    cin>>val;
                    delete_node(val);
                    cout<<"Deleted."<<endl;
                }
                break;
            case 7:
                if (head==0)
                    cout<<"List is Empty."<<endl;
                else
                {
                    reverse();
                    display(head);
                    cout<<endl;
                }
                break;
            case 0:
                return 0;
        }
    }while (choice<8);
    return 0;
}

