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




HashTable* hash_table_create(size_t capacity) {
  HashTable *ht = malloc(sizeof(HashTable));
  if (ht == NULL) {
    return  NULL;
  }
  ht->capacity = capacity;
  ht->size = 0;

  ht->items = calloc(capacity, sizeof(HT_Items *));
  if (ht->items == NULL) {
    free(ht);
    return NULL;
  }
  return ht;
}

void hash_table_insert(HashTable *ht, const char *key, const char *value) {
  unsigned long hash_value = 5381;

  // create a variable so strlen doesnt have to iterate everyloop
  size_t len = strlen[key];
  for (int i = 0; i < len; i++) {
    hash_value = (hash_value << 5) + hash_value;
    hash_value += key[i];
  }
  int index = hash_value % ht->capacity;

  // need to improve this part later {
  HT_Items *new_item = malloc(sizeof(HT_Items);
  if (new_item == NULL) {
    return NULL;
  }

  new_item->key = malloc(strlen(key) + 1);
  if (new_item->key == NULL) {
    free(new_item); 
    return NULL;
  }
  strcpy(new_item->key, key);

  new_item->value = malloc(strlen(value) + 1);
  if (new_item->value == NULL) {
    free(new_item->key);
    free(new_item);
    return NULL;
  }
  strcpy(new_item->value, value);
  
  new_item->next = ht->items[index];

  ht->items[index] = new_item;

  ht->size++;
  // }
}

char *hash_table_get(HashTable *ht, const char *key) {

}
void hash_table_delete(HashTable *ht, const char *key) {

}

void hash_table_destroy(HashTable *ht) {

}
