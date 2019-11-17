#include<iostream>
using namespace std;

class node
{   public:
    node *next,*prev;
    int data,power;
    node *head;
    node()
    {
        next=NULL;
        prev=NULL;
        head=NULL;
    }

    void ins_rear(int,int);
    void traverse();
    void add(node a, node b);
};

void node::ins_rear(int a,int b)
{
    node *temp= new node();
    temp->data=a;
    temp->power=b;
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


void node::add(node a,node b)
{   node c;
    node *temp1=a.head;
    node *temp2=b.head;
    do
    {
        if(temp1->power==temp2->power)
        {   int sum=temp1->data+temp2->data;
            c.ins_rear(sum,temp1->power);
            temp1=temp1->next;
            temp2=temp2->next;

        }

        else if(temp1->power>temp2->power)
        {
            c.ins_rear(temp1->data,temp1->power);
            temp1=temp1->next;
        }

        else
        {
            c.ins_rear(temp2->data,temp2->power);
            temp2=temp2->next;
        }

    }while(temp1!=a.head&&temp2!=b.head);

    if(temp2!=b.head||temp1!=a.head)
    {
        if(temp1!=a.head)
        {
            c.ins_rear(temp1->data,temp1->power);
            temp1=temp1->next;
        }
         if(temp2!=b.head)
        {
            c.ins_rear(temp2->data,temp2->power);
            temp2=temp2->next;
        }

    }
    c.traverse();
}

void node::traverse()
{
    node *curr=head;
    while(curr->next!=head)
    {
        cout<<curr->data<<"^"<<curr->power<<" + ";
        curr=curr->next;
    }
    cout<<curr->data<<"^"<<curr->power;
}

int main()
{
    node a,b,c;
    a.ins_rear(5,4);
    a.ins_rear(6,3);
   // a.ins_rear(3,1);
    //a.ins_rear(2,0);
    a.traverse();
    cout<<endl;
    b.ins_rear(10,3);
    //b.ins_rear(7,2);
    b.ins_rear(9,0);
    b.traverse();
    cout<<endl;
    c.add(a,b);
}

