#ifndef ITEM_H
#define ITEM_H

typedef struct _date
{
    unsigned day;
    unsigned month;
    unsigned year;
} date;

typedef struct _item 
{
    char* name;
    char* description;
    date  dueDate;
    char priority;
    
} item;

#endif // !ITEM_H
