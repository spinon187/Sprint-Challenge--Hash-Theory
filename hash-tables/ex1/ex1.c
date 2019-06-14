#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  int key1 = -1;
  int key2 = -1;
  for(int i = 0; i < length; i++){
    if(hash_table_retrieve(ht, limit - weights[i]) != -1){
      key1 = i;
      key2 = hash_table_retrieve(ht, limit - weights[i]);
    }
    else {
      hash_table_insert(ht, weights[i], i);    
    }
  }
  destroy_hash_table(ht);
  if(key1 == -1 && key2 == -1){
    return NULL;
  }
  Answer *ans = malloc(sizeof(Answer));
  if(key1 > key2){
    ans->index_1 = key1;
    ans->index_2 = key2;
  }
  else{
    ans->index_1 = key2;
    ans->index_2 = key1;
  }
  return ans;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}

#endif
