#include<stdio.h>


#include<math.h>
void dda(int,int,int,int,int,int,int,int);
void dda(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax)
{

            float dx,dy;
            float steps,x=x1,y=y1;
            int i=0;
            dx=x2-x1;
            dy=y2-y1;
            if(abs(dx)>=abs(dy))
                        steps=abs(dx);
            else
                        steps=abs(dy);
            dx=dx/steps;
            dy=dy/steps;
            while(i++<=steps)
            {
            if(x>=xmin && x<=xmax && y>=ymin && y<=ymax)
            {
                        line(x,y,x2,y2);
                        return;
            }
                        x=x+dx;
                        y=y+dy;
            }
}
void main()
{
            int n,gd,gm,x1,x2,y1,y2,xRec,yRec,b1,b2,b3,b4,l,b,yMin,yMax,xMin,xMax;
            float m;
            int a[10][4],i,j, flag=0,in=0;
            gd=DETECT;
            gm=DETECT;
            initgraph(&gm,&gd,"C:\\TC\\BGI");

            printf("Enter the length and breadth of the clipping window:\n");
            scanf("%d%d",&l,&b);

            printf("Enter the starting co-ord of the rectangle\n");
            scanf("%d%d",&xRec,&yRec);
            clrscr();

            rectangle(xRec,yRec,xRec+l,yRec+b);
            getch();
            clrscr();


            printf("Enter the no of lines\n");
            scanf("%d",&n);

            for(i=0;i<n;i++)
            {
                        printf("Enter the co-ord of line %d\n",i+1);
                        for(j=0;j<2;j++)
                        {
                                    scanf("%d",&a[i][j]);
                        }
                        a[i][2]=a[0][0];
                        a[i][3]=a[0][1];
                        if(i!=0)
                        {
                               a[i-1][2]=a[i][0];
                               a[i-1][3]=a[i][1];
                        }
            }
            clrscr();
            rectangle(xRec,yRec,xRec+l,yRec+b);
            for(i=0;i<n;i++)
            {
                        line(a[i][0],a[i][1],a[i][2],a[i][3]);
            }
            getch();
            clrscr();
            rectangle(xRec,yRec,xRec+l,yRec+b);

            xMin=xRec;
            yMin=yRec;
            xMax=xRec+l;
            yMax=yRec+b;

            for(i=0;i<n;i++)
            {
                        flag=0;
                        x1=a[i][0];
                        x2=a[i][2];
                        y1=a[i][1];
                        y2=a[i][3];

                        if(x1>=xMin && x1<=xMax && y1>=yMin && y1<=yMax)
                                    flag++;
                        if(x2>=xMin && x2<=xMax && y2>=yMin && y2<=yMax)
                                    flag++;


                        switch(flag)
                        {
                                    case 0:
                                                break;

case 1: if(x2>=xMin && x2<=xMax && y2>=yMin &&    y2<=yMax)
                                                {
                                                            dda(x1,y1,x2,y2,xMin,yMin,xMax,yMax);

                                                }
                                                else
                                                {
                                                            dda(x2,y2,x1,y1,xMin,yMin,xMax,yMax);

                                                }
                                                break;
                                    case 2: line(x1,y1,x2,y2);
                                                break;
                        }
            }

            getch();

            closegraph();
}








//Weiler-Atherton’s method

#include<conio.h>
#include <graphics.h>
#include<dos.h>
void weiler_polygon_clipping();
void main()
{ int gd = DETECT, gm;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  settextstyle(SMALL_FONT,HORIZ_DIR,4);
  clrscr();
  outtextxy(50,80,"Weiler-Atherton Polygon Clipping");
  cleardevice();
  setbkcolor(6);
  weiler_polygon_clipping();
  cleardevice();
  setbkcolor(2);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
  outtextxy(150,150,"THANK YOU");
  getch();
  closegraph();
}
void weiler_polygon_clipping()
{ outtextxy(50,30,"Weiler-Atherton Polygon Clipping");
  outtextxy(50,60,"In this clipping method vertex processing procedures");
  outtextxy(50,70,"for window boundaries are modified so that concave polygons");
  outtextxy(50,80,"are displayed correctly.The basic idea int this algorithm");

  outtextxy(50,90,"is that instead of always proceeding around the polygon edges");
  outtextxy(50,100,"as vertices are processed,we sometimes want to follow the window");
  outtextxy(50,110,"boundaries.Which path follow depends on the polygon-processing");
  outtextxy(50,120,"direction (clockwise or counter clockwise) and whether the pair");
  outtextxy(50,130,"of polygon vertices currently being processed represents an");
  outtextxy(50,140,"outside-to-inside or an inside-to-outside pair.");
  outtextxy(50,170,"For clockwise direction processing of polygon vertices, we use");
  outtextxy(50,180,"following rules.");
  outtextxy(50,190,"[1] For an outside-to-inside pair of vertices,follow the polygon");
  outtextxy(50,200,"    boundary.");
  outtextxy(50,210,"[2] For an inside-to-outside pair of vertices,follow the window");
  outtextxy(50,220,"    boundary in a clockwise direction.");
  rectangle(70,240,180,360);
  delay(1100);
  line(30,310,110,270);
  delay(1100);
  line(110,270,100,295);
  delay(1100);
  line(100,295,50,330);
  delay(1100);
  line(50,330,110,340);
  delay(1100);
  line(110,340,30,350);
  delay(1100);
  line(30,310,30,350);
  delay(1100);
  outtextxy(20,310,"v1");
  delay(1100);
  outtextxy(110,270,"v2");
  delay(1100);
  outtextxy(105,295,"v3");
  delay(1100);
  outtextxy(45,330,"v4");
  delay(1100);
  outtextxy(115,340,"v5");
  delay(1100);
  outtextxy(20,350,"v6");
  delay(1100);
  outtextxy(65,285,"v1'");
  delay(1100);
  outtextxy(65,305,"v3'");
  delay(1100);
  outtextxy(75,325,"v4'");
  delay(1100);
  outtextxy(50,350,"v5'");
  outtextxy(50,469,"Hit any key to continue...");
  getch();
  cleardevice();
  rectangle(70,240,180,360);
  setcolor(11);
  line(70,290,110,270);
  line(110,270,100,295);
  line(100,295,70,320);
  line(70,290,70,320);
  delay(2000);
  line(70,330,110,340);
  line(70,330,110,340);
  line(110,340,70,350);
  line(70,330,70,350);
  setcolor(15);
  outtextxy(50,469,"Hit any key to continue...");
  getch();
}