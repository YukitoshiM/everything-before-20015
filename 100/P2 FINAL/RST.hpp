#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "RSTNode.hpp"
#include <iostream> 

using namespace std;

/**
 * Author: Scott Chuong and Yukitoshi Murase 
 * Username: schuong and ymurase
 * File: RST.hpp
 * Description: the class allows user to add data to a random search tree,
 * inheriting BST class
 */

template <typename Data>
class RST : public BST<Data>{
   public:
   /** Given a reference to a Data item, insert a copy of it in this RST.
   *  Return true if the item was added to this RST
   *  as a result of this call to insert.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */
   virtual bool insert(const Data& item)
   {
      // pointers for current and RST node
      RSTNode<Data>* cur;
      RSTNode<Data>* node = new RSTNode<Data>(item);
      
      // add element as root when tree is empty
      if( this->root == 0 )
      {
	 this->root = node;
	 this->isize++;
	 return true;
      }
      
      // set current pointer as root pointer
      cur = (RSTNode<Data>*)this->root;

      
      while( cur->data != item )
      {
	 if( cur->data < item )
	 {
	    // place element on right side of the root/parent & increase size
	    if(cur->right == 0 )
	    {
	       cur->right = node;
	       node->parent = cur;
	       this->isize++;

	       // use AVL rotation to store data into a treaps	     
	       while(node->parent != 0 && 
                  ((RSTNode<Data>*)(node->parent))->priority < node->priority)
	       { 
		  // right child rotation
		  if( node->parent->right == node )
		  {
		     node = 
		     rotateWithRightChild((RSTNode<Data>*)node->parent);	    
		  }
		  // left child rotation
		  else
		  {
		     node = 
		     rotateWithLeftChild((RSTNode<Data>*)node->parent);
		  }
	       }
	       return true;
	    }
	    else
	    {
	       cur = (RSTNode<Data>*)cur->right;
	    }
	 }

	 
	 else if( item < cur->data)
	 {
	    // place element on left side of the root/parent & increase size
	    if( cur->left == 0 )
	    {
	       cur->left = node;
	       node->parent = cur;
	       this->isize++;

	       // use AVL rotation to store data into a treaps
	       while( node->parent != 0 && 
                  ((RSTNode<Data>*)(node->parent))->priority < node->priority)
	       {
		  // right child rotation
		  if( node->parent->right  == node )
		  {  
		     node = 
		     rotateWithRightChild((RSTNode<Data>*)node->parent);    
		  }
		  // left child rotation
		  else
		  {
		     node = 
		     rotateWithLeftChild((RSTNode<Data>*)node->parent);
		  }
	       }
	       return true;
	    }
	    else
	    { 
	       cur = (RSTNode<Data>*)cur->left;
	    }
	 }
      }

      return false;
      
   }

   private:     
   /** 
    * Single AVL Rotation Case 1: insertion in the left subtree of the 
    * left child
    */
   RSTNode<Data>* rotateWithLeftChild(RSTNode<Data>* X) 
   {
      RSTNode<Data>* L = (RSTNode<Data>*)X->left;
      
      // assigning left child parent
      L->parent = X->parent;

      // assigning left child as root
      if( X->parent == 0 )
      {
         this->root = L;
      }
      
      // rotating left child up
      else
      {
         if(L->parent->left == X )
	    L->parent->left = L;
	 else if(L->parent->right == X)
	     L->parent->right =L;
      }

      X->left = L->right;

      if(X->left != 0)
      {
         X->left->parent = X;
      }

      L->right = X;
      X->parent=L;

      return (RSTNode<Data>*)L;
   }

   /** 
    * Single AVL Rotation Case 2: insertion in the right subtree of the 
    * right child
    */
   RSTNode<Data>* rotateWithRightChild(RSTNode<Data>* X)
   {
      RSTNode<Data>* R = (RSTNode<Data>*)X->right;
 
      // assign right child parent
      R->parent = X->parent;

      // assign right child as root
      if(X->parent == 0)
      {
	 this->root = R;
      }

      // rotating right child up
      else
      {
         if(R->parent->left == X )
	    R->parent->left = R;
	 else if(R->parent->right == X)
	    R->parent->right =R;
      }
     
      X->right = R->left;

      if(X->right != 0)
      {
         X->right->parent = X;
      }

      R->left = X;
      X->parent=R;
   
      return (RSTNode<Data>*)R;
   }
};
#endif
