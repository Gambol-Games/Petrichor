#ifndef ENTITY_H
#define ENTITY_H
#include "Model.h"
#include "Texture.h"

class Entity
{
    //==qualities==
    bool physics;
    bool render;
    //=============

    int ID; //identifies position in entity array
    int RenderID; //id in the render array, -1 otherwise
    int PhysicsID; //id in the physics array, -1 otherwise

    float x,y,z; // position
    float rx,ry,rz; //rotation
    Model model; //single model
    Texture texture; // single texture, temporary, should get more complex later



    public:

    Entity();
    void Frame(); //happens every frame, as long as Entity exists
    void Render(); // generally applicable to all children, probably. may not always occur though
    void Physics(); // not necessarily applicable to all children of Entity. even less likely to trigger


    virtual ~Entity();
    protected:
    private:
};

#endif // ENTITY_H
