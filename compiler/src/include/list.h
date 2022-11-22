#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct ARRAY_LIST{

	void** items;
	unsigned int listSize;
	unsigned int itemSize;
};

struct ARRAY_LIST* createArrayList(unsigned int itemSize);
char addItem(struct ARRAY_LIST* list, void* item);

//Experimental
char removeItem(struct ARRAY_LIST* list, unsigned int i);

#endif

