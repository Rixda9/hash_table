#include "hash_table.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SEED 5381UL

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

// private helper
static unsigned long hash_function(const char *str) {
  unsigned long hash = HASH_SEED;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

//
HashTable *hash_table_create(size_t capacity) {
  HashTable *ht = malloc(sizeof(HashTable));
  if (ht == NULL) {
    return NULL;
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

  unsigned long hash_value = hash_function(key);

  int index = hash_value % ht->capacity;

  HT_Items *new_item = malloc(sizeof(HT_Items));
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

  unsigned long hash_value = hash_function(key);

  int index = hash_value % ht->capacity;

  HT_Items *current = ht->items[index];

  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      // printf("Found: %s", current->value);
      return current->value;
    }
    current = current->next;
  }

  return NULL;
}

void hash_table_delete(HashTable *ht, const char *key) {}

void hash_table_destroy(HashTable *ht) {}
