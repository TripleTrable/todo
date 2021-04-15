#include "commands.h"
#include "../todo.h"
#include "../item.h"
#include <stdio.h>
#include <argp.h>
#include <string.h>
#include "../util.h"
#include <stdlib.h>
#include "../filehandler.h"

const char *argp_program_versio = "todo" STR(VERSION);
const char *argp_program_bug_address = STR(EMAIL);
const char doc[] = "simple terminal todo list manager.";
static char args_doc[] = "";
static struct argp_option options[] = {
    {"description", 'd', "descr", 0, "description text"},
    {"due", 'D', "due", 0, "due date in format dd.mm.yyyy"},
    {"priority", 'p', "priority", 0, "priority of item"}

};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    Item *item = state->input;
    printf("%c",key);
    switch (key)
    {
        case 'd': item->description = arg; break;
        case 'D': item->dueDate = StringToDate(arg); break;
        case 'p': item->priority = atoi(arg); break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options,parse_opt,args_doc,doc};

bool addHandler(int argc, const char **argv)
{
    Item item;
    item.description = "";
    item.name = argv[2]; // 0-> progname 1-> add 2-> name
    printf(item.name);
    item.priority = 0;
    if(!argp_parse(&argp,argc -2, argv + 2,0,0,&item ))
        AddItemToFile(&item);
    return false;
}