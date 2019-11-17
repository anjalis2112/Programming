#include<iostream>
using namespace std;

class node
{   public:
    node *lc, *rc;
    int data;

    node()
    {
        lc=NULL;
        rc=NULL;
    }

   node* ins(node* root, int key)
{
    node *temp= new node();
    temp->data=key;

    if (root == NULL)
    {
        return temp;
    }

    if (key < root->data)
        root->lc  = ins(root->lc, key);
    else if (key > root->data)
        root->rc = ins(root->rc, key);


    return root;
}
    void inorder(node *root)
    {
        if(root==NULL)
            return;

        inorder(root->lc);
        cout<<root->data<<" ";
        inorder(root->rc);


    }

    node* minim(node *root)
    {
        node *curr=root;
        while(curr->lc!=NULL)
            curr=curr->lc;
        return curr;
    }

    node* del(node *root, int a)
    {
        if(root==NULL)
            return root;
        if(a<root->data)
            root->lc=del(root->lc,a);
        else if(a>root->data)
            root->rc=del(root->rc,a);

        else
        {
            if(root->lc&&!root->rc)
            {
                node *temp=root->lc;
                delete(root);
                return temp;

            }

            else if(!root->lc&&root->rc)
            {
                node *temp=root->rc;
                delete(root);
                return temp;
            }


            else
            {
                node *temp= minim(root->rc);
                root->data=temp->data;
                root->rc=del(root->rc,a);
            }
        }

    }
};


int main()
{
    node p;
    node *root=NULL;
    int a,ele;
    do
    {cin>>a;
    cout<<"ele";
    cin>>ele;
    root=p.ins(root,ele);}while(a!=2);

    p.inorder(root);
    p.del(root,25);
    cout<<endl;
    p.inorder(root);


}
