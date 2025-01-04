#pragma once
#include <stdlib.h>

typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int length;
  ht_item **items;
} hash_table;

hash_table *ht_new();

ht_item *item_new(const char *k, const char *v);

void item_del(ht_item *i);

void ht_del(hash_table *table);

void ht_insert(hash_table *ht, const char *key, const char *value);
char *ht_search(hash_table *ht, const char *key);
void ht_delete(hash_table *h, const char *key);
