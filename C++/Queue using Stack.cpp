#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack
{   public:
    int a[50];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(int c)
    {
        if(top==50)
            cout<<"Overflow";
        else
            a[++top]=c;
    }

    int pop()
    {
        if(top==-1)
            cout<<"";
        else
            return a[top--];
    }

    void display()
    {
        for(int i=0;i<=top;i++)
            cout<<a[i]<<" ";
    }



};


int main()
{
    Stack s1,s2;

    int choice;
    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display\n";
        cin>>choice;

        switch(choice)
        {
        case 1:
            int ele;
            cout<<"Enter ele: ";
            cin>>ele;
            s1.push(ele);
            break;

        case 2:
            while(s1.top!=-1)
            s2.push(s1.pop());
            s2.pop();
            while(s2.top!=-1)
                s1.push(s2.pop());
            break;

        case 3:
            s1.display();
        }
    }while(choice!=4);
}
