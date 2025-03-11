#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cache_size;

typedef struct {
    int index, expire;
    char *value;
} Cache;

typedef struct {
    char *namespace;
    Cache **Caches;
} Cache_List;

Cache **Caches;

void push_cache(Cache *c) {
    Caches = (Cache**)realloc(Caches, (cache_size+ 1) * sizeof(Cache));
    c->index = cache_size;
    printf("push_cache = %d\n", c->index);
    Caches[cache_size] = c;
    cache_size++;
}

void delete_cache(Cache *c) {
    for (int i = 0; i < cache_size; i++) {
        if (i >= c->index && i < cache_size - 1) {
            Caches[i] = Caches[i+1];
            Caches[i]->index = i;
        }

        if (i == (cache_size - 1)) {
            Caches[i] = NULL;
        }
    }

    cache_size--;
    Caches = realloc(Caches, cache_size * sizeof(Cache));
    free(c);
}

int main(void) {
    Caches = (Cache**)calloc(sizeof(Cache), cache_size);
    Cache *cache_1 = (Cache*)malloc(sizeof(Cache));
    cache_1->value = "TEST 1";
    push_cache(cache_1);

    Cache *cache_2 = (Cache*)malloc(sizeof(Cache));
    cache_2->value = "TEST 2";
    push_cache(cache_2);

    Cache *cache_3 = (Cache*)malloc(sizeof(Cache));
    cache_3->value = "TEST 3";
    push_cache(cache_3);

    printf("Print Caches \nValue | Index\n");
    for (int i = 0; i < cache_size; i++) {
        printf("%s | %d\n", Caches[i]->value, Caches[i]->index);
    }

    delete_cache(cache_3);
    printf("Delete Caches \nValue | Index\n");
    for (int i = 0; i < cache_size; i++) {
        printf("%s | %d\n", Caches[i]->value, Caches[i]->index);
    }

    return 1;
}
