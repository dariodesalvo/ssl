#include "scanner.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

enum Tokens {FDT = EOF, SEP = ','};
char caracter;
char cadena[100];
char aux[1];

bool esToken(char c){

  if(isspace(c)){
    return false;
  }

  return true;
}

void analisis(FILE * archivo){
  while((caracter=getc(archivo)) != FDT){

  if(esToken(caracter)){

    if(caracter==SEP){
      
      if(cadena[0] != '\0'){
        printf("Cadena: %s \n",cadena);
        cadena[0]='\0';  
      }

      printf("Separador: %c \n",caracter);

    }else{
      aux[0]=caracter;
      strcat(cadena,aux);
    }
    
    }
  
  }//fin ciclo  
}
  
int get_token(){

  FILE *archivo = fopen("entrada.txt", "r");
  analisis(archivo);
  fclose(archivo);
  printf("Fin de texto:\n");
  return 0;

}//fin función principal


