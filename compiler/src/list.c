#include "include/list.h"

struct ARRAY_LIST* createArrayList(unsigned int itemSize){

	struct ARRAY_LIST* list = calloc(1, itemSize);
	list->listSize = 0;
	list->itemSize = itemSize;
	list->items = 0;

	return list;
}

char addItem(struct ARRAY_LIST* list, void* item){
	list->listSize++;
	list->items = realloc(list->items, (list->listSize * list->itemSize));
	list->items[list->listSize] = item;
}

char removeItem(struct ARRAY_LIST* list, unsigned int i){

}
