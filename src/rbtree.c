#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *t = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t * nil = (node_t *)calloc(1,sizeof(rbtree));
  nil -> color = RBTREE_BLACK;
  t->root = t->nil = nil;
  return t;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  node_t *node = t->root;
  if (node != t->nil){
    recur_delete(t, node);
  }
  free(t -> nil);
  free(t);
}

void recur_delete(rbtree *t, node_t *node){
  if(node -> left != t->nil){
    recur_delete(t,node->left);
  }
  if(node -> right != t->nil){
    recur_delete(t,node->right);
  }
  free(node);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *new_node = (node_t *)calloc(1,sizeof(rbtree));
  new_node -> key = key;
  new_node -> color = RBTREE_RED;
  new_node -> left = t->nil;
  new_node -> right = t->nil;
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t *node = t->root;
  while ((node != t->nil) && (node->key != key))
  {
    if (key < node->key){
      node = node->left;
    }else{
      node = node->right;
    }
  }
  return node;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t *node = t->root;
  while (node != t->nil)
  {
    node = node->left;
  }
  return node;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t *node = t->root;
  while (node != t->nil)
  {
    node = node->right;
  }
  return node;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
