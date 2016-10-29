/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Disjoint.cpp
  */ 


#include "Disjoint.hpp"
/**
  * This method looks to see if the vector that is used in the disjoint
  * class holds a number below zero at the index number that is passed
  * as the parameter.
  */
int Disjoint:: find(int i){
   //What to do is the value at the index that is being checked is 
   //below zero.
   if(dvec[i] < 0)return i;
   //What to do if otherwise.
   else return find( dvec[i] );
}

/**
  * This method compares that values being contained in two different
  * indexes. If the index that is holding the smaller value is from the second
  * of the two indexes being compared, it will set the value of the first
  * index being compared to the second index's value. If the value of the first
  * index of the indexes being compared is smaller, then it will set the value
  * of the first index to the value of the second index. Then, it will 
  * remove the first index.
  */
void Disjoint:: uni( int root1 , int root2 ){
   if(dvec[root2]<dvec[root1])
      dvec[root1] = root2;
   else{
      if(dvec[root1]<dvec[root2])
	 dvec[root1]--;
      dvec[root2] = root1;
   }
}
