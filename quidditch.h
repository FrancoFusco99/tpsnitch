#ifndef QUIDDITCH_H
#define QUIDDITCH_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_FILAS_CAMPO 25
#define MAX_COLUMNAS_CAMPO 15
#define FILA_INICIAL_JUGADOR 12
#define COLUMNA_INICIAL_JUGADOR 7
#define FILA_INICIAL_BLUDGER0 2
#define FILA_INICIAL_BLUDGER1 7
#define FILA_INICIAL_BLUDGER2 12
#define FILA_INICIAL_BLUDGER3 17
#define FILA_INICIAL_BLUDGER4 22
#define COLUMNA_INICIAL_BLUDGER 0
#define COLUMNA_FINAL_BLUDGER 14
#define FILA_INICIAL_DEMENTOR0 5
#define COLUMNA_INICIAL_DEMENTOR0 3
#define FILA_INICIAL_DEMENTOR1 5
#define COLUMNA_INICIAL_DEMENTOR1 11
#define FILA_INICIAL_DEMENTOR2 19
#define COLUMNA_INICIAL_DEMENTOR2 3
#define FILA_INICIAL_DEMENTOR3 19
#define COLUMNA_INICIAL_DEMENTOR3 11
#define COLUMNA_INICIAL_CAMPO 0
#define COLUMNA_FINAL_CAMPO 14
#define FILA_INICIAL_CAMPO 0
#define FILA_FINAL_CAMPO 24

#define JUGADOR 'J'
#define DEMENTORES 'D'
#define BLUDGERS 'B'
#define SNITCH 'S'

#define VALOR_VACIO '*'

#define RESISTENCIA_INICIAL 50
#define CANTIDAD_BLUDGERS 5
#define CANTIDAD_DEMENTORES 4
#define MINIMA_DISTANCIA_SNITCH 5
#define MAXIMA_DISTANCIA_SNITCH 10
#define GOLPE_BLUDGER 10

#define ARRIBA 'w'
#define ABAJO 's'
#define DERECHA 'd'
#define IZQUIERDA 'a'

#define EN_EJECUCION 0
#define GANO 1
#define PERDIO 2

#define DER 'D'
#define IZQ 'I'



/* ACA VAN LAS CONSTANTES */

typedef struct coordenada {
	int fila;
	int columna;
} coordenada_t;

typedef struct juego {
	coordenada_t posicion_jugador;
	char casa;
	int resistencia;
	coordenada_t posicion_snitch;

	int bludgers_en_juego; // tope del vector posicion_bludgers
	coordenada_t posicion_bludgers[CANTIDAD_BLUDGERS];
	char direccion; // 'D': derecha – 'I': izquierda

	int dementores_en_juego; // tope del vector posicion_dementores
	coordenada_t posicion_dementores[CANTIDAD_DEMENTORES];
	
	int estado; // 0: en ejecucion – 1: jugador gano – 2: jugador perdio
} juego_t;

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE inicializar_juego
 */
void inicializar_juego(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], char casa, juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
char pedir_movimiento(coordenada_t posicion_jugador);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_jugador(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], char direccion, juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_snitch(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_bludgers(char campo[MAX_FILAS_CAMPO][MAX_COLUMNAS_CAMPO], juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
coordenada_t posicion_inicial_snitch();

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
bool finalizo_juego(juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mostrar_resultado(juego_t juego);

#endif /* QUIDDITCH_H */
