#include <stdio.h>
#include <string.h>
int main()
{
   char a[100], b[100];
   int i, j;
   int m, n;
   printf("the text:\n");
   gets(a);
   printf("text to find:\n");
   gets(b);
   m = strlen(b);
   n = strlen(a);
   for (i = 0; i <= n - m; i++)
   {
      j = 0;
      while (m > j && b[j] == a[i + j])
      {
         j = j + 1;
      }
      if (j == m)
      {
         printf("substring is found at location :%d\n", i);
         break;
      }
   }
   if (j != m)
   {
      printf("substring is not found\n");
   }
   return 0;
}
