#include <stdio.h>
int i, adj[10][10], visit[10], n, top_order[10];
int dfs(int v)
{
   int w;
   visit[v] = 1;
   for (w = 1; w <= n; w++)
      if ((adj[v][w] == 1) && (visit[w] == 0))
         dfs(w);
   top_order[i--] = v;
}
int main()
{
   int w, v;
   printf("no of vertices:\n");
   scanf("%d", &n);
   for (v = 1; v <= n; v++)
      for (w = 1; w <= n; w++)
         scanf("%d", &adj[v][w]);
   for (v = 1; v <= n; v++)
   {
      visit[v] = 0;
   }
   i = n;
   for (v = 1; v <= n; v++)
   {
      if (visit[v] == 0)
         dfs(v);
   }
   printf("topological sorting:\n");
   for (v = 1; v <= n; v++)
   {
      printf("v%d ", top_order[v]);
   }
}