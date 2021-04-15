#ifndef __FILEHANDLER_H__
#define __FILEHANDLER_H__

#include <stdbool.h>
#include "item.h"
#include "todo.h"

bool AddItemToFile(const Item* item);
bool RemItemFromFile(Item* item);
bool ListItemsFromFile(unsigned int count, Item* items);


#endif // __FILEHANDLER_H__
