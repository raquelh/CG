/**
 * This demo shows how to periodically call an update() function to create
 * animations over time. In this case, the animation is to rotate a red square.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

int rotX =0;
int rotY =0;
int rotZ =0;


// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 160;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control the angle to rotate the red square

float angle = 0;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void Cube(int t){
	glColor3f(0.f, 0.f, 1.f);
	//quadrado 1
	glBegin(GL_LINES);
		glVertex3f(-t, t, 0.0f);
		glVertex3f(t, t, 0.0f);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-t, -t, 0.0f);
		glVertex3f(t, -t, 0.0f);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(t, -t, 0.0f);
		glVertex3f(t, t, 0.0f);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-t, -t, 0.0f);
		glVertex3f(-t, t, 0.0f);
	glEnd();
	//quadrado 2
	glBegin(GL_LINES);
		glVertex3f(-t, t, t);
		glVertex3f(t, t, t);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-t, -t, t);
		glVertex3f(t, -t, t);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(t, -t, t);
		glVertex3f(t, t, t);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-t, -t, t);
		glVertex3f(-t, t, t);
	glEnd();

	//ligação
	glBegin(GL_LINES);
		glVertex3f(-t, -t, 0);
		glVertex3f(-t, -t, t);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-t, t, 0);
		glVertex3f(-t, t, t);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(t, -t, t);
		glVertex3f(t, -t, 0);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(t, t, t);
		glVertex3f(t, t, 0);
	glEnd();



}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	if (rotX == 1){
		glRotatef(angle, 1.0f, 0.0f, 0.0f);	
	}
	if (rotY == 1){
		glRotatef(angle, 0.0f, 1.0f, 0.0f);	
	}if (rotZ== 1){
		glRotatef(angle, 0.0f, 0.0f, 1.0f);	
	}
	
	//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	
	// Render a red square
	//        R  G  B
	glColor3f(1, 0, 0);
	Cube(2.0);
	//        x1    y1    x2     y2
	//glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
	//glutWireCube(3.0);
	//glutWireSphere(1.0,1.0,1.0);

	//glutWireTeapot(4.0);
	//glutWireDodecahedron();
	// Start the rendering on a new frame
	glutSwapBuffers();
}

void update(int value)
{
	// Update the angle of rotation
	angle += 3;

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.

	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	std::cout<<key<<std::endl;
	if (key == 'x') {
		rotX = 1;
	}else if (key == 'x' && rotX == 1){
		rotX=0;
	}
	if(key == 'y'){
		rotY = 1;
	}else if(key == 'y' && rotY == 1){
		rotY = 0;
	}
	if (key == 'z'){
		rotZ = 1;
	}else if(key == 'z' && rotZ == 1){
		rotZ = 0;
	}
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}