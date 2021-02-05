/*
 * spicoli piersivlio
 * traccia aereoporto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

//nuovo tipo di dato strutturato
typedef struct{
	char id_volo[5];
	char partenza[50];
	char arrivo[50];
	int totali;
	int occupati;
	int disp;
}vol;

//dichiarazione array di record
vol voli[max];

//dichiarazione prototipi
void input(vol[]);
void output(vol[]);
void gestionePren(vol[]);

//variabili globali
int i, n_voli = 0, posti_input = 0;
int pos, flag, flagId; //flag di controllo di gestionePren

int main(){

	setbuf(stdout, NULL);

	input(voli);
	gestionePren(voli);
	printf("\n");
	output(voli);

	return 0;
}

void input(vol arr[]){ //parametro formale - per indirizzo i vettori sempre per indirizzo

	do{
		printf(":: inserire il numero di voli: ");
		scanf("%d", &n_voli);
	}while(n_voli <= 0);


	for(i = 0; i < n_voli; i++){

		printf("\n");
		printf(":: codice volo: ");
		scanf("%s", arr[i].id_volo);
		printf(":: data partenza: ");
		scanf("%s", arr[i].partenza);
		printf(":: data arrivo: ");
		scanf("%s", arr[i].arrivo);
		printf(":: posti totali: ");
		scanf("%d", &arr[i].totali);
		printf(":: posti occupati: ");
		scanf("%d", &arr[i].occupati);

		arr[i].disp = arr[i].totali - arr[i].occupati;
	}
}

void output(vol arr[]){

	printf("tabella aggiornata\n\n");
	for(i = 0; i < n_voli; i++){
		printf(":: codice del volo: %s\n", arr[i].id_volo);
		printf(":: data di partenza: %s \n", arr[i].partenza);
		printf(":: data di arrivo: %s \n", arr[i].arrivo);
		printf(":: posti totali: %d \n", arr[i].totali);
		printf(":: posti occupati: %d \n", arr[i].occupati);
		printf(":: posti disponibili: %d \n", arr[i].disp);
	}
}

void gestionePren(vol arr[]){

	char id_volo[5];

	flag = 0;

	printf(":: inserire il codice del volo da ricercare: ");
	scanf("%s", id_volo);

	/*do{
		i = 0;
		if(strcmp(id_volo, arr[i].id_volo) == 0){

			flagId = 1;
			controlloPosti(arr);
		}
		i += 1;
	}while(i < n_voli && flagId == 1);*/

	do{
		flagId = 0;
		for(i = 0; i < n_voli; i++){
				if(strcmp(id_volo, arr[i].id_volo) == 0){

							flagId = 1;
							do{
									printf(":: inserire numero posti: ");
									scanf("%d", &posti_input);
								}while(posti_input <= 0);

								if(posti_input <= arr[i].disp){

									flag = 1;
									pos = i;

									arr[i].occupati += posti_input;
									arr[i].disp -= posti_input;
								}
					}
			}
	}while(flagId == 0);


	if(flagId == 0){
		printf(":: citta non presente");
	}else if(flag == 0){
		printf(":: richiesta non effettuata");
	}else{
		printf("richiesta acettata ecco i dati: \n\n");
		printf(":: posti richiesti: %d\n", posti_input);
		printf(":: codice del volo: %s \n", arr[pos].id_volo);
		printf(":: data di partenza: %s\n", arr[pos].partenza);
		printf(":: data di arrivo: %s\n", arr[pos].arrivo);
		printf(":: posti totali: %d\n", arr[pos].totali);
		printf(":: posti occupati: %d\n", arr[pos].occupati);
		printf(":: posti disponibili: %d\n", arr[pos].disp);
	}
}

