#ifndef ITEM_H  
#define ITEM_H

#include "vector.h"

class Screen;

class Item
{
	private:
		const Vector coords;
		char symbole;
		int* color;
		const int countLimitColor = 2;

		friend class Screen;
	public:
		//Screen(Vector _coords, char symbole)
};

#endif