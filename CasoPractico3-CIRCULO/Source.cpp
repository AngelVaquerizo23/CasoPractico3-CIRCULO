#include <GL/glut.h>
#include<iostream>

void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Bresenham(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa - xb), dy = abs(ya - yb);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
	int x, y, xEnd;
	/*Determine which points to start and End */
	if (xa > xb) {
		x = xb;
		y = yb;
		xEnd = xa;
	}
	else {
		x = xa; y = ya; xEnd = xb;
	}
	//putpixel(x, y, WHITE);
	setPixel(x, y);
	while (x < xEnd) {
		x++;
		if (p < 0) {
			p = p + twoDy;
		}
		else {
			y++;
			p = p + twoDyDx;
		}
		//putpixel(x, y, WHITE);
		setPixel(x, y);
	}

}


void drawcircle(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		setPixel(x0 + x, y0 + y);
		setPixel(x0 + y, y0 + x);
		setPixel(x0 - y, y0 + x);
		setPixel(x0 - x, y0 + y);
		setPixel(x0 - x, y0 - y);
		setPixel(x0 - y, y0 - x);
		setPixel(x0 + y, y0 - x);
		setPixel(x0 + x, y0 - y);

		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}

		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(4.0);

	//setPixel(200, 100);
	Bresenham(200, 100, 400, 200);
	drawcircle(200, 100, 70);

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("UNACH demo1");
	myinit();

	glutDisplayFunc(display);
	glutMainLoop();

	//return 0;
}