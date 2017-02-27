#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Camera.h>
#include <Entity.h>
#include <Radar.h>
#include <vector>
#include <list>
#include "Primitives.h"
#include <Ship.h>
#include <Descriptor.h>
class Controller
{
    public:
        Controller(WINDOW* W);
        void Process();
        virtual ~Controller();
    protected:
    std::list<Entity*> e;
    std::list<Ship*> s;
    std::list<Ship*>::iterator tgC;
    Entity* tg;
    Ship ply;
    Radar r;
    Descriptor d;
    WINDOW* w;
    private:

};

#endif // CONTROLLER_H
