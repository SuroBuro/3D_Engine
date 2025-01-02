#include <GL/glut.h>

float angle = 0.0; // Rotation angle

// Initialization function
void init() 
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45,1.0f, 0.0001f, 1000);
    glClearColor(0,0,0,1); // Set the background color to black
    glColor3f(1,1,1);
    glEnable(GL_DEPTH_TEST);          // Enable depth testing
}



void aCube()
{
	glColor3f(0.5f,0.2f,1);
	glutSolidCube(0.3);
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

// Function to draw the axes
void drawAxes() {
    glBegin(GL_LINES);

    // X-axis in red
    glColor3f(1,0,0); // Red
    glVertex3f(0,0,0);glVertex3f(1,0,0);

    // Y-axis in green
    glColor3f(0,1,0); // Green
    glVertex3f(0,0,0);glVertex3f(0,1,0);

    // Z-axis in blue
    glColor3f(0,0,1); // Blue
    glVertex3f(0,0,0);glVertex3f(0,0,1);

    glEnd();
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1,0.5,0); // Move the camera back
    glRotatef(angle, 1, 1, 0); // Rotate the gizmo

	drawGrid();
    drawAxes();
    aCube();

    glutSwapBuffers(); // Swap the buffers
}

// Timer function for animation
void timer(int value) {
    angle += 2.0; // Increment the rotation angle
    if (angle > 360.0) angle -= 360.0;

    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timer, 0); // 60 FPS
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Rotating Gizmo");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

