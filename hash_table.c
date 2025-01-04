#include "hash_table.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int PRIME_A = 157;
int PRIME_B = 199;

hash_table *ht_new() {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->size = 50;
  ht->length = 0;
  ht->items = calloc(ht->size, sizeof(ht_item *));
  return ht;
}

ht_item *item_new(const char *k, const char *v) {
  ht_item *i;
  i->key = strdup(k);
  i->value = strdup(v);
  return i;
}

void item_del(ht_item *i) {
  free(i->key);
  free(i->value);
  free(i);
}

void ht_del(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    ht_item *item = table->items[i];
    if (item != NULL) {
      item_del(item);
    }
  }
  free(table->items);
  free(table);
}

int hash_str(const char *s, int a, int m) {
  long hash = 0;
  int st_len = strlen(s);
  for (int i = 0; i < st_len; i++) {
    hash += (long)pow(a, st_len - (i + 1)) * s[i];
    hash = hash % m;
  }
  return hash;
}

int get_hash(const char *s, int range, int attempt) {
  const int hash_a = hash_str(s, PRIME_A, range);
  const int hash_b = hash_str(s, PRIME_B, range);
  return (hash_a + (attempt * (hash_b + 1))) % range;
}

void ht_insert(hash_table *ht, const char *key, const char *value) {
  if (ht->length >= ht->size) {
    return;
  }
  int idx = -1;
  int i = 0;
  while (!(idx > 0 && ht->items[idx] != NULL)) {
    idx = get_hash(key, ht->size, i);
    i++;
  }
  ht->items[idx] = item_new(key, value);
}
