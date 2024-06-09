/* Alunos: Carlos Eduardo Nogueira Silva e Felipe Gomes da Silva
   Atividade Árvore AVL, balanceada, como tudo deve ser
*/

#include "AVL.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Tree *insertAVL(Tree *root, int key) {
  root = insert(root, key);
  if (root) {
    return updateFb(root);
  }
  return root;
}

Tree *insert(Tree *tree, int key) {
  if (!tree) {
    tree = malloc(sizeof(Tree));
    if (!tree)
      return NULL;
    tree->data.key = key;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
  }

  if (tree->data.key == key)
    return tree;
  if (tree->data.key > key)
    tree->left = insert(tree->left, key);
  if (tree->data.key < key)
    tree->right = insert(tree->right, key);

  return tree;
}

Tree *search(Tree *tree, int key) {
  if (tree == NULL)
    return tree;
  if (tree->data.key == key)
    return tree;
  if (tree->data.key > key)
    search(tree->left, key);
  if (tree->data.key < key)
    search(tree->right, key);
  return tree;
}

Tree *updateFb(Tree *tree) {
  if (tree == NULL)
    return NULL;
  if (tree->left != NULL)
    tree->left = updateFb(tree->left);
  if (tree->right != NULL)
    tree->right = updateFb(tree->right);

  tree->Fb = calculateFb(tree);

  if (tree && sqrt(tree->Fb * tree->Fb) >= 2)
    tree = rebalance(tree);
  return tree;
}

int calculateFb(Tree *tree) {
  if ((!tree->left && !tree->right))
    return 0;
  return height(tree->right) - height(tree->left);
}

Tree *rebalance(Tree *tree) {
  if (tree->Fb > 1) {
    if (tree->right->Fb < 0)
      return doubleRotateLeft(tree);
    return rotateLeft(tree);
  }
  if (tree->left->Fb > 0)
    return doubleRotateRight(tree);
  return rotateRight(tree);
}

Tree *doubleRotateRight(Tree *tree) {
  tree->left = rotateLeft(tree->left);
  return rotateRight(tree);
}

Tree *doubleRotateLeft(Tree *tree) {
  tree->right = rotateRight(tree->right);
  return rotateLeft(tree);
}

Tree *rotateLeft(Tree *tree) {
  printf("\nrotação a esquerda!\n");
  Tree *newNode = tree->right;
  tree->right = newNode->left;
  newNode->left = tree;
  return newNode;
}

Tree *rotateRight(Tree *tree) {
  printf("\nrotação a direita!z\n");
  Tree *newNode = tree->left;
  tree->left = newNode->right;
  newNode->right = tree;
  return newNode;
}

void preOrder(Tree *tree) {
  if (tree) {
    printf("chave: %d\n", tree->data.key);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

Tree *removeNode(Tree *root, int key) {
  Tree *removable = NULL;

  if (!root->left) {
    removable = root;
    root = root->right;
    free(removable);
    return root;
  }
  if (!root->right) {
    removable = root;
    root = root->left;
    free(removable);
    return root;
  }
  removable = findLowest(root->right);
  printf("removable: %d", removable->data.key);
  root->data = removable->data;
  root->right = searchRemove(root->right, removable->data.key);
  return root;
}

Tree *findLowest(Tree *tree) {
  if (tree->left)
    return findLowest(tree->left);
  return tree;
}

Tree *searchRemove(Tree *tree, int key) {
  if (tree == NULL)
    return NULL;
  if (tree->data.key == key) {
    printf("a");
    return removeNode(tree, key);
  }
  if (tree->data.key < key)
    tree->right = searchRemove(tree->right, key);
  if (tree->data.key > key)
    tree->left = searchRemove(tree->left, key);
  return tree;
}

int height(Tree *tree) {
  if (!tree)
    return 0;

  int heightLeft = height(tree->left);
  int heightRight = height(tree->right);

  if (heightLeft > heightRight)
    return heightLeft + 1;
  return heightRight + 1;
}
