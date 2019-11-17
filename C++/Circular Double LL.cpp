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
    void traverse();
    void del(int pos);

};


void node::ins_rear(int a)
{
    node *temp= new node();
    temp->data=a;
    node *curr=head;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
        head->prev=head;
        return;
    }

    while(curr->next!=head)
        curr=curr->next;

    curr->next=temp;
    temp->next=head;
    temp->prev=curr;
    temp->next->prev=temp;
}

void node::del(int pos)
{
    node *curr=head;
    int count=1;

    if(pos==1)
    {
        node *temp=head;
        head->prev->next=head->next;
        head=head->next;
        delete(temp);
        return;
    }

    while(count!=pos)
    {
        curr=curr->next;
        count++;
    }

    if(curr->next==head)
    {
        node *temp=curr;
        curr->prev->next=curr->next;
        delete(temp);
        return;
    }

    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    delete(curr);



}

void node::traverse()
{
    node *curr=head;
    while(curr->next!=head)
    {
        cout<<curr->data<<"<-->";
        curr=curr->next;
    }
    cout<<curr->data<<"<-->"<<"head";
}


int main()
{
    node a;
    a.ins_rear(1);
    a.ins_rear(2);
    a.ins_rear(3);
    a.ins_rear(4);
    a.ins_rear(5);
    a.traverse();
    cout<<endl;
    a.del(1);
    a.traverse();
    cout<<endl;
    a.del(3);
    a.traverse();
    cout<<endl;
    a.del(3);
    a.traverse();
    cout<<endl;
}
