#include "quidditch.h"



/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE inicializar_juego
 */
void inicializar_juego(char campo[MAXFILAS][MAXCOLUMNAS], char casa, juego_t *juego){
	(*juego).posicion_snitch = posicion_inicial_snitch();
	for(int i=0; i<(*juego).bludgers_en_juego; i++){
		(*juego).posicion_bludgers[i].columna=0;
	}
	(*juego).posicion_bludgers[0].fila=2;
	(*juego).posicion_bludgers[1].fila=7;
	(*juego).posicion_bludgers[2].fila=12;
	(*juego).posicion_bludgers[3].fila=17;
	(*juego).posicion_bludgers[4].fila=22;
	(*juego).posicion_dementores[0].fila=5;
	(*juego).posicion_dementores[0].columna=3;
	(*juego).posicion_dementores[1].fila=11;
	(*juego).posicion_dementores[1].columna=11;
	(*juego).posicion_dementores[2].fila=19;
	(*juego).posicion_dementores[2].columna=3;
	(*juego).posicion_dementores[3].fila=19;
	(*juego).posicion_dementores[3].columna=11;
	(*juego).posicion_jugador.fila=FILA_INICIAL_JUGADOR;
	(*juego).posicion_jugador.columna=COLUMNA_INICIAL_JUGADOR;

}




/*
    ACA VAN LAS PRE Y POST CONDICIONES DE pedir_movimiento
    Pre: recibir las coordenadas del jugador para evitar movimientos que lo lleven afuera del campo,
    Post: dar una direccion validada (que no salga del campo) a donde mover al jugador
 */
char pedir_movimiento(coordenada_t posicion_jugador){

	printf("Para donde quieres volar?");
	printf("\n");
	bool valido=false;
	char direccion;
	while(!valido){
		scanf(" %c", &direccion);
		switch(direccion){

				case 'w':
					if(posicion_jugador.fila>MINFILAS){
						valido=true;
					}
					break;

				case 's':
					if(posicion_jugador.fila<MAXFILAS){
						valido=true;
					}
					break;
				case 'a':
					if(posicion_jugador.columna>MINCOLUMNAS){
						valido=true;
					}
					break;
				case 'd':
					if(posicion_jugador.columna<MAXCOLUMNAS){
						valido=true;
					}
					break;
		}
		if(!valido){
			printf("Direccion invalida, solo podes moverte con W, A, S y D");
		}
	}
	return direccion;
}


/*  ACA VAN LAS PRE Y POST CONDICIONES DE mover_jugador
    Pre: recibir un movimiento validado de pedir_movimiento
    Post:
 */
void mover_jugador(char campo[MAXFILAS][MAXCOLUMNAS], char direccion, juego_t *juego){

	if(direccion=='w'){
		(*juego).posicion_jugador.fila--;
		(*juego).resistencia--;
	}
	else if(direccion=='s'){
		(*juego).posicion_jugador.fila++;
		(*juego).resistencia--;
	}
	else if(direccion=='a'){
		(*juego).posicion_jugador.columna--;
		(*juego).resistencia--;
	}
	else if(direccion=='d'){
		(*juego).posicion_jugador.columna++;
		(*juego).resistencia--;
	}

	if((*juego).posicion_jugador.fila==(*juego).posicion_snitch.fila && (*juego).posicion_jugador.columna==(*juego).posicion_snitch.columna){
		(*juego).estado=GANO;
	}

	for(int i=0; i<(*juego).bludgers_en_juego; i++){
		if(((*juego).posicion_bludgers[i].columna)==(*juego).posicion_jugador.columna && ((*juego).posicion_bludgers[i].fila)==(*juego).posicion_jugador.fila && (*juego).casa!='S'){
			((*juego).resistencia)=((*juego).resistencia)-GOLPEBLUDGERS;
			for(int i=0; i<(*juego).bludgers_en_juego-1; i++){
				(*juego).posicion_bludgers[i].fila=(*juego).posicion_bludgers[i+1].fila;
				(*juego).posicion_bludgers[i].columna=(*juego).posicion_bludgers[i+1].columna;
			}
			(*juego).bludgers_en_juego--;
		}
	}

	for(int i=0; i<(*juego).dementores_en_juego; i++){
		if((*juego).posicion_jugador.fila==(*juego).posicion_dementores[i].fila && (*juego).posicion_jugador.columna==(*juego).posicion_dementores[i].columna && (*juego).casa!='G'){
			(*juego).resistencia=0;
			(*juego).dementores_en_juego--;
		}
		else if((*juego).posicion_jugador.fila==(*juego).posicion_dementores[i].fila && (*juego).posicion_jugador.columna==(*juego).posicion_dementores[i].columna && (*juego).casa=='G'){
			(*juego).posicion_dementores[i].fila=(*juego).posicion_dementores[i+1].fila;
			(*juego).dementores_en_juego--;
		}
	}

	if((*juego).resistencia<=0){
		(*juego).estado=PERDIO;
	}
}


/*
    ACA VAN LAS PRE Y POST CONDICIONES DE mover_snitch
    Pre: no tiene
    Post: Mover la Snitch a donde este más lejos del jugador (si esta a una distancia menor o igual a 10) y que este movimiento este orientado a arriba a la izquierda si es la misma distancia en dos opciones
 */
void mover_snitch(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego){
	int izquierda_arrib=0, izquierda_abaj=0, derecha_arrib=0, derecha_abaj=0, dist_snitch_jugador=0;
	izquierda_arrib=abs((*juego).posicion_snitch.fila-(*juego).posicion_jugador.fila-1)+abs((*juego).posicion_snitch.columna-(*juego).posicion_jugador.columna-1);
	izquierda_abaj=abs((*juego).posicion_snitch.fila-(*juego).posicion_jugador.fila+1)+abs((*juego).posicion_snitch.columna-(*juego).posicion_jugador.columna-1);
	derecha_arrib=abs((*juego).posicion_snitch.fila-(*juego).posicion_jugador.fila-1)+abs((*juego).posicion_snitch.columna-(*juego).posicion_jugador.columna+1);
	derecha_abaj=abs((*juego).posicion_snitch.fila-(*juego).posicion_jugador.fila+1)+abs((*juego).posicion_snitch.columna-(*juego).posicion_jugador.columna+1);

	dist_snitch_jugador=abs((((*juego).posicion_snitch).fila)-(((*juego).posicion_jugador).fila))+abs((((*juego).posicion_snitch).columna)-(((*juego).posicion_jugador).columna));

	if((*juego).posicion_snitch.fila==0){
		izquierda_arrib=0;
		derecha_arrib=0;
	}

	if((*juego).posicion_snitch.fila==15){
		izquierda_abaj=0;
		derecha_abaj=0;
	}

	if((*juego).posicion_snitch.columna==0){
		izquierda_arrib=0;
		izquierda_abaj=0;
	}

	if((*juego).posicion_snitch.columna==25){
		derecha_arrib=0;
		derecha_abaj=0;
	}

	if(DIST_SNITCH_QUIETA>=dist_snitch_jugador){
		if(izquierda_abaj<izquierda_arrib && derecha_arrib<izquierda_arrib && derecha_abaj<izquierda_arrib && (*juego).posicion_snitch.fila>=1 && (*juego).posicion_snitch.columna>=1){
			((*juego).posicion_snitch).fila--;
			((*juego).posicion_snitch).columna--;
		}
		else if(izquierda_arrib<izquierda_abaj && derecha_arrib<izquierda_abaj && derecha_abaj<izquierda_abaj && (*juego).posicion_snitch.fila<MAXFILAS && (*juego).posicion_snitch.columna>=1){
			((*juego).posicion_snitch).fila++;
			((*juego).posicion_snitch).columna--;
		}
		else if(izquierda_abaj<derecha_arrib && izquierda_arrib<derecha_arrib && derecha_abaj<derecha_arrib && (*juego).posicion_snitch.fila>=1 && (*juego).posicion_snitch.columna<MAXCOLUMNAS){
			((*juego).posicion_snitch).fila--;
			((*juego).posicion_snitch).columna++;
		}
		else if(izquierda_abaj<derecha_abaj && derecha_arrib<derecha_abaj && izquierda_arrib<derecha_abaj && (*juego).posicion_snitch.fila<MAXFILAS && (*juego).posicion_snitch.columna<MAXCOLUMNAS){
			((*juego).posicion_snitch).fila++;
			((*juego).posicion_snitch).columna++;
		}
		else if(izquierda_abaj==izquierda_arrib || derecha_arrib==izquierda_arrib || derecha_abaj==izquierda_arrib){
			((*juego).posicion_snitch).fila--;
			((*juego).posicion_snitch).columna--;
		}
		else if(izquierda_arrib==izquierda_abaj||derecha_arrib==izquierda_abaj||derecha_abaj==izquierda_abaj){
			((*juego).posicion_snitch).fila++;
			((*juego).posicion_snitch).columna--;
		}
		else if(izquierda_abaj==derecha_arrib||derecha_arrib==izquierda_arrib||derecha_abaj==derecha_arrib){
			((*juego).posicion_snitch).fila--;
			((*juego).posicion_snitch).columna++;
		}
		else if(izquierda_abaj==derecha_abaj||derecha_arrib==derecha_abaj||derecha_abaj==izquierda_arrib){
			((*juego).posicion_snitch).fila++;
			((*juego).posicion_snitch).columna++;
		}
	}
}

/*
    ACA VAN LAS PRE Y POST CONDICIONES DE mover_bludgers
    Pre: No hay
    Post: si le dan al jugador desaparecer y restarle 10, si esta la Snitch moverse y que en el mapa aparezca la Snitch arriba
 */
void mover_bludgers(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego){
	for(int i=0; i<(*juego).bludgers_en_juego; i++){
		if((*juego).direccion=='D' && ((*juego).posicion_bludgers[i].columna+1)!=(*juego).posicion_snitch.columna && (((*juego).posicion_bludgers[i]).fila)!=(*juego).posicion_snitch.fila){
			(*juego).posicion_bludgers[i].columna++;
		}
		else if((*juego).direccion=='I' && ((*juego).posicion_bludgers[i].columna-1)!=(*juego).posicion_snitch.columna && ((*juego).posicion_bludgers[i].fila)!=(*juego).posicion_snitch.fila){
			(*juego).posicion_bludgers[i].columna--;
		}
	}

	for(int i=0; i<(*juego).bludgers_en_juego; i++){
		if(((*juego).posicion_bludgers[i].columna)==(*juego).posicion_jugador.columna && ((*juego).posicion_bludgers[i].fila)==(*juego).posicion_jugador.fila && (*juego).casa!='S'){
			((*juego).resistencia)=((*juego).resistencia)-GOLPEBLUDGERS;
			for(int i=0; i<(*juego).bludgers_en_juego; i++){
				(*juego).posicion_bludgers[i].fila=(*juego).posicion_bludgers[i+1].fila;
				(*juego).posicion_bludgers[i].columna=(*juego).posicion_bludgers[i+1].columna;
			}
			(*juego).bludgers_en_juego--;
		}
	}

}

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE POSICION_INICIAL_SNITCH
 * Pre: Nada
 * Post: Estas a 5 o más casilleros de la posicion inicial del jugador y ser aleatoria
 */
coordenada_t posicion_inicial_snitch(){
	coordenada_t posicion_snitch;
	posicion_snitch.fila=0;
	posicion_snitch.columna=0;

	int dist_snitch_jugador=6;

	while(dist_snitch_jugador<5){
		srand((unsigned int)clock());
		posicion_snitch.fila=rand()%(MAXFILAS);
		posicion_snitch.columna=rand()%(MAXCOLUMNAS);

 		dist_snitch_jugador=abs(posicion_snitch.fila-FILA_INICIAL_JUGADOR)+abs(posicion_snitch.columna-COLUMNA_INICIAL_JUGADOR);
	}

	return posicion_snitch;
}

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE finalizo_juego
 */
bool finalizo_juego(juego_t *juego) {
	return ((*juego).estado!=EJECUCION);
}

/*
 * ACA VAN LAS PRE Y POST CONDICIONES DE mostrar_resultado
 */
void mostrar_resultado(juego_t juego) {
	if(juego.estado==PERDIO){
		printf("Perdio");
	}
	else{
		printf("Ganaste");
	}
}
