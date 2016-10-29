/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Vertex.cpp
  */ 


#include "Vertex.hpp"

int Vertex:: indexNum(int i){
   index = i;
}
/**
  * This is an overload for the vertex class that allows you to
  * check if it is the same vertex or not.
  */
bool Vertex:: operator<(const Vertex*& other)const{
   return name < other->name;
}
