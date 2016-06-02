# compiler
CC := g++
# include files
CFLAGS := $(shell pkg-config opencv --cflags)
LIBS := $(shell pkg-config opencv --libs)

GTP := main

all: $(GTP)

$(GTP): $(GTP).cpp
	$(CC) $(CFLAGS) $(LIBS) -g -o $(GTP) $(GTP).cpp 
	
clean:
	rm $(GTP)
