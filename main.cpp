#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
#include "BmpLoader.h"
using namespace std;

///special key garir function
float chngEkpashArekpash = 1.6;     /// camera view ekpash theke arek pash e change hbe+ car tao sore jabe ulta pashe 180 degree 0.4 *2
float chngEkpash = 0.8;             ///  camera + car 90 degree change korbe. 0.4 karon look ar eye er distance 0.4
///normal key garir function
float samneSpeed = 1.1;
float pichoneSpeed = 1.1;
float samneBamDanS = 0.5;        ///bam or dan key press korle samne koto speed e jabe seita  0.02
float bamdanS = 0.5;              /// bam or dan key press korle bam or dan e koto speed e jabe seita 0.01





int i = 0;


double windowHeight=1920, windowWidth=1080;
bool rott=false;
float rotlimX = 0.0;
float rotlimY = 0.0;
float rotlimZ = 0.0;
float rotlim = 0.0;      ///garir rotation






bool chkx = false;
bool chky = false;

bool chkd = false;


bool backward = false;     //backward e jabe
bool forWard = false;       //forward e jabe
bool scenerotBam = false;
bool scenerotDan = false;









bool chX = false;
bool chY = false;


bool scenerotX = false;
bool scenerotY = false;
bool scenerotZ = false;

#define PI 3.141592654

//eye-12.5 -1.1 23.8
//look-12.5 -1.1 24.6

//GLfloat eyeX =-12.5;      ///eye  -0.5
//GLfloat eyeY = -1.1;     /// -1.1
//GLfloat eyeZ = 53.8;        ///-4.8
//
//GLfloat lookX = -12.5;      ///look at point -0.5
//GLfloat lookY = -1.1;      ///-1.1
//GLfloat lookZ = 54.6;      ///-4.0

////
GLfloat eyeX =-0.5;      ///eye  -0.5
GLfloat eyeY = -1.1;     /// -1.1
GLfloat eyeZ = -4.8;        ///-4.8

GLfloat lookX = -0.5;      ///look at point -0.5
GLfloat lookY = -1.1;      ///-1.1
GLfloat lookZ = -4.0;      ///-4.0

unsigned int IDe[100];


bool zas = true;
bool zap = false;
bool xas = false;   //false
bool xap = false;  //true




static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}


void cube(float var2,float var1)
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



    glBegin(GL_QUADS);
     /// FRONT
//    getNormal3p(-0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,0.5f, 0.5f, 0.5f);
    //glColor3f(fr,fg,fb);
    glTexCoord2f(0,var1);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0,0);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glTexCoord2f(var2,0);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glTexCoord2f(var2,var1);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // BACK
    getNormal3p(-0.5f, -0.5f, -0.5f,-0.5f, 0.5f, -0.5f,0.5f, 0.5f, -0.5f);
    //glColor3f(fr,fg,fb);
     glTexCoord2f(0,var1);    //a
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(0,0);   //b
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glTexCoord2f(var2,0);    //c
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glTexCoord2f(var2,var1);   //d
    glVertex3f(-0.5f, 0.5f, -0.5f);

    /// LEFT
    getNormal3p(-0.5f, -0.5f, 0.5f,-0.5f, 0.5f, 0.5f,-0.5f, 0.5f, -0.5f);
    //glColor3f(lr,lg,lb);
    glTexCoord2f(0,var1);//B
    glVertex3f(-0.5f, -0.5f, -0.5f);
     glTexCoord2f(0,0); // A
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(var2,0); // D
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(var2,var1); // C
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // RIGHT
    getNormal3p( 0.5f, -0.5f, -0.5f,0.5f, 0.5f, -0.5f,0.5f, 0.5f, 0.5f);
    //glColor3f(lr,lg,lb);
    glTexCoord2f(0,var1); //a
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glTexCoord2f(0,0); //B
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glTexCoord2f(var2,0);  //c
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glTexCoord2f(var2,var1); // D
    glVertex3f( 0.5f, 0.5f, -0.5f);

    /// TOP
    getNormal3p(-0.5f, 0.5f, 0.5f,0.5f, 0.5f, 0.5f,0.5f, 0.5f, -0.5f);
    //glColor3f(tr,tg,tb);


    glVertex3f(-0.5f, 0.5f, -0.5f); glTexCoord2f(0,var1);
    glVertex3f( 0.5f, 0.5f, -0.5f); glTexCoord2f(0,0);
    glVertex3f( 0.5f, 0.5f, 0.5f);  glTexCoord2f(var2,0);
    glVertex3f(-0.5f, 0.5f, 0.5f);  glTexCoord2f(var2,var1);
    // BOTTOM
    getNormal3p(-0.5f, -0.5f, 0.5f,-0.5f, -0.5f, -0.5f,0.5f, -0.5f, -0.5f);
    //glColor3f(tr,tg,tb);

     glVertex3f(-0.5f, -0.5f, -0.5f);  glTexCoord2f(0,var1);//a-b
    glVertex3f( 0.5f, -0.5f, -0.5f);  glTexCoord2f(0,0);//b-a
    glVertex3f( 0.5f, -0.5f, 0.5f);  glTexCoord2f(var2,0);//c-d
    glVertex3f(-0.5f, -0.5f, 0.5f);   glTexCoord2f(var2,var1); //d-c
    glEnd();
}




















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


void light()
{
    //GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 10.0, 50.0, 1.0 };

    glEnable( GL_LIGHT0);

    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);*/
}


//// test er jonno .....
void scene1()
{
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glRotatef(rotlimY,0,1,0);
    auditorium();
    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
}




void scene()
{

    glPushMatrix();

    basescene();

    glPopMatrix();

///garir code e hat dibo na robbar er age
    glPushMatrix();


    glTranslatef(lookX,lookY-0.2,lookZ );        ///lookX,lookY,lookZ        -0.5,-1.5,0.2
    //glTranslatef(-0.5,-1.5,0.2);
    glRotatef(rotlim,0,1,0);
    glScalef(0.04,0.05,0.05);
    ok();
    glPopMatrix();



    ///deyal

    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(7.5,-2,50.2);
    glRotatef(90,0,1,0);
    wall(31);
    glPopMatrix();



    ///gate
    glPushMatrix();
    glScalef(0.5,0.5,0.1);
    glTranslatef(-1,-1,6);
    kuetgate();
    glPopMatrix();
    ///gate er samner sthapona
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[7]);
    glPushMatrix();
    glScalef(0.5,0.25,8);
    glTranslatef(2,-7.5,-0.45);
    cube(6,6);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///gate er samner sthapona
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[7]);
    glPushMatrix();
    glScalef(1,0.25,8);
    glTranslatef(-2.47,-7.5,-0.45);
    cube(6,6);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///gate er checkpost
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(14,-2.8,107);
    checkpost1();         ///2 no mane dan e bam e repeat
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(2.5,-2.5,2.9);
    checkpost1();         ///2 no mane dan e bam e repeat
    glPopMatrix();

    ///khajar samner deyal
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-20,-3.5,37);
    tarkatawall(34);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glPushMatrix();

    glScalef(0.5,0.5,0.5);
    glTranslatef(-20.5,-3.5,47.5);
    glRotatef(90,0,1,0);
    tarkatawall(10);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-20,-3.5,48);
    tarkatawall(34);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glPushMatrix();
/// khaja hall er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glScalef(10,0.1,2);
    glTranslatef(-0.8,-20,12.5);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
///khajar rastar fuler deyal
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-10,-1.8,25);
    fulerwall(7);
    glPopMatrix();
//// ei code baki hall er jonno o use korbo
///khaja
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-1,-0.5,25.2);
    khaja();
    glPopMatrix();
///khajar pukur
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-4,-2.5,35);
    pukur();
    glPopMatrix();
///shahiud minar
    glPushMatrix();
    glTranslatef(-18,-1.5,25);
    glRotatef(-90,0,1,0);
    glScalef(0.5,0.5,0.5);
    shahidminar();
    glPopMatrix();

///lake
    glPushMatrix();
    //glScalef(1,1,1);
    glTranslatef(-26,-2.5,25);
    glScalef(1,1,0.5);
    pukur();
    glPopMatrix();

///rokeya hall
    glPushMatrix();
    glTranslatef(-37,-0.5,23.2);
    glScalef(1,1.5,2);
    glRotatef(90,0,1,0);
    khaja();
    glPopMatrix();

/// math er  footbal bar
    glPushMatrix();
    glTranslatef(-16,-1.8,35);
    glRotatef(-90,0,1,0);
   glScalef(0.5,0.5,0.5);
    footbalbar();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-26,-1.8,35);
    glRotatef(-90,0,1,0);
   glScalef(0.5,0.5,0.5);
    footbalbar();
    glPopMatrix();


///auditorium er pasher
    glPushMatrix();
    glTranslatef(-4,-1,45);
    glRotatef(90,0,1,0);
    glScalef(1.5,1.5,1.5);
    stha();
    glPopMatrix();
///auditorium
    glPushMatrix();
    glTranslatef(-20,-1,50);
    //glRotatef(90,0,1,0);
    glScalef(1,2,2);
    auditorium();
    glPopMatrix();

///auditorium er samner rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-32,-2.1,55);
    glScalef(40,0.1,1.2);
    cube(6,40);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
///civil building
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-31,0,49);
    bongoamar(1.1);
    glPopMatrix();
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-38,0,49);
    bongoamar(1.1);
    glPopMatrix();
///admin building
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-57,0,60);
    bongoamar(11.1);
    glPopMatrix();



/// pocket gate er  er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    ///glScalef(10,0.1,2);
    glTranslatef(-2,-2.1,52);
    glScalef(20,0.1,2);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    ///pocket er rastar fuler deyal
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-10,-2.1,52);
    fulerwall(20);
    glPopMatrix();

    ///rashid
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,-0.5,55);
    khaja();
    glPopMatrix();

    ///banga
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(4,0,60);
    bongoamar();
    glPopMatrix();
/// banga hall er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-3.8,-2,60);
    glScalef(16,0.1,2);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
///bqanger rastar fuler deyal
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-10,-2,60);
    fulerwall(12);
    glPopMatrix();

///fazlul
    glPushMatrix();
    glScalef(1,1,2);
    glTranslatef(-1,-0.5,33);
    khaja();
    glPopMatrix();

    ///amar
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(4,0,75);
    bongoamar();
    glPopMatrix();
/// amar hall er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-3.8,-2,75);
    glScalef(16,0.1,2);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
///amar rastar fuler deyal
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-10,-2,75);
    fulerwall(12);
    glPopMatrix();
///lalan
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(3,0,90);
    lalan();
    glPopMatrix();
    /// lalan hall er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-3.8,-2,90);
    glScalef(16,0.1,2);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///laln rastar fuler deyal
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(-10,-2,90);
    fulerwall(12);
    glPopMatrix();

///new academic building

    glPushMatrix();
    glScalef(2,1,2);
    glTranslatef(-11,0,40.5);
    newAcademicBuilding();
    glPopMatrix();

//archi
    glPushMatrix();
    //
    glTranslatef(-34,0,70.5);
    glScalef(2,1,2);
    miscb();
    glPopMatrix();
    glPushMatrix();
    //
    glPushMatrix();
    glTranslatef(-36,0,101.5);
    glScalef(1,1,1);
    miscb();
    glPopMatrix();





///kmc
    ///auditorium
    glPushMatrix();
    glTranslatef(-20,-1,106);
    //glRotatef(90,0,1,0);
    auditorium();
    glPopMatrix();
    ///kmc er pasher
    ///auditorium
    glPushMatrix();
    glTranslatef(-28,-1,106);
    //glRotatef(90,0,1,0);
    auditorium();
    glPopMatrix();




    ///l;ogo
    glPushMatrix();
    glScalef(0.1,0.1,0.1);
    glTranslatef(10,-7,140);
    glRotatef(45,0,1,0);
    kuetlogo();
    glPopMatrix();



///rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glScalef(4,0.1,16);
    glTranslatef(-0.2,-21,0.2);
    cube(20,6);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glScalef(16,0.1,4);
    glTranslatef(-0.424,-21,3);
    cube(6,20);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    ///sobche lomba rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-12.8,-2.1,57);
    glScalef(4,0.1,90);
    cube(120,12);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///ager rastar mirr0r
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-50,-2.1,57);
    glScalef(4,0.1,90);
    cube(120,12);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    ///circuit er base oblong er rasta
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-32,-2.1,100);
    glScalef(40,0.1,4);
    cube(6,40);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //miorror
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,IDe[4]);
    glPushMatrix();
    glTranslatef(-32,-2.1,12);
    glScalef(40,0.1,4);
    cube(6,40);         ///2 no mane dan e bam e repeat
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    ///rasta sesh


}








void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glOrtho(0.0,2,0.0,2,0.0,1.0);
    //glFrustum(-6,6,-6,6, 1, 30);
    glFrustum(-0.1,0.1,-0.1,0.1, 0.1,500);          ///-0.5625,0.5625,-0.5,0.5, 0.1,80        -1,1,-1,1,2,80
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);

    glViewport(0, 0, windowHeight, windowWidth);


    glPushMatrix();

    //glRotatef(rotlimX,1,0,0);
    // glRotatef(rotlimY,0,1,0);
    // glRotatef(rotlimZ,0,0,1);


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
    case 'w':                         ///samne jabe
        forWard = !forWard;
        break;
    case 'd':                         ///dan e jabe
        scenerotDan = !scenerotDan;
        break;
    case 'a':                     ///bam e jabe
        scenerotBam = !scenerotBam;
        break;
    case 's':
        backward =! backward;
        break;















    case 'c':
        chX = !chX;
        break;
    case 'u':
        chY = !chY;
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

void SpecialInput(int key, int x, int y)        ///don't touch z
{
    switch(key)
    {
    case GLUT_KEY_UP:

        rotlim = 0;

        if(zap)
        {
            eyeZ = eyeZ - chngEkpashArekpash;
        }
        else if(xap)
        {
            eyeZ = eyeZ - chngEkpash;
            eyeX = eyeX - chngEkpash;
        }
        else if(xas)
        {
            eyeZ = eyeZ - chngEkpash;
            eyeX = eyeX + chngEkpash;
        }

        zas = true;
        zap = false;
        xas = false;   //false
        xap = false;
        break;

    case GLUT_KEY_DOWN:



        rotlim = 180;
        if(zas)
        {
            eyeZ = eyeZ + chngEkpashArekpash;
        }
        else if(xap)
        {
            eyeZ = eyeZ +chngEkpash;
            eyeX = eyeX - chngEkpash;
        }
        else if(xas)
        {
            eyeZ = eyeZ + chngEkpash;
            eyeX = eyeX + chngEkpash;
        }

        zas = false;
        zap = true;
        xas = false;   //false
        xap = false;
        break;
    case GLUT_KEY_LEFT:



        rotlim = 90;

        if(xap)
        {
            eyeX = eyeX - chngEkpashArekpash;
        }
        else if(zas)
        {
            eyeZ = eyeZ + chngEkpash;
            eyeX = eyeX - chngEkpash;
        }
        else if(zap)
        {
            eyeZ = eyeZ - chngEkpash;
            eyeX = eyeX - chngEkpash;
        }

        zas = false;
        zap = false;
        xas = true;   //false
        xap = false;
        break;
    case GLUT_KEY_RIGHT:




        rotlim = 270;
        if(zas)
        {
            eyeZ = eyeZ + chngEkpash;
            eyeX = eyeX + chngEkpash;
        }
        else if(zap)
        {
            eyeZ = eyeZ - chngEkpash;
            eyeX = eyeX + chngEkpash;
        }
        else if(xas)
        {
            eyeX = eyeX + chngEkpashArekpash;
        }

        zas = false;
        zap = false;
        xas = false;   //false
        xap = true;
        break;

    glutPostRedisplay();
    }

}
















void animate()
{

    if (forWard)                      /// samne jabe
    {
        if(zas)
        {

            eyeZ = eyeZ + samneSpeed;
            lookZ = lookZ + samneSpeed;
        }
        else if(zap)
        {

            eyeZ = eyeZ - samneSpeed;
            lookZ = lookZ - samneSpeed;


        }
        else if(xas)
        {

            eyeX = eyeX + samneSpeed;
            lookX = lookX + samneSpeed;

        }
        else if(xap)
        {

            eyeX = eyeX - samneSpeed;
            lookX = lookX - samneSpeed;

        }
//        GLfloat currenttime = glutGet(GLUT_ELAPSED_TIME) / 1000;
//        cout<<currenttime<<"       current"<<endl;

        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;

        forWard = false;
    }
    if( backward)
    {
        if(zas)
        {

            eyeZ = eyeZ - pichoneSpeed;
            lookZ = lookZ - pichoneSpeed;

            //rotlimBam = 0.0;
            // rotlimDan = 0.0;
            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            // cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(zap)
        {

            eyeZ = eyeZ + pichoneSpeed;
            lookZ = lookZ + pichoneSpeed;


            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            //cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(xas)
        {

            eyeX = eyeX - pichoneSpeed;
            lookX = lookX - pichoneSpeed;

            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            //cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(xap)
        {

            eyeX = eyeX + pichoneSpeed;
            lookX = lookX + pichoneSpeed;
        }


        backward = false;
    }

    if (scenerotBam)
    {
        if(zas)
        {
            eyeZ = eyeZ + samneBamDanS;
            lookZ = lookZ + samneBamDanS;
            eyeX = eyeX + bamdanS;
            lookX = lookX + bamdanS;

        }
        else if(zap)
        {
            eyeZ = eyeZ - samneBamDanS;
            lookZ = lookZ - samneBamDanS;
            eyeX = eyeX - bamdanS;
            lookX = lookX - bamdanS;
        }
        else if(xas)
        {

           eyeZ = eyeZ - bamdanS;
            lookZ = lookZ - bamdanS;
            eyeX = eyeX + samneBamDanS;
            lookX = lookX + samneBamDanS;
        }
        else if(xap)
        {

            eyeZ = eyeZ + bamdanS;
            lookZ = lookZ + bamdanS;
            eyeX = eyeX - samneBamDanS;
            lookX = lookX - samneBamDanS;
        }




        scenerotBam = false;



    }


    if (scenerotDan)
    {

        if(zas)
        {
            eyeZ = eyeZ + samneBamDanS;
            lookZ = lookZ + samneBamDanS;
            eyeX = eyeX - bamdanS ;
            lookX = lookX - bamdanS;

        }
        else if(zap)
        {
            eyeZ = eyeZ - samneBamDanS;
            lookZ = lookZ - samneBamDanS;
            eyeX = eyeX + bamdanS;
            lookX = lookX + bamdanS;
        }
        /*
        */
        else if(xas)
        {

           eyeZ = eyeZ + bamdanS;
            lookZ = lookZ + bamdanS;
            eyeX = eyeX + samneBamDanS;
            lookX = lookX + samneBamDanS;
        }

        else if(xap)
        {
            eyeZ = eyeZ - bamdanS;
            lookZ = lookZ - bamdanS;
            eyeX = eyeX - samneBamDanS;
            lookX = lookX - samneBamDanS;
        }

        scenerotDan = false;


    }









    if (chkx)
    {
        eyeX = eyeX + samneSpeed;
        lookX = lookX + samneSpeed;
        chkx = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }
    if (chky)
    {
        eyeY = eyeY + samneSpeed;
        lookY = lookY + samneSpeed;
        chky = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }






    if (chX)
    {
        eyeX = eyeX - samneSpeed;
        lookX = lookX - samneSpeed;
        chX = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }
    if (chY)
    {
        eyeY = eyeY - samneSpeed;
        lookY = lookY - samneSpeed;
        chY = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }


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



    glutPostRedisplay();
}






void LoadTexture(const char*filename, int nnn)
{
    glGenTextures(1, &IDe[nnn]);
    glBindTexture(GL_TEXTURE_2D, IDe[nnn]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, IDe[nnn]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}




int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("1607076-ClassRoom");


    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\carclr.bmp", 0);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\creambuiding.bmp", 1);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\building.bmp", 2);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\license.bmp", 3);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\road.bmp", 4);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\grass.bmp", 5);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\water.bmp", 6);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\redbrick.bmp", 7);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\whitebuild.bmp", 8);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\whitebrick.bmp", 9);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\columnbuild.bmp", 10);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\audibuild.bmp", 11);


    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);

    glutIdleFunc(animate);
    glClearColor(0,0,0,1);
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    //glDisable(GL_COLOR_MATERIAL);


    light();

    glutMainLoop();

    return 0;
}
