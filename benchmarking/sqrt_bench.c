#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long sqrt_query(int* a, int* blocks, int l, int r, int block_size)
{
    long long sum = 0;
    while (l < r && l % block_size != 0)
        sum += a[l++];
    while (l + block_size <= r) {
        sum += blocks[l / block_size];
        l += block_size;
    }
    while (l < r)
        sum += a[l++];
    return sum;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int block_size = (int)sqrt(n);
    int block_count = (n + block_size - 1) / block_size;
    int* blocks = calloc(block_count, sizeof(int));
    for (int i = 0; i < n; ++i)
        blocks[i / block_size] += a[i];

    long long total = 0;
    clock_t start = clock();
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        total += sqrt_query(a, blocks, l, r, block_size);
    }
    clock_t end = clock();

    printf("Sqrt sum total = %lld\n", total);
    printf("Time: %.3f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
    free(blocks);
    return 0;
}
