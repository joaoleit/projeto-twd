#include <stdio.h>
#include <stdlib.h>



char mapa[10][10];
int end = 0, jogo = 0;

void menu();

int main(void){
  do
  {
    menu();
    while(jogo == 1)
    {

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
      end = 1;
      break;
    case 2:
      printf("\nRick acorda atordoado em algum lugar aleatorio no cenario, com uma arma sem balas.\n\nExistem 15 zumbis espalhados pelo cenario e os obstaculos estao por toda parte");
      printf("Nesse cenario existe uma unica saida, se ela estiver bloqueada rick nao tem saida e morrera. Caso Contrario, se Rick alcancar a saida, o jogo e encerrado");
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
