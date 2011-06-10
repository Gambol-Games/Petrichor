#ifndef TPLATE_H
#define TPLATE_H
#include <GL/glfw.h>


class tPlate
{
    float x1,x2,y1,y2;
    float width,height;





    public:
    float x,y;
    int orient;
    float r;
        tPlate(float, float);
        void Pos(float,float);
        void Rot(float);
        void Orient(int,int);
        void Render();
        virtual ~tPlate();
    protected:
    private:
};

#endif // TPLATE_H
