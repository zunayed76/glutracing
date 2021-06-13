
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;


#define PI 3.141592654

int anglex= 0, angley = 0, anglez = 0;          //rotation angles
//int window;
int wired=0;
int shcpt=1;
int animat = 0;
const int L=20;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;				//number of slices along x-direction
const int ntheta = 20;


GLfloat ctrlpoints[L+1][3] =
{
    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
    { 0.1, 1.7, 0.0},{ 0.5, 1.5, 0.0},
    {1.0, 1.5, 0.0}
//    ,
//    {1.4, 1.4, 0.0},
//    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
//    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
//    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
//    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
//    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
//    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
//    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
//    {6.8, 0.52, 0.0}
};

//control points
long long nCr(int n, int r)
{
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);

    //return y;
}

///////////////////////
void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
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

    glNormal3f(-Nx,-Ny,-Nz);
}

void tireBezier()
{
    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);       ///eikhan dia kaj shuru
    x = xy[0];
    r = xy[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= ntheta; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i

}











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
    glBindTexture(GL_TEXTURE_2D,IDe[0]);
    glPushMatrix();        /// chaka
    //glRotatef(90,0,1,0);
    glTranslatef(-2,-4,5);    /// z okkho = x okkho
    glScalef(1,1.2,1.2);
    tireBezier();
    glPopMatrix();
    glPushMatrix();        /// chaka2
    //glRotatef(90,0,1,0);
    glTranslatef(2,-4,5);    /// z okkho = x okkho
    glScalef(1,1.2,1.2);
    glRotatef(180,0,1,0);
    tireBezier();
    glPopMatrix();


    glPushMatrix();        /// chaka
    //glRotatef(90,0,1,0);
    glTranslatef(-2,-4,0);    /// z okkho = x okkho
    glScalef(1,1.2,1.2);
    tireBezier();
    glPopMatrix();
    glPushMatrix();        /// chaka2
    //glRotatef(90,0,1,0);
    glTranslatef(2,-4,0);    /// z okkho = x okkho
    glScalef(1,1.2,1.2);
    glRotatef(180,0,1,0);
    tireBezier();
    glPopMatrix();
//
//    glPushMatrix();   ///chaka2
//    glRotatef(90,0,1,0);
//    glTranslatef(-5,-4,1.75);    /// z okkho = x okkho
//    glutSolidTorus(0.4,1,30,30);
//    glPopMatrix();
//
//    glPushMatrix();   ///chaka3
//    glRotatef(90,0,1,0);
//    glTranslatef(0.6,-4,-1.65);    /// z okkho = x okkho
//    glutSolidTorus(0.4,1,30,30);
//    glPopMatrix();
//    glPushMatrix();   ///chaka4
//    glRotatef(90,0,1,0);
//    glTranslatef(0.6,-4,1.65);    /// z okkho = x okkho
//    glutSolidTorus(0.4,1,30,30);
//    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    ///license plate
//
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,IDe[3]);
//    glPushMatrix();
//    glBegin(GL_QUADS);      ///pichoner  janla
//    glVertex3f(1,-2.5,-2.1);  glTexCoord2f(0,0);
//    glVertex3f(1,-3.5,-2.1);  glTexCoord2f(1,0);
//    glVertex3f(-1,-3.5,-2.1); glTexCoord2f(1,1);
//    glVertex3f(-1,-2.5,-2.1); glTexCoord2f(0,1);
//    glEnd();
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);






}



