#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack
{   public:
    char a[50];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(char c)
    {
        if(top==50)
            cout<<"Overflow";
        else
            a[++top]=c;
    }

    char pop()
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

 void prefix(string a) //this is actually prefix
    {
        Stack s;
        int len=a.size();
          reverse(a.begin(),a.end()); //everything after this is technically postfix. I do my prefix by reversing, postfixing and reversing again
            for(int i=0;i<len;i++)
            {
                if(a[i]=='(')
                    a[i]==')';
                if(a[i]==')')
                    a[i]=='(';
            }

            string output;
            for(int i=0;i<len;i++)
            {
                if(!isOperator(a[i]))
                    output+=a[i];

                else if(a[i]=='(')
                            s.push(a[i]);

                else if(a[i]==')')
                  {
                      while(s.a[s.top]!='(')
                          output+=s.pop();
                          s.pop();
                  }

                else
                {
                    while(priority(a[i])<=priority(s.a[s.top]))
                        output+=s.pop();
                    s.push(a[i]);
                }

            }

            while(s.top!=-1)
                output+=s.pop();

                 reverse(output.begin(),output.end());
                 cout<<output;







    }






int main()
{
    Stack s;
    string a;

    cout<<"Enter infix\n";
    cin>>a;
    prefix(a);
}
