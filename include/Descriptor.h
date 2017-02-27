#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <Panel.h>
#include <Entity.h>
#include <ncurses.h>

class Entity;
class Descriptor : public Panel
{
    public:
        Descriptor();
        void SetTg(Entity* TG){tg=TG;}
        void Clear();
        Descriptor(int X, int Y, int W, int H);
        void DrawArray();
        virtual ~Descriptor();
    protected:
        Entity* tg;
    private:
};

#endif // DESCRIPTOR_H
