#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *lc,*rc;
    public:
    node()
    {

        lc=NULL;
        rc=NULL;
    }

    node* create()
{
    node *p;
    cout<<"Enter data(-1 for no data)\n";
    int a;
    cin>>a;
    if(a==-1)
        return NULL;
    p=new node();
    p->data=a;

    cout<<"Enter LC of"<<a<<endl;
    p->lc=create();
    cout<<"Enter RC of"<<a<<endl;
    p->rc=create();

    return p;
}

    void level(node *root)
    {
        queue <node*> q;
        q.push(root);

        while(!q.empty())
        {
            node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->lc)
                q.push(temp->lc);
            if(temp->rc)
                q.push(temp->rc);
        }
    }


};


int main()
{
    node p, *root;
    root=p.create();
    p.level(root);
}
