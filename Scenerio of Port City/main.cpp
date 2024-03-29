#include <windows.h>
#include <GL/glut.h>
#include<Gl/gl.h>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#define PI   3.14159265358979323846




using namespace std;

GLfloat boatPosition = 0.0f,carPosition = 0.0f,carPosition1 = 0.0f,railPosition=0.0f,planePosition=0.0f,rotatei=-10.0f,rotatei1=0.0f,sunPosition=0.0f,moonPosition=0.0f,positionRain = 0.0f;
GLfloat boatSpeed= 0.0f,carSpeed= 0.0f,carSpeed1= 0.0f,railSpeed=0.0f,planeSpeed=0.0f,sunSpeed=0.0f,moonSpeed=0.0f,rainSpeed=0.01;
double rainX = -1.0,rainY;
static GLint f1=0,f2=0,f3=0,f4=0;
bool rt = true,rainday=false,night=false;

void update(int value)
{
    if (boatPosition < -1.1)
        boatPosition = 1.0f;
    else if (boatPosition > 1.0)
        boatPosition = -1.0f;

    if (carPosition < -0.2)
        carPosition = 1.98f;
    else if (carPosition > 1.98)
        carPosition = -0.2f;

    if (carPosition1 < -1.5)
        carPosition1 = 1.0f;

    if (railPosition < -1.9)
        railPosition = 0.7;
    else if (railPosition > 1.98)
        railPosition = -1.0f;

    if (planePosition > 1.4)
        planePosition=-1.2;

    if (sunPosition < -1.0)
    {
        sunPosition=-1.0;
        night=true;
    }

    if (moonPosition > 0.8)
        moonPosition=0.8;

    if (positionRain < -0.5)
        positionRain=0.0;

    boatPosition -=boatSpeed;
    carPosition -=carSpeed;
    carPosition1 -=carSpeed1;
    railPosition-=railSpeed;
    planePosition-=planeSpeed;
    sunPosition-=sunSpeed;
    moonPosition-=moonSpeed;
    positionRain-=rainSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, update,0);
}

void stop()
{
    carSpeed = 0.0f;
    carSpeed1 = 0.0f;
    boatSpeed = 0.0f;
    railSpeed = 0.0f;
    planeSpeed =0.0f;
}

void circle(GLfloat x, GLfloat y, GLfloat r)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x+(r*cos(i * twicePi / triangleAmount)),
            y+(r*sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void boat()
{
    glPushMatrix();
    glTranslatef(boatPosition, 0.0f,0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0f, .0f, 0.0f);

    glVertex3f(-0.03f, -0.92f,0.0f);
    glVertex3f(0.03f,-0.92f,0.0f);
    glVertex3f(0.13f, -0.85f,0.0f);
    glVertex3f(-0.13f,-0.85f,0.0f);


    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.10f, -0.85f,0.0f);
    glVertex3f(-0.10f,-0.85f,0.0f);;
    glVertex3f(-0.10f, -0.83f,0.0f);
    glVertex3f(0.10f, -0.83f,0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.07f, -0.83f,0.0f);
    glVertex3f(-0.07f,-0.83f,0.0f);;
    glVertex3f(-0.07f, -0.81f,0.0f);
    glVertex3f(0.07f, -0.81f,0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.05f, -0.81f,0.0f);
    glVertex3f(-0.04f,-0.81f,0.0f);;
    glVertex3f(-0.04f, -0.79f,0.0f);
    glVertex3f(-0.05f, -0.79f,0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.01f, -0.81f,0.0f);
    glVertex3f(0.0f,-0.81f,0.0f);
    glVertex3f(0.0f, -0.79f,0.0f);
    glVertex3f(-0.01f, -0.79f,0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.03f, -0.81f,0.0f);
    glVertex3f(0.04f,-0.81f,0.0f);;
    glVertex3f(0.04f, -0.79f,0.0f);
    glVertex3f(0.03f, -0.79f,0.0f);

    glEnd();
    glPopMatrix();
    glFlush();


}

void plane()
{
    glPushMatrix();
    glTranslatef(planePosition, 0.0f, 0.0f);

    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-.30, 0.7);
    glVertex2f(-.30, 0.6);
    glVertex2f(.10, 0.6);
    glVertex2f(.10, 0.7);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);

    glVertex2f(0.10f, 0.6f);
    glVertex2f(0.20f, 0.65f);
    glVertex2f(0.10f, 0.7f);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-.30, 0.7);
    glVertex2f(-.30, 0.75);
    glVertex2f(-.25, 0.75);
    glVertex2f(-.22, 0.7);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.7);
    glVertex2f(-0.1, 0.8);
    glVertex2f(-.05, 0.8);
    glVertex2f(.0, 0.7);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-.05, 0.6);
    glVertex2f(-.1, 0.5);
    glVertex2f(-.05, 0.5);
    glVertex2f(.0, 0.6);
    glEnd();

    glPopMatrix();
    glFlush();

}


void road()
{
    glBegin(GL_QUADS);
    glColor3ub	(0,0,0);
    //road black shade
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(-1.0f, -0.41f);
    glVertex2f(1.0f, -0.41f);
    glVertex2f(1.0f, -0.65f);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    //road lane line between road
    glVertex2f(-1.0f, -0.53f);
    glVertex2f(-0.8f, -0.53f);

    glVertex2f(-0.75f, -0.53f);
    glVertex2f(-0.55f, -0.53f);

    glVertex2f(-0.5f, -0.53f);
    glVertex2f(-0.3f, -0.53f);

    glVertex2f(-0.25f, -0.53f);
    glVertex2f(0.0f, -0.53f);

    glVertex2f(0.05f, -0.53f);
    glVertex2f(0.25f, -0.53f);

    glVertex2f(0.3f, -0.53f);
    glVertex2f(0.5f, -0.53f);

    glVertex2f(0.55f, -0.53f);
    glVertex2f(0.75f, -0.53f);

    glVertex2f(0.8f, -0.53f);
    glVertex2f(1.0f, -0.53f);
    glEnd();

    glFlush();
}


void river()
{

    glBegin(GL_QUADS);
    glColor3ub	(30,144,255);
    //between river and road
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-1.0f, -0.95f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.0f, -0.70f);
    //river with sky blue color
    glColor3ub	(240,230,140);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(1.0f, -0.65f);
    glVertex2f(1.0f, -0.70f);


    glEnd();
    glFlush();
}

void field()
{

    glBegin(GL_QUADS);
    glColor3ub	(205,133,63);
    //field after road
    glVertex3f(-1.0f, -0.25f,0.0f);
    glVertex3f(-1.0f, -0.45f,0.0f);
    glVertex3f(1.0f, -0.45f,0.0f);
    glVertex3f(1.0f, -0.25f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub	(205,133,63);
    glVertex3f(-1.0f, -0.20f,0.0f);
    glVertex3f(-1.0f, -0.02f,0.0f);
    glVertex3f(1.0f, -0.02f,0.0f);
    glVertex3f(1.0f, -0.20f,0.0f);
    glEnd();

}

void hill()
{
    glBegin(GL_QUADS);
    if (night==true)
    {
        glColor3ub(10, 41, 14);
    }
    else
        glColor3ub(3, 99, 17);
    //glColor3ub(3, 99, 17);
    glVertex2f(1.0f, 0.20f);
    glVertex2f(1.0f, -0.02f);
    glVertex2f(-1.0f, -0.02f);
    glVertex2f(-1.0f, 0.20f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(-0.885f, 0.33f);
    glVertex2f(-0.75f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.71f, 0.20f);
    glVertex2f(-0.55, 0.38f);
    glVertex2f(-0.40f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.55f, 0.20f);
    glVertex2f(-0.32f, 0.37f);
    glVertex2f(-0.27f, 0.35f);
    glVertex2f(-0.15f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.13f, 0.20f);
    glVertex2f(0.0f, 0.37f);
    glVertex2f(0.12f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.15f, 0.20f);
    glVertex2f(0.28f, 0.39f);
    glVertex2f(0.38f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.28f, 0.20f);
    glVertex2f(0.46f, 0.39f);
    glVertex2f(0.49f, 0.37f);
    glVertex2f(0.60f, 0.20f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.53f, 0.20f);
    glVertex2f(0.68f, 0.36f);
    glVertex2f(0.80f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.78f, 0.20f);
    glVertex2f(0.90f, 0.38f);
    glVertex2f(1.0f, 0.20f);
    glEnd();

}

void building()
{
    glBegin(GL_QUADS);
    glColor3ub	(0,0,255);

    //1st building blue color

    glVertex3f(-.60f, -0.10f,0.0f);
    glVertex3f(-.60f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.10f,0.0f);

    //2nd tall building
    glColor3ub	(135,206,235);
    glVertex3f(-.45f, -0.05f,0.0f);
    glVertex3f(-.45f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.05f,0.0f);
    glEnd();

    glBegin(GL_QUADS);

    //red shades window in 1st building
    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.13f,0.0f);
    glVertex3f(-0.60f, -0.15f,0.0f);
    glVertex3f(-0.45f, -0.15f,0.0f);
    glVertex3f(-0.45f, -0.13f,0.0f);

    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.20f,0.0f);
    glVertex3f(-0.60f, -0.22f,0.0f);
    glVertex3f(-0.45f, -0.22f,0.0f);
    glVertex3f(-0.45f, -0.20f,0.0f);

    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.27f,0.0f);
    glVertex3f(-0.60f, -0.29f,0.0f);
    glVertex3f(-0.45f, -0.29f,0.0f);
    glVertex3f(-0.45f, -0.27f,0.0f);
    glEnd();
}

void grass()
{
    glBegin(GL_QUADS);
    glColor3ub		(34,139,34);
    // grass field
    glVertex3f(-1.0f, -0.20f,0.0f);
    glVertex3f(-1.0f, -0.25f,0.0f);
    glVertex3f(1.0f, -0.25f,0.0f);
    glVertex3f(1.0f, -0.20f,0.0f);
    glEnd();


}
void Sky(void)
{

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(5, 245, 237);


    glBegin(GL_QUADS);
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0, 0.8);
    glVertex2f(1.0, 0.8);
    glVertex2f(1.0, 1.0);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(81, 245, 239);


    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.8);
    glVertex2f(-1.0, 0.6);
    glVertex2f(1.0, 0.6);
    glVertex2f(1.0, 0.8);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(131, 242, 238);

    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.6);
    glVertex2f(-1.0, 0.4);
    glVertex2f(1.0, 0.4);
    glVertex2f(1.0, 0.6);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(167, 242, 240);

    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.4);
    glVertex2f(-1.0, 0.2);
    glVertex2f(1.0, 0.2);
    glVertex2f(1.0, 0.4);
    glEnd();

}

void clouds()
{
    glColor3ub(204, 219, 219);
    circle(-0.45f,0.85f,0.1f);
    circle(-0.61f,0.85f,0.15f);
    circle(-0.71f,0.85f,0.13f);
    circle(-0.82f,0.85f,0.1f);

    circle(0.54f,0.85f,0.1f);
    circle(0.64f,0.85f,0.15f);
    circle(0.75,0.85f,0.13f);
}


void car()
{
    glPushMatrix();
    glTranslatef(carPosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(3, 98, 252);
    glVertex2f(-0.90f, -0.40f);
    glVertex2f(-0.95f, -0.45f);
    glVertex2f(-0.95f, -0.50f);
    glVertex2f(-0.75f, -0.50f);
    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.80f, -0.40f);
    glVertex2f(-0.90f, -0.40f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(-0.89f, -0.41f);
    glVertex2f(-0.94f, -0.45f);
    glVertex2f(-0.86f, -0.45f);
    glVertex2f(-0.86f, -0.41f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(-0.84f, -0.41f);
    glVertex2f(-0.84f, -0.45f);
    glVertex2f(-0.76f, -0.45f);
    glVertex2f(-0.81f, -0.41f);
    glEnd();

    glColor3ub(250, 17, 5);
    circle(-0.80,-0.50,0.02);
    circle(-0.91,-0.50,0.02);

    if (night==true)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(255, 242, 0);
        glVertex2f(-0.75, -0.45f);
        glVertex2f(-0.73f, -0.52f);
        glVertex2f(-0.70f, -0.52f);
        glEnd();
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosition1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(3, 98, 252);
    glVertex2f(0.30f, -0.53f);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.25f, -0.63f);
    glVertex2f(0.45f, -0.63f);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.40f, -0.53f);
    glVertex2f(0.30f, -0.53f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(0.31f, -0.54f);
    glVertex2f(0.26f, -0.58f);
    glVertex2f(0.34f, -0.58f);
    glVertex2f(0.34f, -0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(0.36f, -0.54f);
    glVertex2f(0.36f, -0.58f);
    glVertex2f(0.44f, -0.58f);
    glVertex2f(0.40f, -0.54f);
    glEnd();

    glColor3ub(250, 17, 5);
    circle(0.29,-0.63,0.02);
    circle(0.40,-0.63,0.02);

    if (night==true)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(255, 242, 0);
        glVertex2f(0.25f, -0.58f);
        glVertex2f(0.23f, -0.65f);
        glVertex2f(0.20f, -0.65f);
        glEnd();

    }

    glPopMatrix();

    glFlush();
}

void sun()
{
    glColor3ub(255, 126, 5);
    glPushMatrix();
    glTranslatef(0.0, sunPosition, 0.0f);
    circle(0.9, 0.9, 0.1);
    glPopMatrix();
    //sunSpeed-=0.05;
    glFlush();

}

void moon()
{

    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0, moonPosition, 0.0f);
    circle(-0.9,0.1,0.1);
    //moonPosition+=0.005;
    glPopMatrix();
}

void dayNight()
{
    sunPosition-=0.05;
    if (sunPosition < -1.0)
    {
        moonPosition+=0.05;
    }

}

void railTrack()
{
    for(float j=-1.0f; j<=1.0f; j+=0.05f)
    {
        glBegin(GL_LINES);
        glColor3f(0.5f,0.0f,0.0f);
        glVertex2f(j,-0.08);
        glVertex2f(j,-0.16);
        glEnd();
    }
    glBegin(GL_LINES);
    glColor3f(0.5f,0.0f,0.0f);
    glVertex2f(-1.0,-0.08);
    glVertex2f(1.0,-0.08);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5f,0.0f,0.0f);
    glVertex2f(-1.0,-0.16);
    glVertex2f(1.0,-0.16);
    glEnd();
}

void rail()
{
    glPushMatrix();
    glTranslatef(railPosition, 0.0f, 0.0f);

    glColor3f(0.5f,0.0f,0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0.50, -0.13);
    glVertex2f(0.65, -0.13);
    glVertex2f(0.65, -0.04);
    glVertex2f(0.50, -0.04);
    glEnd();

    if (night==true)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(255, 242, 0);
        glVertex2f(0.50, -0.04);
        glVertex2f(0.45, -0.16);
        glVertex2f(0.35, -0.16);
        glEnd();

    }

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.51, -0.10);
    glVertex2f(0.54, -0.10);
    glVertex2f(0.54, -0.06);
    glVertex2f(0.51, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.56, -0.10);
    glVertex2f(0.59, -0.10);
    glVertex2f(0.59, -0.06);
    glVertex2f(0.56, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.61, -0.10);
    glVertex2f(0.64, -0.10);
    glVertex2f(0.64, -0.06);
    glVertex2f(0.61, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.65, -0.13);
    glVertex2f(0.66, -0.13);
    glVertex2f(0.66, -0.10);
    glVertex2f(0.65, -0.10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,1.0f);
    glVertex2f(0.66, -0.13);
    glVertex2f(0.81, -0.13);
    glVertex2f(0.81, -0.04);
    glVertex2f(0.66, -0.04);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.67, -0.10);
    glVertex2f(0.70, -0.10);
    glVertex2f(0.70, -0.06);
    glVertex2f(0.67, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.72, -0.10);
    glVertex2f(0.75, -0.10);
    glVertex2f(0.75, -0.06);
    glVertex2f(0.72, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.77, -0.10);
    glVertex2f(0.80, -0.10);
    glVertex2f(0.80, -0.06);
    glVertex2f(0.77, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.81, -0.13);
    glVertex2f(0.82, -0.13);
    glVertex2f(0.82, -0.10);
    glVertex2f(0.81, -0.10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(0.82, -0.13);
    glVertex2f(0.97, -0.13);
    glVertex2f(0.97, -0.04);
    glVertex2f(0.82, -0.04);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.83, -0.10);
    glVertex2f(0.86, -0.10);
    glVertex2f(0.86, -0.06);
    glVertex2f(0.83, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.88, -0.10);
    glVertex2f(0.91, -0.10);
    glVertex2f(0.91, -0.06);
    glVertex2f(0.88, -0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.93, -0.10);
    glVertex2f(0.96, -0.10);
    glVertex2f(0.96, -0.06);
    glVertex2f(0.93, -0.06);
    glEnd();

    glColor3ub(12, 5, 237);
    circle(0.94,-0.14,0.02);
    circle(0.85,-0.14,0.02);
    circle(0.78,-0.14,0.02);
    circle(0.69,-0.14,0.02);
    circle(0.62,-0.14,0.02);
    circle(0.53,-0.14,0.02);

    glPopMatrix();
    glFlush();
}

void windmill()
{
    glPushMatrix();
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(117, 117, 117);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.28);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if(rt)
    {
        glRotatef(rotatei,0,0.0,0.1);
    }
    // P1
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.2, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.2, 0.1);
    glEnd();

    // P2
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, 0.2);
    glVertex2f(0, 0.2);
    glEnd();

    // P3
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0);
    glEnd();

    // P4
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.2);
    glVertex2f(0, -0.2);
    glEnd();
    glPopMatrix();
    if(rt)
    {
        rotatei+=1.0f;
    }
}

void windmill2()
{
    glPushMatrix();
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.83, -0.2);
    glVertex2f(-0.83, 0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if(rt)
    {
        glRotatef(rotatei1,0,0.0,0.1);
    }
    // P1
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(-1.03, 0.1);
    glVertex2f(-0.83f, 0.1f);
    glVertex2f(-1.03, 0.2);
    glEnd();

    // P2
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.83, 0.1);
    glVertex2f(-0.73, 0.3);
    glVertex2f(-0.83, 0.3);
    glEnd();

    // P3
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.83, 0.1);
    glVertex2f(-0.63, 0.0);
    glVertex2f(-0.63, 0.1);
    glEnd();

    // P4
    glBegin(GL_TRIANGLES);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.83, 0.1);
    glVertex2f(-0.93, -0.1);
    glVertex2f(-0.83, -0.1);
    glEnd();
    glPopMatrix();
    if(rt)
    {
        //rotatei1 -=0.1f;
    }
}

void Rain()
{
    if(rainday==true)
    {
        glPushMatrix();
        glTranslatef(0.0, 0.5f, 0.0f);

        glPushMatrix();
        glTranslatef(0.0, positionRain, 0.0f);
        for(float i=1.0f; i>=-1.5f; i-=0.05f)
        {
            for(float j=-1.0f; j<=1.5f; j+=0.05f)
            {
                glLineWidth(1);
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(j+0.01,i);
                glVertex2f(j,i+0.02);
                glEnd();
            }
        }
        glPopMatrix();
        glPopMatrix();

    }
    positionRain-=0.05;
    glFlush();
}


void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);

    Sky();
    sun();
    moon();
    grass();
    field();
    railTrack();
    rail();
    //building();
    clouds();
    hill();
    plane();
    railTrack();
    rail();
    windmill();
    windmill2();
    glPushMatrix();
    building();
    glTranslatef(.60f,0.0f,0.0f);
    building();
    glTranslatef(.70f,0.0f,0.0f);
    building();
    glPopMatrix();
    glPushMatrix();
    glPopMatrix();
    river();
    road();
    car();
    boat();
    Rain();
    if (f1==1)
    {
        dayNight();
    }
}


void mouse(int button,int state,int x,int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        //carSpeed += 0.01f;
        carSpeed1 += 0.01f;
        boatSpeed += 0.01f;
        railSpeed += 0.01f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        carSpeed -= 0.01f;
        //carSpeed1 -= 0.01f;
        boatSpeed -= 0.01f;
        planeSpeed -=0.01f;
    }
    if (button==GLUT_MIDDLE_BUTTON)
    {
        carSpeed = 0.0f;
        carSpeed1 = 0.0f;
        boatSpeed = 0.0f;
        railSpeed = 0.0f;
        planeSpeed =0.0f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='a')
    {
        //sun();
        f1=0;
        night=false;
        sunPosition=0.0;
        moonPosition=0.0;
        glutPostRedisplay();
    }
    if(key=='b')
    {
        //sun();
        f1=0;
        night=true;
        sunPosition=-1.0;
        moonPosition=0.8;
        glutPostRedisplay();
    }

    if(key=='i')
    {
        rainday=true;
        glutPostRedisplay();
    }
    if(key=='j')
    {
        rainday=false;
        glutPostRedisplay();
    }
    if(key=='m')
    {
        planeSpeed -=0.01f;
        glutPostRedisplay();
    }
    else if(key=='n')
    {
        planeSpeed =0.0f;
        glutPostRedisplay();
    }
    else if(key=='o')
    {
        railSpeed += 0.01f;
        glutPostRedisplay();
    }
    else if(key=='p')
    {
        railSpeed = 0.0f;
        glutPostRedisplay();
    }
    else if(key=='q')
    {
        carSpeed -= 0.01f;
        glutPostRedisplay();
    }
    else if(key=='r')
    {
        carSpeed = 0.0f;
        glutPostRedisplay();
    }
    else if(key=='s')
    {
        carSpeed1 += 0.01f;
        glutPostRedisplay();
    }
    else if(key=='t')
    {
        carSpeed1 = 0.0f;
        glutPostRedisplay();
    }
    else if(key=='u')
    {
        boatSpeed += 0.01f;
        glutPostRedisplay();
    }
    else if(key=='v')
    {
        boatSpeed -= 0.01f;
        glutPostRedisplay();
    }
    else if(key=='w')
    {
        boatSpeed = 0.0f;
        glutPostRedisplay();
    }
    else if(key=='x')
    {
        f1=1;
        glutPostRedisplay();
    }
    else if(key=='z')
    {
        stop();
        glutIdleFunc(display);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(700,700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Port City");
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    //init();
    glutMainLoop();
    return 0;
}
s
