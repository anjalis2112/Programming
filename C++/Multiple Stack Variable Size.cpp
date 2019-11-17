#include<iostream>
using namespace std;

class Stack
{
    public:
    int* arr;
    int* top;
    int* bot;
    int max_size;
    int noo;
    Stack()
    {   int no;

        cout<<"Enter number of stacks\n";
        cin>>no;
        noo=no;
        int s[no];
        int sum=0;
        for(int i=0;i<no;i++)
        {
            cout<<"Enter size of stack "<<i+1<<endl;
            cin>>s[i];
            sum+=s[i];
        }

        arr=new int[sum];
        top= new int[no];
        bot= new int[no];
        top[0]=-1;bot[0]=-1;
        for(int i=1;i<no;i++)
          {
              top[i]=top[i-1]+s[i-1];
              bot[i]=top[i];
          }

    }


    void push(int p)
    {
        cout<<"Enter stack no\n";
        int num;
        cin>>num;
        if(top[num-1]==bot[num])
            cout<<"Overflow\n";
        else
            arr[++top[num-1]]=p;


    }

    int pop()
    {
        cout<<"Enter stack no\n";
        int num;
        cin>>num;
        if(top[num-1]==bot[num-1])
            cout<<"Underflow\n";
        else
         return arr[top[num-1]--];
    }

    void display()
    {
        for(int i=0;i<noo;i++)
            {   cout<<"Stack no: "<<i+1<<endl;
                for(int j=bot[i]+1;j<=top[i];j++)
                {
                    cout<<arr[j]<<" ";
                }
                cout<<endl;
            }
    }
};

int main()
{   int num;
    Stack s;
    do
    {

        cout<<"\n1.Push\n2.Pop\n3.Display\n";
        cin>>num;
        switch(num)
        {
        case 1:
            cout<<"Enter ele";
            int ele;
            cin>>ele;
            s.push(ele);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        }

    }while(num!=4);
}
