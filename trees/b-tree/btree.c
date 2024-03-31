#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"


bool isEmpty(Node *node) {
  if(!node->left && !node->right)
    return true;
  return false;
}

Node *searchPosition(Node *root, int key) {
  if(!isEmpty(root)) {
    if(root->data.key > key)
      return searchPosition(root->left, key);
    if (root->data.key < key)
      return searchPosition(root->right, key);
    return NULL;
  } 
  return root;
}

Node *setNewNode(Data data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insertData(Node *root, Data data) {
  Node *newNode = setNewNode(data);
  if(newNode)
    newNode = searchPosition(root, newNode->data.key);
}

void printNode(Node *root);

int *getAllKeys(Node *root, tipoP v) {
  int coiso[20] = {0};

  return coiso;
}



void removeNode(Node *root, int key);

