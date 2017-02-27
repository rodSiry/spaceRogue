#ifndef PANEL_H
#define PANEL_H
#include <ncurses.h>
#include <string>
class Panel
{
    public:
        Panel(int X=0, int Y=0, int W=40, int H=40);
        virtual ~Panel();
        void Blit(int X, int Y, char c);
        void Blit(int X, int Y, std::string s);
        bool Getactive() { return active; }
        void Setactive(bool val) { active = val; }
        int Geth() { return h; }
        void Seth(int val) { h = val; }
        int Getw() { return w; }
        void Setw(int val) { w = val; }
        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
    protected:
        bool active;
        int h;
        int w;
        int x;
        int y;
};

#endif // PANEL_H
