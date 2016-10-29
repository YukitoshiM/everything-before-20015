/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Disjoint.hpp
  */ 


#ifndef DISJOINT_HPP
#define DISJOINT_HPP

using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "Vertex.hpp"
#include "Edge.hpp"


class Disjoint{
private:
   vector<int> dvec;

  
public:
   //This is the constructor for the Disjoint class.
   Disjoint(int size){
      dvec = vector<int>(size,-1);
   }

   //This is here so that the Disjoint.cpp can create this method.
   int find(int i);

   //This is here so that the Disjoint.cpp can create this method.
   void uni(int root1, int root2);

};
#endif
