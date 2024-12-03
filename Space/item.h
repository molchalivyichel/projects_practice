#ifndef ITEM_H  
#define ITEM_H

#include "vector.h"

class Screen;

class Item
{
	private:
		friend class Screen;
		const Vector coords;
		char symbole;
};

#endif