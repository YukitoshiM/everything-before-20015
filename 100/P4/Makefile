CC=g++
CXXFLAGS=-g
LDFLAGS=-g

all:netplan

netplan: Graph.o Vertex.o Edge.o Disjoint.o 

Graph.o: Graph.hpp Vertex.o Edge.o

Disjoint.o: Disjoint.hpp Vertex.o Edge.o

Vertex.o: Vertex.hpp

Edge.o: Edge.hpp

clean:
	rm -f netplan *.o core*

purify:
	purify:
	prep purify
	purify -cache-dir=$HOME g++ netplan.cpp Graph.cpp Disjoint.cpp Vertex.cpp Edge.cpp -o netplan
