#include "sombrero.h"
#include <stdio.h>

void pedir_valor_de_atributos(int *atributo,char *nombre_atributos,int *super_atributos){
         
               
           printf("Ingrese valor de atributo para %s\n", nombre_atributos);
           scanf("%i", atributo);
           while(*atributo<ATRIBUTO_MIN||*atributo>ATRIBUTO_MAX){
               printf("Valor ingresado erroneo. Ingreselo nuevamente\n");
               scanf("%i", atributo);
           }  
            if(*atributo>SUPER_ATRIBUTO_MIN&&*atributo<SUPER_ATRIBUTO_MAX){  
                      (*super_atributos)++;  
            }
}
char obtener_casa(){
   int Fuerza, Valor, Inteligencia, Ingenio, Dedicacion;
   int super_atributos=0;    
   int valido=0;        
       
   while(!valido){        
       pedir_valor_de_atributos(&Fuerza,F,&super_atributos);
       pedir_valor_de_atributos(&Valor,V,&super_atributos);
       pedir_valor_de_atributos(&Inteligencia,I,&super_atributos);
       pedir_valor_de_atributos(&Ingenio,Y,&super_atributos);
       pedir_valor_de_atributos(&Dedicacion,D,&super_atributos);
 
       
       if(super_atributos<=LIMITE_DE_SUPER_ATRIBUTOS){
               valido=1;
       }else{
           super_atributos=0;
           printf("No podes tener mas de dos superatributos!\n");
           
       }
   }
   if(Fuerza>FUERZA_MIN_GRYFFINDOR&&Valor>VALOR_MIN_GRYFFINDOR&&Ingenio<INGENIO_MAX_GRYFFINDOR){
       return GRYFFINDOR;
   }else if(Inteligencia>INTELIGENCIA_MIN_RAVENCLAW&&Ingenio>INGENIO_MIN_RAVENCLAW){
       return RAVENCLAW;
   }else if(Inteligencia>INTELIGENCIA_MIN_SLYTHERIN&&Inteligencia<INTELIGENCIA_MAX_SLYTHERIN&&Ingenio>INGENIO_MIN_SLYTHERIN){
       return SLYTHERIN;
   }else{
       return HUFFLEPUFF;
   }
   

}
