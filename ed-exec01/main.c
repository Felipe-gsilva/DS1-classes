#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{
  int op;
  lista L;
  Definir(&L);
  tipo_elem x;
  int chave = 1;
  int chaveEsc = 0;
  int posic;

  puts("______SEJA BEM-VINDO______");
  while(op){
    puts("\n______     MENU     ______"); 
    puts("1-Inserir Aluno\n2-Remover Aluno\n3-Buscar Aluno\n4-Imprimir Aluno\n0-Sair");
    scanf("%d", &op);
    switch(op)
    {
      case 0:
        exit(1);
      case 1:
        puts("Insira o nome:");
        scanf("%s", x.info.nome);
        puts("Insira a idade:");
        scanf("%d", &x.info.idade);
        puts("Insira sua média final:");
        scanf("%f", &x.info.media_final);
        x.chave = chave;
        if(Inserir_ord(x, &L))
        {
          printf("Inserido com sucesso na chave %d\n", chave);
          chave++;
        }
        break;
      case 2:
        puts("Escolha a chave pra remover o aluno\n");
        scanf("%d", &chaveEsc); 
        if(Remover_ch(chaveEsc, &L))
          printf("Aluno %d removido com sucesso\n", chaveEsc);
        break;
      case 3:
        puts("Escolha a chave pra buscar o aluno");
        scanf("%d", &chaveEsc); 
        Buscar_ord(chaveEsc, &L, &posic);
        printf("A chave está na posição %d da lista", posic);
        break;
      case 4:
        puts("------------");
        Imprimir(&L);
        puts(" ");
        break;
      default:
        puts("Opção inválida\n");
        break;
    }
  }
  return 0;
}

