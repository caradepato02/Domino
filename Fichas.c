#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int ficha(void);
int random(void);
int repartir(void);

main()
{
	int p1[6], p2[6], p3[6], p4[6],total[28],r;
	float fichas[28];
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
	
	for(j=0;j<7;j++)
	{
		
		r=repartir();
		//sleep(1);
		p1[j]=fichas[r];
		printf("%d\n",p1[j]);
	}
}

//Generador de fichas
int ficha(void)
{
	float fichas[28];
	float k,c;
	int i,n,a,b,d;
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
		printf("%.1f\n",fichas[a]);
	}
	return(0);
}

//Generador aleatorio
int random(void)
{
	int random;
	time_t t;
	srand((unsigned) time (&t));
	random = rand()%27;
	return(random); 
}

//Reparticion
int repartir(void)
{
	int i,j,k,r,select[28]={30};
	//for(i=0;i<7;i++)
	//{
		do
		{
			r=random();
		}while(r==select[r]);
		select[r]=r;
		return(r);
	//}
	
}
