#include<iostream>
using namespace std;
int a, g[10][10]={0},n,visited[10];
void dfs(int a)    // Here we use recursion traverse the adjacency matrix.Recursion uses stack data structures
{
   visited[a]=1;   
   cout<<a<<"  ";
    for(int i=0;i<n;i++){
      if(!visited[i] && g[a][i]==1){
     dfs(i);
          }
    }
}
int main()
{ cout<<" ***************** Practical1 (DSAL)- Graph DFS & BFS  ******************"<<endl<<endl;
  cout<<"Represent a given graph using adjacency matrix to perform DFS  Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS "<<endl<<endl;
cout<<"enter how many vertices in graph"<<endl;   //here we take no of vertex in graph

cin>>n;

for(int i=0;i<n;i++)
{
      visited[i]=0;
}
cout<<" Enter adjacency matrix "<<endl;   //Here we take adjacency matrix from user
for(int i=0;i<n;i++)
{

   for(int j=0;j<n;j++)
        {
        
        
         cin>>g[i][j];
        
        
        }

}
cout<<"Graph in adjancery matrix form"<<endl;

for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
         {
        cout<<g[i][j]<<"     ";

         }
cout<<endl;

   }
cout<<" Graph travseral by depth first search is"<<endl;
dfs(0);     //function call to depth first search 
return 0;

}
