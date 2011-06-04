#include "Entity.h"


Entity::Entity(){
    physics=false;
    render=true;
    ID=-1;
    RenderID=-1;
    PhysicsID=-1;
    x=0;y=0;z=0;
    rx=0;ry=0;rz=0;
}

void Entity::Frame(){
}

void Entity::Render(){
}

void Entity::Physics(){
}


Entity::~Entity(){
    //dtor
}
