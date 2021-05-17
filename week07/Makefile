

NAME=matz
#LIBS= -fstream -iostream -math.h -stdlib.h -sstream
SOURCES=\
	matz.cc\



CC=gcc
CFLAGS=-g -Wall

CXX=g++
CXXFLAGS=$(CFLAGS)

LD=g++
LDFLAGS=


OBJECTS=${SOURCES:.cc=.cc}


.PHONY: clean
.SUFFIXES: .o .c .cc .cpp


all: program

clean:
	$(RM) $(OBJECTS)
	$(RM) $(NAME)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<


program: $(NAME)
$(NAME): $(OBJECTS)
	$(LD) $(LDFLAGS) $(LIBS) -o $@ $^

