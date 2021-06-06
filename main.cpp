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


double windowHeight=1920, windowWidth=1080;
bool rott=false;
float rotlimX = 0.0;
float rotlim = 0.0;      ///garir rotation




float rotlimZ = 0.0;
bool chkx = false;
bool chky = false;
bool chkz = false;
bool chkd = false;


bool backward = false;     //backward e jabe
bool forWard = false;       //forward e jabe
bool scenerotBam = false;
bool scenerotDan = false;









bool chX = false;
bool chY = false;
bool chZ = false;

bool scenerotX = false;

bool scenerotZ = false;

#define PI 3.141592654

GLfloat eyeX = -0.5;      ///eye  4.5
GLfloat eyeY = -1.1;     /// 1.9
GLfloat eyeZ = -0.2;        ///-6

GLfloat lookX = -0.5;      ///look at point
GLfloat lookY = -1.1;
GLfloat lookZ = 0.2;

unsigned int IDe[100];


bool zas = true;
bool zap = false;
bool xas = false;   //false
bool xap = false;  //true



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



void scene()
{
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,IDe[2]);





    glPushMatrix();

    basescene();

    glPopMatrix();


    glPushMatrix();


    glTranslatef(lookX,lookY-0.4,lookZ );        ///lookX,lookY,lookZ        -0.5,-1.5,0.2
    //glTranslatef(-0.5,-1.5,0.2);
    glRotatef(rotlim,0,1,0);
    glScalef(0.08,0.1,0.06);
    ok();


    glPopMatrix();



    glPushMatrix();


    glScalef(0.5,0.5,0.1);
    glTranslatef(-1,-1,4);
    kuetgate();
    glPopMatrix();

    glPushMatrix();


    glScalef(0.05,0.05,0.015);
    glTranslatef(35,-35,100);
    glRotatef(45,0,1,0);
    kuetlogo();
    glPopMatrix();





    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-1,0,10);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-1,0,18);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-1,0,22);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-1,0,26);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-1,0,30);
    building();
    glPopMatrix();




    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-9,0,18);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-9,0,20);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-9,0,22);
    building();
    glPopMatrix();
    glPushMatrix();
    glScalef(1.5,5,0.75);
    glTranslatef(-9,0,24);
    building();
    glPopMatrix();




    //glDisable(GL_TEXTURE_2D);
}









void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glOrtho(0.0,2,0.0,2,0.0,1.0);
    //glFrustum(-6,6,-6,6, 1, 30);
    glFrustum(-0.5625,0.5625,-0.5,0.5, 0.1,20);
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
    case 'v':
        chZ = !chZ;
        break;
    case 'e':
        scenerotX = !scenerotX;
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
            eyeZ = eyeZ - 0.8;
        }
        else if(xap)
        {
            eyeZ = eyeZ - 0.4;
            eyeX = eyeX - 0.4;
        }
        else if(xas)
        {
            eyeZ = eyeZ - 0.4;
            eyeX = eyeX + 0.4;
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
            eyeZ = eyeZ + 0.8;
        }
        else if(xap)
        {
            eyeZ = eyeZ + 0.4;
            eyeX = eyeX - 0.4;
        }
        else if(xas)
        {
            eyeZ = eyeZ + 0.4;
            eyeX = eyeX + 0.4;
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
            eyeX = eyeX - 0.8;
        }
        else if(zas)
        {
            eyeZ = eyeZ + 0.4;
            eyeX = eyeX - 0.4;
        }
        else if(zap)
        {
            eyeZ = eyeZ - 0.4;
            eyeX = eyeX - 0.4;
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
            eyeZ = eyeZ + 0.4;
            eyeX = eyeX + 0.4;
        }
        else if(zap)
        {
            eyeZ = eyeZ - 0.4;
            eyeX = eyeX + 0.4;
        }
        else if(xas)
        {
            eyeX = eyeX + 0.8;
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

            eyeZ = eyeZ + 0.1;
            lookZ = lookZ + 0.1;
            chkz = false;
        }
        else if(zap)
        {

            eyeZ = eyeZ - 0.1;
            lookZ = lookZ - 0.1;
            chkz = false;

        }
        else if(xas)
        {

            eyeX = eyeX + 0.1;
            lookX = lookX + 0.1;
            chkz = false;
        }
        else if(xap)
        {

            eyeX = eyeX - 0.1;
            lookX = lookX - 0.1;
            chkz = false;
        }

        forWard = false;
    }
    if( backward)
    {
        if(zas)
        {

            eyeZ = eyeZ - 0.1;
            lookZ = lookZ - 0.1;
            chkz = false;
            //rotlimBam = 0.0;
            // rotlimDan = 0.0;
            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            // cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(zap)
        {

            eyeZ = eyeZ + 0.1;
            lookZ = lookZ + 0.1;
            chkz = false;

            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            //cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(xas)
        {

            eyeX = eyeX - 0.1;
            lookX = lookX - 0.1;
            chkz = false;

            // cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
            //cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;;
        }
        else if(xap)
        {

            eyeX = eyeX + 0.1;
            lookX = lookX + 0.1;
            chkz = false;
        }


        backward = false;
    }


    if (scenerotX)
    {
        rotlimX+= 0.5;

        if(rotlimX > 360)
            rotlimX = 0.0;

    }
    if (scenerotBam)
    {
        if(zas)
        {
            eyeZ = eyeZ + 0.02;
            lookZ = lookZ + 0.02;
            eyeX = eyeX + 0.01;
            lookX = lookX + 0.01;

        }
        else if(zap)
        {
            eyeZ = eyeZ - 0.02;
            lookZ = lookZ - 0.02;
            eyeX = eyeX - 0.01;
            lookX = lookX - 0.01;
        }
        else if(xas)
        {

           eyeZ = eyeZ - 0.01;
            lookZ = lookZ - 0.01;
            eyeX = eyeX + 0.02;
            lookX = lookX + 0.02;
        }
        else if(xap)
        {

            eyeZ = eyeZ + 0.01;
            lookZ = lookZ + 0.01;
            eyeX = eyeX - 0.02;
            lookX = lookX - 0.02;
        }





        //lookX = lookX + 0.02;
        //eyeZ = eyeZ + 0.015;
        //lookZ = lookZ + 0.015;
        cout<<"rotlimitdbam"<<rotlim<<endl;
        scenerotBam = false;



    }


    if (scenerotDan)
    {

        if(zas)
        {
            eyeZ = eyeZ + 0.01;
            lookZ = lookZ + 0.01;
            eyeX = eyeX - 0.015;
            lookX = lookX - 0.015;

        }
        else if(zap)
        {
            eyeZ = eyeZ - 0.02;
            lookZ = lookZ - 0.02;
            eyeX = eyeX + 0.01;
            lookX = lookX + 0.01;
        }
        /*
        */
        else if(xas)
        {

           eyeZ = eyeZ + 0.01;
            lookZ = lookZ + 0.01;
            eyeX = eyeX + 0.02;
            lookX = lookX + 0.02;
        }

        else if(xap)
        {
            eyeZ = eyeZ - 0.01;
            lookZ = lookZ - 0.01;
            eyeX = eyeX - 0.02;
            lookX = lookX - 0.02;
        }

        //eyeZ = eyeZ + 0.015;
        cout<<"rotlimitdan"<<rotlim<<endl;
        // lookZ = lookZ - 0.02;
        scenerotDan = false;


    }









    if (chkx)
    {
        eyeX = eyeX + 0.1;
        lookX = lookX + 0.1;
        chkx = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }
    if (chky)
    {
        eyeY = eyeY + 0.1;
        lookY = lookY + 0.1;
        chky = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }






    if (chX)
    {
        eyeX = eyeX - 0.1;
        lookX = lookX - 0.1;
        chX = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }
    if (chY)
    {
        eyeY = eyeY - 0.1;
        lookY = lookY - 0.1;
        chY = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
    }
    if (chZ)
    {
        eyeZ = eyeZ - 0.1;
        lookZ = lookZ - 0.1;
        chZ = false;
        cout<<"eye"<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<"look"<<lookX<<" "<<lookY<<" "<<lookZ<<endl<<endl;
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
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\redcar.bmp", 1);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\building.bmp", 2);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\license.bmp", 3);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\roaad.bmp", 4);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\grass.bmp", 5);
    LoadTexture("C:\\Users\\zunayed76\\Desktop\\glutracing\\texture\\water.bmp", 6);



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
