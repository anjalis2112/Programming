#include<iostream>
using namespace std;

class node
{   public:
    node *next,*prev;
    int data;
    node *head;
    node()
    {
        next=NULL;
        prev=NULL;
        head=NULL;
    }

    void ins_rear(int);
    void del_rear();
    void ins_pos(int);
    void del_pos(int);
    void ins_aft(int,int);
    void ins_bef(int,int);
    void traverse();
    void reverse();

};

void node::ins_rear(int a)
{   node *temp=new node();
    temp->data=a;
    node *curr=head;
    if(head==NULL)
        {head=temp;
            return;}
    while(curr->next!=NULL)
        curr=curr->next;

        curr->next=temp;
        temp->prev=curr;
}

void node::del_rear()
{
    node *curr=head;

    if(head->next==NULL)
    {
        node *prev=head;
        head=head->next;
        delete(prev);
    }
    else
    {
        while(curr->next!=NULL)
            curr=curr->next;

        curr->prev->next=NULL;
        delete(curr);
    }
}

void node::ins_pos(int a)
{   node *curr=head;
    node *temp=new node();
    temp->data=a;
    int p;
    cout<<"Enter position\n";
    cin>>p;
    int q=1;
    if(p==1)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else{
    while(p-1!=q&&curr!=NULL)
    {
        curr=curr->next;
        q++;
    }
    if(curr==NULL)
        {cout<<"Pos DNE\n";
            return;}
    else
      { if(curr->next!=NULL){
        temp->next=curr->next;
        curr->next=temp;
        temp->prev=curr;
        temp->next->prev=temp;}

        else
        {
            temp->next=curr->next;
            curr->next=temp;
            temp->prev=curr;
        }
      }
}}

void node::traverse()
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"<-->";
        curr=curr->next;
    }
    cout<<"NULL";
}

void node::del_pos(int a)
{
    int p=1;
    node *curr=head;
    if(a==1)
    {
        node *t=head;
        head=head->next;
        delete(t);
        return;
    }
    while(a!=p&&curr!=NULL)
    {
        curr=curr->next;
        p++;
    }
    if(curr==NULL)
        {cout<<"DNE";return;}
    else
    {   if(curr->next!=NULL){
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        delete(curr);}

        else
        {
             curr->prev->next=curr->next;
             delete(curr);
        }
    }
}

void node::ins_aft(int a,int b)
{   node *curr=head;
    node *temp=new node();
    temp->data=a;
    while(curr->data!=b&&curr->next!=NULL)
    {
        curr=curr->next;
    }
    if(curr->next==NULL&&curr->data!=b)
        {cout<<"DATA DNE\n";
        return;}
    else
    {
            temp->next=curr->next;
            temp->prev=curr;
            curr->next=temp;
    }
}

void node::ins_bef(int a,int b)
{
    node *curr=head;
    node *temp= new node();
    temp->data=a;
    if(curr->data==b)
    {
        temp->next=curr;
        head=temp;
        return;
    }

    while(curr->data!=b&&curr!=NULL)
        curr=curr->next;

    if(curr==NULL)
        cout<<"DNE\n";
    else
    {
        temp->next=curr;
        curr->prev->next=temp;
        temp->prev=curr->prev;
        curr->prev=temp;
    }
}

void node::reverse()
{
    node *curr=head;
    node *temp;
    temp=head->next;
    while(temp!=NULL)
    {
        temp->prev=temp->next;
        temp->next=curr;
        curr=temp;
        temp=temp->prev;

    }
    head->next=NULL;
    head=curr;
}

int main()
{
    node a;
    a.ins_rear(5);
    a.ins_rear(6);
    a.ins_rear(7);
    a.ins_rear(8);
    a.ins_rear(9);
    a.traverse();
    cout<<endl;
    a.ins_bef(69,9);
    a.traverse();
    cout<<endl;
    a.reverse();
    a.traverse();
    cout<<endl;
}
