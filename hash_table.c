#include "hash_table.h"
#include <string.h>
#include <stdlib.h>


typedef struct HT_Items {

  char *key;
  char *value;
  struct HT_Items *next;

} HT_Items ;

typedef struct HashTable {
  
  int capacity;
  int size; 
  HT_Items **items;

} HashTable;




HashTable* hash_table_create(size_t capacity)
{
  HashTable *ht = malloc(sizeof(HashTable));
  if (ht == NULL) 
  {
    return  NULL;
  }
  ht->capacity = capacity;
  ht->size = 0;

  ht->items = calloc(capacity, sizeof(HT_Items *));
  if (ht->items == NULL) 
  {
    free(ht);
    return NULL;
  }
  return ht;
}

void hash_table_insert(HashTable *ht, const char *key, const char *value)
{
  for (int i = 0; i < strlen(key); i++) {

  }
}

char *hash_table_get(HashTable *ht, const char *key)
{

}
void hash_table_delete(HashTable *ht, const char *key){

}

void hash_table_destroy(HashTable *ht)
{

}
