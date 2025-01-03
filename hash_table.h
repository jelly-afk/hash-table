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

ht_item *item_new(char *k, char *v);

void item_del(ht_item *i);

void ht_del(hash_table *table);
