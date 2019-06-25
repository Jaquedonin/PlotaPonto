# Disciplina de computação gráfica UFPB

Neste repositório estão os trabalhos da disciplina de computação gráfica com a professora Liliane. 

## Configurações do ambiente

 Funções da Reta, DDA , Bresenham e biblioteca GLUT

### Para instalação da biblioteca GLUT utilize:

$sudo apt-get install freeglut3-dev

$sudo apt-cache search glut

### Verificar a instalação

$dpkg -L freeglut3-dev

### Para compilar os códigos utilize:

$ gcc -o  codigo 'nomedoprograma'.c -lglut -lGL -lGLU -lGLEW -lSDL2main -lSDL2 -lm

### Se não houver erro, compile o comando abaixo:

$ ./codigo

### Verifique se todas as bibliotecas foram instaladas
