#include<windows.h>
#include<GLUT/glut.h>
#include<GL/glut.h>
#include<stdlib.h>// new project estimation //new project estimation
// Life of pie........................................................
float _moveAll = 0.0f;
float nytground = 0.3;
float moonCtrl = 0.2;
float cloudCtrl = 0.7;

void ground()
{
    glBegin(GL_QUADS);          // near the road silver ground
    glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(-1,0.5);
       glVertex2f(1,0.5);
       glVertex2f(1,0.4);
       glVertex2f(-1,0.4);
       glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(-1.0,1.1);
       glVertex2f(1,1.1);
       glVertex2f(1,0.5);
       glVertex2f(-1.0,0.5);
       glEnd();
}

void hill(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

    glBegin(GL_TRIANGLES);           //it is the most left hill 1
    glColor3f(0.0f, hillCtrl, 0.0f);
       glVertex2f(-2.2,1.1);
       glVertex2f(-1.7,1.1);
       glVertex2f(-1.9,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);  //2
       glVertex2f(-1.9,1.1);
       glVertex2f(-1.5,1.1);
       glVertex2f(-1.7,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);  //3
       glVertex2f(-1.8,1.1);
       glVertex2f(-1.3,1.1);
       glVertex2f(-1.45,1.7);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.45,1.1);
       glVertex2f(-1.0,1.1);
       glVertex2f(-1.3,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);  //4
       glVertex2f(-1.3,1.1);
       glVertex2f(-0.9,1.1);
       glVertex2f(-1.1,1.7);
       glEnd();
    glBegin(GL_TRIANGLES);  //5
       glVertex2f(-1.1,1.1);
       glVertex2f(-0.6,1.1);
       glVertex2f(-0.9,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);  //6
       glVertex2f(-0.9,1.1);
       glVertex2f(-0.5,1.1);
       glVertex2f(-0.7,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);  //7
       glVertex2f(-0.75,1.1);
       glVertex2f(-0.35,1.1);
       glVertex2f(-0.5,1.7);
       glEnd();
    glBegin(GL_TRIANGLES); //8
       glVertex2f(-0.5,1.1);
       glVertex2f(-0.1,1.1);
       glVertex2f(-0.3,1.5);
       glEnd();
    glBegin(GL_TRIANGLES); //9
       glVertex2f(-0.3,1.1);
       glVertex2f(0.05,1.1);
       glVertex2f(-0.15,1.55);
       glEnd();
    glBegin(GL_TRIANGLES); //10
       glVertex2f(-0.15,1.1);
       glVertex2f(0.25,1.1);
       glVertex2f(0.1,1.65);
       glEnd();
    glBegin(GL_TRIANGLES); //11
       glVertex2f(0.1,1.1);
       glVertex2f(0.45,1.1);
       glVertex2f(0.25,1.8);
       glEnd();
    glBegin(GL_TRIANGLES);  //12
       glVertex2f(0.2,1.1);
       glVertex2f(0.6,1.1);
       glVertex2f(0.45,1.65);
       glEnd();
    glBegin(GL_TRIANGLES);  //13
       glVertex2f(0.35,1.1);
       glVertex2f(0.85,1.1);
       glVertex2f(0.65,1.55);
       glEnd();
    glBegin(GL_TRIANGLES);  //14
       glVertex2f(0.65,1.1);
       glVertex2f(1.15,1.1);
       glVertex2f(0.85,1.75);
       glEnd();
    glBegin(GL_TRIANGLES);  //15
       glVertex2f(0.85,1.1);
       glVertex2f(1.25,1.1);
       glVertex2f(1.05,1.65);
       glEnd();
    glBegin(GL_TRIANGLES);  //16
       glVertex2f(1.05,1.1);
       glVertex2f(1.45,1.1);
       glVertex2f(1.25,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);  //17
       glVertex2f(1.25,1.1);
       glVertex2f(1.65,1.1);
       glVertex2f(1.45,1.75);
       glEnd();
    glBegin(GL_TRIANGLES);  //18
       glVertex2f(1.45,1.1);
       glVertex2f(1.85,1.1);
       glVertex2f(1.6,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);  //19
       glVertex2f(1.6,1.1);
       glVertex2f(2.2,1.1);
       glVertex2f(1.9,1.7);
       glEnd();
    glPopMatrix();
}
void moon(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    circle(-0.75f, 1.9f, 0.1f);
    glColor3f(moonCtrl, moonCtrl, 0.2f);
    circle(-0.73f, 1.91f, 0.09f);
    glPopMatrix();
}
void clouds(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glColor3f(cloudCtrl, cloudCtrl, cloudCtrl);
    circle(0.0f,1.95f,0.1f);
    circle(-0.16f,1.95f,0.15f);
    circle(-0.26f,1.95,0.13f);
    circle(-0.37f,1.95f,0.1f);

    glPushMatrix();
	glTranslatef(0.8f,0.0f,0.0f);
    circle(0.0f,1.95f,0.1f);
    circle(-0.16f,1.95f,0.15f);
    circle(-0.3f,1.95,0.13f);
    glPopMatrix();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1100,850);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Mordern City ");

    glutMainLoop();
    return 0;
}
