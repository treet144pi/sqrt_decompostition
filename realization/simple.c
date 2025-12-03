#include <stdio.h>
#include <stdlib.h>

long long naive_query(int* a, int l, int r)
{
    long long sum = 0;
    for (int i = l; i < r; ++i)
        sum += a[i];
    return sum;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", naive_query(a, l, r));
    }

    free(a);
    return 0;
}
