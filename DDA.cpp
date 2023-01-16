#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cmath>
float x1,yy1,x2,y2,m,i,j;
float dx,dy;
float Round(float a)
{
	if (a - (int)a >= 0.5)
		return floor(a + 1);
	return floor(a);
}

void swapPoints()
{
	float temp = x1;
	x1 = x2;
	x2 = temp;
	temp = yy1;
	yy1 = y2;
	y2 = temp;
}

void plotPoint(float x, float y)
{
    //glPointSize(3.0);
    glBegin(GL_POINTS);
	/// for rbg color
	glColor3f (1.0, 0.0, 0.0);
	glVertex2i(x, y);
	//glVertex3f(x,y,0.0);
	glEnd();
}

void DDA(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    printf("%f\n",m);
	if (abs(m) <= 1){
	    if (x1 > x2){
            swapPoints();
        }
        float x = x1, y = yy1;

		while (x <= x2 ){
		    plotPoint(x, Round(y));
			x = x + 1;
			y = y + m;
		}
		//plotPoint(x, y);
	}
	else if (abs(m) > 1){
		if (yy1 > y2){
			swapPoints();
		}
		m = 1 / m;
		float x = x1, y = yy1;
		while (y <= y2 ){
		    plotPoint(Round(x), (y));
			x = x + m;
			y = y + 1;
		}
		//plotPoint(x2, y2);
	}
	glFlush();

}
void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    //glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{

    //glVertex3f(x1/100,yy1/100,0.0);write your code here
    printf("Enter value of X1 :");
    scanf("%f",&x1);
    printf("Enter value of yy1 :");
    scanf("%f",&yy1);
    printf("Enter value of X2 :");
    scanf("%f",&x2);
    printf("Enter value of Y2 :");
    scanf("%f",&y2);
    dx=x2-x1;
    dy=y2-yy1;
    m=dy/dx;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA Bitch!!");

    init ();
    glutDisplayFunc(DDA);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
