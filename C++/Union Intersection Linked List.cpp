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
    void intersection(node,node);
    void union_1(node,node);
    int search_data(node,int);

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

int node::search_data(node p,int data)
{
    node *curr=p.head;
    while(curr!=NULL){
    if(curr->data==data)
        return 1;
    curr=curr->next;

}   return 0;
}

void node::union_1(node a,node b)
{
    node c;
    node *curr=a.head;
    node *temp=b.head;
    while(curr!=NULL)
    {
      c.ins_rear(curr->data);
      curr=curr->next;

    }
    while(temp!=NULL)
    {

        if(!search_data(a,temp->data))
        {
            c.ins_rear(temp->data);
        }
        temp=temp->next;
    }

    c.traverse();

}

void node::intersection(node a,node b)
{
     node c;
    node *curr=a.head;
    node *temp=b.head;
    while(temp!=NULL)
    {
        if(search_data(a,temp->data))
        {
            c.ins_rear(temp->data);

        }
        temp=temp->next;
    }
    c.traverse();

}

int main()
{
    node c;
    node d;
    node e;
    c.ins_rear(5);
    c.ins_rear(6);
    c.ins_rear(7);
    d.ins_rear(8);
    c.ins_rear(9);
    c.ins_rear(10);
    d.ins_rear(9);
    d.ins_rear(10);
    c.traverse();
    cout<<endl;
    d.traverse();
    cout<<endl;
    e.intersection(c,d);
    cout<<endl;
    e.union_1(c,d);


}


