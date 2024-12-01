#include <GL/glut.h>

int main(int argc, char** argv)
{
	glutInit($argc, argv);
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(320,320);
	glutWindowPosition(50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
}


