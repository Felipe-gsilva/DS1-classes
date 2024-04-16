#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

int main(int argc, char *argv[]) {
  Node *node = malloc(sizeof(Node));
  fillNode(node, fillData(0));
  insertData(node, fillData(1));
  insertData(node, fillData(2));
  insertData(node, fillData(5));
  insertData(node, fillData(851));
  insertData(node, fillData(-21098));
  printf("Lowest = %d", (findLowest(node))->data.key); 
  printLesser(searchNode(node, fillData(5)));
  freeAll(node);
  free(node);
  return 0;
}

bool isEmpty(Node *node) {
   return (!node) ? true : false;
}

void insertData(Node *root, Data data) { // exercicio 12
  if(!isEmpty(root)) {
    if(root->data.key > data.key)
      insertData(root->right, data);
    if(root->data.key < data.key)
      insertData(root->left, data);
    if(root->data.key == data.key)
      return;
  }

  Node *newNode = malloc(sizeof(Node));
  fillNode(newNode, data);
  root = newNode;
  return;
}

Data fillData(int key) {
  Data data;
  data.key = key;
  return data;
}

void fillNode(Node *node, Data data) {
  node->data = data;
}

Node *searchNode(Node *root, Data data) { //exercicio 11
  if(!isEmpty(root)){
    if(root->data.key == data.key)
      return root;
    if(root->data.key > data.key)
      return searchNode(root->right, data);
    if(root->data.key < data.key)
      return searchNode(root->left, data);
  }
  return NULL;
}

bool leaf(Node *node) {
  return (isEmpty(node->right) && isEmpty(node->left)) ? true : false;
}

Node *findLowest(Node *root) { // exercicio 13
  if(!root->left)
    return root;
  return findLowest(root->left);
}

void printLesser(Node *root) {
  if(isEmpty(root->left))
     return;
  preOrder(root->left);
}

void visit(Node *node) {
  printf("%d", node->data.key);
}

void preOrder(Node *root) {
  if(!isEmpty(root)) {
    visit(root);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node *root) {
  if(!isEmpty(root)) {
    preOrder(root->left);
    visit(root);
    preOrder(root->right);
  }
}

void posOrder(Node *root) {
  if(!isEmpty(root)) {
    preOrder(root->left);
    preOrder(root->right);
    visit(root);
  }
}

void freeAll(Node *node) {
  if(isEmpty(node->left))
     free(node->left);
  if(isEmpty(node->right))
    free(node->right);
  freeAll(node->left);
  freeAll(node->right);
  free(node);
}

Node *searchRemove(Node *root, int key) {
  if(isEmpty(root))
    return NULL;
  if(root->data.key == key)
    root = removeNode(root, key); 
  if(root->data.key > key)
    root = searchRemove(root->left, key); 
  if(root->data.key < key)
    root = searchRemove(root->right, key); 
  return root;
}

Node *removeNode(Node *node, int key) {
  Node *rmNode;
  if(!node->left) {
    rmNode = node;
    node = node->right;
    free(rmNode);
  }
  else if(!node->right) {
    rmNode = node;
    node = node->left;
    free(rmNode);
  }
  else {
    rmNode = findLowest(node->right);
    node->data = rmNode->data;
    node->right = searchRemove(node->right, key);
  }
  return node;
}
