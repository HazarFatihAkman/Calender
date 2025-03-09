#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cache_size;

typedef struct {
    int index;
    char *value; 
} Cache;

Cache **Caches;

void push_cache(Cache *c) {
    Caches = (Cache**)realloc(Caches, (cache_size+ 1) * sizeof(Cache));
    c->index = cache_size;
    Caches[cache_size] = c;
    cache_size++;
}

void delete_cache(Cache *c) {
    for (int i = 0; i < cache_size; i++) {
        if (c->index == i) {
            Caches[c->index] = NULL;
        }
        else {
            Caches[i] = Caches[i++];
        }
    }

    for (int i = 0; i < cache_size - 1; i++) {
        printf("%d | %d\n", i, Caches[i] == NULL);
    }
    //TODO : delete cache
    Caches = realloc(Caches, (cache_size - 1) * sizeof(Cache));
    cache_size--;
    free(c);
}

int main(void) {
    Caches = (Cache**)malloc(sizeof(Cache));
    Cache *cache_1 = (Cache*)malloc(sizeof(Cache));
    cache_1->value = "TEST";
    push_cache(cache_1);

    Cache *cache_2 = (Cache*)malloc(sizeof(Cache));
    cache_2->value = "TEST 2";
    push_cache(cache_2);

    // for (int i = 0; i < 2; i++) {
    //     printf("%s | %d\n", Caches[i]->value, Caches[i]->index);
    // }

    delete_cache(cache_1);
    // for (int i = 0; i < cache_size; i++) {
    //     printf("%s | %d\n", Caches[i]->value, Caches[i]->index);
    // }

    return 1;
}
