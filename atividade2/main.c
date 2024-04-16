#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argv, char *argv[]) {
  return 0;
}

Tree *search(Tree *tree, int key) {
  if(tree == NULL)
    return tree;
  if(tree->data.key == key)
    return tree;
  if(tree->data.key > key)
    search(tree->left, key);
  if(tree->data.key < key)
    search(tree->right, key);
  return tree;
}

void insert(Tree *tree, int key) {
  if(tree != NULL) {
    if(tree->data.key > key) 
      insert(tree->left, key);
    if(tree->data.key < key)
      insert(tree->right, key);
    if(tree->data.key == key)
      return;

    Tree *newNode = malloc(sizeof(Tree));
    newNode->data.key = key;
    newNode->right = NULL;
    newNode->left = NULL;
    tree = newNode;
  }
}

void inOrder(Tree *tree) {
  if(tree) {
    inOrder(tree->left);
    printf("chave %d:", tree->data.key);
    inOrder(tree->right); 
  }
}

Tree *removeNode(Tree *root, int key) {
  Tree *removable;
  if(!root->left) {
    removable = root; 
    root = root->right;
    free(removable);
  }

  if(!root->right) {
    removable = root; 
    root = root->left;
    free(removable);
  }
  
  removable = findLowest(root->right);
  root->data = removable->data;
  root->right = searchRemove(root->right, removable->data.key); 
  return root;
}

int calculaFb(Tree *tree) {
  return height(tree->left) - height(tree->right);
}

void define(Tree *tree) {
  tree = NULL; 
}

Tree *findLowest(Tree *tree) {
  if(tree->left)
    return findLowest(tree->left);
  return tree;
}

Tree *searchRemove(Tree *tree, int key) {
  if(!tree) 
    return NULL;
  if(tree->data.key == key) 
    return tree;
  if(tree->data.key < key)
    searchRemove(tree->right, key);
  if(tree->data.key > key) 
    searchRemove(tree->left, key);
  return tree;
}
