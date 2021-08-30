#include "scanner.h"

char caracter;
int i;
  
struct token get_token(){
// ini token
  token.tipo=0;
  token.lexema[0]='\0';
  caracter=getchar();
// comienza a procesar entradas
  while(caracter != EOF){

  if(caracter == ','){

      token.tipo=SEP;    
      token.lexema[0]=',';
      token.lexema[1]='\0';

      return token;
     
    }else{

      if(!isspace(caracter)){
        i=0;
        do{  
      
          token.lexema[i]=caracter;
          i++;
          caracter=getchar();
        }while((caracter!=',') && !isspace(caracter) && caracter != EOF); 
        //procesa caracteres alfanuméricos

      token.lexema[i]='\0';
      ungetc(caracter,stdin);
      token.tipo=CADENA;

      return token;
    }
  }
  caracter=getchar();
  }//fin proceso de entradas

  token.tipo=FDT;
  token.lexema[0]='\0';

  return token;

}//fin función principal


