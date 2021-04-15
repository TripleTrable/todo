#include <stdint.h>
#include <stdbool.h>
#include "todo.h"
#include "config.h"


#define LENGTH(X) (sizeof X / sizeof X[0])

int main(int argc,  const char* argv[])
{
    if(argc < 2)
    {
        die(USAGE);
    }
    for(int i = 0; i < LENGTH(commands); i++)
    {
        if(!strcmp(argv[1], commands[i].command))
        {
            bool handled = commands[i].commandCallback(argc,argv);
            if(handled)
                break;
        }
    }
}