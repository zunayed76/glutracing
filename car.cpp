
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
//#include "header.h"
using namespace std;


void ok()
{
    ///uprer aboron
    glBegin(GL_TRIANGLE_STRIP);    /// quad er 4 ta point
    glColor3f(1,1,1);
    glVertex3f(2,0,-2);
    glVertex3f(-2,0,-2);
    glVertex3f(2,0,4);
    glVertex3f(-2,0,4);

    glVertex3f(2,-0.5,4.5);
    glVertex3f(-2,-0.5,4.5);
    glEnd();

    glBegin(GL_QUADS);      ///samner dandi dan pash
    glVertex3f(-2,-0.5,4.5);
    glVertex3f(-2,-2,6);
    glVertex3f(-1.75,-2,6);
    glVertex3f(-1.75,-0.5,4.5);
    glEnd();
    glBegin(GL_QUADS);      ///samner dandi bam pash
    glVertex3f(2,-0.5,4.5);
    glVertex3f(2,-2,6);
    glVertex3f(1.75,-2,6);
    glVertex3f(1.75,-0.5,4.5);
    glEnd();

    glBegin(GL_QUADS);      ///windshield
    glColor3f(1,1,0);
    glVertex3f(1.75,-2,6);
    glVertex3f(1.75,-0.5,4.5);
    glVertex3f(-1.75,-0.5,4.5);
    glVertex3f(-1.75,-2,6);
    glEnd();
    glBegin(GL_QUADS);      ///pichoner dandi bam pash
    glVertex3f(2,0,-2);
    glVertex3f(2,-2,-2);
    glVertex3f(1.75,-2,-2);
    glVertex3f(1.75,0,-2);
    glEnd();
    glBegin(GL_QUADS);      ///pichoner dandi dan pash
    glVertex3f(-2,0,-2);
    glVertex3f(-2,-2,-2);
    glVertex3f(-1.75,-2,-2);
    glVertex3f(-1.75,0,-2);
    glEnd();
    glBegin(GL_QUADS);      ///engine bonet
    glVertex3f(-2,-2,6);
    glVertex3f(-2,-2,7.5);
    glVertex3f(2,-2,7.5);
    glVertex3f(2,-2,6);
    glEnd();
    glBegin(GL_QUADS);      ///headlight er jayga  eitar moddhe grill er texture majh dia deoar try korbo

    glVertex3f(-2,-2,7.5);
    glVertex3f(-2,-4,7.5);
    glVertex3f(2,-4,7.5);
    glVertex3f(2,-2,7.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1,0,1);
    glVertex3f(-2,-4,7.5);
    glVertex3f(-2,-4,6.5);
    glVertex3f(-2,-2,7.5);
    glVertex3f(-2,-2,6.5);
    glEnd();


    glPushMatrix();        /// chaka
    glRotatef(90,0,1,0);
    glTranslatef(-5,-4,-1.75);    /// z okkho = x okkho
    glutSolidTorus(0.2,1,30,30);
    glPopMatrix();


    glPushMatrix();   ///chaka2
    glRotatef(90,0,1,0);
    glTranslatef(-5,-4,1.75);    /// z okkho = x okkho
    glutSolidTorus(0.2,1,30,30);
    glPopMatrix();

    glPushMatrix();   ///chaka3
    glRotatef(90,0,1,0);
    glTranslatef(0,-4,-1.75);    /// z okkho = x okkho
    glutSolidTorus(0.2,1,30,30);
    glPopMatrix();
    glPushMatrix();   ///chaka4
    glRotatef(90,0,1,0);
    glTranslatef(0,-4,1.75);    /// z okkho = x okkho
    glutSolidTorus(0.2,1,30,30);
    glPopMatrix();


}









/*void cube(float fr = 1.0, float fg = 0.0, float fb = 0.0,float lr = 0.0, float lg = 1.0, float lb = 0.0,float tr = 0.0, float tg = 0.0, float tb = 1.0 )
{

    glBegin(GL_QUADS);
    /// FRONT
    glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // BACK
    glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);

    /// LEFT
    glColor3f(lr,lg,lb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    // RIGHT
    glColor3f(lr,lg,lb);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);

    /// TOP
    glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // BOTTOM
    glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glEnd();
}
*/
