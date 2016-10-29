#ifndef RSTNODE_HPP
#define RSTNODE_HPP
#include "BSTNode.hpp"
#include <cstdlib>

/**
 * Author: Scott Chuong and Yukitoshi Murase 
 * Username: schuong and ymurase
 * File: RSTNode.hpp
 * Description: the class allows user to create a RSTNode inheriting
 * BSTNode class
 */

template <typename Data>
class RSTNode : public BSTNode<Data>{
   public:
      // RSTNode constructor stores BST data and includes priority value	
      RSTNode(Data const & d) :BSTNode<Data>(d){
          //set priority to be a random number 
	  priority = rand();
      }
      int priority;

};
#endif
