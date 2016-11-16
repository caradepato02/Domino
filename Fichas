#include <stdio.h>

main()
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
		//printf("%f\n",fichas[i]);
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
