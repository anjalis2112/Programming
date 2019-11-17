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

void infix(string str)
{
    Stack s;
    int len=str.size();
    for(int i=len;i>-1;i--)
    {   string op="";
        if(!isOperator(str[i]))
        {
            op+=str[i];
            s.push(op);

        }

        else
        {
            string op1=s.pop();
            string op2=s.pop();
            s.push("("+op1+str[i]+op2+")");
        }
    }

    cout<<s.pop();
}

int main()
{
    string s;
    cin>>s;
    infix(s);
}
