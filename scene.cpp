
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;








void auditorium()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[11]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(4,2,4);
    cube(1,2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[8]);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(4.2,0.1,4.2);
    cube(1,2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}



void newAcademicBuilding()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[1]);
    glPushMatrix();
    glTranslatef(0,0,4);
    glScalef(4,4,3);
    cube(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(4,4,3);
    cube(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-4);
    glScalef(4,4,3);
    cube(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-8);
    glScalef(4,4,3);
    cube(1,2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-2);
    glScalef(1,1,12);
    cube(1,2);
    glPopMatrix();



    glDisable(GL_TEXTURE_2D);
}


void miscb()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[1]);
    glPushMatrix();
    glTranslatef(0,0,4);
    glScalef(3,6,4);
    cube(1,2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}





void footbalbar()
{
     glPushMatrix();
    glTranslatef(1,1.5,1);
    glScalef(0.1,3,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,1.5,1);
    glScalef(0.1,3,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,3,1);
    glScalef(2,0.1,0.1);
    cube(2,4);
    glPopMatrix();
}

void bongoamar(int iii,int yyy)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[iii]);
    glPushMatrix();
    glTranslatef(0,0,4);
    glScalef(4,4,1);
    cube(2,yyy);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-4);
    glScalef(4,4,1);
    cube(2,yyy);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2,0,0);
    glScalef(1,4,8);
    cube(2,yyy);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    glScalef(1,4,8);
    cube(2,yyy);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
void lalan()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[2]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,4,8);
    cube(2,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}





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
    glTranslatef(-1.5,2.3,0);
    glRotatef(40,0,0,1);
    glScalef(1,5,1);
    cube();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2,-1.8,0);
    glRotatef(-30,0,0,1);
    glScalef(1,6,1);
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

    ///base
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[5]);
    glPushMatrix();
    glScalef(40,10,8);
    glTranslatef(-0.2,-1.15,0);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


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



    /// ghas


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[5]);
    glPushMatrix();




    glBegin(GL_QUADS);



    glVertex3f(-60,-2.1,-5);  glTexCoord2f(0,125);
    glVertex3f(10,-2.1,-5);  glTexCoord2f(0,0);
    glVertex3f(10,-2.1,125); glTexCoord2f(70,0);
    glVertex3f(-60,-2.1,125); glTexCoord2f(70,125);

    glEnd();


    glPopMatrix();
    glDisable(GL_TEXTURE_2D);









}

void checkpost1()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[8]);
    glPushMatrix();
    glScalef(2,2,2);
    //glTranslatef(2,-7.5,-0.45);
    cube();         ///2 no mane dan e bam e repeat
    glPopMatrix();

    glPushMatrix();
    glScalef(2.2,0.2,2.2);
    glTranslatef(0,4.5,0);
    cube();         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void tarkatawall(int son)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[8]);
    for(int i =0;i<=son;i++){
    glPushMatrix();
    glTranslatef(i,0,0);
    glScalef(1,1,0.1);
    cube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(i+0,0.75,0);
    glScalef(0.05,0.75,0.05);
    cube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(i+0.45,0.75,0);
    glScalef(0.05,0.75,0.05);
    cube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(i-0.45,0.75,0);
    glScalef(0.05,0.75,0.05);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(i+0,0.7,0);
    glScalef(1,0.05,0.05);
    cube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(i+0,0.9,0);
    glScalef(1,0.05,0.05);
    cube();
    glPopMatrix();
    }


    glDisable(GL_TEXTURE_2D);
}
void fulerwall(int son)
{
    for(int i = 0;i<son;i++) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[7]);
    glPushMatrix();
    glTranslatef(i+0,0,0);
    glScalef(1,0.25,0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[5]);
    glPushMatrix();
    glTranslatef(i+0,0.1,0);
    glScalef(0.9,0.20,0.40);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    }

}

void wall(int son)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[9]);
    for(int i =0;i<=son;i++){
    glPushMatrix();
    glTranslatef(i,0,0);
    glScalef(1,1.5,0.05);
    cube();
    glPopMatrix();

    }


    glDisable(GL_TEXTURE_2D);
}

void pukur()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[6]);

    glPushMatrix();
    //glTranslatef(0,0,0);
    glScalef(10,1,10);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[8]);

    glPushMatrix();
    //glTranslatef(0,0,0);
    glScalef(10.25,1.1,0.5);
    glTranslatef(0,0,-10);
    cube();
    glPopMatrix();
    glPushMatrix();
    //glTranslatef(0,0,0);
    glScalef(10.5,1.1,0.5);
    glTranslatef(0,0,10);
    cube();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5,1.1,10.5);
    glTranslatef(-10,0,0);
    cube();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.5,1.1,10.5);
    glTranslatef(10,0,0);
    cube(10,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void khaja()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[2]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1,3,2);
    cube(2,3);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D,IDe[8]);
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glScalef(1.1,0.1,2.1);
    cube(2,3);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[2]);
    glPushMatrix();
    glTranslatef(-1,0,2);
    glScalef(1,3,2);
    cube(2,3);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D,IDe[8]);
    glPushMatrix();
    glTranslatef(-1,1.5,2);
    glScalef(1.1,0.1,2.1);
    cube(2,3);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}







void stha()
{
    glPushMatrix();
    glTranslatef(-0.5,0.8,0);
    glScalef(4.2,0.1,2.2);
    cube();
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[10]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(3,1.5,2);
    cube(1,4);
    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[7]);
    glPushMatrix();
    glTranslatef(-2,0,0);
    glScalef(1,1.5,2);
    cube(4,4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



}





void minar_circle(float h,float w,float l)
{
    glPushMatrix();
    for(float i=0; i<=360; i+=1)
    {
        glPushMatrix();
        glRotatef(i,0,0,1);
        glScalef(h,l,w);
        cube();
        glPopMatrix();
    }
    glPopMatrix();
}
void shahidminar()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[7]);
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(4,0.5,2);
    cube(2,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-1,-2);
    glScalef(6,1.5,4);
    cube(6,6);
    glPopMatrix();



    glDisable(GL_TEXTURE_2D);



    glPushMatrix();
    glTranslatef(0.25,1.5,1);
    glScalef(0.1,3,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.25,1.5,1);
    glScalef(0.1,3,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,3,1);
    glScalef(0.5,0.1,0.1);
    cube(2,4);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-1,1.25,1);
    glScalef(0.1,2.5,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.25,1.25,1);
    glScalef(0.1,2.5,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.125,2.5,1);
    glScalef(0.25,0.1,0.1);
    cube(2,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,1.25,1);
    glScalef(0.1,2.5,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25,1.25,1);
    glScalef(0.1,2.5,0.1);
    cube(2,4);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.125,2.5,1);
    glScalef(0.25,0.1,0.1);
    cube(2,4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2,1.2);
    glScalef(1,1,1);
    minar_circle(1,0.1,1);
    glPopMatrix();






}


void building()
{


    glColor3f(1,1,1);
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

   // glTexCoord2f(1,1);
   //glTexCoord2f(1,0);
   // glTexCoord2f(0,0);
    //glTexCoord2f(0,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[2]);
    glPushMatrix();

    glBegin(GL_QUADS);
    /// FRONT
    //glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, 0.5f); glTexCoord2f(1,1);
    glVertex3f( 0.5f, -0.5f, 0.5f); glTexCoord2f(1,0);
    glVertex3f( 0.5f, 0.5f, 0.5f);  glTexCoord2f(0,0);
    glVertex3f(-0.5f, 0.5f, 0.5f);  glTexCoord2f(0,1);

    // BACK
   // glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, -0.5f); glTexCoord2f(1,1);
    glVertex3f(-0.5f, 0.5f, -0.5f); glTexCoord2f(1,0);
    glVertex3f( 0.5f, 0.5f, -0.5f); glTexCoord2f(0,0);
    glVertex3f( 0.5f, -0.5f, -0.5f); glTexCoord2f(0,1);

    /// LEFT
    //glColor3f(lr,lg,lb);
    glVertex3f(-0.5f, -0.5f, 0.5f);        glTexCoord2f(1,1);
    glVertex3f(-0.5f, 0.5f, 0.5f); glTexCoord2f(1,0);
    glVertex3f(-0.5f, 0.5f, -0.5f); glTexCoord2f(0,0);
    glVertex3f(-0.5f, -0.5f, -0.5f);glTexCoord2f(0,1);

    // RIGHT
    //glColor3f(lr,lg,lb);
    glVertex3f( 0.5f, -0.5f, -0.5f);  glTexCoord2f(1,1);
    glVertex3f( 0.5f, 0.5f, -0.5f);   glTexCoord2f(1,0);
    glVertex3f( 0.5f, 0.5f, 0.5f);glTexCoord2f(0,0);
    glVertex3f( 0.5f, -0.5f, 0.5f); glTexCoord2f(0 ,1);

    /// TOP
    //glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // BOTTOM
    //glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}


///building pop korle use korbo
//glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-1,0,10);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-1,0,18);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-1,0,22);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-1,0,26);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-1,0,30);
//    building();
//    glPopMatrix();
//
//
//
//
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-9,0,18);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-9,0,20);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-9,0,22);
//    building();
//    glPopMatrix();
//    glPushMatrix();
//    glScalef(1.5,5,0.75);
//    glTranslatef(-9,0,24);
//    building();
//    glPopMatrix();

















