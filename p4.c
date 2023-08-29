#include <stdio.h>
#define A 999
int prim(int cost[10][10], int source, int n)
{
   int m, u, v;
   int vertex[10], distance[10], visited[10];
   int i, j, sum = 0;
   for (i = 1; i <= n; i++)
   {
      vertex[i] = source;
      visited[i] = 0;
      distance[i] = cost[source][i];
   }
   visited[source] = 1;
   for (i = 1; i < n; i++)
   {
      m = A;
      for (j = 1; j <= n; j++)
      {
         if (!visited[j] && distance[j] < m)
         {
            m = distance[j];
            u = j;
         }
      }
      visited[u] = 1;
      sum = sum + distance[u];
      printf("\n%d->%d\n", vertex[u], u);
      for (v = 1; v <= n; v++)
      {
         if (!visited[v] && cost[u][v] < distance[v])
         {
            distance[v] = cost[u][v];
            vertex[v] = u;
         }
      }
   }
   return sum;
}
int main()
{
   int n, i, j, source, m, a[10][10];
   printf("no of vertex:\n");
   scanf("%d", &n);
   for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
         scanf("%d", &a[i][j]);
   printf("arbitary vertex is:\n");
   scanf("%d", &source);
   m = prim(a, source, n);
   printf("cost of minimum spanning tree is:%d\n", m);
}