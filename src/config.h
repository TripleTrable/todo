#ifndef CONFIG_H
#define CONFIG_H



#include "todo.h"
#include "commands/commands.h"
static Command commands[] = {
    {"add", addHandler }

};


#endif // !CONFIG_H