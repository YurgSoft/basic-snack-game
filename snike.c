#include "funcoes.h"
#include <time.h>

void jogar();

int fundo = 0 , letra = 0;

int main(){
    int menu = 1, sub = 1;
    system("cls");
    srand((unsigned)time(NULL)); // preparar a geracao dos numeros aleatorios 
    inicializar();
    inicializar_cobra();
    aplicar_rato();
    do{   
        switch(menu_principal()){
              case 1: perdeu_flag = 0; 
                      inicializar_cobra(); inicializar();
                      aplicar_rato(); ponto = 0; nivel = 1;
                      jogar(); 
                      break;   // comecar o jogo
              case 2: 
                   do{
                       switch(configurar()){
                            case 1: aplicar_fundo(&fundo, &letra); break; // configurar o fundo do jogo                    
                            case 2: aplicar_letra(&fundo, &letra); break; // configurar a cor dos caracteres 
                            case 3: sub = 0; // voltar pra o menu principal
                       }
                   }while(sub);
                   break; // configuracao;
              case 3: ver_pontos(); break; //pontuacoes
              case 4: menu = 0; //sair 
        }
    }while( menu );
    
    return 0;    
}

char tecla;

void jogar(){
     system("cls");
     
     do{
         
        renderizar();
         
        switch(tecla = getch()){
              case 'w': case 'W': cima();   break; // cima
              case 's': case 'S': baixo();  break; // baixo
              case 'a': case 'A': traz();   break; // esquerda
              case 'd': case 'D': frente(); break; // direita
              case ' ': perdeu_flag = 1; system("cls");             
        }
     }while(!(perdeu_flag));
}
