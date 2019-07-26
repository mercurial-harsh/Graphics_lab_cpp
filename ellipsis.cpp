
#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;



void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glutPostRedisplay();



}




void drawDot (GLint x, GLint y)
{ glColor3f(0.0,1.0,0.0);
glPointSize(3.0);
  glBegin (GL_POINTS);
	  glVertex2i (x,y);
  glEnd();
}

void symmetricPixels (int x, int y, int xc, int yc)
{ drawDot (xc + x, yc + y);
  
  drawDot (xc - x, yc + y);
  drawDot (xc + x, yc - y);
  drawDot (xc - x, yc - y);
}

void Ellipse (void)
{ 
  glColor3f(1,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(-320,0);
    glVertex2i(320,0);
    glEnd();
    glColor3f(1,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(0,-240);
    glVertex2i(0,240);
    glEnd();

    glFlush();
  
  
  int a=50,b=40, xc=0,yc=0;
  int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
  aSq = a*a;
  bSq = b*b;
  twoASq = 2*aSq;
  twoBSq = 2*bSq;
  d = bSq - b*aSq + aSq/4;
  dx = 0;
  dy = twoASq*b;
  x = 0;
  y = b;
  symmetricPixels(x,y,xc,yc);
  while (dx < dy)
  { x++;
    dx += twoBSq;
    if (d >= 0)
    { y--;
      dy -= twoASq;
    }
    if (d < 0)
     d += bSq + dx;
    else
     d += bSq + dx - dy;
    symmetricPixels (x,y,xc,yc);
  }
  d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
                 aSq*bSq);
  while (y > 0)
  { y--;
    dy -= twoASq;
    if (d <= 0)
    { x++;
      dx += twoBSq;
    }
    if (d > 0)
         d += aSq - dy;
    else
         d += aSq -dy +dx;
    symmetricPixels(x,y,xc,yc);
  }
  glFlush();
}


               
                
       
    




int main(int argc, char** argv){
   glutInit(&argc, argv);
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("007_ellipsis_!!for namesake!!");
    
    glutDisplayFunc(Ellipse);
    glutPostRedisplay();
    init();
    glutMainLoop();
        
}