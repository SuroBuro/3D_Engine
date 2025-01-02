#include <iostream>
#include <GL/glut.h>
using namespace std;

bool fullscreen = false;
bool mouseDown = false;

float x_rot = 0.0f;
float y_rot = 0.0f;

float x_diff = 0.0f;
float y_diff = 0.0f;

void aCube()
{
	glColor3f(0.3f,0.2f,1);
	glutSolidCube(1);
}

void drawGrid()
{
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINES);
	
	//Drawing Vertical lines
	int i;
	for(i = 0; i<40; i++)
	{
	glPushMatrix();
	if(i<20){ glTranslatef(0,0,i);}
	if(i>=20){ glTranslatef(i-20,0,0); glRotatef(-90,0,1,0);}
	
	glBegin(GL_LINES);
	//glColor3f(1,1,1); glLineWidth(1);
	glVertex3f(0,-0.1,0); glVertex3f(19,-0.1,0);
	glEnd();
	glPopMatrix();	
	}
	

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0,0);

	glRotatef(20,0.5,1,0);
	aCube();
	glutSwapBuffers();
}

bool init()
{
glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
glClearDepth(1.0f);

return true;
}
/*
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75,1.0f, 0.1f, 1000);
	glMatrixMode(GL_DEPTH_TEST);
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);
}
*/

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27 :
		exit(1); break;
	}
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;
		
	if (fullscreen)
	glutFullScreen();
	else
	{
		glutReshapeWindow(1024,768);
		glutPositionWindow(300,100);
	}
}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		
		x_diff = x - y_rot;
		y_diff = -y + x_rot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		y_rot = x - x_diff;
		x_rot = y + y_diff;
	}
}

int main(int argc ,char **argv)
{
	glutInit(&argc, argv);
	
	glutInitWindowPosition(300,100);
	glutInitWindowSize(1024,768);
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutCreateWindow("My Own Modeller (Maybe CAD program)");
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}
