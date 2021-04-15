#include "filehandler.h"
#include "util.h"
#include <stdio.h>
#include "config.h"
#include <string.h>
#include <errno.h>

extern int errno;

bool AddItemToFile(const Item *item)
{
    //TODO: if path not exists create path
    const char *path = STR(CONFIGPATH) "/todo.dat";
    FILE *file = fopen(path, "a+");
    if (file == NULL)
    {
        const char *err = strerror(errno);
        printf("ERRNO: %s", err);
        return false;
    }
    const char *d = DateToString(&(item->dueDate));
    fprintf(file, "%s,%s,%s,%02d\n", item->name, item->description, d, item->priority);
    free(d);
    fclose(file);
}
bool RemItemFromFile(Item *item)
{
}
bool ListItemsFromFile(unsigned int count, Item *items)
{
}