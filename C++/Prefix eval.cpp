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
            cout<<a[i];
    }



};

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
}

int priority(char C)
{
        if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;

}

void preeval(string str)
{
    Stack s;
    for(int i=str.size();i>-1;i--)
    {
        if(!isOperator(str[i]))
            s.push(str[i]-'0');
        else
        {
            int a=s.pop();
            int b=s.pop();

            if(str[i]=='+')
                s.push(a+b);

            else if(str[i]=='-')
                s.push(a-b);

            else if(str[i]=='*')
                s.push(a*b);

            else if(str[i]=='/')
                s.push(a/b);

        }
    }

    cout<<s.pop();


}

int main()
{
    string s;
    cin>>s;
    preeval(s);
}
