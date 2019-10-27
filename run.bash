# // Computer Graphics
# // Profa. Raquel Landa
# // Rento Sánchez Nevares
# // A01281104
# // Septiembre 28, 2019

#!/bin/bash

echo Jelleo Yellow!

clang -o model.o model_A01281104.c -L/System/Library/Frameworks -framework GLUT -framework OpenGL && clear


echo Compiled!
echo Running...

./model.o
