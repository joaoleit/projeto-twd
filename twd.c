#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

char mapa[10][10];
int end = 0, game = 0, pos1, pos2, ammo = 0, restart = 1;

void menu();
void gameInit();
void opening();
void mapStatus();
void playerPosition();
void checkCollision(int posy, int posx);
void gameStatus();

int main(void){
  do
  {
    if(restart == 1)
    {
      gameInit();
      opening();
    }
    menu();
    while(game == 1)
    {
      gameStatus();
    }
  }while(end == 0);
}

void menu(){
  system("cls");
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
      printf("\nRick(R) acorda atordoado em algum lugar aleatorio no cenario, com uma arma sem balas(B).\n\nExistem 15 zumbis(Z) espalhados pelo cenario e os obstaculos estao por toda parte");
      printf("Nesse cenario existe uma unica saida(S), se ela estiver bloqueada rick nao tem saida e morrera. Caso Contrario, se Rick alcancar a saida, o game e encerrado");
      printf("\n\nRick se move com as teclas 'w','a','s','d', com a tecla 'p' jogo pausa e volta ao menu, apertando o ESC jogo reinicia e volta ao menu.\n\nExistem 4 balas espalhadas no cenario. Se Rick se movimentar e tiver uma bala naquela posicao, Rick carregara a arma imediatamente.");
      printf("Se Rick tentar se mover para uma regiao em que ha um obstaculo, ele permanece onde esta e nao se movimenta.\n\nCaso ele se movimente para uma regiao em que ha um zumbi, existem duas possibilidades:");
      printf("\nSe Rick estiver com a arma descarregada, ele e atacado e morre caso contrario, Rick usa a bala no zumbi.\nOs zumbis que estao proximos de Rick passam a persegui-lo. Os que estao mais distantes, ficam parados.");
      printf("\n\nPressione ENTER para voltar ao menu: ");
      getchar();
      break;
    default:
      end = 1;
      break;
  }
}

void opening(){
  int cicle = 0;
  system("cls");
  printf("   __          THE    _      _  _______ _   _  _____    _____  ______          _____   \n");Sleep(200);
  printf("   \\ \\        / /\\   | |    | |/ /_   _| \\ | |/ ____|  |  __ \\|  ____|   /\\   |  __ \\  \n");Sleep(200);
  printf("    \\ \\  /\\  / /  \\  | |    | ' /  | | |  \\| | |  __   | |  | | |__     /  \\  | |  | | \n");Sleep(200);
  printf("     \\ \\/  \\/ / /\\ \\ | |    |  <   | | | . ` | | |_ |  | |  | |  __|   / /\\ \\ | |  | | \n");Sleep(200);
  printf("      \\  /\\  / ____ \\| |____| . \\ _| |_| |\\  | |__| |  | |__| | |____ / ____ \\| |__| | \n");Sleep(200);
  printf("       \\/  \\/_/    \\_\\______|_|\\_\\_____|_| \\_|\\_____|  |_____/|______/_/    \\_\\_____/  \n");Sleep(800);
  while(cicle < 3)
  {
    system("cls");Sleep(280);
    printf("   __          THE    _      _  _______ _   _  _____    _____  ______          _____   \n");
    printf("   \\ \\        / /\\   | |    | |/ /_   _| \\ | |/ ____|  |  __ \\|  ____|   /\\   |  __ \\  \n");
    printf("    \\ \\  /\\  / /  \\  | |    | ' /  | | |  \\| | |  __   | |  | | |__     /  \\  | |  | | \n");
    printf("     \\ \\/  \\/ / /\\ \\ | |    |  <   | | | . ` | | |_ |  | |  | |  __|   / /\\ \\ | |  | | \n");
    printf("      \\  /\\  / ____ \\| |____| . \\ _| |_| |\\  | |__| |  | |__| | |____ / ____ \\| |__| | \n");
    printf("       \\/  \\/_/    \\_\\______|_|\\_\\_____|_| \\_|\\_____|  |_____/|______/_/    \\_\\_____/  \n");Sleep(720);
    cicle++;
  }

  printf("\n\nPressione ENTER para comecar: ");
  getchar();
}

void gameInit(){
  srand(time(NULL));
  int k, l;
  ammo = 0, restart = 0;
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      mapa[i][j] = '.';
    }
  }

  for(int i = 0; i < 40; i++)
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
    else if(i < 21) mapa[k][l] = 'Z';
    else if(i < 25) mapa[k][l] = 'C';
    else if(i < 32) mapa[k][l] = 'A';
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
  char control, check;
  printf("Mova Rick: ");
  control = getch();
  printf("\n");
  switch(control)
  {
    case 'w':
      if(pos1 == 0)
      {
        printf("Rick nao pode ir para cima\n");Sleep(500);
        playerPosition();
      }
      else checkCollision(-1, 0);
      break;
    case 's':
      if(pos1 == 9)
      {
        printf("Rick nao pode ir para baixo\n");Sleep(500);
        playerPosition();
      }
      else checkCollision(1, 0);
      break;
    case 'a':
      if(pos2 == 0)
      {
        printf("Rick nao pode ir para esquerda\n");Sleep(500);
        playerPosition();
      }
      else checkCollision(0, -1);
      break;
    case 'd':
      if(pos2 == 9)
      {
        printf("Rick nao pode ir para direita\n");Sleep(500);
        playerPosition();
      }
      else checkCollision(0, 1);
      break;
    case 'p':
      game = 0;
      break;
    case 27:
      printf("\nTem certeza que deseja reiniciar o jogo?(s/n): ");
      scanf(" %c", &check);
      getchar();
      if(check == 's') game = 0, restart = 1;
      break;
    default:
      printf("'w', 'a', 's', 'd' Para se mover\n");Sleep(500);
      playerPosition();
      break;
  }
}

void checkCollision(int posy, int posx){
  if(mapa[pos1 + posy][pos2 + posx] == 'A' || mapa[pos1 + posy][pos2 + posx] == 'P' || mapa[pos1 + posy][pos2 + posx] == 'C')
  {
    if(mapa[pos1 + posy][pos2 + posx] == 'A') printf("\nHa uma arvore no caminho\n");
    if(mapa[pos1 + posy][pos2 + posx] == 'P') printf("\nHa uma pedra no caminho\n");
    if(mapa[pos1 + posy][pos2 + posx] == 'C') printf("\nHa um carro no caminho\n");
    Sleep(650);
    printf("Escolha uma nova direcao\n"); Sleep(650);
  }
  else if(mapa[pos1 + posy][pos2 + posx] == 'B' || mapa[pos1 + posy][pos2 + posx] == '.')
  {
    if(mapa[pos1 + posy][pos2 + posx] == 'B')
    {
      ammo++;
      printf("\nVoce encontrou uma bala"); Sleep(650);
      printf("\nE recarregou sua arma"); Sleep(650);
      printf("\nBalas: %d", ammo); Sleep(700);
    }
    mapa[pos1][pos2] = '.';
    mapa[pos1 + posy][pos2 + posx] = 'R';
    pos1 += posy;
    pos2 += posx;
  }
  else if(mapa[pos1 + posy][pos2 + posx] == 'S')
  {
    printf("\n\nParabens! Voce Ganhou\n");Sleep(650);
    printf("Rick encontrou a saida\n\n");Sleep(650);
    printf("Pressione ENTER para voltar ao MENU: ");
    getchar();
    restart = 1, game = 0;
  }
  else if(mapa[pos1 + posy][pos2 + posx] == 'Z')
  {
    printf("\nRick encontrou um Zumbi\n");Sleep(650);
    if(ammo > 0)
    {
      ammo--;
      printf("Rick tinha bala e matou ele\n");Sleep(650);
      printf("Balas: %d", ammo);Sleep(700);
      mapa[pos1][pos2] = '.';
      mapa[pos1 + posy][pos2 + posx] = 'R';
      pos1 += posy;
      pos2 += posx;
    }
    else
    {
      printf("Voce Perdeu!\n");Sleep(650);
      printf("Rick nao tinha bala e acabou morrendo\n\n");Sleep(650);
      printf("Pressione ENTER para voltar ao menu: ");
      getchar();
      restart = 1, game = 0;
    }
  }
}

void zombiePosition(){
  int zomby, zombx, distance = 2;
  for(int i = pos1 - distance; i <= pos1 + distance; i++)
  {
    for(int j = pos2 - distance; j <= pos2 + distance; j++)
    {
      if(j > -1 && j < 10 && mapa[i][j] == 'Z')
      {
        zomby = pos1 - i;
        zombx = pos2 - j;
        if(zomby <= zombx || zombx == 0)
        {
          if(pos1 > i && mapa[i + 1][j] == '.'){mapa[i + 1][j] = 'Z';mapa[i][j] = '.';}
          if(pos1 < i && mapa[i - 1][j] == '.'){mapa[i - 1][j] = 'Z';mapa[i][j] = '.';}
        }
        else if(zombx < zomby || zomby == 0)
        {
          if(pos2 > j && mapa[i][j + 1] == '.'){mapa[i][j + 1] = 'Z';mapa[i][j] = '.';}
          if(pos2 < j && mapa[i][j - 1] == '.'){mapa[i][j - 1] = 'Z';mapa[i][j] = '.';}
        }
      }
    }
  }
}

void gameStatus(){
    system("cls");
    mapStatus();
    playerPosition();
    zombiePosition();
}
