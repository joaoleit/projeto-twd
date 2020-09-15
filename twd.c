#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char mapa[10][10];
int end = 0, game = 0, restart = 0;

void menu();
void gameInit();
void mapStatus();


int main(void){
  gameInit();
  do
  {
    //if(restart == 1)
    gameInit();
    menu();
    while(game == 1)
    {
      mapStatus();
    }
  }while(end == 0);
}

void menu(){
  int opcao;
  printf("\n***MENU***\n");
  printf("1- Jogar\n");
  printf("2- Instrucoes\n");
  printf("3- Sair\n");
  printf("Digite a opcao: ");
  scanf("%d", &opcao);
  getchar();

  switch(opcao)
  {
    case 1:
      game = 1;
      break;
    case 2:
      printf("\nRick acorda atordoado em algum lugar aleatorio no cenario, com uma arma sem balas.\n\nExistem 15 zumbis espalhados pelo cenario e os obstaculos estao por toda parte");
      printf("Nesse cenario existe uma unica saida, se ela estiver bloqueada rick nao tem saida e morrera. Caso Contrario, se Rick alcancar a saida, o game e encerrado");
      printf("\n\nRick se move com as teclas 'w','a','s','d'. Existem 4 balas espalhadas no cenario.\nSe Rick se movimentar e tiver uma bala naquela posicao, Rick carregara a arma imediatamente.");
      printf("Se Rick tentar se mover para uma regiao em que ha um obstaculo, ele permanece onde esta e nao se movimenta.\n\nCaso ele se movimente para uma regiao em que ha um zumbi,existem duas possibilidades:");
      printf("\nSe Rick estiver com a arma descarregada, ele e atacado e morre caso contrario, Rick usa a bala no zumbi.\nOs zumbis que estao proximos de Rick passam a persegui-lo. Os que estao mais distantes, ficam parados.");
      printf("\n\nPressione ENTER para voltar ao menu: ");
      getchar();
      break;
    default:
      end = 1;

  }
}

void gameInit(){
  srand(time(NULL));
  int k, l;

  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      mapa[i][j] = '.';
    }
  }

  for(int i = 0; i < 21; i++)
  {
    do
    {
      k = rand() % 10;
      l = rand() % 10;
    }while(mapa[k][l] != '.');

    if(i == 0) mapa[k][l] = 'R';
    else if(i == 1) mapa[k][l] = 'S';
    else if(i < 6) mapa[k][l] = 'B';
    else mapa[k][l] = 'Z';
  }

  for(int i = 0; i < 19; i++)
  {
    do
    {
      k = rand() % 10;
      l = rand() % 10;
    }while(mapa[k][l] != '.');

    if(i < 4) mapa[k][l] = 'C';
    else if(i < 11) mapa[k][l] = 'A';
    else mapa[k][l] = 'P';
  }
}

void mapStatus(){
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
      {
        printf("%c ", mapa[i][j]);
      }
      printf("\n");
    }
    //end = 1;
    game = 0;
}
