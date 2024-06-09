typedef struct {
  int key;
} Data;

typedef struct tree {
  struct tree *right; 
  struct tree *left;
  Data data;
  int Fb;
} Tree;

int main();

Tree *search(Tree *tree, int key);  

Tree *insert(Tree *tree, int key);

Tree *removeNode(Tree *root, int key);

void preOrder(Tree *tree);

void define(Tree *tree);

Tree *findLowest(Tree *tree);

Tree *searchRemove(Tree *tree, int key);

int calculateFb(Tree *tree);

Tree *updateFb(Tree *tree);

int height(Tree *tree);

Tree *rebalance(Tree *tree);

Tree *rotateLeft(Tree *tree);

Tree *rotateRight(Tree *tree);

Tree *doubleRotateRight(Tree *tree);

Tree *doubleRotateLeft(Tree *tree);

Tree *insertAVL(Tree *root, int key);
