#include <stdio.h>
#include <api/malloc.h>
#include <lib/ff_simple.h>
#include <../kernel/memory.h>

void demo()
{
 

    if (!k_mpool)
    {
        printf("Error: ne postoji k_mpool\n");
    }

    void *a[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = ffs_alloc(k_mpool, 100);

        if (!a[i])
        {
            printf("Error: Ne mogu alocirati blok %d\n", i + 1);
        }
    }
    for (int j = 0; j < 4; j++)
    {
        ffs_free(k_mpool, a[j]);
    }

    a[3] = ffs_alloc(k_mpool, 1100);
    if (!a[0])
    {
        printf("Error: Ne mogu alocirati blok 1\n");
    }

    for (int k = 3; k < 5; k++)
    {
        ffs_free(k_mpool, a[k]);
    }
}