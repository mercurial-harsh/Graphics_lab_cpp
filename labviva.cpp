#include <GL/glut.h>
void init2D(float r, float g, float b){
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0); }
void display(void)
            {            
                    glClear(GL_COLOR_BUFFER_BIT);
                    glColor3f(1.0, 0.0, 0.0);
                    glBegin(GL_LINES);
                        glVertex2i(2,0);
                        glVertex2i(2,100);
                        glVertex2i(2,100);
                         glVertex2i(20,100);
                          glVertex2i(20,100);
                          glVertex2i(20,60);
                          glVertex2i(20,60);
                           glVertex2i(40,60);glVertex2i(40,60);
                            glVertex2i(40,100);
                            glVertex2i(40,100);
                             glVertex2i(60,100);glVertex2i(60,100);
                              glVertex2i(60,0);
                              glVertex2i(60,0);
                               glVertex2i(40,0); glVertex2i(40,0);
                               glVertex2i(40,40);
                                glVertex2i(40,40);
                               glVertex2i(20,40); glVertex2i(20,40);
                               glVertex2i(20,0);
                               glVertex2i(2,0);
                    glEnd();
    glFlush();
 }
int main(int argc,char *argv[])
{	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("harsh gupta letter H");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
