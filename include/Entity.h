#ifndef ENTITY_H
#define ENTITY_H
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <string>
#include <Descriptor.h>
class Descriptor;
class Entity
{
    public:
        Entity(std::string C = "v",glm::vec3 P=glm::vec3(0.,0.,0.),float V=0.);
        std::string GetC(){return c;}
        glm::vec3 GetP(){return p;}
        glm::mat4 GetD(){return dir;}
        float GetHp(){return hp;}
        void SetP(glm::vec3 P){p=P;}
        virtual void DrawDesc(int w, int h, Descriptor* desc);
        void TakeDmg( float dmg){hp-=dmg;}
        virtual ~Entity();
    protected:
        glm::vec3 p;
        float v;
        glm::vec3 vit;
        float hp;
        std::string c;
        glm::mat4 dir;
    private:
};

#endif // ENTITY_H
