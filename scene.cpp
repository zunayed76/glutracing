
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;




void kuetgate()
{
    glBegin(GL_QUADS);  ///nicher trivuj bam pash
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(3,-3,-1);
    glVertex3f(3,-3,0);
    glEnd();
    glBegin(GL_QUADS);  ///nicher trivuj dan pash
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(-3,-3,-1);
    glVertex3f(-3,-3,0);
    glEnd();
    glBegin(GL_QUADS);  ///uprer sobche uchu
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(-3,3,-1);
    glVertex3f(-3,3,0);
    glEnd();
    glBegin(GL_QUADS);  ///somantoral
    glVertex3f(0,0,0);
    glVertex3f(0,0,-1);
    glVertex3f(-3,0,-1);
    glVertex3f(-3,0,0);
    glEnd();

    glBegin(GL_QUADS);  ///nicher dan er somantoral
    glVertex3f(-1.5,1.5,0);
    glVertex3f(-1.5,1.5,-1);
    glVertex3f(-3,0,-1);
    glVertex3f(-3,0,0);
    glEnd();
    glBegin(GL_QUADS);  ///
    glVertex3f(-1.5,-1.5,0);
    glVertex3f(-1.5,-1.5,-1);
    glVertex3f(-3,0,-1);
    glVertex3f(-3,0,0);
    glEnd();
    glBegin(GL_QUADS);  ///dan diker dandi
    glVertex3f(-3,-3,0);
    glVertex3f(-3,-3,-1);
    glVertex3f(-3,0,-1);
    glVertex3f(-3,0,0);
    glEnd();
    glBegin(GL_QUADS);  ///solid
    glVertex3f(-3,0,0);
    glVertex3f(-1.5,-1.5,0);
    glVertex3f(-2.9,-3,0);
    glVertex3f(-3,-3,0);
    glEnd();


}

void kuetlogo()
{

    /// kkkkkkkkk
    glPushMatrix();
    glScalef(1,10,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-0.5,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-0.5,4.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();


    glPushMatrix();
    glScalef(1,5,1);
    glTranslatef(-3.5,-0.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();


    /// u
    glPushMatrix();
    glScalef(1,10,1);
    glTranslatef(-6,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(1,10,1);
    glTranslatef(-10,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();

    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-2,-4.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();




    //e

    glPushMatrix();
    glScalef(1,10,1);
    glTranslatef(-12,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-3.5,-4.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-3.5,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(4,1,1);
    glTranslatef(-3.5,4.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();


    //t

    glPushMatrix();
    glScalef(1,10,1);
    glTranslatef(-20.5,0,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(6,1,1);
    glTranslatef(-3.4,4.5,0);
    //glRotatef(90,0,0,1);
    cube();
    glPopMatrix();



}
void basescene()
{



    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();

    ///main road
    glBegin(GL_QUADS);

    glVertex3f(0,-2,0);   glTexCoord2f(0,0);
    glVertex3f(-1,-2,0);  glTexCoord2f(0,1);
    glVertex3f(-1,-2,5.99); glTexCoord2f(1,1);
    glVertex3f(0,-2,5.99); glTexCoord2f(1,0);


    glEnd();
    glPopMatrix();



    glBegin(GL_QUADS);

    glVertex3f(0,-2,6); glTexCoord2f(0,0);
    glVertex3f(0,-2,7);   glTexCoord2f(0,1);
    glVertex3f(-5.99,-2,7);   glTexCoord2f(1,1);
    glVertex3f(-5.99,-2,6);   glTexCoord2f(1,0);
    glEnd();


    glBegin(GL_QUADS);

    glVertex3f(-6,-2,6); glTexCoord2f(0,0);
    glVertex3f(-7,-2,6); glTexCoord2f(0,1);
    glVertex3f(-7,-2,25); glTexCoord2f(1,1);
    glVertex3f(-6,-2,25);glTexCoord2f(1,0);
    glEnd();


    glBegin(GL_QUADS);

    glVertex3f(-7,-2,25); glTexCoord2f(0,0);
    glVertex3f(-7,-2,24);  glTexCoord2f(0,1);
    glVertex3f(-16,-2,24); glTexCoord2f(1,1);
    glVertex3f(-16,-2,25); glTexCoord2f(1,0);
    glEnd();

    glBegin(GL_QUADS);


    glVertex3f(-16,-2,6); glTexCoord2f(0,0);
    glVertex3f(-17,-2,6); glTexCoord2f(0,1);
    glVertex3f(-17,-2,25); glTexCoord2f(1,1);
    glVertex3f(-16,-2,25); glTexCoord2f(1,0);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(-16,-2,6);  glTexCoord2f(0,0);
    glVertex3f(-16,-2,7);  glTexCoord2f(0,1);
    glVertex3f(-6,-2,7); glTexCoord2f(1,1);
    glVertex3f(-7,-2,6); glTexCoord2f(1,0);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);





    /// ghas majhkhan



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[5]);
    glPushMatrix();


    glBegin(GL_QUADS);

    glVertex3f(-7,-2,7);  glTexCoord2f(0,0);
    glVertex3f(-16,-2,7);  glTexCoord2f(0,1);
    glVertex3f(-16,-2,24); glTexCoord2f(1,1);
    glVertex3f(-7,-2,24); glTexCoord2f(1,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0,-2,7);  glTexCoord2f(0,0);
    glVertex3f(-6,-2,7);  glTexCoord2f(0,1);
    glVertex3f(-6,-2,11); glTexCoord2f(1,1);
    glVertex3f(0,-2,11); glTexCoord2f(1,0);
    glEnd();
///2 tar majhe pukur


    glBegin(GL_QUADS);
    glVertex3f(0,-2,13);  glTexCoord2f(0,0);
    glVertex3f(-6,-2,13);  glTexCoord2f(0,1);
    glVertex3f(-6,-2,25); glTexCoord2f(1,1);
    glVertex3f(0,-2,25); glTexCoord2f(1,0);
    glEnd();



    glBegin(GL_QUADS);
    glVertex3f(-1,-2,0);  glTexCoord2f(0,0);
    glVertex3f(-17,-2,0);  glTexCoord2f(0,1);
    glVertex3f(-17,-2,6); glTexCoord2f(1,1);
    glVertex3f(-1,-2,6); glTexCoord2f(1,0);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3f(2,-2,0);  glTexCoord2f(0,0);
    glVertex3f(0,-2,0);  glTexCoord2f(0,1);
    glVertex3f(0,-2,25); glTexCoord2f(1,1);
    glVertex3f(2,-2,25); glTexCoord2f(1,0);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3f(2,-2,-1);  glTexCoord2f(0,0);
    glVertex3f(-17,-2,-1);  glTexCoord2f(0,1);
    glVertex3f(-17,-2,0); glTexCoord2f(1,1);
    glVertex3f(2,-2,0); glTexCoord2f(1,0);
    glEnd();


    glPopMatrix();
    glDisable(GL_TEXTURE_2D);





    ///pukur
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[6]);
    glPushMatrix();

    glBegin(GL_QUADS);
    glVertex3f(0,-2,11);  glTexCoord2f(0,0);
    glVertex3f(-6,-2,11);  glTexCoord2f(0,1);
    glVertex3f(-6,-2,13); glTexCoord2f(1,1);
    glVertex3f(0,-2,13); glTexCoord2f(1,0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);





}

























