#include<iostream>
using namespace std;
#define size 10
class tree 
{
    public:
    int p[size];
    int q[size];
    int arr[size];
    int n;
    int c[size][size];
    int w[size][size];
    int r[size][size];
    void getdata();
    void obst();
    int minimum(int i,int j);
    void display();
};
void tree::getdata()
{
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter value of node: \n";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter probability of successful search: \n";
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    cout<<"Enter probability of unsuccessful search: \n";
    for(int i=0;i<=n;i++)
    {
        cin>>q[i];
    }
}
int tree::minimum(int i,int j)
{
    int min=1000;
    int a; 
    for(int k=i+1;k<=j;k++)
    {
        c[i][j]=c[i][k-1]+c[k][j];
        if(c[i][j] < min)
        {
            min=c[i][j];
            a=k;
        }
    }
    return a;  
}
void tree::obst()
{
    w[n][n]=q[n];
    r[n][n]=c[n][n]=0;
    cout<<"cost,weight and root for last value: "<<endl;
    cout<<endl;
    cout<<"c["<<n<<"]"<<"["<<n<<"]"<<c[n][n]<<endl;
    cout<<"w["<<n<<"]"<<"["<<n<<"]"<<w[n][n]<<endl;
    cout<<"r["<<n<<"]"<<"["<<n<<"]"<<r[n][n]<<endl;
    for(int i=0;i<n;i++)
    {
        c[i][i]=0;
        w[i][i]=q[i];
        r[i][i]=0;
        cout<<"cost,weight and root when differance is 0: "<<endl;
        cout<<endl;
        cout<<"c["<<i<<"]"<<"["<<i<<"]"<<c[i][i]<<endl;
        cout<<"w["<<i<<"]"<<"["<<i<<"]"<<w[i][i]<<endl;
        cout<<"r["<<i<<"]"<<"["<<i<<"]"<<r[i][i]<<endl;
        
        
       /* // w[i][i+1]=q[i]+q[i+1]+p[i+1];
        w[i][i+1]=w[i][i]+p[i+1]+q[i+1];
        // cout<<"\n"<<w[i][i+1];

        r[i][i+1]=i+1;
        // c[i][i+1]=q[i]+q[i+1]+p[i+1];
        c[i][i+1]=w[i][i+1]+c[i][i]+c[i+1][i+1];
        cout<<endl;

        cout<<"cost,weight and root when differance is 1: "<<endl;
        cout<<endl;
        cout<<"c["<<i<<"]"<<"["<<i+1<<"]"<<c[i][i+1]<<endl;
        cout<<"w["<<i<<"]"<<"["<<i+1<<"]"<<w[i][i+1]<<endl;
        cout<<"r["<<i<<"]"<<"["<<i+1<<"]"<<r[i][i+1]<<endl;
        cout<<endl;*/

    }
    for(int i=0;i<n;i++)
    {
         w[i][i+1]=w[i][i]+p[i+1]+q[i+1];
        // cout<<"\n"<<w[i][i+1];

        r[i][i+1]=i+1;
        // c[i][i+1]=q[i]+q[i+1]+p[i+1];
        c[i][i+1]=w[i][i+1]+c[i][i]+c[i+1][i+1];
        cout<<endl;

        cout<<"cost,weight and root when differance is 1: "<<endl;
        cout<<endl;
        cout<<"c["<<i<<"]"<<"["<<i+1<<"]"<<c[i][i+1]<<endl;
        cout<<"w["<<i<<"]"<<"["<<i+1<<"]"<<w[i][i+1]<<endl;
        cout<<"r["<<i<<"]"<<"["<<i+1<<"]"<<r[i][i+1]<<endl;
        cout<<endl;

    }
    for(int m=2;m<=n;m++)
    {
        // cout<<"enter in m loop for m= "<<m<<endl;;
        for(int i=0;i<=n-m;i++)
        {
            // cout<<"enter in i loop for i= "<<i<<endl;
            int j=i+m;
            // cout<<j<<endl;
            int k;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            // cout<<w[i][j];
            k=minimum(i,j);
            // cout<<"got k";
            c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
            r[i][j]=k;
            cout<<"c["<<i<<"]"<<"["<<j<<"]"<<c[i][j]<<endl;
            cout<<"w["<<i<<"]"<<"["<<j<<"]"<<w[i][j]<<endl;
            cout<<"r["<<i<<"]"<<"["<<j<<"]"<<r[i][j]<<endl;
            cout<<endl;
        }
    }
}
void tree::display()
{
    int queue[20],front=-1,rear=-1;
    cout<<"The optimal binary srearch tree: "<<endl;
    cout<<"\nThe root of OBST is: "<<r[0][n];
    cout<<"\nThe cost of OBST is: "<<c[0][n];
    cout<<"\n\n\tNODE\t LEFT CHILD \t Right CHILD ";
    cout<<"\n";
    queue[++rear]=0;
    queue[++rear]=n;
    while(front!=rear)
    {
        int i=queue[++front];
        int j=queue[++front];
        int k=r[i][j];
        cout<<"\n\t"<<k;
        if((r[i][k-1]!=0))
        {
            cout<<"\t\t"<<r[i][k-1];
            queue[++rear]=i;
            queue[++rear]=k-1;
        }
        else
            cout<<"\t\t";
        if(r[k][j]!=0)
            {
                cout<<"\t\t"<<r[k][j];
                queue[++rear]=k;
                queue[++rear]=j;
            }
    } 
}
int main()
{
    tree t;
     t.getdata();
    
    t.obst();

    t.display();
}
