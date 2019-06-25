 #include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//variaveis globais
GLfloat anguloTerra=0.0;
GLfloat anguloMarte=0.0;
 GLfloat traslSol=0.10;
GLfloat traslTerra=0.50;
GLfloat traslMarte=0.75;
GLfloat i=0.0;
int j = 0; 

void functionDesenha (void) 
{ 
	
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//vista esquerda
			glColorMask(0,0,1,0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-1.0,1.0,-1.0,1.0,1.0,100.0);
			// Especifica as dimensões da Viewport
			glViewport(0, 0, 400, 400); 
			glMatrixMode (GL_MODELVIEW);
			glLoadIdentity();
			glTranslated(0.0, 0.0, -40.0 );
			glRotatef(90,1.0,0.0,0.0);
	
			glPushMatrix(); 
			glColor3f (1.0, 1.0, 1.0);//amarelo 
			glutWireSphere(0.2,20,20);//sol aramado
			glRotatef(anguloTerra,0.0,0.0,1.0); 
			glTranslatef(traslTerra,0.0,0.0); 

			glutWireSphere(0.1,10,10);//terra aramada
			glPopMatrix();
			glPushMatrix(); 
			glRotatef(anguloMarte,0.0,0.0,1.0); 
			glTranslatef(traslMarte,0.0,0.0); 

			glutWireSphere(0.1,10,10);//marte aramada
			

			

		
		//vista direita
			glColorMask(1,0,0,0);
			glMatrixMode (GL_MODELVIEW);
			glLoadIdentity();
			glTranslated(0.0, 0.0, -40.0 );
			glRotatef(4,0.0,1.0,0.0);
			glRotatef(90,1.0,0.0,0.0);
			
			glPushMatrix(); 
			glColor3f (1.0, 1.0, 0.0);//amarelo 
			glutWireSphere(0.2,20,20);//sol aramado
			glRotatef(anguloTerra,0.0,0.0,1.0); 
			glTranslatef(traslTerra,0.0,0.0); 

			glutWireSphere(0.1,10,10);//terra aramada
			glPopMatrix();
			glPushMatrix(); 
			glRotatef(anguloMarte,0.0,0.0,1.0); 
			glTranslatef(traslMarte,0.0,0.0); 

			glutWireSphere(0.1,10,10);//marte aramada
			glColorMask(1,1,1,0);
			glClearColor(0.0, 0.0, 0.0, 0.0);

	glFlush(); 
					
	
} 

void functionReescalado(GLsizei w, GLsizei h) 
{ 
	if (j==1)
	{
		glMatrixMode (GL_PROJECTION);  
		glLoadIdentity (); 
		gluPerspective(90.0, (float)w/(float)h, 2.0, 7.0); 
		glViewport (0, 0, w, h); 
		glMatrixMode (GL_MODELVIEW); 
		glLoadIdentity();
		glTranslated(0.0, 0.0, -5.0 );
		glRotatef(90,1.0,0.0,0.0);

		
	}
	if (j==0)
	{
		
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1.0,1.0,-1.0,1.0,1.0,800.0);
		// Especifica as dimensões da Viewport
		glViewport(0, 0, w, h); 
		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity();
		glTranslated(0.0, 0.0, -20.0 );
		glRotatef(90,1.0,0.0,0.0);
			 
	} 
} 

void functionRotaTransl(unsigned char key, int x, int y) 
{ 
	if((key=='a')||(key=='A')) 
	{ 
		anguloTerra+=5.0;
		anguloMarte+=2.0;
	
		if(anguloTerra>=360) 
		{ 
			anguloTerra=0.0; 	
		} 

		functionDesenha(); 
		i=1; 
	}

	if((key=='s')||(key=='S')) 
	{ 
		anguloTerra+=5.0; 
		anguloMarte+=2.0;
	
		if(anguloMarte>=360) 
		{ 
			anguloTerra=0.0; 
			anguloMarte=0.0;
		}

		functionDesenha(); 
		i=2; 
	} 

	if((key=='P')||(key=='p')) 
	{ 
		j=1; 
	} 

	if((key=='O')||(key=='o')) 
	{ 
		j=0; 
	} 

	if((key=='E')||(key=='e')) 
	{ 
		glEnable(GL_DEPTH_TEST); 
	}

} 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(800,400); 
	//glutInitWindowPosition(400,300); 
	glutCreateWindow("Jaqueline Sistema Solar"); 
	//glutReshapeFunc(functionReescalado); 
	glutKeyboardFunc (functionRotaTransl); 
	glutDisplayFunc(functionDesenha); 
	//glutDisplayFunc(functionDesenha);
	glutMainLoop(); 
	return 0; 
}
