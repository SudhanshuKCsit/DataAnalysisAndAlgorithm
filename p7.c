#include <stdio.h>
#include <omp.h>
#define A 999
int min(int i, int j)
{
   return i < j ? i : j;
}
int floyd(int n, int p[10][10])
{
   int i, j, k;
#pragma omp parallel for private(i, j, k) shared(p)
   for (k = 1; k <= n; k++)
      for (i = 1; i <= n; i++)
         for (j = 1; j <= n; j++)
            p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int main()
{
   int a[10][10], d[10][10], i, j, n;
   double start_time, end_time;
   printf("no of nodes:\n");
   scanf("%d", &n);
   printf("adjacency matrix:\n");
   for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
         scanf("%d", &a[i][j]);
   start_time = omp_get_wtime();
   floyd(n, a);
   end_time = omp_get_wtime();
   printf("distance matrix:\n");
   for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
         printf("%d\t", a[i][j]);
   printf("\n");
   printf("time taken is :%10.9f\n", (double)(start_time - end_time));
   return 0;
}