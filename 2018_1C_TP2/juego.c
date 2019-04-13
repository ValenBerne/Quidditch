#include "quidditch.h"
#include"sombrero.h"
#include <stdio.h>

void imprimir_pantalla(char campo[MAXFILAS][MAXCOLUMNAS]){

	for(int i=0; i<MAXFILAS; i++){
		for(int j=0; j<MAXCOLUMNAS; j++){
			if(campo[i][j]==' '){
				printf("-");
			}
			else if(campo[i][j]=='S'){
				printf("S");
			}
			else if(campo[i][j]=='B'){
				printf("B");
			}
			else if(campo[i][j]=='J'){
				printf("J");
			}
			else if(campo[i][j]=='D'){
				printf("D");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void bucle_juego(char campo[MAXFILAS][MAXCOLUMNAS], juego_t *juego){

	while((*juego).estado==EJECUCION){
		imprimir_pantalla(campo);
		pedir_movimiento((*juego).posicion_jugador);
		mover_jugador(campo, (*juego).direccion, juego);
		if((*juego).casa=='H'){
			pedir_movimiento((*juego).posicion_jugador);
			mover_jugador(campo, (*juego).direccion, juego);
		}
		mover_bludgers(campo, juego);
		mover_snitch(campo, juego);
		finalizo_juego(juego);
	}

	mostrar_resultado(*juego);

}

int main(){
	char campo[MAXFILAS][MAXCOLUMNAS];
	char casa=obtener_casa();
	juego_t juego;

	inicializar_juego(campo, casa, &juego);

	imprimir_pantalla(campo);





}
