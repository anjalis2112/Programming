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

    void ins_beg(int a)

    {
        node *temp=new node();
        temp->data=a;
        node *curr=head;
        if(head==NULL)
            {head=temp;
            return;}
        temp->next=head;
        head->prev=temp;
        head=temp;
    }



    void traverse()
    {
        node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data;
        curr=curr->next;
    }

    }




};


void add_long(long a, long b)
{
    node p,q;
    int c1=0;
    int c2=0;
    while(a!=0)
    {
        p.ins_beg(a%10);
        a=a/10;
        c1++;
    }


    while(b!=0)
    {
        q.ins_beg(b%10);
        b=b/10;
        c2++;
    }

    if(c1>c2)
    {
        while(c2!=c1)
            {q.ins_beg(0);
                c2++;}

    }

   if(c1<c2)
    {
        while(c2!=c1)
            {p.ins_beg(0);
                c1++;}

    }


    node c;
    node *curr1=p.head;
    node *curr2=q.head;
    while(curr1->next!=NULL)
        curr1=curr1->next;
    while(curr2->next!=NULL)
        curr2=curr2->next;
    int carry=0;
    while(curr1!=p.head||curr2!=q.head)
    {
        int temp=curr1->data+curr2->data+carry;
        if(temp>10)
        {
            c.ins_beg(temp-10);
            carry=1;
        }

        else
        {
             c.ins_beg(temp);
             carry=0;
        }

        curr1=curr1->prev;
        curr2=curr2->prev;
    }




    if(curr2==q.head&&curr1==p.head)
    {int temp=curr2->data+carry+curr1->data;
        c.ins_beg(temp);

    }

    c.traverse();

}

int main()
{
    node p;

    add_long(3445671,894);

}
