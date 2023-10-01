/*
hw1: main.cpp
by 2021176091 Jongmu Kim
*/

#include <GL/glew.h>
#include <GL/glut.h>

void display(void) {
    /* clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) and red x-y axis */
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1 / 1.732, -0.5, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1 / 1.732, -0.5, 0.0);

    glEnd();

    glFlush();
}

void init(void) {
    /* select clearing color 	*/
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2021170691");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    // return 0;   /* ANSI C requires main to return int. */
}
