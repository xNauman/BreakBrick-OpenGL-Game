/*
 * BBMain.cpp
 *
 *  Created on: Mar 29, 2010
 *      Author: Admin
 */

/*
 * Main.cpp
 *
 *  Created on: Mar 24, 2010
 *      Author: Admin
 */
//#include <windows.h>
#include "GMainFuncs.h"

#include <windows.h>

const unsigned int gameSpeed = 10;
int old_time =0;
void idle()
{
 int t= GetTickCount();
 int passedTime = t-old_time;
 old_time=t;
 Display();
 glutPostRedisplay();

}

int main(int argc, char *argv[])
{
	int win;
	glutInit(&argc,argv);

	glutInitDisplayMode( GLUT_RGB);
	glutInitWindowSize(800, 600);
	win = glutCreateWindow("Break Brick");

	glClearColor(0, 0, 0, 0.0);

	glutDisplayFunc(Display);

	glutKeyboardFunc(keysController);

	glutSpecialFunc(keyDown);
	glutSpecialUpFunc(keyUp);
	//glutIgnoreKeyRepeat(1);
	glutReshapeFunc(changeWindowSize);
glutIdleFunc(idle);
	//glutKeyboardFunc(keyCB);

	//glutIdleFunc(Display);
		initGlobals();

	glutMainLoop();

	return 0;
}
