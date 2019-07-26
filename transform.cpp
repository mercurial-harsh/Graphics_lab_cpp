#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
float sx=1,sy=1;
float sum=0;
int c,d,k;
int i,j;
int tx=160;
int ty=160;
float T[3][3]={0,0,0,0,0,0,0,0,1};
float P[3][4]={0,150,150,0,0,0,150,150,1,1,1,1};
float trans[3][4]={0,0,0,0,0,0,0,0,0,0,0,0};
typedef struct
{
float x;
float y;
}Point;
Point centre={75,75};
float xcenter=0,ycenter=0,x,y;
float R1x,R1y,R2x,R2y;
static GLfloat spin_z = 0.0;
static GLfloat spin_x = 0.0;
static GLfloat spin_y = 0.0;
void myInit(void);
void display(void);
void reshape(int, int);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-683,683,-384,384);
}

void reshape(int w, int h) {
glViewport(0, 0, (GLsizei)w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glMatrixMode(GL_MODELVIEW);
}
void Midline()
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(4.0);
glBegin(GL_POINTS);
glVertex2f(-683, 0);
glVertex2f(0, 384);
glVertex2f(683, 0);
glVertex2f(0, -384);
glVertex2f(0, 0);
glEnd();
glBegin(GL_LINES);
glVertex2f(-683, 0);
glVertex2f(683, 0);
glEnd();
glBegin(GL_LINES);
glVertex2f(0, 384);
glVertex2f(0, -384);
glEnd();
glFlush();
}

void drawBitmapText(char *string, float x, float y)
{
    char *c;
    glRasterPos2f(x, y);//define position on the screen where to draw text.

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void myDisplay(void) {
Midline();
drawBitmapText("----Menu------",-683,350);
drawBitmapText("1. Translation (use 3)",-683,300);
drawBitmapText("2. Rotation (use 1 and 2)",-683,250);
drawBitmapText("3. Scaling (use 'g')",-683,200);
drawBitmapText("4. Reflection",-683,150);
drawBitmapText("5. Shearing",-683,100);
display();
glEnd();
glFlush();
}
void display(void){
glColor3f(1.0, 1.0, 0.0);
glPushMatrix();
glRotatef(spin_z, 0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(0.0, 0.0);
glVertex2f(150.0, 0.0);
glVertex2f(150.0, 150.0);
glVertex2f(0.0, 150.0);
glPopMatrix();
glutSwapBuffers();


}

void keyboard(unsigned char key,int x, int y) {
switch(key) {
case 103:
if(sx>2||sy>2)
{
return;
}
T[0][0]=sx;T[1][1]=sy;
T[0][2]=(centre.x)*(1-sx);
T[1][2]=(centre.y)*(1-sy);
for (c = 0; c < 3; c++) {
for (d = 0; d < 4; d++) {
for (k = 0; k < 3; k++) {
sum = sum + T[c][k]*P[k][d];
}
trans[c][d]=sum;
sum = 0;
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf("\n T[%d][%d]=%f",i,j,T[i][j]);
}
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
printf("\n P[%d][%d]=%f",i,j,P[i][j]);
}
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
printf("\n trans[%d][%d]=%f",i,j,trans[i][j]);
}
glBegin(GL_POLYGON);
glVertex2f(trans[0][0],trans[1][0]);
glVertex2f(trans[0][1],trans[1][1]);
glVertex2f(trans[0][2],trans[1][2]);
glVertex2f(trans[0][3],trans[1][3]);
glEnd();
glFlush();
for(i=0;i<3;i++)
{ for(j=0;j<4;j++)
P[i][j]=trans[i][j]; }
if(sx<2&&sy<2)
{ sx=sx+0.2;
sy=sy+0.2; }
break;
case 49:
glBegin(GL_QUADS);
glVertex2f(0.0, 0.0);
glVertex2f(150.0, 0.0);
glVertex2f(150.0, 150.0);
glVertex2f(0.0, 150.0);
glEnd();
glColor3f(1.0, 0.0, 0.0);
glRotatef(5,0,0,1);
break;
case 50:
glBegin(GL_QUADS);
glVertex2f(0.0, 0.0);
glVertex2f(150.0, 0.0);
glVertex2f(150.0, 150.0);
glVertex2f(0.0, 150.0);
glEnd();
glColor3f(1.0, 0.0, 0.0);
glRotatef(-5,0,0,1);
break;
case 51:
glBegin(GL_QUADS);
glVertex2f(0.0, 0.0);
glVertex2f(150.0, 0.0);
glVertex2f(150.0, 150.0);
glVertex2f(0.0, 150.0);
glEnd();
glColor3f(1.0, 0.0, 0.0);
glTranslatef(200,0,0);
glFlush();
break;
case 52:
glutPostRedisplay();
break;
default: break;
}
}}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(1366, 768);
glutInitWindowPosition(0, 0);
glutCreateWindow("Menu");
myInit();
glutDisplayFunc(myDisplay);


glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}

