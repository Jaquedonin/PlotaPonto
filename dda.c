#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
void DDA(int X1,int Y1, int X2,int Y2)
{
	int Length, I;
	float X,Y,Xinc,Yinc;
	int dx = X2 - X1, dy = Y2 - Y1;
	
	if (fabs(dy) > fabs(dx))
		Length = fabs(Y2-Y1);
	else
		Length = fabs(X2 - X1);
	Xinc = (float) dx/ (float) Length;
	Yinc = (float) dy/ (float) Length;
	X = X1;
	Y = Y1;
	printf("%f, %f\n",X,Y );
	//setpixel(Round(X),Round(Y));
	int k=0;
	while(k<Length){
		//setpixel(Round(X),Round(Y));
		X = X + Xinc;
		Y = Y + Yinc;
		printf("%f, %f\n",X,Y );
		k++;
	}
}
int main(int argc, char const *argv[])
{
	clock_t Ticks[2];
    Ticks[0] = clock();
    int k=0;
	while(k<10000){
		DDA(3,3,9,7);
		k++;
	}
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
	return 0;
}
