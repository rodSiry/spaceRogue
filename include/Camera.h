#ifndef CAMERA_H
#define CAMERA_H
#include <ncurses.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Camera
{
    public:
        Camera(WINDOW* W);
        glm::mat4 PollE(int ch);
        virtual ~Camera();
        glm::vec3 Getp() { return p; }
        void Setp(glm::vec3 val) { p = val; }
        double Geta() { return a; }
        void Seta(double val) { a = val; }
        double Getb() { return b; }
        void Setb(double val) { b = val; }
    protected:
    private:
        glm::vec3 p;
        float a;
        float b;
        float s;
        WINDOW* w;
};

#endif // CAMERA_H
