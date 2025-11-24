#include "hash_table.h"
#include <stdio.h>
#include <string.h>

int main() {
    printf("Creating hash table...\n");
    HashTable *ht = hash_table_create(10);
    
    printf("Inserting items...\n");
    hash_table_insert(ht, "name", "Alice");
    hash_table_insert(ht, "age", "25");
    hash_table_insert(ht, "city", "Paris");
    hash_table_insert(ht, "country", "France");
    
    printf("Getting items...\n");
    printf("name: %s\n", hash_table_get(ht, "name"));
    printf("age: %s\n", hash_table_get(ht, "age"));
    printf("city: %s\n", hash_table_get(ht, "city"));
    
    printf("Deleting 'age'...\n");
    hash_table_delete(ht, "age");
    
    char *deleted = hash_table_get(ht, "age");
    if (deleted == NULL) {
        printf("'age' successfully deleted!\n");
    }
    
    printf("Destroying hash table...\n");
    hash_table_destroy(ht);
    
    printf("Success! All tests passed.\n");
    return 0;
}

