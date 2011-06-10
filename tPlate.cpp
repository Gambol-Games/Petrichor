#include "tPlate.h"

tPlate::tPlate(float w,float h){
    width=w;
    height=h;
    Orient(0,0);
    Pos(0,0);
}
void tPlate::Pos(float X,float Y){
x=X;y=Y;
}

void tPlate::Rot(float R){
}
void tPlate::Orient(int i,int j){

    if(i==0){
        x1=0;x2=width;
    }
    if(i==1){
        x1=-width/2;x2=width/2;
    }else{
        x2=0;x1=-width;
    }

    if(j==0){
        y1=0;y2=height;
    }
    if(j==1){
        y1=-height/2;y2=height/2;
    }else{
        y2=0;y1=-height;
    }
}

void tPlate::Render(){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(r,0,0,1);
glBegin(GL_QUADS);
    {
        glColor3f(1, 0, 0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    }glEnd();

    glPopMatrix();
}

tPlate::~tPlate(){
    //dtor
}
