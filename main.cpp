#include <stdio.h>
#include <ncurses.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <string>
#include <vector>
#include "Camera.h"
#include "include/Controller.h"
#include "include/Entity.h"
#include "include/Radar.h"
#include <time.h>
using namespace std;
using namespace glm;
int main()
{
    srand(time(NULL));
    raw();
    WINDOW* w=initscr();
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);
    noecho();
    Controller c(w);
    while(1)
    {
        c.Process();
    }
    endwin();
    return 0;
}
