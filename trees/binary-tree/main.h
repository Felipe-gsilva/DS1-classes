typedef struct data {
  int id;
} data;

typedef struct node {
  data data;
  struct node *left;
  struct node *right;
} Node;

int main(int argc, char *argv[]);

bool vazia(Node *root);

void display(Node *root, char *o);

void printTree(Node *node);

Node *createTree();

void insertRight(Node *node, int id);

void insertLeft(Node *node, int id);

Node *search(int id, Node *root);

void fillNode(data data, Node *node);

void preOrder(Node *node);

void inOrder(Node *node);

void postOrder(Node *node);

Node *biggestNode(Node *node);

int nNodes(Node *node);

bool full(Node *node);
