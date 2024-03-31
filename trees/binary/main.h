typedef struct data {
  int id;
} data;

typedef struct node {
  struct data;
  struct node *left;
  struct node *right;
} node;

int main(int argc, char *argv[]);

bool cheia(node *top);
