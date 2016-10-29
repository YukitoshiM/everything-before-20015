# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall

#include debugging symbols in executable
LDFLAGS= -g	

#rst: test_RST.o countint.o 
#	g++ -g test_RST.o countint.o -o rst

benchtree: benchtree.o countint.o
	g++ -g benchtree.o countint.o -o benchtree

benchtree.o: RST.hpp RSTNode.hpp BST.hpp BSTNode.hpp BSTIterator.hpp countint.hpp countint.cpp benchtree.cpp
	g++ -g -c benchtree.cpp -o benchtree.o

#test_RST.o: RST.hpp RSTNode.hpp BST.hpp BSTNode.hpp BSTIterator.hpp countint.hpp countint.cpp	test_RST.cpp
#	g++ -g -c test_RST.cpp -o test_RST.o

clean:
	rm -rf *o 
