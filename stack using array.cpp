#include <iostream>
using namespace std;
#define max 5
class Stack{
    int top;
    int arr[max];
    public:
        Stack ()
        {
            top=-1;
        }
        int isFull()
        {
            if (top==max-1)
                return 1;
            else
                return 0;
        }
        int isEmpty()
        {
            if (top==-1)
                return 1;
            else
                return 0;
        }
        void push (int val)
        {
            top++;
            arr[top]=val;
        }
        int pop ()
        {
            if (!isEmpty())
            {
                int x=arr[top];
                top--;
                cout<<"Poped value: "<<x<<endl;
            }
            else
                cout<<"Stack is Empty."<<endl;
        }
        int peek ()
        {
            if (!isEmpty())
                cout<<"Peeked value: "<<arr[top]<<endl;
            else
                cout<<"Stack is Empty."<<endl;
        }
        void print()
        {
            if (isEmpty())
                cout<<"Stack is Empty."<<endl;
            else
            {
                cout<<"Stack values are: "<<endl;
                for (int i=top;i>=0;--i)
                    cout<<arr[i]<<" ";
                cout<<endl;
            }
        }
};

int main ()
{
    Stack s;
    int ch,value;
    do
    {

        cout<<"1 for push"<<endl;
        cout<<"2 for pop"<<endl;
        cout<<"3 for peek"<<endl;
        cout<<"4 for empty"<<endl;
        cout<<"5 for Full"<<endl;
        cout<<"6 for print"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
            	if (!(s.isFull()))
                {
                    cout<<"Enter the item: ";
                    cin>>value;
                    s.push(value);
                }
                else
                    cout<<"Stack is Full."<<endl;
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty())
                    cout<<"Stack is empty."<<endl;
                else
                    cout<<"Stack is not empty."<<endl;
                break;
            case 5:
                if (s.isFull())
                    cout<<"Stack is full."<<endl;
                else
                    cout<<"Stack is not full."<<endl;
                break;
            case 6:
                s.print();
                break;
            default:
                cout<<"Check again."<<endl;
        }
    }while (ch<7);
    return 0;
}

