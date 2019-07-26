#include<stdio.h>
#include<GL/glut.h>

int flag=0,minx=0,miny=0,maxx=50,maxy=50;
double xcwmin=minx,ycwmin=miny,xcwmax=300, ycwmax=300; //clipping window boundaries
int x1,y1,x2,y2; int a1=60,b1=20,a2=400,b2=350,counterl=0,counterc=0;
int cliptest(double p,double q,double *t1,double *t2)
{      // p is denominator in division and q is numerator                  
// t1 is t entering and t2 is t leaving
    double t=q/p;
    if(p<0.0)        //potentially entry point ,update te
    {    if(t>*t1) {*t1=t;}
        if(t>*t2) {flag=1;
        //printf("for this segment the values of t1(entering) and t2(leaving) are %lf and %lf \n",*t1,*t2);
        return(0);} //line portion is outside as in line no 2 where t(entering)
                  
                                       // has become more than t(leaving)
    }
    else if(p>0.0) //potentially leaving point ,update tl
        {
        if(t<*t2) {*t2=t;}
            if(t<*t1) {flag=1;//printf("for this segment the values of t1(entering) and t2(leaving) are %lf and %lf \n",*t1,*t2);
            return(0);} //line portion is outside
        }
        else if(p==0.0)
            { if(q<0.0)
                 {flag=1;//printf("for this segment the values of t1(entering) and t2(leaving) are %lf and %lf \n",*t1,*t2);
                 return(0);}//line parallel to edge but outside
            }
    //printf("for this segment the values of t1(entering) and t2(leaving) are %lf and %lf \n",*t1,*t2);       
    return(1);
}

void liangV9(double x0,double y0,double x1,double y1)
{
    double dx= x1-x0,dy=y1-y0, te=0.0,tl=1.0;


    if(cliptest(-dx,x0-xcwmin,&te,&tl))// inside test wrt left edge
// t for the left edge is t=(xcwmin-x0) /dx .... order of numerator is reversed and you get -dx
    if(cliptest(dx,xcwmax-x0,&te,&tl))// inside test wrt right edge
// t for the right edge is t=(xcwmax-x0)/dx.... first parameter becomes q and second p then t=q/p 
    if(cliptest(-dy,y0-ycwmin,&te,&tl))// inside test wrt bottom edge

    if(cliptest(dy,ycwmax-y0,&te,&tl))// inside test wrt top edge
 
    {
        if(tl<1.0)
        {
            x1=x0+tl*dx;
            
            y1=y0+tl*dy;
        }
        if(te>0.0)
        {
            x0=x0+te*dx;
            y0=y0+te*dy;
        }
  }
    
            double vx0= xcwmin+(x0-xcwmin);
            double vy0= ycwmin+(y0-ycwmin);
            double vx1= xcwmin+(x1-xcwmin);
            double vy1= ycwmin+(y1-ycwmin);
// draw a red colored clipping window
        if(flag==1)
        {glColor3f(1.0,0.0,0.0);flag--;}
        else{glColor3f(0.0,1.0,0.0);} //draw green colored clip line
        glBegin(GL_LINES);
        glVertex2d(vx0,vy0);
        glVertex2f(vx1,vy1);
        glEnd();
        printf("for this segment finally the values of t1(entering) and t2(leaving) are %lf and %lf \n",te,tl);
        
            glColor3f(0.0,0.0,1.0);     //draw a blue color window
            glBegin(GL_LINE_LOOP);
            glVertex2f(xcwmin,ycwmin);
            glVertex2f(xcwmax,ycwmin);
            glVertex2f(xcwmax,ycwmax);
            glVertex2f(xcwmin,ycwmax);
            glEnd();
            glFlush();

}
void display()
{
    
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0,0.0,0.0);          //draw a line with red color
            glBegin(GL_LINES);
            glVertex2d(a1,b1);
            glVertex2d(a2,b2);
            glEnd();   glFlush(); 
            liangV9(a1,b1,a2,b2);
            glFlush();
            
            if(xcwmax==499)
            {xcwmax=maxx;ycwmax+=50;
            xcwmin=minx;ycwmin+=50;
            }
            else
            {
                xcwmax++;xcwmin++;ycwmax++;ycwmin++;
            }

            
    
   
    
            
    
}

void mouseclick(int button, int state, int x, int y)
{   
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
       { if(counterc == 0) 
            {xcwmin =x;
            ycwmin =y;
            counterc++;
            }
            else if(counterc == 1) 
            {
            
            if(x>xcwmin)
            {
                xcwmax=x;

            }
            else
            {
                xcwmax=xcwmin;
                xcwmin=x;
            }
            
            //now time for y

            if(y>ycwmin)
            {
                ycwmax=y;
            }
            else
            { 
                ycwmax=ycwmin;
                ycwmin=y;

            }


            
            counterc--;
            

            
            
            glFlush();

            glutPostRedisplay();
                  
            
                
            
            
             }
       }
    
          
    

    
    
}

void myinit(){
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,499.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
           glClearColor(0.5,0.5,0.0,0.5);
           char buffer[10]={'r','7','0',' ','&',' ','R','6','6'};
       
        glRasterPos2f(350,350);
        glColor3f(1.0,0.0,1.0);
        for(int i=0 ; i<10 ; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,buffer[i]);
            }
        glFlush();
}
int main(int argc, char** argv)
{   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("liang barsky clipping algorithm");
    myinit();
    glutDisplayFunc(display);
    
    glutMouseFunc(mouseclick);
    
    glutMainLoop();
    return 0;
}