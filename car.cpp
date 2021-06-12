
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

void ok()
{
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    ///uprer aboron
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[1]);
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);    /// quad er 4 ta point
   // glColor3f(1,1,1);
    glVertex3f(2,0,-2);
    glVertex3f(-2,0,-2);
    glVertex3f(2,0,4);
    glVertex3f(-2,0,4);

    glVertex3f(2,-0.5,4.5);
    glVertex3f(-2,-0.5,4.5);
    glEnd();
    //glPopMatrix();

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
    glBegin(GL_QUAD_STRIP);         ///body
    //glColor3f(1,0,1);
    glVertex3f(-2,-4,7.5);
    glVertex3f(-2,-2,7.5);
    glVertex3f(-2,-4,-2);
    glVertex3f(-2,-2,-2);
    glVertex3f(2,-4,-2);
    glVertex3f(2,-2,-2);
    glVertex3f(2,-4,7.5);
    glVertex3f(2,-2,7.5);
    glEnd();
    glBegin(GL_QUAD_STRIP);    /// jANAR ABORON SAMNE PASHE UPRE
    glVertex3f(-2,-0.25,4);
    glVertex3f(-2,0,4);
    glVertex3f(2,-0.25,4);
    glVertex3f(2,0,4);
    glVertex3f(2,-0.25,-2);
    glVertex3f(2,0,-2);
    glEnd();
    glBegin(GL_QUADS);     ///same part
    glVertex3f(-2,0,-2);
    glVertex3f(-2,-0.25,-2);
    glVertex3f(-2,-0.25,4);
    glVertex3f(-2,0,4);
    glEnd();
    glBegin(GL_QUADS);      ///samner dandi dan pash JANALAR ABORON
    //glColor3f(1,0,1);
    glVertex3f(-2,0,4);
    glVertex3f(-2,-0.25,4);
    glVertex3f(-2,-2,5.75);
    glVertex3f(-2,-2,6);
    glEnd();
    glBegin(GL_QUADS);      ///samner dandi bam pash JANALAR ABORON
    //glColor3f(1,0,1);
    glVertex3f(2,0,4);
    glVertex3f(2,-0.25,4);
    glVertex3f(2,-2,5.75);
    glVertex3f(2,-2,6);
    glEnd();
    glBegin(GL_QUADS);      ///majher dandi bam pash
    //glColor3f(1,0,1);
    glVertex3f(2,-0.25,1);
    glVertex3f(2,-2,1);
    glVertex3f(2,-2,2);
    glVertex3f(2,-0.25,2);
    glEnd();
    glBegin(GL_QUADS);      ///majher dandi dan pash
    glVertex3f(-2,-0.25,1);
    glVertex3f(-2,-2,1);
    glVertex3f(-2,-2,2);
    glVertex3f(-2,-0.25,2);
    glEnd();
    glBegin(GL_QUADS);         ///janalar aboron piche upre

    glVertex3f(1.75,0,-2);
    glVertex3f(1.75,-0.25,-2);
    glVertex3f(-1.75,-0.25,-2);
    glVertex3f(-1.75,0,-2);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

 ///prothom texture sesh









  //  glPopMatrix();
//    glDisable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);      ///windshield
    glVertex3f(1.75,-2,6);
    glVertex3f(1.75,-0.5,4.5);
    glVertex3f(-1.75,-0.5,4.5);
    glVertex3f(-1.75,-2,6);
    glEnd();
    glBegin(GL_QUADS);      ///dan pash samner janla
    glVertex3f(-2,-0.25,4);
    glVertex3f(-2,-2,5.75);
    glVertex3f(-2,-2,2);
    glVertex3f(-2,-0.25,2);
    glEnd();
    glBegin(GL_QUADS);      ///bam pash samner janla
    glVertex3f(2,-0.25,4);
    glVertex3f(2,-2,5.75);
    glVertex3f(2,-2,2);
    glVertex3f(2,-0.25,2);
    glEnd();
    glBegin(GL_QUADS);      ///dan pash pichoner janla
    glVertex3f(-2,-0.25,-2);
    glVertex3f(-2,-2,-2);
    glVertex3f(-2,-2,1);
    glVertex3f(-2,-0.25,1);
    glEnd();
    glBegin(GL_QUADS);      ///bam pash pichoner janla
    glVertex3f(2,-0.25,-2);
    glVertex3f(2,-2,-2);
    glVertex3f(2,-2,1);
    glVertex3f(2,-0.25,1);
    glEnd();
    glBegin(GL_QUADS);      ///pichoner  janla
    glVertex3f(1.75,0,-2);
    glVertex3f(1.75,-2,-2);
    glVertex3f(-1.75,-2,-2);
    glVertex3f(-1.75,0,-2);
    glEnd();











    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[2]);
    glPushMatrix();        /// chaka
    glRotatef(90,0,1,0);
    glTranslatef(-5,-4,-1.75);    /// z okkho = x okkho
    glutSolidTorus(0.4,1,30,30);
    glPopMatrix();


    glPushMatrix();   ///chaka2
    glRotatef(90,0,1,0);
    glTranslatef(-5,-4,1.75);    /// z okkho = x okkho
    glutSolidTorus(0.4,1,30,30);
    glPopMatrix();

    glPushMatrix();   ///chaka3
    glRotatef(90,0,1,0);
    glTranslatef(0.6,-4,-1.65);    /// z okkho = x okkho
    glutSolidTorus(0.4,1,30,30);
    glPopMatrix();
    glPushMatrix();   ///chaka4
    glRotatef(90,0,1,0);
    glTranslatef(0.6,-4,1.65);    /// z okkho = x okkho
    glutSolidTorus(0.4,1,30,30);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    ///license plate

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[3]);
    glPushMatrix();
    glBegin(GL_QUADS);      ///pichoner  janla
    glVertex3f(1,-2.5,-2.1);  glTexCoord2f(0,0);
    glVertex3f(1,-3.5,-2.1);  glTexCoord2f(1,0);
    glVertex3f(-1,-3.5,-2.1); glTexCoord2f(1,1);
    glVertex3f(-1,-2.5,-2.1); glTexCoord2f(0,1);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);






}



