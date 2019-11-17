#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    char data;
    node *lc,*rc;
    public:
    node(char c)
    {
        data=c;
        lc=NULL;
        rc=NULL;
    }

    void inorder(node *root)
    {
        if(root==NULL)
            return;
        inorder(root->lc);
        cout<<root->data<<" ";
        inorder(root->rc);
    }

};

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
}

node* tree(char arr[])
{
    stack <node*> s;
    node *t, *t1, *t2;

    for(int i=0;arr[i]!='\0';i++)
    {
        if(!isOperator(arr[i]))
        {
            t=new node(arr[i]);
            s.push(t);
        }

        else
        {
            t=new node(arr[i]);
            t1=s.top();
            s.pop();
            t2=s.top();
            s.pop();

            t->rc=t1;
            t->lc=t2;

            s.push(t);
        }
    }

    t=s.top();
    s.pop();

    return t;
}

int main()
{
    node p('l');
    char postfix[] = "ab+";
    node* r = tree(postfix);

    p.inorder(r);
    return 0;
}
