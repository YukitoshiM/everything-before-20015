#include "RST.hpp"
#include "BST.hpp"
#include "countint.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include "limits.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

/**
 * Author: Scott Chuong and Yukitoshi Murase 
 * Username: schuong and ymurase
 * File: benchtree.cpp
 * Description: program benchmarks the average number of comparisons for 
 * successful find. Program allows user to input data struture, order,
 * size, and runs
 */	
int main(int argc, char** argv){
   // end program for incorrect arguments
   if(argc != 5) {
      cout<<"Invalid arguments!"<<endl;
      return -1;
   }
   
   // variables to store arguments
   string tree, order;
   int size, runTime;
   tree = argv[1];
   order = argv[2];
   size = atoi(argv[3]);
   runTime = atoi(argv[4]);

   // end program for incorrect options
   if(tree != "rst" && tree != "bst" && tree != "set") {
      cout<<"Invalid tree selection"<<endl;
      return -1;
   }
   if(order != "sorted" && order != "shuffled") {
      cout<<"Invalid order selection"<<endl;
      return -1;
   }
   if(size < 1) {
      cout<<"Invalid size value!"<< endl;
      return -1;
   }
   if(runTime < 1) {
      cout<<"Invalid runTime value!"<< endl;
      return -1;
   }

   // variables for tree and stdev calculation
   vector<countint> v;
   double t;
   double s;
   double stdev;
   double avgcomps;
   double avgcompsTotal;
   double squareAvgTotal;
   int b = 1;
   int a;
      
   // display benchmarking data
   cout << "\n# Benchmarking average number of comparisons for successful"
        << " find" << endl;
   cout << "# Data structure: " + tree << endl;
   cout << "# Data: " + order << endl;
   cout << "# N is powers of 2, minus 1, from 1 to " << size << endl;
   cout << "# Averaging over " << runTime << " runs of each N\n"
        << "#" << endl;
   cout << "# N\t" << "avgcomps\t" << "stdev" << endl;

   // set 6 digits display max
   cout.unsetf(ios::floatfield);
   cout.precision(6);
   
   // run 2^N-1 from 1 to user input size	
   for(int i=1, a=1; i<=size; ++i, ++a) {
      if(a == (pow(2,b) - 1)) {
	 b++;
	 
	 // set width to max 6
	 cout << setw(6) << a << "\t";
	 
	 // RST data structure
	 if(tree == "rst") {
	    // the number of runs on a "N"
	    for(int k=0; k<runTime; ++k) {	       
	       RST<countint> r;
	       
	       // enter data in sorted or shuffled order
	       if(order == "sorted") {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }  
	       }
	       else {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }
		  // shuffle order
		  random_shuffle(v.begin(), v.end()); 
	       }

	       // store data in iterator
	       vector<countint>::iterator vit = v.begin();
	       vector<countint>::iterator ven = v.end();
      
	       // insert data
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.insert(*vit);      
	       }
	       
	       // find data
	       countint::clearcount();
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.find(*vit);  
	       }

	       // calculate average comparisons, avg comp square and overall
	       avgcomps = countint::getcount()/(double)a;
	       avgcompsTotal += avgcomps;
	       squareAvgTotal += (avgcomps*avgcomps);      
	    }
	    
	    // calculate stdev
	    t = avgcompsTotal / runTime;
	    s = squareAvgTotal / runTime;
	    stdev = sqrt(abs(s - (t*t)));
      
	    // display overall average comparisons and standard deviation
	    cout << t << "\t";
	    cout << "\t" << stdev << endl;

	    avgcompsTotal = 0;
	    squareAvgTotal = 0;
	 }
	 
	 // BST data structure
	 else if(tree == "bst") {
	    // the number of runs on a "N"
	    for(int k=0; k<runTime; ++k) {	       
	       BST<countint> r;
	       
	       // enter data in sorted or shuffled order
	       if(order == "sorted") {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }  
	       }
	       else {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }
		  // shuffle order
		  random_shuffle(v.begin(), v.end()); 
	       }

	       // store data in iterator
	       vector<countint>::iterator vit = v.begin();
	       vector<countint>::iterator ven = v.end();
      
	       // insert data
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.insert(*vit);      
	       }
	       
	       // find data
	       countint::clearcount();
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.find(*vit);  
	       }

	       // calculate average comparisons, avg comp square and overall
	       avgcomps = countint::getcount()/(double)a;
	       avgcompsTotal += avgcomps;
	       squareAvgTotal += (avgcomps*avgcomps);      
	    }
	    
	    // calculate standard deviation
	    t = avgcompsTotal / runTime;
	    s = squareAvgTotal / runTime;
	    stdev = sqrt(abs(s - (t*t)));
      
	    // display overall average comparisons and standard deviation
	    cout << t << "\t";
	    cout << "\t" << stdev << endl;

	    avgcompsTotal = 0;
	    squareAvgTotal = 0;
	 }
	 
	 // Set data structure
	 else {	    
	    // the number of runs on a "N"
	    for(int k=0; k<runTime; ++k) {	       
	       set<countint> r;
	       
	       // enter data in sorted or shuffled order
	       if(order == "sorted") {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }  
	       }
	       else {
		  v.clear();
		  for(int j=0; j<a; ++j) {
		     v.push_back(j);	 
		  }
		  // shuffle order
		  random_shuffle(v.begin(), v.end()); 
	       }

	       // store data in iterator
	       vector<countint>::iterator vit = v.begin();
	       vector<countint>::iterator ven = v.end();
      
	       // insert data
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.insert(*vit);      
	       }
	       
	       // find data
	       countint::clearcount();
	       for(vit = v.begin(); vit != ven; ++vit) {
		  r.find(*vit);  
	       }

	       // calculate average comparisons, avg comp square and overall
	       avgcomps = countint::getcount()/(double)a;
	       avgcompsTotal += avgcomps;
	       squareAvgTotal += (avgcomps*avgcomps);      
	    }
	    
	    // calculate standard deviation
	    t = avgcompsTotal / runTime;
	    s = squareAvgTotal / runTime;
	    stdev = sqrt(abs(s - (t*t)));
      
	    // display overall average comparisons and standard deviation
	    cout << t << "\t";
	    cout << "\t" << stdev << endl;

	    avgcompsTotal = 0;
	    squareAvgTotal = 0;
	 }
      }      
   }        
return 0; 
}
