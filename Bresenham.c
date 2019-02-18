#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
void Bresenham(int X1,int Y1, int X2,int Y2)
{
	float dx = fabs(X2 - X1), dy = fabs(Y2 - Y1);
	float p = 2 * dy - dx;
	float twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
	float X, Y;
	// determinar qual ponto final usar como posição inicial
	if(X1 > X2){
		X = X2;
		Y = Y2;
		X2 = X1;
	}
	else{
		X = X1;
		Y = Y1;
	}
	printf("%f, %f\n",X,Y );
	while(X < X2){
		X++;
		if(p > 0)
			p+= twody;
		else{
			Y++;
			p+= twodyminusdx;
		}
	printf("%f, %f\n",X,Y );
	}
}

int main(int argc, char const *argv[])
{
	clock_t Ticks[2];
    Ticks[0] = clock();
    int k=0;
	while(k<10000){
		Bresenham(3,3,9,7);
		k++;
	}
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
	return 0;
}

