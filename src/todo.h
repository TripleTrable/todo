#ifndef TODO_H
#define TODO_H


#define STR_(X) #X
#define STR(X) STR_(X)

#define USAGE "Usage:\n"\
              "todo add <name>\n"\
              "optional:\n"\
              "\t -d, --descriptions <string>\t\tdescription of todo item\n"\
              "\t -D, --due <date (dd-mm-yyyy)>\t\tdue date\n"\
              "\t -p, --priority <number>\t\tdescription of todo item"




typedef struct _command
{
    const char* command;
    bool (*commandCallback) (int argc, const char** argv); 
} Command;
#endif // !TODO_H