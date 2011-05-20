#include <stdlib.h>
#include <GL/glfw.h>
#include "Screen.h"


void Init();
void Shut_Down(int return_code);
void Main_Loop();
void Draw();
void Draw_Square(float, float, float);
void Logic();
void D2();
void D3();


float rotate_y = 0,rotate_z = 0;
const float rotations_per_tick = .2;

bool    running = true;

const int window_width = 600,window_height = 600;

double old_time = glfwGetTime();


Screen screen= Screen(window_width,window_height);;



int main()
{
    Init();
    Main_Loop();
    Shut_Down(0);
}

void Init()
{

}

void Shut_Down(int return_code)
{
    glfwTerminate();
    exit(return_code);
}

void Main_Loop()
{
    while(running)
    {
     Logic();
     Draw();
    }
}

void Logic(){


        double current_time = glfwGetTime();
        double delta_rotate = (current_time - old_time) * rotations_per_tick * 360;
        old_time = current_time;
        // escape to quit, arrow keys to rotate view
        if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
            rotate_y += delta_rotate;
        if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
            rotate_y -= delta_rotate;
        // z axis always rotates
        rotate_z += delta_rotate;

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED);
}

void Draw()
{
    screen.Begin();
    screen.Mode3D();
    D3();
    screen.Mode2D();
    D2();
    screen.End();
}

void D3(){
    glTranslatef(0, 0, -30);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);


    int i = 0, squares = 15;
    float red = 0, blue = 1;
    for (; i < squares; ++i)
    {
        glRotatef(360.0/squares, 0, 0, 1);

        red += 1.0/12;
        blue -= 1.0/12;
        Draw_Square(red, .6, blue);
    }
    //glPopMatrix();
}

void D2()
{
    int X,Y;
    glfwGetMousePos(&X,&Y);
    float x=(2.0f*X/window_width)-1;
    float y=(-2.0f*Y/window_height)+1;

    glBegin(GL_QUADS);
    {
        glColor4f(1,0,0,0.1);
        glVertex2f(x, y);
        glColor4f(0,0,1,0.5);
        float f=1.0f;
        glVertex2f(f+x, y);
        glVertex2f(f+x, y+f);
        glVertex2f(x, y+f);
    }
    glEnd();
}

void Draw_Square(float red, float green, float blue)
{
    glBegin(GL_QUADS);
    {
        glColor3f(red, green, blue);
        glVertex2i(1, 11);
        glColor3f(red * .8, green * .8, blue * .8);
        glVertex2i(-1, 11);
        glColor3f(red * .5, green * .5, blue * .5);
        glVertex2i(-1, 9);
        glColor3f(red * .8, green * .8, blue * .8);
        glVertex2i(1, 9);
    }
    glEnd();
}
