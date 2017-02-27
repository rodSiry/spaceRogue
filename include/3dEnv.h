#ifndef _3DENV_H
#define _3DENV_H

#include <Panel.h>
#include <vector>
#include <list>
#include "Entity.h"
#include <glm/glm.hpp>
#include <ncurses.h>
#include <string>
class _3dEnv : public Panel
{
	public:
		_3dEnv(int X, int Y, int W, int H, std::list<Entity*>* E);
		void Blit(glm::vec3 v, char c);
		void BlitIn(int X, int Y, char c);
		void ClearDBuff();
		virtual ~_3dEnv();
		std::vector<std::vector<float> > GetdBuff() { return dBuff; }
		void SetdBuff(std::vector<std::vector<float> > val) { dBuff = val; }
	protected:
		glm::mat4 m;
		std::vector<std::vector<float> > dBuff;
		std::list<Entity*>* e;
};

#endif // 3DENV_H
