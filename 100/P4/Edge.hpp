/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Edge.hpp
  */ 


#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include "Vertex.hpp"
using namespace std;

class Edge{
private:
   

public:
   int weight, time;
   Vertex* v0;
   Vertex* v1;

   //This is the constructor for Edge class.
   Edge( int we, int ti, Vertex* ve0, Vertex* ve1){
      weight = we;
      time = ti;
      v0 = ve0;
      v1 = ve1;
   }

//This is here so that the Edge.cpp can create this method.
Vertex* getV0();

//This is here so that the Edge.cpp can create this method.
Vertex* getV1();

//This is here so that the comparison operator < can be overloaded.
bool operator<(const Edge other)const;
};
#endif
