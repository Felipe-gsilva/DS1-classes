typedef struct data {
  int key;

} Data;

typedef struct node {
  Data data; 
  struct node *left;
  struct node *right;
} Node;

bool isEmpty(Node *node);

void insertData(Node *root, Data data);

Node *searchNode(Node *root, Data data); 

Node *setNewNode(Data data);

void fillNode(Node *node, Data data);

Data fillData(int key); 

void preOrder(Node *root);

void inOrder(Node *root);

void posOrder(Node *root);

Node *findLowest(Node *node);

void printLesser(Node *node);

void freeAll(Node *node);

Node *removeNode(Node *node, int key);

Node *searchRemove(Node *root, int key);

bool leaf(Node *node);
