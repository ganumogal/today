import java.util.Scanner;
class Merge
{  static int b[]=new int [100];
static void merge(int arr[],int low,int high,int mid)
{  
   int i=low;
   int j=mid+1;
   int k=0;
   
   while(i<=mid && j<=high)
   {

     if(arr[i]>arr[j])
       {
        b[k]=arr[j];
        j++;
        k++;
       }    
       else
        {
         b[k]=arr[i];
         i++;
         k++;


       }

   }
  while(i<=mid)
    {
         b[k]=arr[i];
         i++;
         k++;

    }

  while(j<=high)
    {
         b[k]=arr[j];
         j++;
         k++;

    }
  int f=0;
  for(i=low;i<=high;i++)
   {
   arr[i]=b[f];
//System.out.println(arr[i]);
   f++;
   
   }


}
static void mergesort(int arr[],int low,int high)
{ int mid; 
  if(low<high)
   {
    mid=(low+high)/2;
   Merge.mergesort(arr,low,mid);
   
    Merge.mergesort(arr,mid+1,high);
    Merge.merge(arr,low,high,mid);
    
   }

}

   public static void main(String args[])
   {Scanner sc=new Scanner(System.in);
    int n;
   int i;
   System.out.println("enter no of array elements");
   n=sc.nextInt();
   int arr[]=new int[30];
   System.out.println("enter array elements");
   for(i=0;i<n;i++)
     {
 
      arr[i]=sc.nextInt();;
     }

    Merge.mergesort(arr,0,n-1);
    System.out.println("Sorted elements are");
    for(i=0;i<n;i++)
     {
 
      System.out.println(arr[i]);
     }


   }












}