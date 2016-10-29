#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

/**
 * Author: Scott Chuong and Yukitoshi Murase 
 * Username: schuong and ymurase
 * File: BST.hpp
 * Description: this class allows user to add data to a binary search tree
 */

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
     deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  virtual bool insert(const Data& item) {
     //creates a new node object with parameter "item"
     node = new BSTNode<Data>( item );
     
     //if the tree is an empty tree set a new node to a root of the tree
     if( root == 0 )
     {
        root = node;
        isize++;
        return true;
     }

     //set a current object is the root of the tree
     cur = root;

     /*while the data of current object is not same as the parameter 
      *continue the loop
      */
     while( cur->data != item )
     {
        /*if the current data is less than the item get into the
         * if statement,and then else get in the else statement
         */ 
        if( cur->data < item )
        {
           /*if a right child of a current object is none set the new node
            *is right child of it and the node is the perent of current 
            *object. else updatitng the current object to the right chiled 
            *of it.
            */
           if(cur->right == 0 )
           {
              cur->right = node;
              node->parent = cur;
              isize++;
              return true;
           }
           else
           {
              cur = cur->right;
           }
        }
        else if( item < cur->data)
        {
           /*this if and else statement do same thisn as the last one with 
            *a left chld intead of right child
            */
           if( cur->left == 0 )
           {
              cur->left = node;
              node->parent = cur;
              isize++;
              return true;
           }
           else
           { 
              cur = cur->left;
           }
        }
     }
     /*this returns false if the new obj does not match the cases in
      *the while loop which is the tree has a data exactly same as item
      */
     return false;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  iterator find(const Data& item) const {

     //vreates new obj
     BSTNode<Data>* node = new BSTNode<Data>( item );
     BSTNode<Data>* cur;
 
     //if the tree is empty retrun null obj
     if( root == 0 )
     {
        return this->end();
     }
     
     cur = root;

     //in the  find a data same as item from the parameter
     while( cur->data != item )
     {
        if( item < cur->data )
        {
           if( cur->left == 0 )
           {
              return this->end();
           }
           cur = cur->left;
        }
        else if( cur->data < item )
        {
           if( cur->right == 0 )
           {
              return this->end();
           }
           cur = cur->right;
        }
     }
     return typename BST<Data>::iterator(node);
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
     return isize;
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
     if( isize == 0 )
     {
        return 1;
     }
     return 0;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
     return typename BST<Data>::iterator( first(root) );
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  BSTNode<Data>* cur;
  BSTNode<Data>* node;

  /** Recursive inorder traversal 'helper' function */
  void inorder(BSTNode<Data>* n) const {
    if(n==0) return;
    inorder(n->left);
    std::cout << *n << std::endl;
    inorder(n->right);
  }

  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  // do a postorder traversal, deleting nodes
  static void deleteAll(BSTNode<Data>* n) {
    if (0 == n) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }
};
#endif //BST_HPP
