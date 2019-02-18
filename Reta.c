#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
void FunReta(int X1,int Y1, int X2,int Y2)
{
	
	float X = X1,Y = Y1;
	int dx = X2 - X1, dy = Y2 - Y1;
	float m = (float) dy/ (float) dx;
	float dx2=0;
	printf("%f, %f\n",X,Y );
	while(X<X2){
		X++;
		dx2 = X - X1;
		Y = m*dx2 + Y1;
		//setpixel(Round(X),Round(Y));
		printf("%f, %f\n",X,Y );
		
	}
}
int main(int argc, char const *argv[])
{
	clock_t Ticks[2];
    Ticks[0] = clock();
    int k=0;
	while(k<10000){
		FunReta(3,3,9,7);
		k++;
	}
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
	return 0;
}

