#include <stdio.h>
int quicksort(int num[25], int first, int last)
{
   int a, b, pivot, temp;
   if (first < last)
   {
      pivot = first;
      a = first;
      b = last;
      while (a < b)
      {
         while (num[a] <= num[pivot])
            a++;
         while (num[b] > num[pivot])
            b--;
         if (a < b)
         {
            temp = num[a];
            num[a] = num[b];
            num[b] = temp;
         }
      }
      temp = num[pivot];
      num[pivot] = num[b];
      num[b] = temp;
      quicksort(num, first, b - 1);
      quicksort(num, b + 1, last);
   }
}
int main()
{
   int a[20], count, i;
   printf("no of elements : \n");
   scanf("%d", &count);
   for (i = 0; i < count; i++)
      scanf("%d", &a[i]);
   quicksort(a, 0, count - 1);
   for (i = 0; i < count; i++)
      printf("%d ", a[i]);
}
