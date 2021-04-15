#ifndef CONFIG_H
#define CONFIG_H
#include "todo.h"
#include "commands/commands.h"

#define CONFIGPATH config

static Command commands[] = {
    {"add", addHandler }

};


#endif // !CONFIG_H