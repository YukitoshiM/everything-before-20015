#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/**
 * Author: Scott Chuong and Yukitoshi Murase 
 * Username: schuong and ymurase
 * File: BSTNode.hpp
 * Description: this class allows users to make a BSTNode to store dat,
 * and nodes to children and parent
 */

template<typename Data>
class BSTNode {

private: 

   BSTNode<Data>* cur;

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
     
     //finding the next bigger data in the tree 
     if( this->right != 0 )
     { 
        cur = this->right;
        while( cur->left != 0 )
        {
           cur = cur->left;
        }
        return cur;
     }
     else if( this->right == 0 )
     {
        cur = this->parent; 
        while(cur != 0 )
        {
           if( this->data < cur->data )
           {
              return cur;
           }
           cur = cur->parent;
        }
        return cur;
     }
     //no bigger data in the tree return false
     return 0;
  }
}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
