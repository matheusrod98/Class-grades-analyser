CC = clang
CXX = clang++

ifeq ($(cc), GCC)
CC = gcc
CXX = g++
endif

CCFLAGS = -Wall -std=c11
CXXFLAGS = -Wall -std=c++11

OBJECTS = sqlite3.o DAO.o Main.o

EXEC = class-grades-analyser

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

.c.o:
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o

clean-all:
	rm -f *.o class-grades-analyser
