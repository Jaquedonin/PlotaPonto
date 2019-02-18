#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void FunReta(int X1,int Y1, int X2,int Y2)
{
	float X = X1,Y = Y1;
	int dx = X2 - X1, dy = Y2 - Y1;
	float m = (float) dy/ (float) dx;
	float dx2=0;
	glVertex2d(X,Y);
	while(X<X2){
		X++;
		dx2 = X - X1;
		Y = m*dx2 + Y1;
		glVertex2d(X,Y);
	}
}
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
	glVertex2d(X,Y);
	int k=0;
	while(k<Length){
		X = X + Xinc;
		Y = Y + Yinc;
		glVertex2d(X,Y);
		k++;
	}
}
void Bresenham(int X1,int Y1, int X2,int Y2)
{
	int dx = fabs(X2 - X1), dy = fabs(Y2 - Y1);
	int p = 2 * dy - dx;
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
	int X, Y;
	if(X1 > X2){
		X = X2;
		Y = Y2;
		X2 = X1;
	}
	else{
		X = X1;
		Y = Y1;
	}
	glVertex2d(X,Y);
	while(X < X2){
		X++;
		if(p < 0)
			p+= twody;
		else{
			Y++;
			p+= twodyminusdx;
		}
	glVertex2d(X,Y);
	}
}
void FUNCTION (){
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1,1,1);
	glBegin(GL_POINTS);

	FunReta(3,3,9,7);
	DDA(3,3,9,7);
	Bresenham(3,3,9,7);

	glEnd();
	glFlush();
};
int main(int argc, char ** argv)
{
 	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("It's Done");
	
	glutDisplayFunc(FUNCTION);
	glutMainLoop();
	return 0;}





