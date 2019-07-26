#include <iostream>
#include <GL/gl.h>




#include <GL/glut.h>


#include <stdlib.h>
#include <math.h>
#include <cmath>

class Point {
public: double x;
public: double y;

public:
Point(double x1,double y1){
    x = x1;
    y = y1;
}
};

Point* p0 = new Point(100,300);
Point* p1 = new Point(250,400);
Point* p2 = new Point(400,400);
Point* p3 = new Point(550,300);
Point* pFinal = new Point(100,300);




Point* bezier(Point* p0, Point* p1, Point* p2, Point* p3,double t, Point* pFinal ) {
    double x = pow(1-t,3) * p0->x +
               pow(1-t,2) * 3 * t * p1->x +
               (1-t) * 3 * t * t * p2->x +
               t * t * t * p3->x;
    double y = pow(1-t,3) * p0->y +
               pow(1-t,2) * 3 * t * p1->y +
               (1-t) * 3 * t * t * p2->y +
               t * t * t * p3->y;
    // std::cout << t;
    return new Point(x,y);

}

double interpolate(Point* f[], int xi, int n)
{
    double result = 0; // Initialize result

    for (int i=0; i<n; i++)
    {
        // Compute individual terms of above formula
        double term = f[i]->y;
        for (int j=0;j<n;j++)
        {
            if (j!=i)
                term = term*(xi - f[j]->x)/double(f[i]->x - f[j]->x);
        }

        // Add current term to result
        result += term;
    }

    return result;
}

int choosepoint(int x,int y)
{
    int distance1,distance2,distance3,distance4;
    distance1=sqrt(((x - p0->x)*(x - p0->x))+((y - p0->y)*(y - p0->y)));
    distance2=sqrt(((x - p1->x)*(x - p1->x))+((y - p1->y)*(y - p1->y)));
    distance3=sqrt(((x - p2->x)*(x - p2->x))+((y - p2->y)*(y - p2->y)));
    distance4=sqrt(((x - p3->x)*(x - p3->x))+((y - p3->y)*(y - p3->y)));

    if(distance1 < distance2)
    {
        if(distance1 < distance3)
        {
            if(distance1 < distance4)
            {
                return 1;
            }
            else
            {
                return 4;
            }
        }
        else
        {
            if(distance3 < distance4)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }
    else
    {
        if(distance2 < distance3)
        {
            if(distance2 < distance4)
            {
                return 2;
            }
            else
            {
                return 4;
            }
        }
        else
        {
            if(distance3 < distance4)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }

}

void bound_it(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-2,y,fillColor,bc);
        bound_it(x,y+2,fillColor,bc);
        bound_it(x,y-2,fillColor,bc);
    }
}


void mouse(int button, int state, int mousex, int mousey)
{

    if(button ==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int point = choosepoint(mousex, 600-mousey);
        switch(point)
        {
        case 1:
            p0->x = mousex;
            
            break;
        case 2:
            p1->x = mousex;
            p1->y = 600 - mousey;
            break;
        case 3:
            p2->x = mousex;
            p2->y = 600 - mousey;
            break;
        case 4:
            p3->x = mousex;
            
            break;
        }
        std::cout << mousex << " " << mousey << "\n";
        glutPostRedisplay();
    }

    else if(button==GLUT_RIGHT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bCol[] = {0,0,0};
            float color[] = {0,1,0};
            //glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
            bound_it(mousex,600-mousey,color,bCol);
        }
    }
       
}

 

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
       //std::cout << pFinal->x;
    Point* f[] = {p0, p1, p2, p3};
    pFinal = new Point(p0->x,interpolate(f, p0->x, 4));
    glPointSize(5);

    glBegin(GL_POINTS);
        glVertex2f(p0->x,p0->y);
        glVertex2f(p1->x,p1->y);
        glVertex2f(p2->x,p2->y);
        
        glVertex2f(p3->x,p3->y);
    glEnd();
    glFlush();
    //glBegin(GL_LINE_LOOP);
      //  glVertex2f(p0->x,p0->y);
        //glVertex2f(p1->x,p1->y);
        //glVertex2f(p2->x,p2->y);
        
        //glVertex2f(p3->x,p3->y);
    //glEnd();
    //glFlush();
     glPointSize(2);
    
        
         for(double i=0.01;i<1;i=i+0.01){
         glBegin(GL_LINE_LOOP);
            glVertex2f(pFinal->x,pFinal->y);
            
            pFinal = bezier(p0,p1,p2,p3,i,pFinal);
            //std::cout << pFinal->x;
            //glVertex2f(pFinal->x,pFinal->y);
       

        } glEnd();
     

    glFlush();
    for(double i=0.01;i<1;i=i+0.01){
         glBegin(GL_LINE_LOOP);
            glVertex2f(pFinal->x,-pFinal->y+600);
            
            pFinal = bezier(p0,p1,p2,p3,i,pFinal);
            //std::cout << pFinal->x;
            
        

        }glEnd();
     

    glFlush();
}


int main(int argc, char *argv[])
{   glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("brezier curve by harsh gupta");
    glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}

