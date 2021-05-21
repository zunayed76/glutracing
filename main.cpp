#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;


double windowHeight=1920, windowWidth=1080;
bool rott=false;
float rotlimX = 0.0;
float rotlimY = 0.0;
float rotlimZ = 0.0;
bool chkx = false;
bool chky = false;
bool chkz = false;

bool chX = false;
bool chY = false;
bool chZ = false;

bool scenerotX = false;
bool scenerotY = false;
bool scenerotZ = false;

#define PI 3.141592654

GLfloat eyeX = 0;      ///eye  4.5
GLfloat eyeY = 0;     /// 1.9
GLfloat eyeZ = -14;        ///-6

GLfloat lookX = 0;      ///look at point
GLfloat lookY = 0;
GLfloat lookZ = 0;






static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}





void scene()
{
    glPushMatrix();
   // glScalef(100,100,100);
    //test();
    ok();

    glPopMatrix();
}









static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glOrtho(0.0,2,0.0,2,0.0,1.0);
    //glFrustum(-6,6,-6,6, 1, 30);
    glFrustum(-3.4,3.4,-3,3,1.5,60);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);

    glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    //glRotatef(rotlimit,0,1,0);
    //fan();
    //fanUpy();
    //chair();
    //desk();
    //cabinet();
    glRotatef(rotlimX,1,0,0);
    glRotatef(rotlimY,0,1,0);
    glRotatef(rotlimZ,0,0,1);
    //dias();
    //course_title_draw();
    //window();
    scene();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}



static void idle(void)
{
    glutPostRedisplay();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'x':
        chkx = !chkx;
        break;
    case 'y':
        chky = !chky;
        break;
    case 'z':
        chkz = !chkz;
        break;
    case 'c':
        chX = !chX;
        break;
    case 'u':
        chY = !chY;
        break;
    case 'v':
        chZ = !chZ;
        break;
    case 'e':
        scenerotX = !scenerotX;
        break;
    case 'r':
        scenerotY = !scenerotY;
        break;
    case 't':
        scenerotZ = !scenerotZ;
        break;
    case 27:	// Escape key
        exit(1);
    }
}

void animate()
{
    if (scenerotX)
    {
        rotlimX+= 0.5;

        if(rotlimX > 360)
            rotlimX = 0.0;

    }
    if (scenerotY)
    {
        rotlimY+= 0.5;

        if(rotlimY > 360)
            rotlimY = 0.0;

    }
    if (scenerotZ)
    {
        rotlimZ+= 0.5;

        if(rotlimZ > 360)
            rotlimZ = 0.0;

    }
    if (chkx)
    {
        eyeX = eyeX + 1;
        lookX = lookX + 1;
        chkx = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chky)
    {
        eyeY = eyeY + 1;
        lookY = lookY + 1;
        chky = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chkz)
    {
        eyeZ = eyeZ + 1;
        lookZ = lookZ + 1;
        chkz = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chX)
    {
        eyeX = eyeX - 1;
        lookX = lookX - 1;
        chX = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chY)
    {
        eyeY = eyeY - 1;
        lookY = lookY - 1;
        chY = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chZ)
    {
        eyeZ = eyeZ - 1;
        lookZ = lookZ - 1;
        chZ = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }

    glutPostRedisplay();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("1607076-ClassRoom");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);


    glutMainLoop();

    return 0;
}
