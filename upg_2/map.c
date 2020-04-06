#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void map_init(struct map* m){
  for(int i = 0; i < MAP_SIZE; i++){
   m->content[i] = NULL;
  }
}

key_t map_insert(struct map* m, value_t v){
  for(int i = 0; i < MAP_SIZE; i++){
    if(m->content[i] == NULL){
      m->content[i] = v;
      return i;
    }
  }
  return -1;
}

value_t map_find(struct map* m, key_t k){
  return m->content[k];
}

value_t map_remove(struct map* m, key_t k){
  value_t buffer = m->content[k];
  m->content[k] = NULL;
  return buffer;
}
void map_for_each(struct map* m, void (*exec)(key_t k, value_t v, int aux), int aux){
  for(int i = 0; i< MAP_SIZE; i++){
    if(m->content[i] != NULL){
      exec(i,m->content[i],aux);
    }
    else{
      continue;
    }
  }
}

void map_remove_if(struct map* m, bool (*cond)(key_t k, value_t v, int aux), int aux){
  for(int i = 0; i< MAP_SIZE; i++){
    if(m->content[i] != NULL){
      if(cond(i,m->content[i],aux)){
        map_remove(m,i);
      }
    }
    else{
      continue;
    }
  }
}

bool condition(key_t k, value_t v, int aux){
  if(aux > 0){
    return k > 10;
  }
  else{
    return *v = 'k';
  }
}
void exec_test(key_t k, value_t v, int aux){
  if(aux > 0){
    printf("%i", k);
    printf("%*c\n", 10, *v);
  }
  else{
    printf("%i\n", k);
    printf("%c\n", *v);
  }
}
