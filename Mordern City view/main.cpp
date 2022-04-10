#include <iostream>
using namespace std;
#include<GL/gl.h>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <Windows.h>



int _raining=1;
int  night=1;
int rainhappen=0;
int _sunY=0;
int nightCheck=3;
int test=0;



void sunMaking()
{
    if(rainhappen==0)
    {


    glBegin(GL_POLYGON); // 1st circle yellow
    glColor3f(1.000, 1.000, 0.000);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=70;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+1000,y+1350 );
	}
	glEnd();

	glBegin(GL_POLYGON);// 2nd circle red
    glColor3f(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=65;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+1000,y+1350 );
	}
	glEnd();

	glBegin(GL_POLYGON);

	glEnd();
    }


}

void normalSky()

{

	glBegin(GL_POLYGON); //Sky
	glColor3f(0,0,0);

	glVertex2i(2000, 1500);
	glVertex2i(0, 1500);

	glColor3f(2.49, 1.87, 1.0);
	glVertex2i(0, 970);
	glVertex2i(2000, 970);
	glEnd();




    }





void river() {


	glBegin(GL_POLYGON); // River


	glColor3f(0, 0, 0.189);
	glVertex2i(0, 200);

	if(rainhappen==1||rainhappen==1&&night==1)
    {
        glColor3f(0.663, 0.663, 0.663);
    }

    else if(night==1)
    {
        glColor3f(0.000, 0.000, 0.545);
    }

	else{glColor3f(1.4, .8, .949);}


	glVertex2i(1000, 200);

	glColor3f(0.106, 1.69, .918);
	glVertex2i(2000, 200);

    glColor3f(0.733, 0.886, .953);
	glVertex2i(2000, 970);

	glColor3f(0.733, 0.886, .953);
	glVertex2i(1000, 970);

	if(rainhappen==1||rainhappen==1&&night==1)
    {
        glColor3f(0.663, 0.663, 0.663);
    }
    if(test==1)
    {
        glColor3f(0.733, 0.886, .953);
    }
	glVertex2i(0, 970);

	glEnd();
    }




void river_side()
{
   glColor3f(0.4, 0.4, 0.4);


}



 void road ()
 {
     glBegin(GL_QUADS);//only road

	glColor3f(0.412, 0.412, 0.412);

	glVertex2i(0,15);
	glVertex2i(2000,50);
	glVertex2i(2000,550);
	glVertex2i(0,500);
	glEnd();

	// 3D testing



	//making 3d lining front side



	// white on under black

	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(150,2);
	glVertex2i(1850,5);
	glVertex2i(1850,45);
	glVertex2i(150,17);
	glEnd();

	//black

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(300,2);
	glVertex2i(1700,5);
	glVertex2i(1700,45);
	glVertex2i(300,23);
	glEnd();


	glBegin(GL_POLYGON);// black
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(600,2);
	glVertex2i(1400,5);
	glVertex2i(1400,43);
	glVertex2i(600,27);
	glEnd();

	glBegin(GL_POLYGON);//white
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750,2);
	glVertex2i(1250,3);
	glVertex2i(1250,41);
	glVertex2i(750,30);
	glEnd();

	glBegin(GL_POLYGON);//black
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(900,2);
	glVertex2i(1100,3);
	glVertex2i(1100,41);
	glVertex2i(900,35);
	glEnd();




	// divider line from right side

	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(1800,250);
	glVertex2i(1950,260);
	glVertex2i(1930,270);
	glVertex2i(1780,265);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(1400,230);
	glVertex2i(1550,240);
	glVertex2i(1530,250);
	glVertex2i(1380,245);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(1000,210);
	glVertex2i(1150,220);
	glVertex2i(1130,230);
	glVertex2i(980,225);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(600,190);
	glVertex2i(750,200);
	glVertex2i(730,210);
	glVertex2i(580,205);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2i(200,170);
	glVertex2i(350,180);
	glVertex2i(330,190);
	glVertex2i(180,185);
    glEnd();


    // footpath beside river


    glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0,500);
	glVertex2i(2000,550);
	glVertex2i(2000,600);
	glVertex2i(0,550);
    glEnd();

    glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(0,500);
	glVertex2i(2000,550);
	glVertex2i(2000,600);
	glVertex2i(0,550);
    glEnd();


    // divder coloring Black

    glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(150,505);
	glVertex2i(1850,545);
	glVertex2i(1850,595);
	glVertex2i(150,555);
    glEnd();

    // divider coloring white

    glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
	glVertex2i(300,505);
	glVertex2i(1700,540);
	glVertex2i(1700,595);
	glVertex2i(300,560);
    glEnd();

    // divider coloring black 2

    glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(450,503);
	glVertex2i(1550,535);
	glVertex2i(1550,595);
	glVertex2i(450,565);
    glEnd();

    // divider coloring white 2

    glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
	glVertex2i(600,508);
	glVertex2i(1400,531);
	glVertex2i(1400,593);
	glVertex2i(600,569);
    glEnd();

    // divider coloring white 3

    glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
	glVertex2i(900,513);
	glVertex2i(1100,521);
	glVertex2i(1100,585);
	glVertex2i(900,578);
    glEnd();


 }

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
      case 27:     // ESC key
         exit(0);
         break;
    }



}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

	normalSky();


    glPushMatrix();

   sunMaking();

    glPopMatrix();



	river();



	river_side();



	road();



if(rainhappen==1)
    {


       glPushMatrix();
	   glTranslatef(0.0f ,_raining ,0.0f);
//
	   glPopMatrix();
    }


	glutPostRedisplay();
	glutSwapBuffers();
}



void update(int value)
{

glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 20 milliseconds
}


int main(int argc, char** argv)
 {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1350, 700);
	glutCreateWindow("City");
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
	glutKeyboardFunc(keyboard);

	glutDisplayFunc(myDisplay);

	glutTimerFunc(20, update, 0);
	glutFullScreen();
	sndPlaySound("3.wav",SND_ASYNC);
	glutMainLoop();


	return 0;
}
