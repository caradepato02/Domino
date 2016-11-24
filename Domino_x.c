#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//Rodrigo Reyes Hernandez 310925
//Isaac Juarez Gordillo 315962
//Cesar Venzor Corral 311111
void archivo(char nombres[], float player[], int n);
void generador(float fichas[]);
void nrandom(int arreglo[], int size);
void nrepartir(int arreglo[], float fichas[], float p[], int *k);

main()
{
	/* solicitud de cantidad de jugadores */
	int jugadores;
	int ciclar = 1;
	printf("Cuantos jugadores? ");
	do {
		scanf("%d", &jugadores);
		if (jugadores < 2 || jugadores > 4) {
			printf("Numero de jugadores no valido\n");
		} else {
			ciclar = 0;
		}
	} while (ciclar);
	
	/* Solicitud de nombres de jugadores */
	char nombres[jugadores][50];
	int i, j;
	for(i=0;i<jugadores;i++)
	{
		printf("Ingresa el nombre del jugador %d: ",i+1);
		fflush(stdin);
		gets(nombres[i]);
	}
	
	
	/* Generador de fichas */
	float fichas[28];
	generador(fichas);
	
	/* Generador random */
	int arreglo[28];
	nrandom(arreglo, 28);
	
	/* Reparticion de fichas y creacion de archvios */
	float player[jugadores][6];
	int k = 0,n=1;
	for (i = 0; i < jugadores; i++) 
	{
		nrepartir(arreglo, fichas, player[i], &k);
		archivo(nombres[i],player[i],n);
		n++;	
	}
	printf("%d\n", k);
	
	/* Fichas de la bolsa */
	float bolsa[28-k];
	printf("Bolsa:\n");
	FILE *bolsita;
	bolsita=fopen("Bolsa.txt","w");
	for(i=0,k;k<28;k++,i++)
	{
		bolsa[i]=arreglo[k];
		printf("%.1f\n",bolsa[k]);
		fprintf(bolsita,"%.1f\n",bolsa[k]);
	}
	fclose(bolsita);
		
	/* Impresion de las fichas de los jugadores */
	for (i = 0; i < jugadores; i++) {
		printf("%s\n",nombres[i]);
		for (j = 0; j < 6; j++) {
			printf("%.1f\n", player[i][j]);
		}	
	}	
}

/* nuevo random */
void nrandom(int arreglo[], int size)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < size; i++) {
		arreglo[i] = i;
	}
	
	for (i = 0; i < size; i++) {
		int tmp = arreglo[i];
		int indice = rand() % size;
		
		arreglo[i] = arreglo[indice];
		arreglo[indice] = tmp;
	}
	
}

/* nuevo repartir v2.0 */
void nrepartir(int arreglo[], float fichas[], float p[], int *k)
{
	int j;
		for (j = 0; j < 6; j++) {
			p[j] = fichas[arreglo[*k]];
			*k += 1;
		}
}

/* Generador de fichas */
void generador(float fichas[])
{
	float k,c;
	int i,j,n,a,b,d;
	for(i=0,k=0,n=0;i<28;i++,k++)
	{
		fichas[i]=(k/10);
		if(k==6) 
		{	
			k=n++;
		}
	}
	for(a=0,b=0,c=0,d=7;a<28;a++,b++)
	{
		if(b==d) 
		{	
			c++;
			b=0;
			d--;
		}
		fichas[a]=(fichas[a]+c);
		//printf("%.1f\n",fichas[a]);
	}
}

/* escribir archivo */
void archivo(char nombres[], float player[],int n)
{
	int i,j;
	char h[5],p[5]="P";
	FILE *fe;
	itoa(n,h,10);
	strcat( nombres, ".txt");
	strcat(p,h);
	strcat(p," ");
	strcat(p, nombres);
	fe=fopen(p,"w");
	for (i=0;i<6;i++)
	{
		fprintf(fe,"%.1f\n",player[i]);
	}
	fclose(fe);
}

