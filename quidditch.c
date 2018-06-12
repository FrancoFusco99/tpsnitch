#include "quidditch.h"
#include "sombrero.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


void inicializar_juego(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], char casa, juego_t *juego){ //aca establezco como empiezan todos los elemntos

    for(int i=0;i<MAX_FILAS_CAMPO;i++){
        for(int j=0;j<MAX_COLUMNAS_CAMPO;j++){     
       campo[i][j]=VALOR_VACIO;
        }
    }      

    juego->posicion_jugador.fila=FILA_INICIAL_JUGADOR;
    juego->posicion_jugador.columna=COLUMNA_INICIAL_JUGADOR;
    campo[juego->posicion_jugador.fila][juego->posicion_jugador.columna]=JUGADOR;

    juego->resistencia=RESISTENCIA_INICIAL;
    
    juego->direccion = DER;

    juego->posicion_snitch=posicion_inicial_snitch();
    campo[juego->posicion_snitch.fila][juego->posicion_snitch.columna]=SNITCH;
    
    juego->bludgers_en_juego=CANTIDAD_BLUDGERS;
    juego->posicion_bludgers[0].fila=FILA_INICIAL_BLUDGER0;
    juego->posicion_bludgers[0].columna=COLUMNA_INICIAL_BLUDGER;
    campo[juego->posicion_bludgers[0].fila][juego->posicion_bludgers[0].columna]=BLUDGERS;
    juego->posicion_bludgers[1].fila=FILA_INICIAL_BLUDGER1;
    juego->posicion_bludgers[1].columna=COLUMNA_INICIAL_BLUDGER;
    campo[juego->posicion_bludgers[1].fila][juego->posicion_bludgers[1].columna]=BLUDGERS;
    juego->posicion_bludgers[2].fila=FILA_INICIAL_BLUDGER2;
    juego->posicion_bludgers[2].columna=COLUMNA_INICIAL_BLUDGER;
    campo[juego->posicion_bludgers[2].fila][juego->posicion_bludgers[2].columna]=BLUDGERS;
    juego->posicion_bludgers[3].fila=FILA_INICIAL_BLUDGER3;
    juego->posicion_bludgers[3].columna=COLUMNA_INICIAL_BLUDGER;
    campo[juego->posicion_bludgers[3].fila][juego->posicion_bludgers[3].columna]=BLUDGERS;
    juego->posicion_bludgers[4].fila=FILA_INICIAL_BLUDGER4;
    juego->posicion_bludgers[4].columna=COLUMNA_INICIAL_BLUDGER;
    campo[juego->posicion_bludgers[4].fila][juego->posicion_bludgers[4].columna]=BLUDGERS;
    
    juego->dementores_en_juego=CANTIDAD_DEMENTORES;
    juego->posicion_dementores[0].fila=FILA_INICIAL_DEMENTOR0;
    juego->posicion_dementores[0].columna=COLUMNA_INICIAL_DEMENTOR0;
    campo[juego->posicion_dementores[0].fila][juego->posicion_dementores[0].columna]=DEMENTORES;
    juego->posicion_dementores[1].fila=FILA_INICIAL_DEMENTOR1;
    juego->posicion_dementores[1].columna=COLUMNA_INICIAL_DEMENTOR1;
    campo[juego->posicion_dementores[1].fila][juego->posicion_dementores[1].columna]=DEMENTORES;
    juego->posicion_dementores[2].fila=FILA_INICIAL_DEMENTOR2;
    juego->posicion_dementores[2].columna=COLUMNA_INICIAL_DEMENTOR2;
    campo[juego->posicion_dementores[2].fila][juego->posicion_dementores[2].columna]=DEMENTORES;
    juego->posicion_dementores[3].fila=FILA_INICIAL_DEMENTOR3;
    juego->posicion_dementores[3].columna=COLUMNA_INICIAL_DEMENTOR3;
    campo[juego->posicion_dementores[3].fila][juego->posicion_dementores[3].columna]=DEMENTORES;
    
    juego->estado = EN_EJECUCION;

}

bool direccion_valida(char direccion,coordenada_t posicion_jugador){

    bool validar_direccion=false;

    if(((direccion==ARRIBA)&&(posicion_jugador.fila==FILA_INICIAL_CAMPO))
        ||((direccion==ABAJO)&&(posicion_jugador.fila==FILA_FINAL_CAMPO))
        ||((direccion==DERECHA)&&(posicion_jugador.columna==COLUMNA_FINAL_CAMPO))
        ||((direccion==IZQUIERDA)&&(posicion_jugador.columna==COLUMNA_INICIAL_CAMPO))){
        validar_direccion=false;
    }else{
        validar_direccion=true;
    }

    if (validar_direccion) printf("La direccion es valida\n");
    else printf("La direccion no es valida\n");

    return validar_direccion;
}

char pedir_movimiento(coordenada_t posicion_jugador){ //interaccion con el usuario, se le pide el movimiento

    char direccion;
    printf("Ejecutando pedir_movimiento\n");
    printf("Ingrese su movimiento \n");
    scanf(" %c",&direccion);

    printf("Eligió %c \n",direccion);

    while((direccion != ARRIBA) && (direccion != ABAJO) && (direccion != DERECHA) && (direccion != IZQUIERDA)){
        printf("Eligió %c: Boton ingresado erroneo. Ingreselo nuevamente\n",direccion);
        scanf(" %c",&direccion);
   }
    //Falta validar si la direccion es valida
    return direccion;
}

void mover_jugador(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], char direccion, juego_t *juego){
    int fila_siguiente_jugador=((juego->posicion_jugador.fila)+1);
    int fila_anterior_jugador=((juego->posicion_jugador.fila)-1);
    int columna_siguiente_jugador=((juego->posicion_jugador.columna)+1);
    int columna_anterior_jugador=((juego->posicion_jugador.columna)-1);

    int fila_inicial = juego->posicion_jugador.fila;
    int columna_inicial = juego->posicion_jugador.columna;
   
    printf("Ejecutando mover_jugador\n");
    printf("Parametro direccion recibido: %c\n",direccion);

    if(direccion==ARRIBA){
        printf("mover_jugador: arriba\n");
        juego->posicion_jugador.fila=fila_anterior_jugador;  
        campo[fila_anterior_jugador][juego->posicion_jugador.columna]=JUGADOR;
        juego->resistencia --;
    }
    if(direccion==ABAJO){
        printf("mover_jugador: abajo\n");
        juego->posicion_jugador.fila=fila_siguiente_jugador;    
        campo[fila_siguiente_jugador][juego->posicion_jugador.columna]=JUGADOR;
        juego->resistencia --;
    }
    if(direccion==DERECHA){
        printf("mover_jugador: derecha\n");
        juego->posicion_jugador.columna=columna_siguiente_jugador;         
        campo[juego->posicion_jugador.fila][columna_siguiente_jugador]=JUGADOR;
        juego->resistencia --;
    }
    if(direccion==IZQUIERDA){
        printf("mover_jugador: izquierda\n");
        juego->posicion_jugador.columna=columna_anterior_jugador;                 
        campo[juego->posicion_jugador.fila][columna_anterior_jugador]=JUGADOR;
        juego->resistencia --;
    } 
    if(juego->resistencia>0){
        juego->estado=EN_EJECUCION;
    }  
    else if(juego->resistencia<=0){
        juego->estado=PERDIO;
    }

    for(int i=0;i<(juego->bludgers_en_juego); i++) {    
        if((juego->posicion_jugador.fila==juego->posicion_bludgers[i].fila)&&(juego->posicion_jugador.columna==juego->posicion_bludgers[i].columna)) {
            
            printf("Golpeo con Bludger\n");
            campo[juego->posicion_bludgers[i].fila][juego->posicion_bludgers[i].columna]=JUGADOR; //Si golpea una bludger, desaparece

            if(juego->casa!=SLYTHERIN){
                juego->resistencia=(juego->resistencia-GOLPE_BLUDGER);
            }

            if(juego->resistencia>0){
                juego->estado=EN_EJECUCION;
            }  
            else if(juego->resistencia<=0){
                juego->estado=PERDIO;
            }
        }
    }
    for(int i=0;i<(juego->dementores_en_juego);i++){   
        if((juego->posicion_jugador.fila==juego->posicion_dementores[i].fila)&&(juego->posicion_jugador.columna==juego->posicion_dementores[i].columna)){
            if(juego->casa==GRYFFINDOR){  //habilidad de gryffindor
                campo[juego->posicion_dementores[i].fila][juego->posicion_dementores[i].columna]=JUGADOR;
                juego->dementores_en_juego--;
                juego->estado=EN_EJECUCION;
            }else if(juego->casa!=GRYFFINDOR){
                juego->estado=PERDIO;
            }
        }
    }
    if (juego->casa==RAVENCLAW) {
        for(int i=fila_anterior_jugador;i<=fila_siguiente_jugador;i++){  //habilidad de ravenclaw 
            for(int j=columna_anterior_jugador;j<=columna_siguiente_jugador;j++){ 
                if(campo[i][j]==SNITCH){
                    juego->estado=GANO;    
                }
            }
        }
    }
    
    campo[fila_inicial][columna_inicial] = VALOR_VACIO; // Elimino la posicion anterior del jugador en el campo
}

int calcular_distancia(coordenada_t coordenada_1,coordenada_t coordenada_2){ //funcion generica para calcular distancia
    int distancia;
    printf("Calculando distancia\n");
    distancia = abs((coordenada_1.fila)-(coordenada_2.fila)) + abs((coordenada_1.columna)-(coordenada_2.columna));
    printf("Distancia: %i\n",distancia);
    return distancia;  
}  

void mover_snitch(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], juego_t *juego){ 
    
    coordenada_t posicion_adyacente_snitch;
    int distancia_momentanea=0;
    int distancia_maxima=0;
    int fila_siguiente=((juego->posicion_snitch.fila)+1);
    int fila_anterior=((juego->posicion_snitch.fila)-1);
    int columna_siguiente=((juego->posicion_snitch.columna)+1);
    int columna_anterior=((juego->posicion_snitch.columna)-1);
    int fila_inicial = juego->posicion_snitch.fila;
    int columna_inicial = juego->posicion_snitch.columna;

    printf("Ejecutando mover_snitch\n");
    printf("Posicion Snitch [%i][%i]\n",fila_inicial,columna_inicial);
   
    int distancia = calcular_distancia(juego->posicion_snitch,juego->posicion_jugador);//movimiento de la snitch
    
    if(distancia <= MAXIMA_DISTANCIA_SNITCH) {

        bool no_movi_snitch = true;

        //caso de las esquinas de la matriz
        if(no_movi_snitch && (juego->posicion_snitch.fila==FILA_INICIAL_CAMPO)&&(juego->posicion_snitch.columna==COLUMNA_INICIAL_CAMPO)&&(campo[1][1]==VALOR_VACIO)){
            juego->posicion_snitch.fila=1;
            juego->posicion_snitch.columna=1;
            no_movi_snitch = false;
        }
        if(no_movi_snitch && (juego->posicion_snitch.fila==FILA_FINAL_CAMPO)&&(juego->posicion_snitch.columna==COLUMNA_INICIAL_CAMPO)&&(campo[23][1]==VALOR_VACIO)){
            juego->posicion_snitch.fila=23;
            juego->posicion_snitch.columna=1;
            no_movi_snitch = false;
        }
        if(no_movi_snitch && (juego->posicion_snitch.fila==FILA_FINAL_CAMPO)&&(juego->posicion_snitch.columna==COLUMNA_FINAL_CAMPO)&&(campo[23][13]==VALOR_VACIO)){
            juego->posicion_snitch.fila=23;
            juego->posicion_snitch.columna=13;
            no_movi_snitch = false;
        }
        if(no_movi_snitch && (juego->posicion_snitch.fila==FILA_INICIAL_CAMPO)&&(juego->posicion_snitch.columna==COLUMNA_FINAL_CAMPO)&&(campo[1][13]==VALOR_VACIO)){
            juego->posicion_snitch.fila=1;
            juego->posicion_snitch.columna=13;
            no_movi_snitch = false;
        }

        //casos de los bordes de la matriz
        if (no_movi_snitch && juego->posicion_snitch.columna==COLUMNA_INICIAL_CAMPO){ // caso borde izquierdo

            if (campo[fila_siguiente][1] == VALOR_VACIO && campo[fila_anterior][1] == VALOR_VACIO) { //Me muevo solo si esta vacio
                posicion_adyacente_snitch.fila = fila_siguiente;  
                posicion_adyacente_snitch.columna = 1;
                int distancia_uno = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo abajo
                
                posicion_adyacente_snitch.fila = fila_anterior;  
                int distancia_dos = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo arriba

                juego->posicion_snitch.columna = 1;
                if (distancia_uno > distancia_dos) {
                    juego->posicion_snitch.fila = fila_siguiente;
                } else {
                    juego->posicion_snitch.fila = fila_anterior;
                }
                no_movi_snitch = false;
            }
            
            if (campo[fila_anterior][1] == VALOR_VACIO) { //Solo esta vacio arriba
                juego->posicion_snitch.fila = fila_anterior;
                juego->posicion_snitch.columna = 1;
                no_movi_snitch = false;
            }

            
            if (campo[fila_siguiente][1] == VALOR_VACIO) { //Solo esta vacio abajo
                juego->posicion_snitch.fila = fila_siguiente;
                juego->posicion_snitch.columna = 1;
                no_movi_snitch = false;
            }          

        }
        if (no_movi_snitch && juego->posicion_snitch.fila==FILA_INICIAL_CAMPO){ // caso borde superior
            
            if (campo[1][columna_siguiente] == VALOR_VACIO && campo[1][columna_anterior] == VALOR_VACIO) { //Me muevo solo si esta vacio
                posicion_adyacente_snitch.fila = 1;  
                posicion_adyacente_snitch.columna =columna_siguiente;
                int distancia_uno = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo abajo
                
                posicion_adyacente_snitch.columna = columna_anterior;  
                int distancia_dos = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo arriba

                juego->posicion_snitch.fila = 1;
                if (distancia_uno > distancia_dos) {
                    juego->posicion_snitch.columna = columna_siguiente;
                } else {
                    juego->posicion_snitch.fila = columna_anterior;
                }
                no_movi_snitch = false;
            }
            
            if (campo[1][columna_anterior] == VALOR_VACIO) { //Solo esta vacio arriba
                juego->posicion_snitch.fila = 1;
                juego->posicion_snitch.columna = columna_anterior;
                no_movi_snitch = false;
            }

            
            if (campo[1][columna_siguiente] == VALOR_VACIO) { //Solo esta vacio abajo
                juego->posicion_snitch.fila = 1;
                juego->posicion_snitch.columna = columna_siguiente;
                no_movi_snitch = false;
            }  

        }
        if (no_movi_snitch && juego->posicion_snitch.fila==FILA_FINAL_CAMPO){ // caso borde inferior

            if (campo[23][columna_siguiente] == VALOR_VACIO && campo[23][columna_anterior] == VALOR_VACIO) { //Me muevo solo si esta vacio
                posicion_adyacente_snitch.fila = 23;  
                posicion_adyacente_snitch.columna =columna_siguiente;
                int distancia_uno = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo abajo
                
                posicion_adyacente_snitch.columna = columna_anterior;  
                int distancia_dos = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo arriba

                juego->posicion_snitch.fila = 23;
                if (distancia_uno > distancia_dos) {
                    juego->posicion_snitch.columna = columna_siguiente;
                } else {
                    juego->posicion_snitch.fila = columna_anterior;
                }
                no_movi_snitch = false;
            }
            
            if (campo[23][columna_anterior] == VALOR_VACIO) { //Solo esta vacio arriba
                juego->posicion_snitch.fila = 23;
                juego->posicion_snitch.columna = columna_anterior;
                no_movi_snitch = false;
            }

            
            if (campo[23][columna_siguiente] == VALOR_VACIO) { //Solo esta vacio abajo
                juego->posicion_snitch.fila = 23;
                juego->posicion_snitch.columna = columna_siguiente;
                no_movi_snitch = false;
            } 
        }
        if (no_movi_snitch && juego->posicion_snitch.columna==COLUMNA_FINAL_CAMPO) { // caso borde derecho
            
            if (campo[fila_siguiente][13] == VALOR_VACIO && campo[fila_anterior][1] == VALOR_VACIO) { //Me muevo solo si esta vacio
                posicion_adyacente_snitch.fila = fila_siguiente;  
                posicion_adyacente_snitch.columna = 13;
                int distancia_uno = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo abajo
                
                posicion_adyacente_snitch.fila = fila_anterior;  
                int distancia_dos = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador); // calculo arriba

                juego->posicion_snitch.columna = 13;
                if (distancia_uno > distancia_dos) {
                    juego->posicion_snitch.fila = fila_siguiente;
                } else {
                    juego->posicion_snitch.fila = fila_anterior;
                }
                no_movi_snitch = false;
            }
            
            if (campo[fila_anterior][13] == VALOR_VACIO) { //Solo esta vacio arriba
                juego->posicion_snitch.fila = fila_anterior;
                juego->posicion_snitch.columna = 13;
                no_movi_snitch = false;
            }
            
            if (campo[fila_siguiente][13] == VALOR_VACIO) { //Solo esta vacio abajo
                juego->posicion_snitch.fila = fila_siguiente;
                juego->posicion_snitch.columna = 13;
                no_movi_snitch = false;
            }          
        }

        if (no_movi_snitch) {
            for(int i=fila_anterior;i<=fila_siguiente;i++){  //distancia mas alejada de la snitch con respecto al jugador 
                for(int j=columna_anterior;j<=columna_siguiente;j++){
                    if (!(i == fila_inicial) && !(j == columna_inicial)) { //Solo quiero las esquinas
                        posicion_adyacente_snitch.fila = i;
                        posicion_adyacente_snitch.columna = j; 
                        distancia_momentanea = calcular_distancia(posicion_adyacente_snitch,juego->posicion_jugador);

                        if ( distancia_momentanea > distancia_maxima && campo[i][j] == VALOR_VACIO) { // Se queda con la primera posicion maxima que sea vacia
                            distancia_maxima = distancia_momentanea;
                            juego->posicion_snitch.fila = i;
                            juego->posicion_snitch.columna = j;
                            no_movi_snitch = false;
                        }
                    }
                }
            }
        }
        if (!no_movi_snitch) {
            campo[fila_inicial][columna_inicial] = VALOR_VACIO;
            campo[juego->posicion_snitch.fila][juego->posicion_snitch.columna] = SNITCH;
        }
    }
}

int calcular_numero_al_azar_fila(){
    return rand()%MAX_FILAS_CAMPO;
}

int calcular_numero_al_azar_columna(){
    return rand()%MAX_COLUMNAS_CAMPO;
}

coordenada_t posicion_inicial_snitch(){

    coordenada_t prueba_de_posicion;
    coordenada_t posicion_inicial_snitch;
    coordenada_t posicion_inicial_jugador;

    posicion_inicial_jugador.fila=FILA_INICIAL_JUGADOR;
    posicion_inicial_jugador.columna=COLUMNA_INICIAL_JUGADOR;


    prueba_de_posicion.fila=calcular_numero_al_azar_fila();

    prueba_de_posicion.columna=calcular_numero_al_azar_columna();
    
    if(calcular_distancia(prueba_de_posicion,posicion_inicial_jugador)<MINIMA_DISTANCIA_SNITCH){
        coordenada_t posicion_inicial_snitch();    
    }else if(calcular_distancia(prueba_de_posicion,posicion_inicial_jugador)>=MINIMA_DISTANCIA_SNITCH){
        posicion_inicial_snitch.fila=prueba_de_posicion.fila;
        posicion_inicial_snitch.columna=prueba_de_posicion.columna;
    }

    return posicion_inicial_snitch;
}

void mover_bludgers(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], juego_t *juego) {

    if(juego->direccion==DER){ 
        for(int i=0;i<(juego->bludgers_en_juego);i++){

            int columna_inicial = juego->posicion_bludgers[i].columna;
            int fila_inicial = juego->posicion_bludgers[i].fila;

            juego->posicion_bludgers[i].columna++;

            if((juego->posicion_jugador.fila==juego->posicion_bludgers[i].fila)&&(juego->posicion_jugador.columna==juego->posicion_bludgers[i].columna)){
                juego->bludgers_en_juego--;
                if(juego->casa!=SLYTHERIN){
                    //campo[juego->posicion_bludgers[i].fila][juego->posicion_bludgers[i].columna]=JUGADOR;            
                    juego->resistencia=(juego->resistencia-GOLPE_BLUDGER);
                }

                campo[juego->posicion_jugador.fila][juego->posicion_jugador.columna] = JUGADOR;
            } 

            if (campo[juego->posicion_bludgers[i].fila][juego->posicion_bludgers[i].columna] == VALOR_VACIO ) {
                campo[juego->posicion_bludgers[i].fila][juego->posicion_bludgers[i].columna] = BLUDGERS;
            }

            if ( campo[fila_inicial][columna_inicial] != JUGADOR) campo[fila_inicial][columna_inicial] = VALOR_VACIO;
            
            if(juego->posicion_bludgers[i].columna==COLUMNA_FINAL_BLUDGER){
                    juego->direccion=IZQ;
            }
        }
    }
    else if(juego->direccion==IZQ){ 
        for(int j=0;j<(juego->bludgers_en_juego);j++){
           
            int columna_inicial = juego->posicion_bludgers[j].columna;
            int fila_inicial = juego->posicion_bludgers[j].fila;

            juego->posicion_bludgers[j].columna--;

            if((juego->posicion_jugador.fila==juego->posicion_bludgers[j].fila)&&(juego->posicion_jugador.columna==juego->posicion_bludgers[j].columna)){
                juego->bludgers_en_juego--;
                if(juego->casa!=SLYTHERIN){
                    //campo[juego->posicion_bludgers[i].fila][juego->posicion_bludgers[i].columna]=JUGADOR;            
                    juego->resistencia=(juego->resistencia-GOLPE_BLUDGER);
                }

                campo[juego->posicion_jugador.fila][juego->posicion_jugador.columna] = JUGADOR;
            } 

            if (campo[juego->posicion_bludgers[j].fila][juego->posicion_bludgers[j].columna] == VALOR_VACIO) {
                campo[juego->posicion_bludgers[j].fila][juego->posicion_bludgers[j].columna] = BLUDGERS;
            }

            if ( campo[fila_inicial][columna_inicial] != JUGADOR) campo[fila_inicial][columna_inicial] = VALOR_VACIO;
            
            if(juego->posicion_bludgers[j].columna==COLUMNA_INICIAL_BLUDGER){
                juego->direccion=DER;
            }
        }
    }

    if(juego->resistencia>0){
        juego->estado=EN_EJECUCION;
    }   
    else {
        juego->estado=PERDIO;
    }
}

bool finalizo_juego(juego_t *juego){
    bool finalizo_juego=true;

    if(juego->estado==GANO||juego->estado==PERDIO){
        finalizo_juego=true;
    }else{ 
        finalizo_juego=false;
    }
    return finalizo_juego;
}

void mostrar_resultado(juego_t juego){
    if(juego.estado==GANO){
        printf("GANASTE \n");
    }else if (juego.estado==PERDIO){
        printf("PERDISTE \n");
    } else {
        printf("SIGUE EL JUEGO\n");
    }
}