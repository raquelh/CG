/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

int rotacao = 0;
int escala =0;
int trans =0;
float ro = 1;
float es = 1;
float tr = 0;
void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();
	glLoadIdentity();

	if (rotacao ==1){
		ro = 5+ ro;
	}

	if (escala == 1 && es < 3){
		es = es+0.2;
	} 
	if (escala == 1 && es> 3){
		es = 1;
	}
	if (trans==1 && tr < 2){
		tr += 1;	
	}
	// Render a red square
	glColor3f(1, 0, 0);
	glScalef(es, es, 0);
	glTranslatef(tr, tr, 0);
	glRotatef(ro, 0.0f, 0.0f, 1.0f);
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);
	


	


	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
		//std::cout<<key<<std::endl;
	if (key == '1' && rotacao == 0) {
		rotacao=1;
	}else{
		rotacao = 0;
	}
	if (key == '2' && trans == 0) {
		trans=1;
	}else{
		trans =0;
	}
	if (key == '3' && escala == 0) {
		escala=1;
	} else{
		escala = 0;
	}

	// Request display update
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}