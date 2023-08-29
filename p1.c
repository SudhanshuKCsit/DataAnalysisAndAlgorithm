#include <string.h>
#include <stdio.h>

int main()
{
    char a[100], b[100];
    int i, m, n, j;
    printf("text : \t");
    gets(a);
    printf("to find : \t");
    gets(b);
    m = strlen(b);
    n = strlen(a);
    for (i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < m && b[j] == a[i + j])
        {
            j = j + 1;
        }
        if (j == m)
        {
            printf("substring found at location %d \n", i + 1);
            break;
        }
    }
    if (j != m)
    {
        printf("substring is not found\n");
    }
    return 0;
}
