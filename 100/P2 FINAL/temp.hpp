#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "RSTNode.hpp"
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream> 

template <typename Data>
class RST : public BST<Data>{

   protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  //RSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  //unsigned int isize;

   BSTNode<Data>* cur;

   public:

      //RST() : root(0), isize(0) {  }



      virtual bool insert(const Data& item){

         RSTNode<Data>* node = new RSTNode<Data>(item);

	 if( this->root == NULL )
	 {
	     this->root = node;
             this->isize++;
             return true;
         }

     //set a current object is the root of the tree
         cur = this->root;

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
	        if(cur->right == NULL )
                 {
                    cur->right = node;
                    node->parent = cur;
                    this->isize++;

                    while( ((RSTNode<Data>*)(node->parent))->priority < node->priority )
                    {
                        if( node->parent->data  < node->data )
			{
                           if(node->parent->parent != NULL )
                           {
			       node->parent = node->parent->parent;
                               if(node->parent->data < node->data)
			          node->parent->right = rotateWithRightChild(node->parent->right);
                               else
                                  node->parent->left = rotateWithRightChild(node->parent->left);
                           }
                           else
                           {
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithRightChild(node->parent);
                              else
                                 node->parent->left = rotateWithRightChild(node->parent);
                           }
			}

                        else
			{
                           if(node->parent->parent != NULL )
                           {
			      node->parent = node->parent->parent;
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithLeftChild(node->parent->right);
                              else
                                 node->parent->left = rotateWithLeftChild(node->parent->left);
                           }
                           else
                           {
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithLeftChild(node->parent);
                              else
                                 node->parent->left = rotateWithLeftChild(node->parent);
                           }
			}
                    }

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
                 if( cur->left == NULL )
                 {
                    cur->left = node;
                    node->parent = cur;
                    this->isize++;

		    while( ((RSTNode<Data>*)(node->parent))->priority < node->priority )
                    {
                        if( node->parent->data  < node->data )
			{
                           if(node->parent->parent != NULL )
                           {
			       node->parent = node->parent->parent;
                               if(node->parent->data < node->data)
			          node->parent->right = rotateWithRightChild(node->parent->right);
                               else
                                  node->parent->left = rotateWithRightChild(node->parent->left);
                           }
                           else
                           {
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithRightChild(node->parent);
                              else
                                 node->parent->left = rotateWithRightChild(node->parent);
                           }
			}

                        else
			{
                           if(node->parent->parent != NULL )
                           {
			      node->parent = node->parent->parent;
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithLeftChild(node->parent->right);
                              else
                                 node->parent->left = rotateWithLeftChild(node->parent->left);
                           }
                           else
                           {
                              if(node->parent->data < node->data)
			         node->parent->right = rotateWithLeftChild(node->parent);
                              else
                                 node->parent->left = rotateWithLeftChild(node->parent);
                           }
			}
                    }

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

   private:       
   //AVL Case 1
   RSTNode<Data>* rotateWithLeftChild(BSTNode<Data>* X) 
   {
      BSTNode<Data>* L = X->left;

      X->left = L->right;
      L->right = X;
      X->parent=L;

      if(X->left != NULL)
      {
         X->left->parent = X;
      }

      return (RSTNode<Data>*)L;
   }

   //AVL Case 4
   RSTNode<Data>* rotateWithRightChild(BSTNode<Data>* X)
   {
      BSTNode<Data>* R = X->right;
      
      X->right = R->left;
      R->left = X;
      X->parent=R;

      if(X->right != NULL)
      {
         X->right->parent = X;
      }
   
      return (RSTNode<Data>*)R;
   }

   //AVL Case 2
   /*BSTNode<Data>* doubleWithLeftChild(BSTNode<Data>* X) 
   {
      X->left = rotateWithRightChild(X->left);
      return rotateWithLeftChild(X);
   }

   //AVL Case 3
   BSTNode<Data>* doubleWithRightChild(BSTNode<Data>* X)
   {
      X->right = rotateWithLeftChild(X->right);
      return rotateWithRightChild(X);
   }*/
};
#endif

