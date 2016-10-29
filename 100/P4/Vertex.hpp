/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Vertex.hpp
  */ 


#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <climits>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Vertex{
private:
   
public:
   std::string name;
   int index, dist, prev;
   bool done;
   vector< pair<Vertex*, int> > adjTime;
   vector< pair<Vertex*, int> > adjCost;
   vector< pair<Vertex*, int> > minAdjTime;

   //This is the constructor for the Vertex class.
   Vertex(std::string s){
      name = s;
      dist = INT_MAX;
      prev = -1;
      index = 0;
      done = 0;
   }

   //This is here so that the method can be made in Vertex.cpp.
   int indexNum( int i);

   //This is here so that the operator < can be overloaded.
   bool operator<(const Vertex*& other)const;
 };
#endif
