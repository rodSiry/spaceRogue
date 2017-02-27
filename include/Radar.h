#ifndef RADAR_H
#define RADAR_H
#include "Entity.h"
#include <list>
#include <3dEnv.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <ncurses.h>
#include <string.h>
#include <Primitives.h>
#include <unistd.h>
#include <Ship.h>
class Radar: public _3dEnv
{
    public:
        Radar(int X=0, int Y=0, int W=0, int H=0, std::list<Entity*>* E=NULL, Ship* Ply=NULL, Entity** Tg=NULL);
        void Draw(glm::mat4 M);
        void Clear();
        glm::vec3 Distort(glm::vec3 V);
        glm::vec3 TransformRadar(glm::vec3 V);
        void DrawArray();
        void DrawLine(Entity* f, Entity* Tg,WINDOW* w, char c);
        virtual ~Radar();
    protected:
        float rg;
        int wW;
        int wH;
        Ship* ply;
        Entity** tg;
};

#endif // RADAR_H
