#include <GL/glut.h>
#include <math.h>
struct pt {
    float x, y;
};
pt upper[4];
pt lower[4];
void myInit() {
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(0.0,1.0,0.0);
    glPointSize(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1360,1360,-720,720);
}
void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void drawLine(pt p1, pt p2) {
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}
pt drawBezier(pt A, pt B, pt C, pt D, double t) {
    pt P;
    P.x = pow((1 - t), 3) * A.x + 3 * t * pow((1 -t), 2) * B.x + 3 * (1-t) * pow(t, 2)* C.x + pow (t, 3)* D.x;
    P.y = pow((1 - t), 3) * A.y + 3 * t * pow((1 -t), 2) * B.y + 3 * (1-t) * pow(t, 2)* C.y + pow (t, 3)* D.y;       
    return P;
}

void myDisplay1() {
        glClear(GL_COLOR_BUFFER_BIT);  
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glLineWidth(20.0);
        glPointSize(19.0);
        glVertex2f(100,100);
        glVertex2f(0,0);
        glEnd();
glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glLineWidth(20.0);
        glPointSize(19.0);
        glVertex2f(-1000,-600);
        glVertex2f(0,0);
        glEnd();
  
    upper[0].x=0,upper[0].y=0;
    upper[1].x=-200,upper[1].y=-500;
    upper[2].x=-400,upper[2].y=-600;
    upper[3].x=-1000,upper[3].y=-600;
        pt pupper=upper[0];

    glColor3f(0.0,1.0,0.0);
    for(double t = 0.0;t <= 1.0; t += 0.1) {
        pt P = drawBezier(upper[0], upper[1], upper[2], upper[3],  t);
        drawLine(pupper, P);
        pupper = P;      

    }
    lower[0].x=0,  lower[0].y=0;
    lower[1].x=-700,lower[1].y=-100;
    lower[2].x=-600,lower[2].y=-50;
    lower[3].x=-1000,lower[3].y=-600;
        pt pbottom=lower[0];

    glColor3f(0.0,1.0,0.0);
    for(double t = 0.0;t <= 1.0; t += 0.1) {
        pt P = drawBezier(lower[0], lower[1], lower[2], lower[3],  t);
        drawLine(pbottom, P);
        pbottom = P; 
                       
    }
        
    glFlush();
    
}
void myDis(){
    
    myDisplay1();
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1360,720);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Leaf");    
    glutDisplayFunc(myDis);
    myInit();
    glutMainLoop();
    return 0;
}