/**
  * Name: Michael Rhee, Yukitoshi Murase
  * Pid: A08775030, A97424977
  * login: cs100fby, ymurase
  * File name: Graph.cpp
  */ 

#include "Graph.hpp"
#include <climits>

/**
  * Adds the vertex that was passed as the parameter into a vector for 
  * use in graph. Returns the vertex that was added when the method is called.
  */
Vertex* Graph:: addVertex(Vertex* v){
   v->indexNum( index );
   vertex.push_back(v); 
   index++;
   return v;
}

/**
  * This method adds the edge passed in as the parameter into a vector. It
  * also updates the adjacency list of the two vertices that are involved.
  */
void Graph:: addEdge(Edge* e0){
   //This makes the vector of edges.
   evec.push_back(e0);
   //Creates adjacency list containing the travel time from the current
   //vertex to the vertices that are connected to it.
   e0->v0->adjTime.push_back(pair<Vertex*,int>(e0->v1, e0->time));
   e0->v1->adjTime.push_back(pair<Vertex*,int>(e0->v0, e0->time));
}

/**
  * This method gets the vertex that is in vector by using the string that was
  * passed in as the parameter. It finds the vertex that has the same string
  * as its name.
  */
Vertex* Graph:: getVertex( std::string s){
   //Loops through the vertex vector until the correct vertex is found.
   for(int i = 0; i < vertex.size(); i++ ){
      if( vertex[i]->name == s ){
	 return vertex[i];
      }
   }
   Vertex* v = new Vertex("");
   return v;
}

/**
  * This method adds the shortest travel time between all the pairs of
  * vertices. Then, it returns the value.
  */
int Graph:: timeSum(){
   totalTime = 0;
   //Goes through all the vertices that are in the graph.
   for(int i = 0; i < vertex.size(); i++){
      //Goes through all the vertices that are connected to the current vertex.
	 totalTime += dijkstra(vertex[i]);
      }
   return totalTime;
}

/**
  * This method finds the shortest path starting from the vertex pointer that 
  * was passed in as startNode to the rest of the vertices
  */
int Graph:: dijkstra(Vertex* startNode){
   //Sets all the distance holders incide the vertices to the biggest int.
   for(int l = 0; l < vertex.size(); l++){
      vertex[l]->dist = INT_MAX;
   }

   priority_queue< pair<Vertex*,int>, vector< pair<Vertex*,int> >, Comp > q;
   Vertex* s = startNode;
   s->dist = 0;
   //Puts the starting node into the priority queue.
   q.push(pair<Vertex*,int>(s,0));
   //Keeps on looping till the priority queue is empty.
   while(!q.empty() ){
      Vertex* v = q.top().first;
      q.pop();
      //This prevents adding distances that have already been added.
      //Prevents from going backwards.
      if(v->done == 0){
	 v->done = 1;
      }
      //This calculates the distance between the nodes.
      for(int i = 0; i < v->adjTime.size(); i++){
	 if(v->adjTime[i].second + v -> dist < v->adjTime[i].first->dist){
	    v->adjTime[i].first->dist = v->dist+v->adjTime[i].second;
            q.push(pair<Vertex*,int>(v->adjTime[i].first, v->adjTime[i].first->dist));
	 }
      }
    }
   int total = 0;
   for(int j = 0; j<vertex.size(); j++){
      total += vertex[j]->dist;
   }
   return total; 
}
/**
  * This method creates a minimum spanning tree using the disjoint class.
  */
int Graph:: Kuruskal(){
   int minDist = 0;

   int ac = 0;

   Disjoint forest = Disjoint(vertex.size());

   Edge* e;

   Vertex* v0;

   Vertex* v1;

   priority_queue<Edge*,vector<Edge*>,Comp2> pq;
   //This puts in all the vertices that are in evec into pq for use.
   for( int i = 0; i < evec.size(); i++){
      pq.push( evec[i] );
   }
   
   //Will keep on looping until the value in ac is equal to
   //the number of elements in vertex.
   while( ac < vertex.size() - 1){
      edg = pq.top();
      pq.pop();
      //Gets the vertices that make up the edge that was taken out of the queue.
      int v0Set = forest.find( edg->v0->index );
      int v1Set = forest.find( edg->v1->index );
      //What to do if the two vertices are different.
      if( v0Set != v1Set){
	 ac++;
	 forest.uni(v0Set,v1Set);
	 minDist += edg->weight;
         //Updates the adjacency list that each of the vertices have for the 
         //minimum spaning tree.
	 edg->v0->minAdjTime.push_back(pair<Vertex*,int>(edg->v1, edg->time));
         edg->v1->minAdjTime.push_back(pair<Vertex*,int>(edg->v0, edg->time));
      }
      
   }
   return minDist;
}

/**
  * This method finds the shortest path in the minimum spanning tree starting
  * from the vertex pointer passed in as startNode to the rest of the vertices.
  */
int Graph:: minDijkstra(Vertex* startNode){
   //Sets all the distance holders in the vertices to the biggest number
   //possible so that the actual distance can be saved.
   for(int l = 0; l < vertex.size(); l++){
      vertex[l]->dist = INT_MAX;
   }

   std::priority_queue< pair<Vertex*,int>, std::vector< pair<Vertex*,int> >, Comp > q;
   Vertex* s = startNode;
   s->dist = 0;
   q.push(pair<Vertex*,int>(s,0));
   //The loop will continue until the priority queue is empty.
   while(!q.empty() ){
      Vertex* v = q.top().first;
      q.pop();
      //What to do if the vertex has been reached for the first time.
      //This will prevent any going backwards.
      if(v->done == 0){
	 v->done = 1;
      }
      //This loops through the adjacency list of the current vertex.
      for(int i = 0; i < v->minAdjTime.size(); i++){
	 //This will calculate the distance and update the vertex that 
	 //is the destination so that it holds the correct distance.
	 if(v->minAdjTime[i].second + v -> dist < v->minAdjTime[i].first->dist){
	    v->minAdjTime[i].first->dist = v->dist+v->minAdjTime[i].second;
            q.push(pair<Vertex*,int>(v->minAdjTime[i].first, v->minAdjTime[i].first->dist));
	 }
      }
   }
   int total = 0;
   for(int j = 0; j<vertex.size(); j++){
      total += vertex[j]->dist;
   }
   return total;
}

/**
  * This method uses the minDijkstra to get the shortest distance between 
  * all the possible pairs in the minimum spanning tree and adds them all
  * together.
  */
int Graph:: minTimeSum(){
   totalTime = 0;
   //This loops through all the vertices in that are part of the graph.
   for(int i = 0; i < vertex.size(); i++){
      totalTime += minDijkstra(vertex[i]);
   }
   return totalTime;
}

