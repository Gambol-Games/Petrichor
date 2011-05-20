#include "Screen.h"

Screen::Screen(int window_width,int window_height)
{

    if (glfwInit() != GL_TRUE)
        Shut_Down(1);
    // 800 x 600, 16 bit color, no depth, alpha or stencil buffers, windowed
    if (glfwOpenWindow(window_width, window_height, 5, 6, 5,
                       0, 0, 0, GLFW_WINDOW) != GL_TRUE)
        Shut_Down(1);
    glfwSetWindowTitle("The GLFW Window");

    // set the projection matrix to a normal frustum with a max depth of 50
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspect_ratio = ((float)window_height) / window_width;
    glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 60);
    glMatrixMode(GL_MODELVIEW);

    //glEnable(GL_DEPTH_TEST);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


Screen::~Screen()
{
    //dtor
}

void Screen::Shut_Down(int return_code)
{
    glfwTerminate();
    exit(return_code);
}

void Screen::Mode3D(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 60);
}

void Screen::Mode2D(){
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0, 1);
}

void Screen::Begin(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Screen::End(){
    glfwSwapBuffers();
}

