// Computer Graphics
// Profa. Raquel Landa
// Rento Sánchez Nevares
// A01281104
// Septiembre 28, 2019

#include <GLUT/glut.h>

// Function Prototypes
void display();
void specialKeys();
// Global Variables
double rotate_y = 0;
double rotate_x = 0;

int main(int argc, char *argv[])
{

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(640, 680); // Set the window's initial width & height
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner

	// Create window
	glutCreateWindow("Awesome Cube");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;
}

void display()
{

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	/* // TRASLADAR FIGURA 0.2 EN X Y Z
	glTranslatef(0.2, 0.0, 0.0);
	glTranslatef(0.0, 0.2, 0.0);
	glTranslatef(0.0, 0.0, 0.2);  */

	/* // ESCALAR FIGURA EN .5 EN X Y Z
	glScalef(.5, .5, .5); */

	glBegin(GL_LINES);
	// X AXIS
	glColor3f(0.0, 0.48, 1.0);
	glVertex3f(1, 0, 0);
	glVertex3f(-1, 0, 0);
	// Y AXIS
	glColor3f(0.86, 0.20, 0.27);
	glVertex3f(0, 1, 0);
	glVertex3f(0, -1, 0);
	// Z AXIS
	glColor3f(0.15, 0.65, 0.27);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, -1);
	glEnd();

	glColor3f(0.97, 0.97, 0.98);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, bodyVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, headBackTailVertices);
	glDrawArrays(GL_QUADS, 0, 48);
	glDisableClientState(GL_VERTEX_ARRAY);
	
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, noseVertices);
	glDrawArrays(GL_QUADS, 0, 16);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, ojoDerVertices);
	glDrawArrays(GL_QUADS, 0, 16);
	glDisableClientState(GL_VERTEX_ARRAY);
	
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pieDerVertices);
	glDrawArrays(GL_QUADS, 0, 16);
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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pieIzqVertices);
	glDrawArrays(GL_QUADS, 0, 16);
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
	};

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, braIzqVertices);
	glDrawArrays(GL_QUADS, 0, 36);
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
	};

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, braDerVertices);
	glDrawArrays(GL_QUADS, 0, 36);
	glDisableClientState(GL_VERTEX_ARRAY);

	glFlush();
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 10;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 10;

	else if (key == GLUT_KEY_UP)
		rotate_x += 10;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 10;

	//  Request display update
	glutPostRedisplay();
}