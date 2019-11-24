# // Computer Graphics
# // Profa. Raquel Landa
# // Rento Sánchez Nevares
# // A01281104
# // Septiembre 28, 2019

#!/bin/bash

echo Jelleo Yellow!

g++ -o modelCPlusPlus model_A01281104_cplusplus.cpp -L/System/Library/Frameworks -framework GLUT -framework OpenGL && clear


echo Compiled!
echo Running...

./modelCPlusPlus
