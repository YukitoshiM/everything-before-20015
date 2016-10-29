/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Edge.cpp
  */ 


#include "Edge.hpp"

/**
  * This compares the time and weight of the edges.
  */
bool Edge:: operator<(const Edge other)const{
   return (weight < other.weight && time < other.time);
}
