#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

int main(int argc, char *argv[])
{
  Node *root = createTree();
  root->data.id = 0;
  insertLeft(root, 1);
  insertRight(root, 5);
  insertLeft(root->left, -2);
  insertRight(root->left, -1);
  insertLeft(root->right, 100);
  insertRight(root->right,8539951);
  printTree(root);
  Node *nodão = biggestNode(root);
  printf("%d nodão", nodão->data.id);


  int contador = nNodes(root);
  printf("%d nodes", contador);

  printf("%d", full(root));
  free(root);
  return 0;
}

bool vazia(Node *root) {
  if(root == NULL)
    return true;
  return false;
}

Node *generateNullNode() {
  Node *newNode = malloc(sizeof(Node));
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

void freeNode(Node *node) {
  free(node);
}

Node *createTree() {

  Node *node = malloc(sizeof(Node));
  node->right = NULL;
  node->left = NULL;
  return node;
}

void fillNode(data data, Node *node) {
  node->data = data;
}
void insertRight(Node *node, int id) {
  if(vazia(node))
    return;
  if(node->right != NULL) 
    return;
  Node *newNode = generateNullNode();
  data data;
  data.id = id;
  fillNode(data, newNode);
  node->right = newNode;
}

void insertLeft(Node *node, int id) {
  if(vazia(node))
    return;
  if(node->left != NULL) 
    return;

  Node *newNode = generateNullNode();
  data data;
  data.id = id;
  fillNode(data, newNode);
  node->left = newNode;
}

void printTree(Node *node) {
  postOrder(node); 
}

void visit(Node *node) {
  printf("Valor: %d\n", node->data.id);
}

void display(Node *root, char *o) {
  if(strcmp(o, "pre")==0) 
    preOrder(root); 
  if(strcmp(o, "pos")==0)
    postOrder(root);
  if(strcmp(o, "in")==0)
    inOrder(root);
  return;
} 

void preOrder(Node *node) {
  if(!vazia(node)) {
    visit(node);
    preOrder(node->left);
    preOrder(node->right);
  }
}

void inOrder(Node *node) {
  if(!vazia(node)) {
    inOrder(node->left);
    visit(node);
    inOrder(node->right);
  }
}

void postOrder(Node *node) {
  if(!vazia(node)) {
    inOrder(node->left);
    inOrder(node->right);
    visit(node);
  }
}

Node *biggestNode(Node *node) {
  Node *nodão = generateNullNode();
  if(!vazia(node)) {
    if(vazia(nodão))
      nodão->data.id = -2147483647;
    if(node->data.id > nodão->data.id) 
      nodão = node;
    if(node->right != NULL)
      return biggestNode(node->right);
    if(node->left != NULL)
      return biggestNode(node->left);
  }
  return nodão; 
}

int nNodes(Node *node) {
  if (!vazia(node)) {
    return nNodes(node->left) + nNodes(node->right) + 1;
  }
  return 0;
}

bool full(Node *node) {
  if(vazia(node))
    return true;
  if(nNodes(node->left) != nNodes(node->right))
    return false;
  if(!node->left && !node->right)
    return true;
  if(full(node->left) && full(node->right))
    return true;
  return false;
}

int altura(Node *node) {
  if(vazia(node)) 
    return 0;

  int altE = altura(node->left);
  int altD = altura(node->right);

  if(altura(node->left) > altura(node->right))
    return altE + 1;
  return altD + 1;
}
