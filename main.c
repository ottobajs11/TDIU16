#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, char const *argv[]) {
  struct map container;
  map* container_addr = &container;
  map_init(container_addr);

  char c = 'k';
  char* k = &c;

  // map_insert(container_addr, k);
  //
  // char* result = map_find(container_addr,0);
  // if(result != NULL){
  //   printf("%c\n", *result);
  // }
  // else{
  //   printf("%s\n", "No value found for that key");
  // }

  for(int i = 0; i< MAP_SIZE; i++){
    map_insert(container_addr, k);
  }

  map_for_each(container_addr,&exec_test, 1);
  map_remove_if(container_addr, &condition,0);
  printf("%s\n", "--------------------------");
  map_for_each(container_addr,&exec_test, 1);



  return 0;
}
