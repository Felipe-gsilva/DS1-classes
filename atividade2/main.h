typedef struct data {
  int key;
} Data;

typedef struct tree {
  struct tree *right, *left;
  Data data;
  int Fb;
} Tree;

int main(int argc, char *argv[]);

Tree *search(Tree *tree, int key);  

void insert(Tree *tree, int key);

Tree *removeNode(Tree *root, int key);

void inOrder(Tree *tree);

void define(Tree *tree);

Tree *findLowest(Tree *tree);

Tree *searchRemove(Tree *tree, int key);

int calculaFb(Tree *tree);

