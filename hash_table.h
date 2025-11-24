#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct HT_Items {
    char *key;
    char *value;
    struct HT_Items *next;
} HT_Items;

typedef struct HashTable {
    size_t capacity;
    size_t size;
    HT_Items **items;
} HashTable;

HashTable *hash_table_create(size_t capacity);

void hash_table_insert(HashTable *ht, const char *key, const char *value); 

char *hash_table_get(HashTable *ht, const char *key);

void hash_table_delete(HashTable *ht, const char *key);

void hash_table_destroy(HashTable *ht);

#endif
