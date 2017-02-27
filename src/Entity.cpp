#include "Entity.h"
using namespace glm;
Entity::Entity(std::string C,glm::vec3 P,float V):v(V),p(P),c(C),dir(mat4(1.)),hp(100),vit(0.,0.,0.)
{
    //ctor
}
void Entity::DrawDesc(int w, int h, Descriptor* desc)
{

}
Entity::~Entity()
{
    //dtor
}
