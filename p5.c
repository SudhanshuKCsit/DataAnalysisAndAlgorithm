#include <stdio.h>
#define A 999
int dijkstra(int cost[10][10], int source, int n, int distance[10])
{
   int visited[10];
   int min, i, j, u;
   for (i = 1; i <= n; i++)
   {
      visited[i] = 0;
      distance[i] = cost[source][i];
   }
   visited[source] = 1;
   for (i = 1; i <= n; i++)
   {
      min = A;
      for (j = 1; j <= n; j++)
      {
         if (visited[j] == 0 && distance[j] < min)
         {
            min = distance[j];
            u = j;
         }
      }
      visited[u] = 1;
      for (j = 1; j <= n; j++)
      {
         if (visited[j] == 0 && (distance[u] + cost[u][j]) < distance[j])
         {
            distance[j] = distance[u] + cost[u][j];
         }
      }
   }
}
int main()
{
   int a[10][10], n, source, distance[10], i, j;
   printf("no of vertex:\n");
   scanf("%d", &n);
   for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
         scanf("%d", &a[i][j]);
   printf("source node is :\n");
   scanf("%d", &source);
   dijkstra(a, source, n, distance);
   for (i = 1; i <= n; i++)
   {
      printf("Shortest distance from %d to %d is : %d", source, i, distance[i]);
   }
}