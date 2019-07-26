#include<GL/glut.h>
#include<stdio.h>
#include <math.h>
#include<iostream>

#define pi 3.142857

using namespace std;

int X,Y; 

void init (void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400,400,-300,300);
    
    
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glLineWidth(2);
    glVertex2i(-400,0);
    glVertex2i(400,0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glLineWidth(2);
    glVertex2i(0,300);
    glVertex2i(0,-300);
    glEnd();

    glFlush();


}

void display (void) 
{   
    cout << "X-coordinate   : "; cin >> X;
	cout << "\nY-coordinate : "; cin >> Y;

	
	glBegin(GL_LINE_LOOP);
	float x, y, i;
	for ( i = 0; i < (2 * pi); i += 0.001)
	{
		x = X+(100 * cos(i));
		y = Y+(100 * sin(i));
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();

}
int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Parametric Circle");
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800,600);

    

    
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
   
    return 0;
}

