/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Graph.hpp
  */ 


#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "Vertex.hpp"
#include "Edge.hpp"
#include <queue>
#include <functional>
#include "Disjoint.hpp"
using namespace std;

/**
  * This class is an overload for comparing values in the verices.
  */ 
class Comp {
public:
    bool operator()( pair<Vertex*, int> zero,  pair< Vertex*, int > one) const {
        return zero.second < one.second;
    }
};

/**
  * This class is an overload for comparing the weighr of the edges.
  */
class Comp2{
public:
   bool operator()(Edge* e0, Edge* e1){
      return e1->weight < e0->weight;
   }
};


class Graph{
private:
   std::vector< Vertex* > vertex;
   vector<Edge*> evec;
   Edge* edg;
   int eSize, vSize, index, row, col,totalTime;
   
public:
   
//This is the constructor for the Graph class.      
Graph(){
      eSize = 0;
      vSize = 0;
      index = 0;
      totalTime = 0;
   }
   
   //This is here so that the Graph.cpp can create this method
   Vertex* addVertex( Vertex* v );

   //This is here so that the Graph.cpp can create this method.
   void addEdge( Edge* e);

   //This is here so that the Graph.cpp can create this method.
   Vertex* getVertex(std::string s);

   //This is here so that the Graph.cpp can create this method.
   int dijkstra(Vertex* startNode);

   //This is here so that the Graph.cpp can create this method.
   int timeSum();

   //This is here so that the Grawph.cpp can create this method
   int Kuruskal();
   
   //This is here so that the Graph.cpp can create this method
   int minDijkstra(Vertex* startNode);

   //This is here so that the Graph.cpp can create this method.
   int minTimeSum();

   ~Graph(){
      for(int i = 0; i < vertex.size(); i++){
	 delete vertex[i];
      }

      for(int j = 0; j < evec.size(); j++){
	 delete evec[j];
      }
      vertex.clear();
      evec.clear();
   }
};
#endif

