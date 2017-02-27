#include "Ship.h"
using namespace glm;
Ship::Ship(std::string C, std::string Name, glm::vec3 P,float V):Entity(C, P, V), name(Name)
{

}
Ship::~Ship()
{
    //dtor
}
void Ship::DrawDesc(int w, int h, Descriptor* desc)
{
    attron(COLOR_PAIR(5));
    int o=floor((w-name.size())/2.f);
    desc->Blit(o-1, 1, '<');
    desc->Blit(o+name.size(), 1, '>');
    desc->Blit(o, 1, name);
    attron(COLOR_PAIR(1));
    o=floor((w-std::to_string(hp).size())/2.f);
    desc->Blit(o,h-2, std::to_string(hp));
}
void Ship::AIProcess(Entity* t)
{
    if(hp<=0)
    {
        c='%';
    }
    else
    {
        vec3 tD=vec3(t->GetD()*vec4(0.,0.,1.,0.));
        vec3 d=vec3(dir*vec4(0.,0.,1.,0.));
        vec3 rA=normalize(cross(t->GetP()-p, d));
        dir=rotate(radians(-5.f), rA)*dir;
        p+=2.f*vec3(dir*vec4(0.,0.,1.,0.));
    }
}
void Ship::PlayerProcess(int ch, Entity* tg)
{
    switch(ch){
        case int('z'):
            dir=dir*rotate(radians(10.f),vec3(1.f,0.f,0.f));
            break;
        case int('s'):
            dir=dir*rotate(radians(-10.f),vec3(1.f,0.f,0.f));
            break;

        case int('q'):
            dir=dir*rotate(radians(10.f),vec3(0.f,0.f,1.f));
            break;

        case int('d'):
            dir=dir*rotate(radians(-10.f),vec3(0.f,0.f,1.f));
            break;
        case int('e'):
            v+=0.5f;
            break;
        case int('a'):
            v-=0.5f;
            break;
        }
    v=5.f;
    v=clamp(v,0.f,10.f);
    p+=2.f*vec3(dir*vec4(0.,0.,1.,0.));
    if(lP.size()>50)
    {
        lP.push_front(p);
        lP.pop_back();
    }
    else
        lP.push_front(p);
}
bool Ship::Shoot(Entity* tg)
{
    vec3 d=vec3(dir*vec4(0.,0.,1.,0.));
    float dd=distance(tg->GetP(),p);
    if(hp>0&&degrees(angle(d,normalize(tg->GetP()-p)))<10&&dd<20.)
    {
        float dmg=10.f/(1.f+dd);
        tg->TakeDmg(dmg);
        return true;
    }
    else
        return false;
}
