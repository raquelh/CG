/**
 * A simple OpenGL program that draws a colorful cube
 * that rotates as you move the arrow keys.
 *
 * Author: Mihalis Tsoukalos
 * Date: Wednesday 04 June 2014
 */
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

// Rotate X
GLfloat rX = 0;
// Rotate Y
GLfloat rY = 0;

// The coordinates for the vertices of the cube
GLfloat x = 0.3f;
GLfloat y = 0.3f;
GLfloat z = 0.3f;

float x1=-0.0;
float y1=0.10;
float escala =1.0;

void display()
{
	// Set Background Color
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	glScalef(escala, escala, 0);
		
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(x1, y1, 0.f);
			glVertex3f(x1, -y1, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(x1+0.2, y1, 0.f);
			glVertex3f(x1+0.2, -y1, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(x1, y1, 0.f);
			glVertex3f(x1+0.2, y1, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(x1+0.0, -y1, 0.f);
			glVertex3f(x1+0.2, -y1, 0.f);
		glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	//std::cout<<key<<std::endl;
	if (key == '2') {
		escala=2;
	} else if (key == '3') {
		escala=3;
	} else if (key == '4') {
		escala=4;
	} else if (key == '5') {
		escala=5;
	}

	// Request display update
	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("OpenGL Cube");

	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}