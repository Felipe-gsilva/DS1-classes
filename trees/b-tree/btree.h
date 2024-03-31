typedef struct data {
  int key;

} Data;

typedef struct node {
  Data data; 
  struct node *left;
  struct node *right;
} Node;
typedef enum tipoP { PRE,IN,POS} tipoP;
  
bool isEmpty(Node *node);

void insertData(Node *root, Data data);

Node *setNewNode(Data data);

void printNode(Node *root);

int *getAllKeys(Node *root, tipoP v);

void removeNode(Node *root, int key);
