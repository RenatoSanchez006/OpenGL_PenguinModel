// Computer Graphics
// Profa. Raquel Landa
// Rento Sánchez Nevares
// A01281104
// Septiembre 28, 2019

#include <stdio.h>
#include <GLUT/glut.h>

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function Prototypes
void display();
void keyboard(unsigned char key, int x, int y);
void makeTexture();
void init();
// Global Variables
double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
double translate_x = 0;
double translate_y = 0;
double translate_z = 0;
double scale = 1;

#define textureHeight 64
#define textureWidth 64
static GLubyte textureImage[textureHeight][textureWidth][4];
int width, height, colours;

int main(int argc, char *argv[])
{

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(640, 680); // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner

	// Create window
	glutCreateWindow("Penguin Model - A01281104");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	init();
	// Callback functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;
}

void display(void)
{
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// gluLookAt(0.0f, 0.0f, 5.0f,
	// 		  0.0f, 0.0f, 0.0f,
	// 		  0.0f, 1.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);

	// Translate FIGURE
	glTranslatef(translate_x, translate_y, translate_z);

	// Scale FIGURE
	glScalef(scale, scale, scale);

	/* glBegin(GL_LINES);
	// X AXIS
	glColor3f(0.86, 0.20, 0.27);
	glVertex3f(1, 0, 0);
	glVertex3f(-1, 0, 0);
	// Y AXIS
	glColor3f(0.15, 0.65, 0.27);
	glVertex3f(0, 1, 0);
	glVertex3f(0, -1, 0);
	// Z AXIS
	glColor3f(0.0, 0.48, 1.0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, -1);
	glEnd(); */

	glColor3f(0.97, 0.97, 0.98); // white
	float bodyVertices [] = {
		// FRONT
		0.4, -.7, -0.3,
		0.4, .30, -0.3, 
		-0.4, .30, -0.3,
		-0.4, -0.7, -0.3,
		// RIGHT
		0.4, -0.7, -0.3,
		0.4, 0.3, -0.3,
		0.4, 0.3, 0.1,
		0.4, -0.7, 0.1,
		// LEFT
		-0.4, -0.7, 0.1,
		-0.4, 0.3, 0.1,
		-0.4, 0.3, -0.3,
		-0.4, -0.7, -0.3,
		// BOTTOM
		0.4, -0.7, -0.3,
		0.4, -0.7, 0.1,
		-0.4, -0.7, 0.1,
		-0.4, -0.7, -0.3
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	// glEnable(GL_TEXTURE_2D);
	glVertexPointer(3, GL_FLOAT, 0, bodyVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	// glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float ojoIzqVertices [] = {
		// Ojo izq front
		-0.4, 0.4, -0.15,
		-0.4, 0.6, -0.15,
		-0.45, 0.6, -0.15,
		-0.45, 0.4, -0.15,
		// Ojo back
		-0.4, 0.4, 0.05,
		-0.4, 0.6, 0.05,
		-0.45, 0.6, 0.05,
		-0.45, 0.4, 0.05,
		// Ojo left
		-0.45, .4, 0.05,
		-0.45, 0.6, 0.05,
		-0.45, 0.6, -0.15,
		-0.45, 0.4, -0.15,
		// Ojo top
		-0.45, 0.6, -0.15,
		-0.45, 0.6, 0.05,
		-0.4, 0.6, 0.05,
		-0.4, 0.6, -0.15,
		// Ojo bottom
		-0.45, 0.4, -0.15,
		-0.45, 0.4, 0.05,
		-0.4, 0.4, 0.05,
		-0.4, 0.4, -0.15,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, ojoIzqVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float ojoDerVertices [] = {
		// Ojo der front
		0.4, 0.4, -0.15,
		0.4, 0.6, -0.15,
		0.45, 0.6, -0.15,
		0.45, 0.4, -0.15,
		// Ojo back
		0.4, 0.4, 0.05,
		0.4, 0.6, 0.05,
		0.45, 0.6, 0.05,
		0.45, 0.4, 0.05,
		// Ojo right
		0.45, .4, 0.05,
		0.45, 0.6, 0.05,
		0.45, 0.6, -0.15,
		0.45, 0.4, -0.15,
		// Ojo top
		0.45, 0.6, -0.15,
		0.45, 0.6, 0.05,
		0.4, 0.6, 0.05,
		0.4, 0.6, -0.15,
		// Ojo bottoms
		0.45, 0.4, -0.15,
		0.45, 0.4, 0.05,
		0.4, 0.4, 0.05,
		0.4, 0.4, -0.15,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, ojoDerVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glColor3f(0.411, 0.329, 0.533); // purple
	float headBackTailVertices [] = {
		// BACK
		0.4, -0.1, 0.3,
		0.4, 0.8, 0.3,
		-0.4, 0.8, 0.3,
		-0.4, -0.1, 0.3,	
		// BACK COLA
		0.4, -0.7, 0.4,
		0.4, -0.1, 0.4,
		-0.4, -0.1, 0.4,
		-0.4, -0.7, 0.4,
		// RIGHT HEAD
		0.4, 0.8, 0.3,
		0.4, 0.3, 0.3,
		0.4, 0.3, -0.3,
		0.4, 0.8, -0.3,
		// RIGHT BODY
		0.4, 0.3, 0.3,
		0.4, -0.7, 0.3,
		0.4, -0.7, 0.1,
		0.4, 0.3, 0.1,
		// RIGHT TAIL
		0.4, -0.1, 0.3,
		0.4, -0.7, 0.3,
		0.4, -0.7, 0.4,
		0.4, -0.1, 0.4,	
		// LEFT HEAD
		-0.4, 0.8, 0.3,
		-0.4, 0.3, 0.3,
		-0.4, 0.3, -0.3,
		-0.4, 0.8, -0.3,
		// LEFT BODY
		-0.4, 0.3, 0.3,
		-0.4, -0.7, 0.3,
		-0.4, -0.7, 0.1,
		-0.4, 0.3, 0.1,
		// LEFT TAIL
		-0.4, -0.1, 0.3,
		-0.4, -0.7, 0.3,
		-0.4, -0.7, 0.4,
		-0.4, -0.1, 0.4,
		// TOP
		0.4, 0.8, 0.3,
		0.4, 0.8, -0.3,
		-0.4, 0.8, -0.3,
		-0.4, 0.8, 0.3,
		// BOTTOM
		0.4, -0.7, 0.1,
		0.4, -0.7, 0.4,
		-0.4, -0.7, 0.4,
		-0.4, -0.7, 0.1,
		// FRONT HEAD
		0.4, 0.8, -0.3,
		0.4, 0.3, -0.3, 
		-0.4, 0.3, -0.3,
		-0.4, 0.8, -0.3,
		// TOP COLA
		0.4, -0.1, 0.4,
		0.4, -0.1, 0.3,
		-0.4, -0.1, 0.3,
		-0.4, -0.1, 0.4,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, headBackTailVertices);
	glDrawArrays(GL_QUADS, 0, 48);
	glDisableClientState(GL_VERTEX_ARRAY);

	float braIzqVertices [] = {
		// BRAZO FRONT
		-0.4, -0.4, -0.15,
		-0.4, 0.2, -0.15,
		-0.45, 0.2, -0.15,
		-0.45, -0.4, -0.15,
		// BRAZO BACK
		-0.4, 0.2, 0.15,
		-0.4, -0.4, 0.15,
		-0.45, -0.4, 0.15,
		-0.45, 0.2, 0.15,
		// BRAZO LEFT
		-0.45, -0.2, 0.15,
		-0.45, 0.2, 0.15,
		-0.45, 0.2, -0.15,
		-0.45, -0.2, -0.15,
		// BRAZO TOP
		-0.45, 0.2, -0.15,
		-0.45, 0.2, 0.15,
		-0.4, 0.2, 0.15,
		-0.4, 0.2, -0.15,
		// BRAZO BOTTOM
		-0.50, -0.4, -0.15,
		-0.50, -0.4, 0.15,
		-0.4, -0.4, 0.15,
		-0.4, -0.4, -0.15,
		// MANO TOP
		-0.45, -0.2, -0.15,
		-0.45, -0.2, 0.15,
		-0.50, -0.2, 0.15,
		-0.50, -0.2, -0.15,
		// MANO FRONT
		-0.45, -0.4, -0.15,
		-0.45, -0.2, -0.15,
		-0.50, -0.2, -0.15,
		-0.50, -0.4, -0.15,
		// MANO BACK
		-0.45, -0.4, 0.15,
		-0.45, -0.2, 0.15,
		-0.50, -0.2, 0.15,
		-0.50, -0.4, 0.15,
		// BRAZO LEFT
		-0.50, -0.4, 0.15,
		-0.50, -0.2, 0.15,
		-0.50, -0.2, -0.15,
		-0.50, -0.4, -0.15,
		// Ojo left
		-0.451, .475, -0.025,
		-0.451, 0.525, -0.025,
		-0.451, 0.525, -0.075,
		-0.451, 0.475, -0.075,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, braIzqVertices);
	glDrawArrays(GL_QUADS, 0, 40);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float braDerVertices [] = {
		// BRAZO FRONT
		0.4, -0.4, -0.15,
		0.4, 0.2, -0.15,
		0.45, 0.2, -0.15,
		0.45, -0.4, -0.15,
		// BRAZO BACK
		0.4, 0.2, 0.15,
		0.4, -0.4, 0.15,
		0.45, -0.4, 0.15,
		0.45, 0.2, 0.15,
		// BRAZO RIGHT
		0.45, -0.2, 0.15,
		0.45, 0.2, 0.15,
		0.45, 0.2, -0.15,
		0.45, -0.2, -0.15,
		// BRAZO TOP
		0.45, 0.2, -0.15,
		0.45, 0.2, 0.15,
		0.4, 0.2, 0.15,
		0.4, 0.2, -0.15,
		// BRAZO BOTTOM
		0.50, -0.4, -0.15,
		0.50, -0.4, 0.15,
		0.4, -0.4, 0.15,
		0.4, -0.4, -0.15,
		// MANO TOP
		0.45, -0.2, -0.15,
		0.45, -0.2, 0.15,
		0.50, -0.2, 0.15,
		0.50, -0.2, -0.15,
		// MANO FRONT
		0.45, -0.4, -0.15,
		0.45, -0.2, -0.15,
		0.50, -0.2, -0.15,
		0.50, -0.4, -0.15,
		// MANO BACK
		0.45, -0.4, 0.15,
		0.45, -0.2, 0.15,
		0.50, -0.2, 0.15,
		0.50, -0.4, 0.15,
		// BRAZO LEFT
		0.50, -0.4, 0.15,
		0.50, -0.2, 0.15,
		0.50, -0.2, -0.15,
		0.50, -0.4, -0.15,
		// Ojo Der
		0.451, .475, -0.025,
		0.451, 0.525, -0.025,
		0.451, 0.525, -0.075,
		0.451, 0.475, -0.075,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, braDerVertices);
	glDrawArrays(GL_QUADS, 0, 40);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glColor3f(0.992, 0.796, 0.431); // yellow
	float noseVertices [] = {
		// Nariz front
		0.08, 0.40, -0.55,
		0.08, 0.50, -0.55,
		-0.08, 0.50, -0.55,
		-0.08, 0.40, -0.55,
		// Nariz left
		-0.08, .40, -0.3,
		-0.08, 0.50, -0.3,
		-0.08, 0.50, -0.55,
		-0.08, 0.40, -0.55,
		// Nariz right
		0.08, .40, -0.55,
		0.08, 0.50, -0.55,
		0.08, 0.50, -0.3,
		0.08, 0.40, -0.3,
		// Nariz top
		0.08, 0.50, -0.3,
		0.08, 0.50, -0.55,
		-0.08, 0.50, -0.55,
		-0.08, 0.50, -0.3,
		// Nariz bottom
		0.08, 0.40, -0.55,
		0.08, 0.40, -0.3,
		-0.08, 0.40, -0.3,
		-0.08, 0.40, -0.55,
	};

	// glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, noseVertices);
	glDrawArrays(GL_QUADS, 0, 20);
	glDisableClientState(GL_VERTEX_ARRAY);
	// glDisable(GL_TEXTURE_2D);
	
	float patDerVertices [] = {
		// PATA front
		0.1, -0.7, 0.00,
		0.1, -0.8, 0.00,
		0.25, -0.8, 0.00,
		0.25, -0.7, 0.00,
		// PATA back
		0.1, -0.7, 0.15,
		0.1, -0.8, 0.15,
		0.25, -0.8, 0.15,
		0.25, -0.7, 0.15,
		// PATA right
		0.25, -0.7, 0.15,
		0.25, -0.8, 0.15,
		0.25, -0.8, 0.00,
		0.25, -0.7, 0.00,
		// PATA left
		0.1, -0.7, 0.15,
		0.1, -0.8, 0.15,
		0.1, -0.8, 0.00,
		0.1, -0.7, 0.00,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, patDerVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float patIzqVertices [] = {
		// Pata front
		-0.1, -0.7, 0.00,
		-0.1, -0.8, 0.00,
		-0.25, -0.8, 0.00,
		-0.25, -0.7, 0.00,
		// pata back
		-0.1, -0.7, 0.15,
		-0.1, -0.8, 0.15,
		-0.25, -0.8, 0.15,
		-0.25, -0.7, 0.15,
		// pata right
		-0.1, -0.7, 0.15,
		-0.1, -0.8, 0.15,
		-0.1, -0.8, 0.00,
		-0.1, -0.7, 0.00,
		// pata left
		-0.25, -0.7, 0.15,
		-0.25, -0.8, 0.15,
		-0.25, -0.8, 0.00,
		-0.25, -0.7, 0.00,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, patIzqVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float pieDerVertices [] = {
		// Pie front
		0.02, -0.8, -0.45,
		0.02, -0.85, -0.45,
		0.34, -0.85, -0.45,
		0.34, -0.8, -0.45,
		// Pie back
		0.02, -0.8, 0.25,
		0.02, -0.85, 0.25,
		0.34, -0.85, 0.25,
		0.34, -0.8, 0.25,
		// Pie right
		0.34, -0.8, 0.25,
		0.34, -0.85, 0.25,
		0.34, -0.85, -0.45,
		0.34, -0.8, -0.45,
		// Pie left
		0.02, -0.85, 0.25,
		0.02, -0.8, 0.25,
		0.02, -0.8, -0.45,
		0.02, -0.85, -0.45,
		// Pie top
		0.34, -0.8, -0.45,
		0.34, -0.8, 0.25,
		0.02, -0.8, 0.25,
		0.02, -0.8, -0.45,
		// Pie bottom
		0.34, -0.85, -0.45,
		0.34, -0.85, 0.25,
		0.02, -0.85, 0.25,
		0.02, -0.85, -0.45,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pieDerVertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	float pieIzqVertices [] = {
		// Pie front
		-0.02, -0.85, -0.45,
		-0.02, -0.8, -0.45,
		-0.34, -0.8, -0.45,
		-0.34, -0.85, -0.45,
		// Pie back
		-0.02, -0.85, 0.25,
		-0.02, -0.8, 0.25,
		-0.34, -0.8, 0.25,
		-0.34, -0.85, 0.25,
		// Pie right
		-0.02, -0.8, 0.25,
		-0.02, -0.85, 0.25,
		-0.02, -0.85, -0.45,
		-0.02, -0.8, -0.45,
		// Pie left
		-0.34, -0.85, 0.25,
		-0.34, -0.8, 0.25,
		-0.34, -0.8, -0.45,
		-0.34, -0.85, -0.45,
		// Pie top
		-0.34, -0.8, -0.45,
		-0.34, -0.8, 0.25,
		-0.02, -0.8, 0.25,
		-0.02, -0.8, -0.45,
		// Pie bottom
		-0.34, -0.85, -0.45,
		-0.34, -0.85, 0.25,
		-0.02, -0.85, 0.25,
		-0.02, -0.85, -0.45,
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pieIzqVertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
	glFlush();
	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	makeTexture();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureImage);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	glFlush();
	glutSwapBuffers();
}

void makeTexture(void)
{
	int i, j, c;
	char keyword[2];
	string comment;

	//Reading texture file
	ifstream inFile;

	inFile.open("test.ppm");
	if (!inFile)
	{
		cout << "Unable to open file ";
		exit(1); // terminate with error
	}

	inFile >> keyword;
	//    cout << keyword << " ";
	inFile >> comment;
	//    cout << comment << " ";
	inFile >> comment;
	//    cout << comment << " ";
	inFile >> comment;
	cout << comment << " ";
	inFile >> comment;
	inFile >> comment;
	//    cout << comment << " ";

	inFile >> width;
	//    cout << width;
	inFile >> height;
	//    cout << height << "\n";
	inFile >> colours;
	//    cout << colours;
	//    cout << endl;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			inFile >> c;
			textureImage[height - i][j][0] = (GLubyte)c;
			//cout << c << " ";
			inFile >> c;
			textureImage[height - i][j][1] = (GLubyte)c;
			//cout << c << " ";
			inFile >> c;
			textureImage[height - i][j][2] = (GLubyte)c;
			//cout << c << " ";
			textureImage[height - i][j][3] = (GLubyte)255;
			//cout << "255n";
		}
		//cout << endl;
	}
	inFile.close();
}

void keyboard(unsigned char key, int x, int y)
{
	// Read keyboard to make transformations
	switch (key)
	{
		case 27:
			exit(1);
			break;
		case 'l': 
		case 'L':
			rotate_y += 9;
			break;
		case 'j': 
		case 'J': 
			rotate_y -= 9;
			break;
		case 'i': 
		case 'I': 
			rotate_x += 9;
			break;
		case 'k': 
		case 'K': 
			rotate_x -= 9;
			break;
		case 'u': 
		case 'U': 
			rotate_z += 9;
			break;
		case 'o': 
		case 'O': 
			rotate_z -= 9;
			break;
		case 'a': 
		case 'A': 
			translate_x -= .05;
			break;
		case 'd': 
		case 'D': 
			translate_x += .05;
			break;
		case 's': 
		case 'S': 
			translate_y -= .05;
			break;
		case 'w': 
		case 'W': 
			translate_y += .05;
			break;
		case 'q': 
		case 'Q': 
			translate_z += .05;
			break;
		case 'e': 
		case 'E': 
			translate_z -= .05;
			break;
		case 'r':
		case 'R':
			scale -= .05;
			break;
		case 'f':
		case 'F':
			scale += .05;
			break;
		default:
			break;
	}

	//  Request display update
	glutPostRedisplay();
}