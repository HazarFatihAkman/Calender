// #include "../include/cache.h"

// int run_cache_test(void) {
//     c_lists = (Cache_List**)malloc(sizeof(Cache_List));
//     char *t_c_namespace = "test.c_namespace";
//     char *t_c_namespace2 = "test.c_namespace.2";

//     Cache *c_1 = (Cache *)malloc(sizeof(Cache));
//     c_1->value = "c_1 Test 1";
//     push_cache(t_c_namespace, c_1);

//     Cache *c_2 = (Cache *)malloc(sizeof(Cache));
//     c_2->value = "c_2 Test 2";
//     push_cache(t_c_namespace, c_2);

//     Cache *c_3 = (Cache *)malloc(sizeof(Cache));
//     c_3->value = "c_3 Test 3";
//     push_cache(t_c_namespace, c_3);

//     Cache *c_1_1 = (Cache *)malloc(sizeof(Cache));
//     c_1_1->value = "c_1_1 Test 1";
//     push_cache(t_c_namespace2, c_1_1);

//     Cache *c_1_2 = (Cache *)malloc(sizeof(Cache));
//     c_1_2->value = "c_1_2 Test 2";
//     push_cache(t_c_namespace2, c_1_2);

//     Cache *c_1_3 = (Cache *)malloc(sizeof(Cache));
//     c_1_3->value = "c_1_3 Test 3";
//     push_cache(t_c_namespace2, c_1_3);

//     printf("Print Cache_List\n");
//     for (int i = 0; i < c_lists_size; i++) {
//         printf("c_namespace : %s \n", c_lists[i]->c_namespace);
        
//         for (int j = 0; j < c_lists[i]->size; j++) {
//             printf("Value : %s\n", c_lists[i]->Caches[j]->value);
//         }
//     }

//     delete_cache(t_c_namespace2, c_1_2);
//     delete_cache(t_c_namespace, c_3);
//     printf("\nDeleted Cache_List\n");
//     for (int i = 0; i < c_lists_size; i++) {
//         printf("c_namespace : %s \n", c_lists[i]->c_namespace);
        
//         for (int j = 0; j < c_lists[i]->size; j++) {
//             printf("Value : %s\n", c_lists[i]->Caches[j]->value);
//         }
//     }

//     Cache_List *c_test_list = fetch_caches(t_c_namespace2);
//     for (int i = 0; i < c_test_list->size; i++) {
//             printf("c_namespace : %s | Value : %s\n", c_test_list->c_namespace, c_test_list->Caches[i]->value);
//     }

//     return 1;
// }
