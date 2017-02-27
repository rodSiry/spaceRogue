#include "Descriptor.h"

Descriptor::Descriptor()
{
    //ctor
}
Descriptor::Descriptor(int X, int Y, int W, int H):Panel(X, Y, W, H), tg(NULL)
{
}
void Descriptor::Clear()
{
    attron(COLOR_PAIR(5));
    for(int i(1);i<w;i++)
    {
        for(int j(0);j<h;j++)
        {
                Panel::Blit(i,j,' ');
        }
    }

}
void Descriptor::DrawArray()
{
    Clear();
    attron(COLOR_PAIR(8));
    attron(A_DIM);
    for(int i(1);i<w;i++)
    {
        Panel::Blit(i,0,' ');
        Panel::Blit(i,h-1,' ');
    }
    for(int i(0);i<h;i++)
    {
            Panel::Blit(0,i,' ');
            Panel::Blit(w-1,i,' ');
    }
    attroff(A_DIM);
    tg->DrawDesc(w, h, this);
}
Descriptor::~Descriptor()
{
    //dtor
}
