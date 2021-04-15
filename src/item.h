#ifndef ITEM_H
#define ITEM_H

typedef struct _date
{
    unsigned day;
    unsigned month;
    unsigned year;
} Date;

typedef struct _item 
{
    char* name;
    char* description;
    Date  dueDate;
    char priority;
    
} Item;

#endif // !ITEM_H
