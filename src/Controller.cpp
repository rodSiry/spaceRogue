#include "Controller.h"
#include <unistd.h>
using namespace glm;
Controller::Controller(WINDOW* W):w(W),tg(NULL),tgC(s.begin())
{
    int row, col;
    getmaxyx(stdscr,row,col);
    r=Radar(0,0,39,40, &e,&ply, &tg);
    d=Descriptor(40, 0, 20, 20);
    for(int i(0);i<5;i++)
    {
        Ship* nSh= new Ship("f","Fighter",vec3(rand()%400-200,rand()%400-200,rand()%400-200));
        e.push_front(nSh);
        s.push_front(nSh);
    }
    for(int i(0);i<0;i++)
    {
        Entity* nE= new Entity("o",vec3(rand()%400-200,rand()%400-200,rand()%400-200));
        e.push_front(nE);
    }

}
void Controller::Process()
{
    int row, col;
    getmaxyx(stdscr,row,col);
    int ch=getch();
    while(ch==int('t'))
    {
        switch(ch)
        {
            case int('t'):
                if(s.size()!=0)
                {
                    tgC++;
                    if(tgC==s.end())
                        tgC=s.begin();
                    tg=&(**tgC);
                    d.SetTg(tg);
                    d.DrawArray();
                    r.Draw(inverse(ply.GetD()));
                }
        }
        ch=getch();
    }
    ply.PlayerProcess(ch, tg);
    r.Clear();
    r.Draw(inverse(ply.GetD()));
    refresh();
    if(tg!=NULL)
    {
        if(ply.Shoot(tg))
        {
            tg->TakeDmg(50.f);
            r.DrawLine(&ply, tg, w, '*');
            d.DrawArray();
        }

    }
    for(std::list<Ship*>::iterator i=s.begin();i!=s.end();i++)
    {
        (*i)->AIProcess(&ply);
        if((*i)->Shoot(&ply))
        {
            r.DrawLine(&(**i), &ply,w, '*');
        }
    }
    r.Clear();
    r.Draw(inverse(ply.GetD()));
    refresh();
}

Controller::~Controller()
{
    for(std::list<Ship*>::iterator i=s.begin();i!=s.end();i++)
    {
        delete *i;
    }
    for(std::list<Entity*>::iterator i=e.begin();i!=e.end();i++)
    {
        delete *i;
    }
}
