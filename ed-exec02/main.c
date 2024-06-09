#include <stdio.h>
#include <stdbool.h>
#include <limits.h> 
#define tam_fila 100

typedef struct
{
  int A[tam_fila];
  int inicio, fim;
} fila;

void Definir(fila *q) {
  q->fim = 0;
  q->inicio = 0;
}

bool Vazia(fila *q) {
  if (q->inicio == q->fim)
    return true;
  return false;
}

bool Cheia(fila *q) {
  if (q->inicio == ((q->fim + 1) % tam_fila))
    return true;
  return false;
}

bool Inserir(fila *q, int elem) {	
  if (Cheia(q))
    return false;
  q->fim = (q->fim + 1) % tam_fila;
  q->A[q->fim] = elem;
  return true;
}

bool Remover(fila *q, int *elem) {
  if (Vazia(q))
    return false;
  q->inicio = (q->inicio + 1) % tam_fila;
  *elem = q->A[q->inicio];
  return true;
}

int main() {
  int N,x, y, value;
  int i, c = 0;
  FILE *fp;
  fila F;

  fp = fopen("digrafo.txt", "r");
  fscanf(fp, "%d", &N);

  int A[N][N];
  int dist[N];

  for (int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      A[i][j] = 0;
    }
  }

  while(!feof(fp)){
    fscanf(fp, "%d %d %d", &x, &y, &value);
    A[x][y] = value;
  }

  for (int j = 0; j<N; j++)  
    dist[j] = INT_MAX;
  dist[c] = 0;

  Definir(&F);
  Inserir(&F,c);

  while (!Vazia(&F)) 
  { 
    Remover(&F,&i);
    for (int j = 0; j < N; j++)
      if (A[i][j] != 0 && (dist[j] >= INT_MAX || dist[i] + A[i][j] < dist[j]))
      {
        dist[j] = dist[i] + A[i][j];
        Inserir(&F,j);
      }
  }

  for (i=0; i<N; i++)
    printf("dist[%d]: %d\n", i, dist[i]);	
}
