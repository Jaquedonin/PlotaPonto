#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
	



GLfloat anguloTierra=0.0; 
GLfloat anguloLuna=0.0; 
GLfloat traslacionTierra=1.5; 
GLfloat traslacionLuna=0.5; 
GLfloat r=0.0; 

void funcionDePintado (void) 
{ 
//color de fondo 
glEnable(GL_DEPTH_TEST);//habilitamos test de profundidad 
glClearColor(0.0, 0.0, 0.0, 0.0);//cargamos color para pantalla 
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//limpiamos la pantalla 
glLoadIdentity();//cargamos la matriz identidad 
glTranslatef(0.0, 0.0, -5.0);//alejamos la camara 
glRotatef(90,1.0,0.0,0.0); 
//si hacemos traslacion de tierra y luna 
if(r==2) 
{ 
glPushMatrix();//colocamos la matriz de transformación en la cima de la pila 
//color de dibujo 

glColor3f (1.0, 1.0, 0.0); 
glutWireSphere(0.8,20,20);//sol 
glRotatef(anguloTierra,0.0,0.0,1.0); 
glTranslatef(traslacionTierra,0.0,0.0); 
glColor3f(0.0,0.0,1.0); 
glutWireSphere(0.3,10,10);//tierra 
glRotatef(anguloLuna,0.0,0.0,1.0); 
glTranslatef(traslacionLuna,0.0,0.0); 
glColor3f(0.5,0.5,0.5); 
glutWireSphere(0.1,10,10);//luna 
// glFlush(); 
glPopMatrix(); 
glutSwapBuffers();//intercambiamos los buffers 
} 
else 
{ 
	glPushMatrix(); 
	glColor3f (1.0, 1.0, 0.0); 
	glutWireSphere(0.8,20,20);//sol 
	glRotatef(anguloTierra,0.0,0.0,1.0); 
	//glTranslatef(traslacionTierra,0.0,0.0); 
	glColor3f(0.0,0.0,1.0); 
	glutWireSphere(0.3,10,10);//tierra 
	glRotatef(anguloLuna,0.0,0.0,1.0); 
	glTranslatef(traslacionLuna,0.0,0.0); 
	glColor3f(0.5,0.5,0.5); 
	glutWireSphere(0.1,10,10);//luna 
	glutSwapBuffers();//intercambiamos los buffers 
	glPopMatrix(); 
} 
} 

void funcionDeReescalado(GLsizei w, GLsizei h) 
{ 
	glMatrixMode (GL_PROJECTION); //activar la matriz de proyeccion 
	glLoadIdentity (); 
	//glFrustum(-1.5, 1.5, -1.5, 1.5, 2.0, 10.0);//establecemos el frustrum de visualizado (izq,der,abaj,arrib,cerca,lejos) 
	gluPerspective(60.0, (float)w/(float)h, 2.0, 7.0); 
	glViewport (0, 0, w, h); 
	glMatrixMode (GL_MODELVIEW); //activar la matriz de modelo-vista 
} 

void funcionRotarTrasladar(unsigned char key, int x, int y) 
{ 
	if((key=='r')||(key=='R')) 
	{ 
	anguloTierra+=5.0; 
	anguloLuna+=5.0; 

	if(anguloTierra>=360) 
	{ 
	anguloTierra=0.0; 
	} 
	if(anguloLuna>=360) 
	{ 
	anguloLuna=0.0; 
	} 
	funcionDePintado(); 
	r=1; 
	} 
	if((key=='t')||(key=='T')) 
	{ 
	anguloTierra+=5.0; 
	anguloLuna+=5.0; 
	if(anguloTierra>=360) 
	{ 
	anguloTierra=0.0; 
	} 
	if(anguloLuna>=360) 
	{ 
	anguloLuna=0.0; 
	} 
	funcionDePintado(); 
	r=2; 
	} 

} 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowSize(800,600); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("Jaqueline Sistema Solar"); 
	glutReshapeFunc(funcionDeReescalado); 
	glutKeyboardFunc (funcionRotarTrasladar); 
	glutDisplayFunc(funcionDePintado); 
	glutMainLoop(); 
	return 0; 
}