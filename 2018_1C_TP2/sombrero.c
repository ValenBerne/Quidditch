#include "sombrero.h"

char obtener_casa(){
	
	int fuerza, valor, inteligencia, ingenio, dedicacion;
	char casa;
	
	int superatributos=0;
	// Ahora puse un contador para ver que no haya más de 2 superatributos

	bool cantidad_valida_de_superatributos=true;
	while(cantidad_valida_de_superatributos){
		printf("Buen día Hechicero, bienvenido a Hogwarts \n");
		printf("Vamos a ver en que casa vas a estar \n");
	
		printf("Veamos cuanto tienes de cada atributo, Cuanto tienes de Fuerza? \n");
		scanf("%d", &fuerza);
	
		while(fuerza>VALOR_MAXIMO_ATRIBUTOS||fuerza<VALOR_MINIMO_ATRIBUTOS){
			printf("No tienes permitido mentirme, los atributos se miden del 1 al 10. Esta vez no me mientas...\n");
			scanf("%d", &fuerza);
		}
		if(fuerza>8){
			superatributos++;
		}   
		printf("interesante...\n");
		
		printf("Cuan valiente eres Hechicero? \n");
		scanf("%i", &valor);
		while(valor>VALOR_MAXIMO_ATRIBUTOS||valor<VALOR_MINIMO_ATRIBUTOS){
			printf("No seas mentiroso, los atributos se miden del 1 al 10. Esta vez no me mientas...\n");    
			scanf("%d", &valor);
		}
		if(valor>8){
			superatributos++;
		}   
		printf("Lo tendre en cuenta...\n");
	
		printf("Que tan inteligente eres Hechicero? \n");
		scanf("%i", &inteligencia);
		while(inteligencia>VALOR_MAXIMO_ATRIBUTOS||inteligencia<VALOR_MINIMO_ATRIBUTOS){
			printf("A mi no me timas, por mÃ¡s inteligente te creas, mÃ¡s tonto eres. El dicho tambien se aplica al revez.\nLos tributos se miden del 1 al 10. Esta vez sin metiras...\n");
			scanf("%i", &inteligencia);
		}
		printf("Algunos son modestos y otros se pasan de listos\n");
		if(inteligencia>8){
			superatributos++;
		}
		
		printf("Que tan ingenioso eres Hechicero? \n");
		scanf("%i", &ingenio);
		while(ingenio>VALOR_MAXIMO_ATRIBUTOS||ingenio<VALOR_MINIMO_ATRIBUTOS){
			printf("Basta de mentiras, los tributos se miden del 1 al 10.\n");
			scanf("%i", &ingenio);
		}
		printf("Ya veo...\n");
		if(ingenio>8){
		superatributos++;
		}
		
		printf("Que tan dedicado eres? \n");
		scanf("%i", &dedicacion);
		while(dedicacion>VALOR_MAXIMO_ATRIBUTOS||dedicacion<VALOR_MINIMO_ATRIBUTOS){
			printf("A mi no me engaÃ±as, los tributos se miden del 1 al 10.\n");
			scanf("%i", &dedicacion);
		}
		printf("Si tu dices...\n");
		if(dedicacion>8){
		superatributos++;
		}
	
		// Con el contador cada vez que el atributo es mayor a 8 cuenta 1 más, para ver cuantos superatributos tenemos. Ahora validamos cuantos superatributos tenemos
		if(superatributos>CANTIDAD_MAXIMA_DE_SUPERATRIBUTOS){
			cantidad_valida_de_superatributos=true;
			printf("\n");
			printf("Tenes más de dos superatributos, esto no esta permitido (superatributos=valores con más de 8). En Hogwarts no se miente!!\n");
			printf("\n");
		}
		else{
			cantidad_valida_de_superatributos=false;
		}
	}
		
	if(fuerza>8&&valor>8&&ingenio<5&&superatributos<=CANTIDAD_MAXIMA_DE_SUPERATRIBUTOS){
		printf("Bienvenido a Griffindor Hechicero, espero que seas feliz en la casa del leon!\n");
		casa='G';
	}
	else if(inteligencia>8&&ingenio>8&&superatributos<=CANTIDAD_MAXIMA_DE_SUPERATRIBUTOS){
		printf("Bienvenido a Ravenclaw Hechicero, la casa del conocimiento y el saber!");
		casa='R';
	}
	else if (inteligencia>5&&inteligencia<8&&ingenio>8&&superatributos<=CANTIDAD_MAXIMA_DE_SUPERATRIBUTOS){
		printf("Bienvenido a Slytherin Hechicero, la casa de la serpiente. Conoceras sus pasillos y ganaras la copa en Algoritmos y programacion 1 Mendez");
		casa='S';
	}
	else if(superatributos<=CANTIDAD_MAXIMA_DE_SUPERATRIBUTOS){
		printf("Bienvenido a Hufflepuff.... Bueno... A trabajar duro");
		casa='H';
	}


	return casa;
};