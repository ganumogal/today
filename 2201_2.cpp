#include<iostream>
using namespace std;
int main()
{ cout<<"***************************************************Practical-2 (DSAL)- Flight graph using adjacency matrix******************************************"<<endl;
  cout<<"There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the diatance between  city B and city A. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency matrix representation of the graph. Check whether the graph is connected or not. Justify the storage representation used."<<endl<<endl;
 int n;
 cout<<"Enter no of city";   //here we take no of citie's from user
 cin>>n;   
 string name[5];             //we declare one string array to store the name of city.
 
 
 for(int i=0;i<n;i++)    //for loop to take city names
    {
      
     
cin>>name[i];

    }
    
int graph[10][10];     //here we declare two dimenstional matrix to represent the matrix
for(int i=0;i<n;i++)
   {
   
      for(int j=0;j<n;j++)
         {  char ch;
            if(i==j || j>i)
            {
            cout<<"Is there is realation between "<<name[i]<<"  &"<<name[j]; 
            cin>>ch;
            if(ch=='Y')
            {
              cout<<"Enter distance between that city";
              cin>>graph[i][j];
              graph[j][i]=graph[i][j];
            
            }
            else
            {
            
              graph[i][j]=0;
              
            }
         }
          
         }
    
}


cout<<endl<<endl;
cout<<"Graph reprsentation using adjacency matrix "<<endl<<endl<<endl;

for(int i=0;i<n;i++)
    {
      
     
    if(i==0)
    cout<<"        "<<name[i];
    else
    {
    
    cout<<"    "<<name[i];
    }    

    }"
cout<<endl;
for(int i=0;i<n;i++)
{   cout<<name[i];
    for(int j=0;j<n;j++)
        {
        
         cout<<"      "<<graph[i][j];
        
        
        }
        cout<<endl;
   


}

return 0;
}
