#ifndef QUIDDITCH_H
#define QUIDDITCH_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define FILA_INICIAL_JUGADOR 12
#define COLUMNA_INICIAL_JUGADOR 7
#define COLUMNA_INICIAL_BLUDGERS 0
#define MAXFILAS 25
#define MAXCOLUMNAS 15
#define MINFILAS 0
#define MINCOLUMNAS 0
#define GOLPEBLUDGERS 10
#define PERDIO 2
#define GANO 1
#define EJECUCION 0
#define DIST_SNITCH_QUIETA 10
#define DIST_INICIAL_SNITCH 5
#define BLUDGERS_PAREDES 15


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
	coordenada_t posicion_bludgers[COLUMNA_INICIAL_BLUDGERS];
	char direccion; // 'D': derecha – 'I': izquierda

	int dementores_en_juego; // tope del vector posicion_dementores
	coordenada_t posicion_dementores[MAXFILAS];

	int estado; // 0: en ejecucion – 1: jugador gano – 2: jugador perdio
} juego_t;

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE inicializar_juego
 */
void inicializar_juego(char campo[MAXFILAS][MAXCOLUMNAS], char casa, juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
char pedir_movimiento(coordenada_t posicion_jugador);

/*void imprimir_campo(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego);

 *
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_jugador(char campo[MAXFILAS][MAXCOLUMNAS], char direccion, juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_snitch(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego);

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
 */
void mover_bludgers(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego);

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

#endif