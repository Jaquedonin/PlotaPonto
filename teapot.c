 #include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>




void display () {
	//luz 1
	GLfloat luz_ambiente[] = {1.0,1.0,0.0,1.0};
	GLfloat luz_difusa[] = {0.5,0.5,1.0,1.0};
	GLfloat luz_especular[] = {0.5,0.5,1.0,1.0};
	GLfloat luz_posicao[] = {1.0,1.0,0.0,1.0};
	glLightfv(GL_LIGHT0,GL_AMBIENT,luz_ambiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_difusa);
	glLightfv(GL_LIGHT0,GL_SPECULAR,luz_especular);
	glLightfv(GL_LIGHT0,GL_POSITION,luz_posicao);

	//luz 2
	GLfloat luz_ambiente1[] = {1.0,0.0,0.0,1.0};
	GLfloat luz_difusa1[] = {0.5,0.5,0.5,1.0};
	GLfloat luz_especular1[] = {0.5,0.5,0.5,1.0};
	GLfloat luz_posicao1[] = {0.0,0.0,1.0,1.0};
	glLightfv(GL_LIGHT1,GL_AMBIENT,luz_ambiente1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,luz_difusa1);
	glLightfv(GL_LIGHT1,GL_SPECULAR,luz_especular1);
	glLightfv(GL_LIGHT1,GL_POSITION,luz_posicao1);

	//material
	GLfloat especular[] = {1.0,0.5,0.5,1.0};
	GLfloat ambiente[] = {0.0,0.0,0.0,1.0};
	GLfloat difuso[] = {0.5,0.5,0.5,0.5};
	
	

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//habilita luz 1
	glEnable(GL_LIGHT0);
	//habilita luz 2
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	//Z-BUFFER
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_MATERIAL1);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,1.0,100.0);
	glViewport(0, 0, 400, 400); 
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0.0, 0.0, -40.0 );
	//APLICANDO EM MATERIAL
	glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuso);
	glMaterialfv(GL_FRONT,GL_AMBIENT, ambiente);
	glutSolidTeapot(.5);

	glFlush();

}

int main ( int argc, char * argv[] ) {

	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Jaqueline");
	glutDisplayFunc(display);
	glutMainLoop();
}
