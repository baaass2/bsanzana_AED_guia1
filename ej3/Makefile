prefix=/usr/local
CC = g++

CFLAGS = -g -Wall 
SRC = Programa.cpp Departamento.cpp
OBJ = Programa.o Departamento.o
APP = Programa

all: $(OBJ)
	$(CC) $(CFLAGS)-o $(APP) $(OBJ) 

clean:
	$(RM) $(OBJ) $(APP)

install: $(APP)
	install -m 0755 $(APP) $(prefix)/bin

uninstall: $(APP)
	$(RM) $(prefix)/bin/$(APP)

