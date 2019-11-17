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
    node* create();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    bool print_ancestors(node *,int);
    int depth(node *);
    int leaf_count(node *);
    bool equality(node *, node *);
    bool mirror(node *, node *);
    node* copy(node *);
    void levelorder(node *,int);
    void level(node *);
    bool parent(node *root,int a);
};


node* node::create()
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


void node::inorder(node *root)
{
    stack<node *> s;
    node *curr= root;

    while(curr!=NULL||!s.empty())
   {

    while(curr!=NULL)
    {
        s.push(curr);
        curr=curr->lc;
    }


        curr=s.top();
        s.pop();
        cout<<curr->data;

        curr=curr->rc;

   }
}

void node::preorder(node *root)
{
    stack<node *> s;
    node *curr= root;
    s.push(curr);
    while(!s.empty())
    {
        node *curr=s.top();
        s.pop();
        cout<<curr->data;
        if(curr->rc!=NULL)
        s.push(curr->rc);
        if(curr->lc!=NULL)
        s.push(curr->lc);
    }

}

void node::postorder(node *root)
{
     stack<node *> s;
     s.push(root);

     stack<int> value;
     while(!s.empty())
     {
         node *curr=s.top();
         s.pop();
         value.push(curr->data);

         if(curr->lc!=NULL)
            s.push(curr->lc);
         if(curr->rc!=NULL)
            s.push(curr->rc);
     }

     while(!value.empty())
     {
         cout<<value.top();
         value.pop();
     }

}

bool node::print_ancestors(node *root, int target)
{
  if (root == NULL)
     return false;
  if (root->data == target)
    return true;

  if(print_ancestors(root->lc, target) || print_ancestors(root->rc, target) )
  {
    cout << root->data << " ";
    return true;
  }

  return false;
}

int node::depth(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int L=depth(root->lc);
        int R=depth(root->rc);

        if(L>R)
            return(L+1);
        else
            return(R+1);
    }
}

int node::leaf_count(node *root)
{
    if(root==NULL)
        return 0;
    else if(root->lc==NULL&&root->rc==NULL)
        return 1;

    else
    {
    int val=leaf_count(root->lc)+leaf_count(root->rc);
        return val;
    }
}

bool node::equality(node *root1, node *root2)
{

    if(root1==NULL&&root2==NULL)
    {   return 1;
    }

    else
    {
        return((root1->data==root2->data)&&equality(root1->lc,root2->lc)&&equality(root1->rc,root2->rc));
    }

   return 0;
}

bool node::mirror(node *a, node *b)
{
    if (a==NULL && b==NULL)
        return true;

    if (a==NULL || b == NULL)
        return false;

    return  a->data == b->data &&
            mirror(a->lc, b->rc) &&
            mirror(a->rc, b->lc);
}

bool node::parent(node* root, int a)
{
    if(root==NULL)
        return false;

    if(root->lc&&root->lc->data==a)
    {
        cout<<"Parent of "<<a<<" is: "<<root->data;
        return true;
    }

     if(root->rc&&root->rc->data==a)
    {
        cout<<"Parent of "<<a<<" is: "<<root->data;
        return true;
    }

    return(parent(root->lc,a)||parent(root->rc,a));
}

node* node::copy(node *a)
{
    node *b;
    if(a==NULL)
        b=NULL;
    else
    {
        b->data=a->data;
        b->lc=copy(a->lc);
        b->rc=copy(a->rc);
    }

    return b;
}

void levelorder(node *root,int level)
{
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data;
    else if(level >1)
    {
        levelorder(root->lc,level-1);
        levelorder(root->rc,level-1);
    }
}

void level(node *root)
{
    node p;
    for(int i=0;i<p.depth(root);i++)
        levelorder(root,i);
}

int main()
{
    node a;
    node *root;
    root=a.create();
    a.parent(root,6);


}








