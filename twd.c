#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

char mapa[10][10];
int end = 0, game = 0, pos1, pos2, ammo = 0;

void menu();
void gameInit();
void mapStatus();
void playerPosition();
void gameStatus();
void checkCollision(int posx, int posy);

int main(void){
  gameInit();
  do
  {
    gameInit();
    menu();
    while(game == 1)
    {
      gameStatus();
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

    if(i == 0)
    {
      mapa[k][l] = 'R';
      pos1 = k;
      pos2 = l;
    }
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
        if(mapa[i][j] == 'R') printf(YEL "%c " RESET, mapa[i][j]);
        else if(mapa[i][j] == 'S') printf(BLU "%c " RESET, mapa[i][j]);
        else if(mapa[i][j] == 'Z') printf(GRN "%c " RESET, mapa[i][j]);
        else if(mapa[i][j] == 'B') printf(RED "%c " RESET, mapa[i][j]);
        else printf("%c ", mapa[i][j]);
      }
      printf("\n");
    }
}

void playerPosition(){
  char control;
  printf("Mova Rick: ");
  scanf("%s", &control);
  getchar();
  switch(control)
  {
    case 'w':
      if(pos1 == 0)
      {
        printf("Rick nao pode ir para cima\n");
        playerPosition();
      }
      else checkCollision(-1, 0);
      break;
    case 's':
      if(pos1 == 9)
      {
        printf("Rick nao pode ir para baixo\n");
        playerPosition();
      }
      else checkCollision(1, 0);
      break;
    case 'a':
      if(pos2 == 0)
      {
        printf("Rick nao pode ir para esquerda\n");
        playerPosition();
      }
      else checkCollision(0, -1);
      break;
    case 'd':
      if(pos2 == 9)
      {
        printf("Rick nao pode ir para direita\n");
        playerPosition();
      }
      else checkCollision(0, 1);
      break;
    case 'o':
      game = 0;
      break;
    default:
      printf("'w', 'a', 's', 'd' Para se mover\n");
      playerPosition();
      break;
  }
  control = ' ';
}

void checkCollision(int posx, int posy){
  if(mapa[pos1 + posx][pos2 + posy] == '.')
  {
    mapa[pos1][pos2] = '.';
    mapa[pos1 + posx][pos2 + posy] = 'R';
    pos1 += posx;
    pos2 += posy;
  }
  else if(mapa[pos1 + posx][pos2 + posy] == 'A' || mapa[pos1 + posx][pos2 + posy] == 'P' || mapa[pos1 + posx][pos2 + posy] == 'C')
  {
    if(mapa[pos1 + posx][pos2 + posy] == 'A') printf("\nHa uma arvore no caminho\n");
    if(mapa[pos1 + posx][pos2 + posy] == 'P') printf("\nHa uma pedra no caminho\n");
    if(mapa[pos1 + posx][pos2 + posy] == 'C') printf("\nHa um carro no caminho\n");
    Sleep(750);
    printf("Escolha uma nova direcao\n"); Sleep(750);
  }
  else if(mapa[pos1 + posx][pos2 + posy] == 'B')
  {
    ammo++;
    printf("\nVoce encontrou uma bala"); Sleep(500);
    printf("\nE Recarregou sua arma"); Sleep(500);
    printf("\nBalas: %d", ammo); Sleep(750);
    mapa[pos1][pos2] = '.';
    mapa[pos1 + posx][pos2 + posy] = 'R';
    pos1 += posx;
    pos2 += posy;
  }
}


void gameStatus(){
    system("cls");
    mapStatus();
    playerPosition();
}
