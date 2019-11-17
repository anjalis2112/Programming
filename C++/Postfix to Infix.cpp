#include<iostream>
using namespace std;

class Stack
{   public:
    string a[50];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(string c)
    {
        if(top==50)
            cout<<"Overflow";
        else
            a[++top]=c;
    }

    string pop()
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

void infix(string s)
{
    Stack in;

    for(int i=0;s[i]!='\0';i++)
    {   string op="";
        if(!isOperator(s[i]))
        {
            op+=s[i];
            in.push(op);

        }

        else
        {
            string op1=in.pop();
            string op2=in.pop();
            in.push("("+op2+s[i]+op1+")");
        }
    }

    cout<<in.pop();
}

int main()
{
    string s;
    cin>>s;
    infix(s);
}
