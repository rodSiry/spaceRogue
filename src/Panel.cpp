#include "Panel.h"

Panel::Panel(int X, int Y, int W, int H): x(X), y(Y), w(W), h(H),active(true)
{
    //ctor
}
void Panel::Blit(int X, int Y, char c)
{
    if(Y>=0&&Y<h&&X>=0&&X<w)
        mvaddch(y+Y,x+X,c);
}
void Panel::Blit(int X, int Y, std::string s)
{
    mvaddstr(y+Y,x+X,&s[0]);
}
Panel::~Panel()
{
    //dtor
}
