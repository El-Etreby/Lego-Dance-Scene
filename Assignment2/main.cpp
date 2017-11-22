#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "joker.hpp"
#include "batman.hpp"
#include "creeper.hpp"
#include "superman.hpp"
#include "steve.hpp"

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

int side = 1;


class Vector3f {
public:
    float x, y, z;
    
    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
        x = _x;
        y = _y;
        z = _z;
    }
    
    Vector3f operator+(Vector3f &v) {
        return Vector3f(x + v.x, y + v.y, z + v.z);
    }
    
    Vector3f operator-(Vector3f &v) {
        return Vector3f(x - v.x, y - v.y, z - v.z);
    }
    
    Vector3f operator*(float n) {
        return Vector3f(x * n, y * n, z * n);
    }
    
    Vector3f operator/(float n) {
        return Vector3f(x / n, y / n, z / n);
    }
    
    Vector3f unit() {
        return *this / sqrt(x * x + y * y + z * z);
    }
    
    Vector3f cross(Vector3f v) {
        return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
};

class Camera {
public:
    Vector3f eye, center, up, initialEye, initialCenter, initialUp, tmpEye, tmpCenter, tmpUp;
    Camera(float eyeX = 1.0f, float eyeY = 0.3f, float eyeZ = 0.79f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
        eye = Vector3f(eyeX, eyeY, eyeZ);
        center = Vector3f(centerX, centerY, centerZ);
        up = Vector3f(upX, upY, upZ);
        initialEye = eye;
        initialCenter = center;
        initialUp = up;
        tmpEye = eye;
        tmpCenter = center;
        tmpUp = up;
    }
    
    void topView(){
        //tmpEye = eye.operator + Vector3f(-0.3, 0, -0.17);
        Vector3f temp1 = up.unit() * 0.4;
        tmpEye = eye + temp1;
        Vector3f temp2 = up.unit() * 3;
        tmpCenter = center - temp2;
        Vector3f temp3 = Vector3f(-0.3, 0, -0.17);
        initialEye = initialEye.operator+(temp3);
        Vector3f temp4 = initialUp.unit() * 0.8;
        eye = initialEye + temp4;
        Vector3f temp5 = initialUp.unit() * 4;
        center = initialCenter - temp5;
    }
    
    void sideView(){
        Vector3f temp1 = Vector3f(-0.3, 0, -0.17);
        initialEye = initialEye.operator-(temp1);
        Vector3f temp2 = Vector3f(-0.3, 0, -0.17);
        eye = tmpEye.operator-(temp2);
        Vector3f temp3 = tmpUp.unit() * 0.4;
        eye = tmpEye - temp3;
        Vector3f temp4 = tmpUp.unit() * 3;
        center = tmpCenter + temp4;
    }
    
    void moveX(float d) {
        Vector3f right = up.cross(center - eye).unit();
        right = right *  d;
        eye = eye + right;
        center = center + right;
    }
    
    void moveY(float d) {
        Vector3f temp = up.unit() * d;
        eye = eye + temp;
        center = center + temp;
    }
    
    void moveZ(float d) {
        Vector3f view = (center - eye).unit();
        Vector3f temp = view * d;
        eye = eye + temp;
        center = center + temp;
    }
    
    void rotateX(float a) {
        Vector3f view = (center - eye).unit();
        Vector3f right = up.cross(view).unit();
        Vector3f temp1 = view * cos(DEG2RAD(a));
        Vector3f temp2 = up * sin(DEG2RAD(a));
        view = temp1 + temp2;
        up = view.cross(right);
        center = eye + view;
    }
    
    void rotateY(float a) {
        Vector3f view = (center - eye).unit();
        Vector3f right = up.cross(view).unit();
        Vector3f temp1 = view * cos(DEG2RAD(a));
        Vector3f temp2 = right * sin(DEG2RAD(a));
        view = temp1 + temp2;
        right = view.cross(up);
        center = eye + view;
    }
    
    void look() {
        gluLookAt(
                  eye.x, eye.y, eye.z,
                  center.x, center.y, center.z,
                  up.x, up.y, up.z
                  );
    }
};

Camera camera;

void drawWall(double thickness) {
    glPushMatrix();
    glTranslated(0.5, 0.5 * thickness, 0.5);
    glScaled(1.0, thickness, 1.0);
    glutSolidCube(1);
    glPopMatrix();
}

void setupLights() {
    GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
    GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
    GLfloat shininess[] = { 50 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
    GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera() {	
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, 640 / 480, 0.001, 100);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.look();
}

void Display() {
    setupCamera();
    setupLights();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    glPushMatrix();
    glTranslated(0.8, 0, 0.45);
    glRotated(95, 0, 1, 0);
    glScaled(0.17, 0.17, 0.17);
    drawJoker();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.5, 0, 0.65);
    glRotated(95, 0, 1, 0);
    glScaled(0.17, 0.17, 0.17);
    drawBatman();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.3, 0, 0.65);
    glRotated(95, 0, 1, 0);
    glScaled(0.17, 0.17, 0.17);
    drawCreeper();
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.5, 0, 0.45);
    glRotated(95, 0, 1, 0);
    glScaled(0.17, 0.17, 0.17);
    drawSteve();
    glPopMatrix();
    
    glPopMatrix();
    int p0[]={0,0};
    int p1[]={1,2};
    int p2[]={1,3};
    int p3[]={2,0};
    bezier(t,p0,p1,p2,p3);
    
    glPushMatrix();
    glTranslated(superX, superY, 0.2);
    glRotated(95, 0, 1, 0);
    glScaled(0.17, 0.17, 0.17);
    drawSuperman();
    glPopMatrix();

    
    glPushMatrix();
    glTranslated(-2, 0, -2);
    glScaled(5, 0.1, 5);
    glColor3f(1, 1, 1);
    drawWall(0.02);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(90, 0, 0, 1.0);
    glTranslated(0, -3, -1.5);
    //glTranslated(-2, -3, 0);
    glScaled(5, 0.1, 5);
    drawWall(0.02);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(90, 0, 0, 1.0);
    glTranslated(0, 1, -1.5);
    //glTranslated(-2, -3, 0);
    glScaled(5, 0.1, 5);
    drawWall(0.02);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslated(-2, 1, 0);
    glScaled(5, 0.1, 5);
    drawWall(0.02);
    glPopMatrix();
    
    glPushMatrix();
    glRotated(-90, 1.0, 0.0, 0.0);
    glTranslated(-2, -3, 0);
    glScaled(5, 0.1, 5);
    drawWall(0.02);
    glPopMatrix();
    
    glFlush();
}

bool animScene = false;

void AnimScene() {
    if(animScene){
        float a = 0.5*2.0;
        float d = 0.5*0.02;
        if (side == 1){
            camera.rotateY(-a);
            camera.moveX(d);
        }
    }
}

void Anim() {
    movJoker2();
    movBatman1();
    movBatman2();
    movCreeper();
    movSuperman();
    movSteve();
    AnimScene();
    glutPostRedisplay();
}

void Timer(int value) {
    movJoker1();
    glutPostRedisplay();
    glutTimerFunc(1000, Timer, 0);
}


void Special(int key, int x, int y) {
    float a = 2*2.0;
    float d = 2*0.02;
    
    switch (key) {
        case GLUT_KEY_UP:
            if (side == 1){
                camera.topView();
                side = 0;
            }
            break;
        case GLUT_KEY_DOWN:
            if (side == 0){
                camera.sideView();
                side = 1;
            }
            break;
        case GLUT_KEY_LEFT:
            
            if (side == 1){
                camera.rotateY(a);
                camera.moveX(-d);
            }
            break;
        case GLUT_KEY_RIGHT:
            if (side == 1){
                camera.rotateY(-a);
                camera.moveX(d);
            }
            break;
    }
    
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '1': if(jokerMov1){
            jokerMov1 = false;
        } else {
            jokerMov1 = true;
        } break;
        case'2':if(jokerMov2){
            jokerAngleRot = 0.0;
            jokerMov2 = false;
        } else {
            jokerMov2 = true;
        } break;
        case '3': if(batmanMov1){
            //Reset variables
            batmanMov1 = false;
            batmanHandsUp = false;
            batmanHandsUpCount1 = 0.0;
            batmanEjectHands = false;
            batmanEjectSpeed = 0.0;
            batmanEjectUp = false;
        } else {
            batmanMov1 = true;
        } break;
        case '4': if(batmanMov2){
            batmanMov2 = false;
             batmanCapeUp = true;
             batmanCapeCount = 0.0;
             batmanHandsUp1 = true;
             batmanHandsUpCount = 0.0;
             batmanSpeed = 0.0;
             batmanMovUp = true;
        } else {
            batmanMov2 = true;
        } break;
        case'5':if(creeperMov){
            creeperMov = false;
            creeperMovUp = true;
            creeperSpeed = 0.0;
            creeperAngleRot = 0.0;
        } else {
            creeperMov = true;
        } break;
        case'6':if(supermanMov){
            supermanMov = false;
            superX = 0;
            superY = 0;
            t = 1;
            supermanCapeCount = 0.0;
            supermanCapeUp = true;
        } else {
             supermanMov = true;
        } break;
        case '7': if(steveMov){
            steveMov = false;
            steveAngleRot = 0.0;
            steveHeight = 0.0;
            steveRotUp = true;
            frontFlip = false;
        } else {
            steveMov = true;
        } break;
        case '8': if(jokerMov1){
            jokerMov1 = false;
            //Batman
            batmanMov2 = false;
            batmanCapeUp = true;
            batmanCapeCount = 0.0;
            batmanHandsUp1 = true;
            batmanHandsUpCount = 0.0;
            batmanSpeed = 0.0;
            batmanMovUp = true;
            //Creeper
            creeperMov = false;
            creeperMovUp = true;
            creeperSpeed = 0.0;
            creeperAngleRot = 0.0;
            //Superman
            supermanMov = false;
            superX = 0;
            superY = 0;
            t = 1;
            supermanCapeCount = 0.0;
            supermanCapeUp = true;
            //Steve
            steveMov = false;
            steveAngleRot = 0.0;
            steveHeight = 0.0;
            steveRotUp = true;
            frontFlip = false;
        } else {
            jokerMov1 = true;
            batmanMov2 = true;
            steveMov = true;
            creeperMov = true;
            supermanMov = true;
        } break;
        case '9': if(animScene){
            animScene = false;
        } else {
            animScene = true;
        }
        default:
            ;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    
    glutCreateWindow("Assignment 2");
    glutDisplayFunc(Display);
    glutSpecialFunc(Special);
    glutIdleFunc(Anim);
    glutTimerFunc(1000, Timer, 0);
    glutKeyboardFunc(Keyboard);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
    glShadeModel(GL_SMOOTH);
    
    glutMainLoop();
}
