#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <Entity.h>
#include <glm/glm.hpp>
#include <list>

class Ship : public Entity
{
    public:
        void PlayerProcess(int ch, Entity* tg);
        void AIProcess(Entity* t);
        bool Shoot(Entity* tg);
        void DrawDesc(int w, int h, Descriptor* desc);
        std::list<glm::vec3>* GetLP(){return &lP;}
        Ship(std::string C = "v",std::string Name="ship",glm::vec3 P=glm::vec3(0.,0.,0.),float V=0.);
        virtual ~Ship();
        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        std::list<glm::vec3> lP;
    protected:
    private:
        std::string name;
};

#endif // SHIP_H
