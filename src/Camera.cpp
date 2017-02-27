#include "Camera.h"
#include <iostream>
using namespace glm;
Camera::Camera(WINDOW* W): a(0.),b(0.),s(50.),p(0.,0.,0.),w(W)
{
}
mat4 Camera::PollE(int ch)
{
    float c=10;
    switch(ch){
        case int('m'):
            a+=c;
            break;
        case int('k'):
            a-=c;
            break;
        case int('l'):
            b+=c;
            break;
        case int('o'):
            b-=c;
            break;
        case int('w'):
            s+=1.;
            break;
        case int('x'):
            s-=1.;
            break;
    }
    b=clamp(b,0.f,90.f);
    return scale(vec3(exp(s/50.f),exp(s/50.f),exp(s/50.f)))*inverse(rotate(radians(a),vec3(0.,1.,0.))*rotate(radians(b),vec3(1.,0.,0.)));
}
Camera::~Camera()
{

}
