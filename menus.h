//
//         Biblioteca com as UI
//
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


void apresentacao();
int menu_principal();
int configurar();
int pontuacao();
void perdeu(int);


void apresentacao(){
     printf("   \n\n");
     
     printf("\t\t //==\\\\   "); printf("||\\     /\\ "); printf("   /\\    "); printf("||  /    ");   printf(" //=\\\\  \n");
     printf("\t\t ||       ");   printf("|| \\    || ");  printf("  /  \\   "); printf("|| /     ");   printf("||  ||    \n");
     printf("\t\t  \\\\      "); printf("||  \\   || ");  printf(" /____\\  "); printf("||/      ");   printf("||  //    \n");
     printf("\t\t     \\\\   "); printf("||   \\  || ");  printf("||    || ");  printf("||\\\\     "); printf("||//      \n");
     printf("\t\t      ||  ");   printf("||    \\ || ");  printf("||    || ");  printf("|| \\\\    "); printf("||  ||    \n");
     printf("\t\t \\\\==//   "); printf("/\\     \\|| "); printf("||    || ");  printf("||  \\\\   "); printf("\\===/    \n");
     
     
     printf(" \n\n\n ");
     printf("\t\t 1. Comecar o jogo \n");
     printf("\t\t 2. configurar \n");
     printf("\t\t 3. Pontuacoes \n");
     printf("\t\t 4. Sair\n");
}

int menu_principal(){
     int r;
     char str[70];
     apresentacao();
     printf("\n\n\t\tInsira a opcao# ");
     gets(str);
     r = atoi(str);
     system("cls");
     return r;
}

int configurar(){
    printf("\n\n\n\t\t 1. Mudar a cor do fundo\n");
    printf("\t\t 2. Mudar a cor dos caracteres\n");
    printf("\t\t 3. Voltar\n");
    char str[50];
    printf("\t\tInsira a tua opcao: ");
    gets(str);
    system("cls");
    return atoi(str);    
}

int pontuacao(){
    return 0;    
}

void perdeu(int pontuacao){
     printf("\n\n\n");
     
     printf("\t\t \\\\          // "); printf("  --    ");   printf("  --     ");  printf("   --    "); putchar('\n');
     printf("\t\t  \\\\        //  "); printf("//  \\\\  "); printf("//   \\  ");  printf(" //   \\ "); putchar('\n');
     printf("\t\t   \\\\      //   "); printf("|    |  ");   printf("|        ");  printf("// -- /  "); putchar('\n');
     printf("\t\t    \\\\    //    "); printf("|    |  ");   printf("|        ");  printf("|        "); putchar('\n');
     printf("\t\t     \\\\  //     "); printf("\\\\  //  "); printf("\\\\   /   ");printf("\\\\   / "); putchar('\n');
     printf("\t\t      \\\\//      "); printf("  --    ");   printf("  --     ");  printf("  --     "); putchar('\n');
     printf("\n\n");
     printf("\t\t  ----  ");   printf("||==== ");  printf("     ");   printf("    || ");  printf("||==== ");  printf(" "); putchar('\n');
     printf("\t\t //  \\\\ "); printf("||/    ");  printf("|| //\\"); printf("   || ");   printf("||/    ");  printf(" "); putchar('\n');
     printf("\t\t||   // ");   printf("||\\    "); printf("||// ");   printf("    || ");  printf("||\\    "); printf("|     ||"); putchar('\n');
     printf("\t\t||===   ");   printf("||===  ");  printf("||   ");   printf(" /--|| ");  printf("||===  ");  printf("|     ||"); putchar('\n');
     printf("\t\t||      ");   printf("||===  ");  printf("||   ");   printf("|   || ");  printf("||===  ");  printf("|     ||"); putchar('\n');
     printf("\t\t||      ");   printf("||/    ");  printf("||   ");   printf("|   || ");  printf("||/    ");  printf("|     ||"); putchar('\n');
     printf("\t\t||      ");   printf("||\\    "); printf("||   ");   printf("\\   || "); printf("||\\    "); printf("\\\\    ||"); putchar('\n');
     printf("\t\t||      ");   printf("||==== ");  printf("||   ");   printf("  ---  ");  printf("||==== ");  printf("  ----||\\"); putchar('\n');
     printf("\t\t===========================================");
     
     printf("\n\n\t\t\t Pontuacao: %10d",pontuacao);
     
     getch();
     system("cls");
}
