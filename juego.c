#include "sombrero.h"
#include "quidditch.h"

void imprimir_matriz(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO]) {
    printf("__________________________________\n");
   for(int i=0;i<MAX_FILAS_CAMPO;i++){
      for(int j=0;j<MAX_COLUMNAS_CAMPO;j++){
          printf("%c",(campo[i][j]));
      }
       printf("\n");
   }
   printf("__________________________________\n");
}

void imprimir_variables_juego(juego_t juego) {
    printf("######################################\n");
    printf("Casa: %c\n",juego.casa);
    printf("Posicion Jugador [%i][%i]\n",juego.posicion_jugador.fila,juego.posicion_jugador.columna);
    printf("Posicion Snitch [%i][%i]\n", juego.posicion_snitch.fila, juego.posicion_snitch.columna);
    printf("Blodgers en juego: %i\n",juego.bludgers_en_juego);
    for(int i = 0; i < juego.bludgers_en_juego; i++)
    {
        printf(" - Posicion Bloger %i : [%i][%i]\n",i,juego.posicion_bludgers[i].fila,juego.posicion_bludgers[i].columna);
    }
    printf("Dementores en Juego: %i\n",juego.dementores_en_juego);
    for(int i = 0; i < juego.dementores_en_juego; i++)
    {
        printf(" - Posicion Dementor %i : [%i][%i]\n",i,juego.posicion_dementores[i].fila,juego.posicion_dementores[i].columna);
    }
    printf("Estado: %i\n",juego.estado);
    printf("Resistencia: %i\n",juego.resistencia);
    printf("######################################\n");
}

int main(void){

    char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO];
    juego_t juego;
    char casa;
    bool finalizar_juego=false;
    char direccion;   

    srand( (unsigned) time(NULL));
    juego.casa=obtener_casa();
    inicializar_juego(campo,casa,&juego);
    
    imprimir_variables_juego(juego);
    
    imprimir_matriz(campo);
    
    while ((!finalizar_juego) && (juego.resistencia>0)) {

        direccion = pedir_movimiento(juego.posicion_jugador);
        imprimir_variables_juego(juego);

        if (juego.casa == HUFFLEPUFF) {
            mover_jugador(campo,direccion,&juego);
            finalizar_juego=finalizo_juego(&juego);
            mostrar_resultado(juego);

            if (!finalizar_juego) {
                direccion = pedir_movimiento(juego.posicion_jugador);
        
                mover_jugador(campo,direccion,&juego);
                finalizar_juego=finalizo_juego(&juego);
                mostrar_resultado(juego);
            }
        } else {
            mover_jugador(campo, direccion, &juego);
            finalizar_juego = finalizo_juego(&juego);            
            mostrar_resultado(juego);  
        }

        
        if (!finalizar_juego) {
            mover_bludgers(campo,&juego);
            finalizar_juego=finalizo_juego(&juego);
            mostrar_resultado(juego);
        }

        if(!finalizar_juego){
            mover_snitch(campo,&juego);
        }

        imprimir_matriz(campo);
    }
    mostrar_resultado(juego);
    //imprimir_matriz(campo);
    return 0;
}



























