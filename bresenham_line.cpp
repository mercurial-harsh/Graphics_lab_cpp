#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>
#include <string.h>


static struct Point
{
float x1;
float y1;
float x2;
float y2;
int counter=0;
}p;

void makeline(int x0, int y0, int x1,int y1)
{
    float dx=x1-x0;
        float dy=y1-y0;
        float a=x0,b=y0;
        float m=dy/dx;
        while(a!=x1)
        {
        if(m>0 && m<1)
            {
            float p0=2*dy-dx;
            static float p10=p0;
            static float p50=p0;
            if(dx>0)
               {
                if(p10<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p10= p10+2*dy;
                a=a+1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p10=p10+2*dy-2*dx;
                b=b+1;
                a=a+1;               
                }
               }
            else
               {
                if(p50<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p50= p50+2*dy-2*dx;
                a=a-1;
                b=b-1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p50=p50+2*dy;
                a=a-1;
                    }
               }
               
            }
        if(m>1)
        {
            float p0=2*dx-dy;
            static float p20=p0;
            static float p60=p0;   
            if(dx>0)
               {
                if(p20<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p20= p20+2*dx;
                b=b+1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p20=p20+2*dx-2*dy;
                b=b+1;
                a=a+1;               
                }
               }
            else
               {
                if(p60<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p60= p60-2*dy+2*dx;
                a=a-1;
                b=b-1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p60=p60+2*dx;
                b=b-1;
                    }
               }
               
            }
        if(m<(-1))
        {
            float p0=2*dx+dy;
            static float p30=p0;
            static float p70=p0;   
            if(dx<0)
               {
                if(p30<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p30= p30+2*dx+2*dy;
                a=a-1;               
                b=b+1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p30=p30+
                2*dx;
                b=b+1;           
                }
               }
            else
               {
                if(p70<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p70= p70+2*dx;
                b=b-1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p70=p70+2*dx+2*dy;
                b=b-1;
                a=a+1;
                    }
               }
               
            }
        if(m>(-1) && m<0)
        {
            float p0=2*dx+dy;
            static float p40=p0;
            static float p80=p0;   
            if(dx<0)
               {
                if(p40<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p40= p40+2*dy;
                a=a-1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p40=p40+2*dy+dx;
                b=b+1;
                a=a-1;           
                }
               }
            else
               {
                if(p80<0)
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                   p80= p80+2*dx+2*dy;
                b=b-1;
                a=a+1;
                }
                else
                {
                glBegin(GL_POINTS);
                glVertex2f(a,b);
                glEnd();
                p80=p80+2*dy;
                a=a+1;
                    }
               } 
               
            }
        }
        char buffer[10]={'\0'};
        sprintf(buffer, "%f",m);
        glRasterPos2f(x1,y1+10);
        int length=strlen(buffer);
        for(int i=0 ; i<length ; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,buffer[i]);
            }



}

void assigncolor(float x, float y, void *font, char *string)
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c!= '\0';c++)
    {
    glutBitmapCharacter(font,*c);
    }
}
void names()
{
    glColor3f(1.0,1.0,0.0);
    assigncolor(5,450,GLUT_BITMAP_8_BY_13,"BRESENHAM'S ALGORITHM");
    assigncolor(10,100,GLUT_BITMAP_8_BY_13,"Harsh Gupta");
    
}
void mouseclick(int button, int state, int x, int y)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && p.counter == 0) {
        p.x1 = x;
        p.y1 = 500-y;               
        p.counter++;
    }
  
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && p.counter == 1) {
        p.x2 = x;
        p.y2 = 500-y;
        p.counter--;
        makeline((int)p.x1,(int)p.y1,(int)p.x2,(int)p.y2);

    }
     if(button == GLUT_RIGHT_BUTTON && state== GLUT_DOWN)
     {
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
}





void display()
{
    names();
    glFlush();
    glutPostRedisplay();
}

void init() {
  
glClearColor(0, 0, 0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0,500.0);
    glutPostRedisplay();
    glFlush();


}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Assignment 1");
    glutDisplayFunc(display);
    glutMouseFunc(mouseclick);
    init();
    glutMainLoop();
    return 0;
}

