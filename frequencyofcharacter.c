#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
 {

   char *s;
    char f[10]={'o','1','2','3','4','5','6','7','8','9'};
    s = malloc(10 * sizeof(char));
    scanf("%[^\n]", s);
   for(int i=0;i<10;i++)
         {  int count=0;
           for(int j=0;j<10;j++)
            {  if(*(s+i)<60 )
               {
               if(f[i]==*(s+j))
                  count++;
                }
              
            }
            

            printf("%d ",count);

         }
    return 0;
}