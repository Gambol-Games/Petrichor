#ifndef SCREEN_H
#define SCREEN_H
#include <GL/glfw.h>
#include <stdlib.h>

class Screen
{
    public:
        Screen(int,int);
        void Begin();
        void End();
        void Mode2D();
        void Mode3D();
        virtual ~Screen();
    protected:
    private:
    float aspect_ratio;
        void Shut_Down(int);
};

#endif // SCREEN_H
