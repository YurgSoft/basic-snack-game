#include <string.h>
#include <stdio.h>

/*
  Declaracao dos prototipos
*/
char *juntar(char*,const char*);
char *getdigitos(const int);
char *getDecimos(const int);
char *getCentenas(const int);
char *getMilesimas(const int);
char *getExtencao(const int);
char getHex(int);

char *juntar(char *str1,const char *str2){
     char *res = malloc(sizeof(char) * 500);
     int i = 0;
     while(*str1){
         res[i++] = *str1;
         str1++;
     }
     while(*str2){
         res[i++] = *str2;
         str2++;
     }
     res[i++] = '\0';
     char *te = &res[0];
     return te;
}

char *juntarC(char *str1, const char ch){
     char *res = malloc(sizeof(char) * 500);
     int i = 0;
     while(*str1){
         res[i++] = *str1;
         str1++;
     }
     res[i++] = ch;
     res[i++] = '\0';
     char *te = &res[0];
     return te; 
}

char *juntarCC(char ch1, const char ch2){
     char res[3];
     res[0] = ch1, res[1] = ch2, res[2] = '\0';
     char *te = res;
     return te; 
}

char *getdigitos(const int valor){
     if(valor == 0) return "zero";
     else if(valor == 1) return "um";
     else if(valor == 2) return "dois";
     else if(valor == 3) return "trez";
     else if(valor == 4) return "quatro";
     else if(valor == 5) return "cinco";
     else if(valor == 6) return "seis";
     else if(valor == 7) return "sete";
     else if(valor == 8) return "oito";
     else if(valor == 9) return "nove";
     return "";
}

char *getDecimos(const int valor){
     if(valor>=0 && valor<10) return getdigitos(valor);
     else if(valor == 10) return "dez";
     else if(valor == 11) return "onze";
     else if(valor == 12) return "doze";
     else if(valor == 13) return "treze";
     else if(valor == 14) return "catorze";
     else if(valor == 15) return "quinze";
     else if(valor == 16) return "dezaseis";
     else if(valor == 17) return "dezasete";
     else if(valor == 18) return "dezoito";
     else if(valor == 19) return "dezanove";
     else if(valor == 20) return "vinte";
     else if(valor>20 && valor<30) return juntar("vinte e ",getdigitos(valor%10));
     else if(valor == 30) return "trinta";
     else if(valor>30 && valor < 40) return juntar("trinta e ",getdigitos(valor%10));
     else if(valor == 40) return "quarenta";
     else if(valor>40 && valor<50) return juntar("quarenta e ",getdigitos(valor%10));
     else if(valor == 50) return "cinquenta";
     else if(valor>50 && valor<60) return juntar("cinquenta e ",getdigitos(valor%10));
     else if(valor == 60) return "secenta";
     else if(valor>60 && valor<70) return juntar("secenta e ",getdigitos(valor%10));
     else if(valor == 70) return "setenta";
     else if(valor>70 && valor<80) return juntar("setenta e ",getdigitos(valor%10));
     else if(valor == 80) return "oitenta";
     else if(valor>80 && valor<90) return juntar("oitenta e ",getdigitos(valor%10));
     else if(valor == 90) return "noventa";
     else if(valor>90 && valor<100) return juntar("noventa e ",getdigitos(valor%10));
     return "";
}

char *getCentenas(const int valor){
     if(valor == 100) return "cem";
     else if(valor>100 && valor<200) return juntar("cento e ",getDecimos(valor%100));
     else if(valor == 200) return "duzentos";
     else if(valor>200 && valor<300) return juntar("duzentos e ",getDecimos(valor%100));
     else if(valor == 300) return "trezentos";
     else if(valor>300 && valor<400) return juntar("trezentos e ",getDecimos(valor%100));
     else if(valor == 400) return "quatrocentos";
     else if(valor>400 && valor<500) return juntar("quatrocentos e ",getDecimos(valor%100));
     else if(valor == 500) return "quientos";
     else if(valor>500 && valor<600) return juntar("quientos e ",getDecimos(valor%100));
     else if(valor == 600) return "seiscentos";
     else if(valor>600 && valor<700) return juntar("seiscentos",getDecimos(valor%100));
     else if(valor==700) return "setecentos";
     else if(valor>700 && valor<800) return juntar("setecentos e ",getDecimos(valor%100));
     else if(valor == 800) return "oitocentos";
     else if(valor>800 && valor<900) return juntar("oirocentos e ",getDecimos(valor%100));
     else if(valor == 900) return "novecentos";
     else if(valor>900 && valor<1000) return juntar("novecentos e ",getDecimos(valor%100));
     return "";     
}

char *getMilesimas(const int valor){
     if(valor == 1000) return "mil";
     else if(valor>1000 && valor<2000) return juntar("mil ",getCentenas(valor%1000));
     else if(valor> 2000 && valor<10000) return juntar(juntar(getdigitos(valor/1000)," mil "),getCentenas(valor%1000));
     return "";     
}

/* Declaracao das funcoes */
char *getExtencao(const int valor){
    if(valor>0 && valor <10) return getdigitos(valor);
    else if(valor>= 10 && valor < 100) return getDecimos(valor);
    else if(valor>=100 && valor<1000) return getCentenas(valor);
    else if(valor>=1000 && valor<10000) return getMilesimas(valor);
    return ""; 
}

// get hexadecimail
char getHex(int valor){
     char ch;

     switch(valor%16){
          case 1: case 2: case 3: case 4:
          case 5: case 6: case 7: case 8:
          case 9: ch = (valor%16) + '0'; break;
          case 10: ch = 'A'; break;
          case 11: ch = 'B'; break;
          case 12: ch = 'C'; break;
          case 13: ch = 'D'; break;
          case 14: ch = 'E'; break;
          case 15: ch = 'F'; break;                 
     }
     return ch;
}
