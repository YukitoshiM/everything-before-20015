/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: netplan.cpp
  */ 


#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"

using namespace std;


int main( int argc, char** argv){
   //What to do if the number of arguments is incorrect.
   if(argc != 2){
      std::cout<<"Type correct number of arguement which is 2!"<<std::endl;
      return -1;
   }

   std::string name0, name1, line;
   int weight, time, minTime, index = 0, weightSum=0, timeSum=0;
   Graph g;
   
   std::set<string> vSet;

   Vertex* ve0;
   Vertex* ve1;

   std::ifstream in(argv[1]);
   //The loop continues until there are no more lines to get from the input file.
   while(std::getline(in,line)){
      std::stringstream lineStream(line);
      lineStream >> name0 >> name1 >> weight >> time;
      ve0 = new Vertex(name0);
      ve1 = new Vertex(name1);
      //What to do if the vector of strings is empty.
      if( vSet.empty() ){	 
	 vSet.insert( name0 );
	 vSet.insert( name1 );

	 ve0 = g.addVertex(ve0);
	 ve1 = g.addVertex(ve1);
      }
      //What to do if the vector of strings is not empty and name0 and name1
      //are not in the vector.
      else if( vSet.find( name0 ) == vSet.end() && 
	  vSet.find( name1 ) == vSet.end()){

	 vSet.insert( name0 );
	 vSet.insert( name1 );

	 ve0 = g.addVertex(ve0);
	 ve1 = g.addVertex(ve1);
      }
      //What to do if only name0 is not in the vector.
      else if( vSet.find( name0 ) == vSet.end() ){
	 vSet.insert( name0 );
	 ve0 = g.addVertex(ve0);
	 ve1 = g.getVertex( name1 );	 
      }
      //What to do if only name1 is not in the vector.
      else if( vSet.find( name1 ) == vSet.end() ){
	 vSet.insert( name1 );
	 ve1 = g.addVertex(ve1);
	 ve0 = g.getVertex( name0 );
      }
      //What to do if both of name0 and name1 are in the vector.
      else{
	 ve0 = g.getVertex( name0 );
	 ve1 = g.getVertex( name1 );
      }
      
      //Creates the edge that contains the vertices that hold name0
      //and name1.
      Edge* e = new Edge(weight,time, ve0, ve1); 

      g.addEdge(e);
      
      weightSum += weight;
   }

   time = g.timeSum();
   int krus = g.Kuruskal();
   minTime = g.minTimeSum();
   in.close();

   cout<<weightSum<<endl;
   cout<<krus<<endl;
   cout<<weightSum-krus<<endl;
   cout<<time<<endl;
   cout<<minTime<<endl;
   cout<<minTime-time<<endl;
   return 0;
}
