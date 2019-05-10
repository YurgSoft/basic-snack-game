#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "umeros.h" 
#include "menus.h"


#define MAX_PONTO 15
#define MAX_X 25
#define MAX_Y 70
#define MAX_TAMANHO_COBRA 15

void carregar_pontos();
void ver_pontos();
void actualizar_ponto();

char matriz[MAX_X][MAX_Y];
char *database = "pontos.data";

enum posicao{ HORIZONTAL = 1, VERTICAL };
enum olhar{ FRENTE = 0, TRAZ, CIMA, BAIXO };

struct pontoacao{
       int nivel;
       long ponto;
}list_ponto[MAX_PONTO];

struct{
    char simbolo;
    int pos_x, pos_y, posi, olhar;
}cobra[MAX_TAMANHO_COBRA];

int rato_x, rato_y;
int tam_actual = 1;
int nivel = 1, ponto = 0;
int perdeu_flag = 0;

char *cores[]={"\t 0  => PRETO\n",
             "\t 1  => AZUL\n",
             "\t 2  => VERDE\n",
             "\t 3  => Azul OCEAN\n",
             "\t 4  => VERMELHA\n",
             "\t 5  => LILAIZ\n",
             "\t 6  => AMARELA\n",
             "\t 7  => BRANCA\n",
             "\t 8  => CINZENTO\n",
             "\t 9  => Azul CLARO\n",
             "\t 10 => VERDE CLARO\n",
             "\t 11 => Azul OCEAN CLARO\n",
             "\t 12 => VERMELHA CLARA\n",
             "\t 13 => LILAIS CLARO\n",
             "\t 14 => AMARELO CLARO\n",
             "\t 15 => BRANCO CLARO\n",
             "\0"
             };

void aplicar_fundo(int *fundo, int *letra){
     char str[50];
     register int i;
     do{
        printf("\n\n");
        for(i = 0 ; *cores[i] ; i++) printf("%s", cores[i]);
        printf("\n\n\t\tInsira a sua opcao: ");
        gets(str); 
        i = atoi(str);
        system("cls");
     }while(i<0 && i>15);
     *fundo = i;
     char *string = juntarC("color ",getHex(*fundo));
     system(juntarC(string,getHex(*letra)));
}

void aplicar_letra(int *fundo, int *letra){
     char str[50];
     register int i;
     do{
        printf("\n\n");
        for(i = 0 ; *cores[i] ; i++) printf("%s", cores[i]);
        printf("\n\n\t\tInsira a sua opcao: ");
        gets(str); 
        i = atoi(str);
        system("cls");
     }while(i<0 && i>15);
     *letra = i;
     char *string = juntarC("color ",getHex(*fundo));
     system(juntarC(string,getHex(*letra)));
}

void inicializar(){
     register int i, j;
     for(i = 0; i < MAX_X ; i++)
        for(j = 0; j < MAX_Y ; j++) matriz[i][j] = ' ';
     carregar_pontos();
}

void inicializar_cobra(){
     register int i;
     tam_actual = 1;
     for(i = 0; i<MAX_TAMANHO_COBRA; i++)
        cobra[i].simbolo = '\0';
        
     cobra[0].simbolo = '>';
     cobra[0].pos_y = 2 , cobra[0].pos_x = rand() % MAX_X; 
     cobra[0].posi = HORIZONTAL , cobra[0].olhar = FRENTE;
}

void rend_cobra(){
     register int i;
     for(i = 1 ; i < tam_actual; i++){
           if(cobra[i].posi == HORIZONTAL)
               matriz[ cobra[i].pos_x ][ cobra[i].pos_y ] = '=';                 
           else matriz[ cobra[i].pos_x ][ cobra[i].pos_y ] = '|';
     }
     if(cobra[0].olhar == FRENTE) matriz[ cobra[0].pos_x ][ cobra[0].pos_y ] = '>';
     if(cobra[0].olhar == TRAZ)   matriz[ cobra[0].pos_x ][ cobra[0].pos_y ] = '<';
     if(cobra[0].olhar == CIMA)   matriz[ cobra[0].pos_x ][ cobra[0].pos_y ] = '^';
     if(cobra[0].olhar == BAIXO)  matriz[ cobra[0].pos_x ][ cobra[0].pos_y ] = '!';
}

void aplicar_rato(){
     int pos_x = rand() % MAX_X; 
     int pos_y = rand() % MAX_Y;
     if(matriz[pos_x][pos_y] == ' '){
          matriz[pos_x][pos_y] = '*';
          rato_x = pos_x, rato_y = pos_y;
     }
     else aplicar_rato();
}

void renderizar(){
     inicializar();
     rend_cobra();
     if(matriz[rato_x][rato_y] == ' ')matriz[rato_x][rato_y] = '*';
     else aplicar_rato();
     register int i_x, i_y;
     system("cls");
     printf("\n\tNivel     : %d\n", nivel);
     printf("\tPontuacao : %d\n\n", ponto);
     
     putchar(' ');
     for(i_y = 0; i_y < MAX_Y ; i_y++) putchar('_');
     putchar('\n');
     for(i_x = 0; i_x <MAX_X; i_x++){
             putchar('|');
             for(i_y = 0; i_y < MAX_Y ; i_y++) putchar(matriz[i_x][i_y]);
             printf("|\n");        
     }
     putchar(' ');
     for(i_y = 0; i_y < MAX_Y ; i_y++) putchar('_');     
}

void comer(){
     if(cobra[0].pos_x == rato_x && cobra[0].pos_y == rato_y){
        ponto += 10;
        if(ponto%50) tam_actual++;
        if(ponto / 200){
            nivel++;  
            ponto = 0;
        }
        aplicar_rato();
     }else if( matriz[ cobra[0].pos_x ][ cobra[0].pos_y ] != ' '){
           perdeu_flag = 1;
           system("cls");
           perdeu(ponto);
           actualizar_ponto();
     }
     
}

void atualizar_cobra(){
     register int i;
     for(i = tam_actual - 1; i > 0; i-- ) cobra[i] = cobra[i-1];  
}

void frente(){
     if(cobra[0].olhar == TRAZ && cobra[0].posi == HORIZONTAL) return;
     cobra[0].pos_y++;
     cobra[0].posi = HORIZONTAL;
     cobra[0].olhar = FRENTE;
     comer();
     atualizar_cobra();
}

void traz(){
     if(cobra[0].olhar == FRENTE && cobra[0].posi == HORIZONTAL) return;
     cobra[0].pos_y--;
     cobra[0].posi = HORIZONTAL;
     cobra[0].olhar = TRAZ;
     comer();
     atualizar_cobra();
}

void cima(){
     if(cobra[0].olhar == BAIXO && cobra[0].posi == VERTICAL) return;
     if(cobra[0].pos_x == 0 ) cobra[0].pos_x = MAX_X - 1;
     else cobra[0].pos_x--;
     cobra[0].posi = VERTICAL;
     cobra[0].olhar = CIMA;
     comer();
     atualizar_cobra(); 
}

void baixo(){
     if(cobra[0].olhar == CIMA && cobra[0].posi == VERTICAL) return;
     if(cobra[0].pos_x == MAX_X - 1 || cobra[0].pos_x == MAX_X) cobra[0].pos_x = 0;
     else cobra[0].pos_x++;
     cobra[0].posi = VERTICAL;
     cobra[0].olhar = BAIXO;
     comer();
     atualizar_cobra();
}

void carregar_pontos(){
     FILE *arquivo;
     if( (arquivo = fopen(database,"r+b")) == NULL ){
         fclose(arquivo);
         if( (arquivo = fopen(database,"w+b")) != NULL ){
            register int i;
            for(i = 0; i < MAX_PONTO; i++){
                  list_ponto[i].nivel = 1;
                  list_ponto[i].ponto = 0;
            }
            fclose(arquivo);
            actualizar_ponto();
            return;    
         }
     }

      
     struct pontoacao stack;
     int i = 0;
     rewind(arquivo);
     while(!feof(arquivo)){
        fread(&stack, sizeof(struct pontoacao), 1, arquivo);
        list_ponto[i++] = stack;
     } 

     fclose(arquivo);
}

void ver_pontos(){
     register int i;
     system("cls");
     printf("\n\n\t\t\tPontuacoes maximas\n\n\n\n");
     printf("\t\tColocacao\tnivel\tPontoacao\n");
     for(i = 0; i< MAX_PONTO ; i++) printf("\t\t%5d\t%11d\t%7ld\n",i+1,list_ponto[i].nivel, list_ponto[i].ponto);
     
     putchar('\n'); getch();
     system("cls");
}

void actualizar_ponto(){
     register int i;
     int pos;
     struct pontoacao stack;
     for(i = 0; i < MAX_PONTO ; i++){
        if(list_ponto[i].ponto < ponto){
            pos = i; break;  
        }
     }
     
     for(i = MAX_PONTO - 1; i > pos ; i-- ) list_ponto[i] = list_ponto[i-1];
     list_ponto[pos].ponto = ponto;
     list_ponto[pos].nivel = nivel;
     
     // agora vamos 
     
     FILE *arquivo;
     
     if( (arquivo = fopen(database,"w+b")) == NULL ){
         printf("Houve uma problema ao guardar a pontuacao! \0\0");
         return;    
     }
     for(i = 0; i<MAX_PONTO ; i++ ){
           struct pontoacao stack = list_ponto[i];
           fwrite(&stack,sizeof(struct pontoacao), 1, arquivo);     
     }
     fclose(arquivo);
}
