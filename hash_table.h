#ifdef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct HashTable HashTable;


HashTable* hash_table_create(size_t capacity);
void hash_table_insert(HashTable *ht, const char *key, const char *value);
char *hash_table_get(HashTable *ht, const char *key);
void hash_table_delete(HashTable *ht, const char *key);
void hash_table_destroy(HashTable *ht);

#endif
