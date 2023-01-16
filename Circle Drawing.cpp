#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cmath>
using namespace std;

float h,k,r,r2,p;

float Round(float a)
{
	if (a - (int)a >= 0.5)
		return floor(a + 1);
	return floor(a);
}
void plot(float x, float y)
{
    //cout<<x<<" "<<y<<endl;
    //glPointSize(3.0);
    glBegin(GL_POINTS);
	/// for rbg color
	glColor3f (1.0, 0.0, 0.0);
	glVertex2i(Round(x+h), Round(y+k));
	glEnd();
}
void midpoint(){
    float x = 0;
    float y = r;
    float decision = 5 / 4 - r;
    plot(x, y);

    while (y > x){
        if (decision < 0){
            x++;
            decision += 2 * x + 3;
        }
        else{
            y--;
            x++;
            decision += 2 * (x - y) + 5;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void bresenham(){
    float x = 0;
    float y = r2;
    float decision = 3 - 2*r2;
    plot(x, y);

    while (y > x){
        if (decision < 0){
            x++;
            decision += 4 * x + 6;
        }
        else{
            y--;
            x++;
            decision += 4 * (x - y) + 10;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
}
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    midpoint();
    bresenham();
    glFlush ();
}
void init(void){

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}
void input(){
    cout << "Enter the coordinates of the center:\n\n"
         << endl;

    cout << "X-coordinate   : ";
    cin >> h;
    cout << "\nY-coordinate : ";
    cin >> k;
    cout << "\nEnter radius : ";
    cin >> r;
    cout << "\nEnter second radius : ";
    cin >> r2;
}
int main(int argc, char** argv)
{
    input();

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA Bitch!!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
