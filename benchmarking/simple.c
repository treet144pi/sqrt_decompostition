#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    long long total = 0;
    clock_t start = clock();
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        total += naive_query(a, l, r);
    }
    clock_t end = clock();

    printf("Naive sum total = %lld\n", total);
    printf("Time: %.3f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
    return 0;
}
