#include "3dEnv.h"
using namespace std;
using namespace glm;
_3dEnv::_3dEnv(int X, int Y, int W, int H, std::list<Entity*>* E):Panel(X,Y,W,H),e(E)
{
    vector<float>dV(h, -9999);
    for(int i(0);i<w;i++)
    {
        dBuff.push_back(dV);
    }

}
void _3dEnv::Blit(vec3 v, char c)
{
    v.z=-v.z;
    int X=floor(v.x);
    int Y=floor(v.y);
    if(X>=0&&X<w&&Y>=0&&Y<h&&(dBuff[X][Y]>=v.z||dBuff[X][Y]<=-9999))
    {
        mvaddch(y+Y,x+X,c);
        dBuff[X][Y]=v.z;
    }
}
void _3dEnv::BlitIn(int X, int Y, char c)
{
    if(Y>0&&Y<h-1&&X>0&&X<w-1)
        mvaddch(y+Y,x+X,c);
}
void _3dEnv::ClearDBuff()
{
    for(int i(0);i<w;i++)
        for(int j(0);j<h;j++)
            dBuff[i][j]=-9999;
}
_3dEnv::~_3dEnv()
{
    //dtor
}
