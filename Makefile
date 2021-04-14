CC=gcc
CFLAGS= -std=c99 -g -Wall -Wextra
 
 
SRC=$(wildcard src/*.c)
OBJ=$(patsubst %.c,%.o,$(SRC))
DPS=$(patsubst %.c,%.d,$(SRC))
#LIB=$(abspath $(wildcard lib/*/*.a))
#LIBS=$(patsubst lib%.a,%,$(notdir $(LIB)))
#LIBPATH=$(dir $(LIB))
#INCLUDE=$(abspath  include/)

TARGET=bin/todo
 
 
all: $(TARGET)


 
clean:
	rm -f $(TARGET) $(OBJ) $(DPS)
 
 
$(TARGET): $(OBJ)
#    $(CC) $(CFLAGS) $^ -o $@ -L $(LIBPATH) -l $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@
 
-include $(DPS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDE) -v
 
install_lib:
	$(MAKE) -C ../ install_lib
 
 
 
 
 
.PHONY: all clean