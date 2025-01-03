#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int length;
  ht_item **items;
} hash_table;

hash_table *ht_new() {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->size = 50;
  ht->length = 0;
  ht->items = calloc(ht->size, sizeof(ht_item *));
  return ht;
}

ht_item *item_new(char *k, char *v) {
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
