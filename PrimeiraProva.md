## Questão 1: As divisões da computação gráfica dê uma exemplo para cada: 

sintese: modelo matemático ---> imagem

visão computacional: imagem---> modelo matemático

processamento: imagem ---> imagem

## Questão 2: A importância do sketpad para evolução da computação gráfica.

## Questão 3: Encontre o erro no código: 

No primero código que ela deu em sala, estude a ordem em que as coisas são 
implementadas, principalmente a parte do main, como mostrado abaixo:

int main(int argc, char ** argv)

{

 	glutInit(&argc, argv);
  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
	glutInitWindowSize(500,500);
  
	glutCreateWindow("It's Done");
	
	glutDisplayFunc(FUNCTION);
  
	glutMainLoop();
  
	return 0;
  }

