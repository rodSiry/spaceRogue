#include <Radar.h>
#include <locale.h>
using namespace glm;
vec3 Radar::Distort(vec3 v)
{
    float D=length(v);
    if(D==0.f)
        return v;
    else if(D>5.f&&D<100.f)
        D=5.f+(D-5.f)*15.f/95.f;
    else if(D>=100.f)
        D=20.f;
    return D*normalize(v);
}
vec3 Radar::TransformRadar(vec3 V)
{
    mat4 t=rotate(radians(30.f),vec3(1.,0.,0.));
    vec4 v=vec4(V,1.);
    vec4 q=m*v;
    vec3 p=vec3(t*q);
    vec3 pj=vec3(t*vec4(q[0],0.,q[2],q[3]));
    vec3 sP=Distort(vec3(p[0],p[1]-pj[1],-pj[2]));
    sP.y=sP.y+sP.z;
    return sP;
}
Radar::Radar(int X, int Y, int W, int H, std::list<Entity*>* E, Ship* Ply, Entity** Tg):_3dEnv(X, Y, W, H, E), ply(Ply),tg(Tg),rg(10.)
{

    setlocale(LC_ALL, "");
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA,COLOR_BLACK);
    init_pair(4, COLOR_BLACK,COLOR_RED);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_GREEN, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);

}
void Radar::Draw(mat4 M)
{

    m=M;
    int row, col;
    getmaxyx(stdscr,row,col);
    if(row!=wH||col!=wW)
    {
        DrawArray();
        wH=row;
        wW=col;
    }
    vec3 off(floor(w/2), floor(h/2),floor(h/2));
    attron(COLOR_PAIR(2));
    for(std::list<Entity*>::iterator i=e->begin();i!=e->end();i++)
    {
        mat4 t=rotate(radians(30.f),vec3(1.,0.,0.));
        vec4 v=vec4((*i)->GetP()-ply->GetP(),1.);
        vec4 q=m*v;
        vec3 p=vec3(t*q);

        if(*tg!=NULL&& &**i==*tg)
            attron(A_UNDERLINE);

        attron(COLOR_PAIR(6));
        vec3 pj=vec3(t*vec4(q[0],0.,q[2],q[3]));
        vec3 sP=Distort(vec3(p[0],p[1]-pj[1],-pj[2]));
        sP.y=sP.y+sP.z;
        sP= sP+off;
        if(sP.x>1&&sP.x<w-1 &&sP.y>1&&sP.y<h-1)
            Blit(sP,((*i)->GetC())[0]);
        attroff(A_UNDERLINE);
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        if(abs(sP[1]-sP[2])>=1)
        {
            if(sP[1]-sP[2]>0)
                sP[1]--;
            else if(sP[1]-sP[2]<0)
                sP[1]++;
            while(abs(sP[1]-sP[2])>1)
            {
                if(sP.x>1&&sP.x<w-1 &&sP.y>1&&sP.y<h-1)
                    Blit(sP,'|');
                if(sP[1]-sP[2]>0)
                    sP[1]--;
                else if(sP[1]-sP[2]<0)
                    sP[1]++;
            }
            if(sP.x>1&&sP.x<w-1 &&sP.y>1&&sP.y<h-1)
                Blit(sP, 'x');
        }
    }

    attron(COLOR_PAIR(5));
    attron(COLOR_YELLOW);
    Blit(off, '>');
    if(*tg!=NULL)
    {
        Panel::Blit(1,h-2,"TARG: ");
        Panel::Blit(7,h-2,std::to_string((*tg)->GetHp()));
        Panel::Blit(1,h-3,"HULL: ");
        Panel::Blit(7,h-3,std::to_string(ply->GetHp()));
    }
}
void Radar::Clear()
{
    ClearDBuff();
    for(int i(1);i<w-1;i++)
        for(int j(1);j<h-1;j++)
            mvaddch(y+j, x+i,' ');
}
void Radar::DrawArray()
{

    //LAYOUT
    attron(A_DIM);
    attron(COLOR_PAIR(8));
    ClearDBuff();
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
}
void Radar::DrawLine(Entity* f, Entity* Tg,WINDOW* W, char c)
{
    mat4 t=rotate(radians(30.f),vec3(1.,0.,0.));
    vec4 v1=vec4(Tg->GetP()-ply->GetP(),1.);
    vec4 v2=vec4(f->GetP()-ply->GetP(),1.);
    float d1=length(v1);
    vec4 q1=m*v1;
    float d2=length(v2);
    vec4 q2=m*v2;
    vec3 p1=vec3(t*q1);
    vec3 p2=vec3(t*q2);
    vec3 pj1=vec3(t*vec4(q1[0],0.,q1[2],q1[3]));
    vec3 sP1=Distort(vec3(p1[0],p1[1]-pj1[1],-pj1[2]));
    sP1.y=sP1.y+sP1.z;
    vec3 pj2=vec3(t*vec4(q2[0],0.,q2[2],q2[3]));
    vec3 sP2=Distort(vec3(p2[0],p2[1]-pj2[1],-pj2[2]));
    sP2.y=sP2.y+sP2.z;
    Clear();
    Draw(m);
    Line(floor(sP1[1])+y+h/2,floor(sP1[0])+x+w/2,floor(sP2[1])+y+h/2,floor(sP2[0])+x+w/2,c);
    refresh();
    usleep(50000);
    nodelay(stdscr, true);
    getch();
    nodelay(stdscr, false);
}
Radar::~Radar()
{
    //dtor
}
