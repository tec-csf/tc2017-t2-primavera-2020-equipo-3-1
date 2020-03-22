// -*- lsst-c++ -*-

/*
 * This file is part of tc2017-t2-primavera-2020-equipo-3-1
 *
 * Developed for Algorithms Design and Analysis Class.
 * See the README file at the repository's root for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, 
 *
 * This program is distributed in the hope that it will help
 * this team to develop its coding habilities regarding AVL and B trees
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <chrono>
#include <malloc.h>
#include <string.h>
#include "BtreeAux.cpp"

using namespace std;

/**
 * Used for the representation of the data to be introduced and used
 * in both, the AVL and the B tree
 * 
 * @tparam V for the type ofa data to be introduced in the trees
 * 
 */
template <class V>

/**
 * Implementation of AVLTree class to perform the insertion, search and
 * delete from a number of elements determined by the final user.
 * 
 * Differents principal methods (eliminateNode, insertNode, and searchValue)
 * use auxiliary methods and functions like cretaNewNode, leftRoration and 
 * rightRotation to perform what has been asked in the Homework.
 * 
 * The method completeImplementation joins all the methods into one so
 * the main() function for this program is neat and simple.
 * 
 */
class AVLTree
{
    /**
     * AVLNode will be be basis for the AVLTRee implementation. This class
     * possess all the atributes (value, depth and 2 pointers to other nodes)
     * needed for any node to be introduced in the AVLTree.
     * 
     */
    class AVLNode
    {
        public:
            V value;
            int depth; //Used to know if certain rotation is needed.
            AVLNode *leftNode;
            AVLNode *rightNode;
    };
    public:
        AVLNode* node = NULL;

        /**
         * Creates a new node to then be introduced in the AVLTree with the
         * help of other functions
         * 
         * @param value represents the number or element to be introduced as the 
         * value/nodeKey of each node of the tree.
         * 
         * @return newNode, which is the pointer of an AVLNode variable. This will 
         * be used by the insertNode function to build the AVLTree.
         *
         * @note Any new node is created with a depth of 1 and subsequently modified as
         * it is moved and introduced inside the AVLTree.
         * 
         */ 
        AVLNode* cretaNewNode(V value)
        {
            AVLNode* newNode = new AVLNode();
            newNode->value = value;
            newNode->depth = 1;
            newNode->rightNode = NULL;
            newNode->leftNode = NULL;

            return newNode;
        }

        /**
         * leftRotation is in charge of performing simple Rorations to the left in case
         * it is needed if the AVL gets unbalanced by an insertion or elimination. Multiple 
         * pointers are moved inside this function so the tree's balancing can be performed adequately.
         * 
         * @param nodeToBeRotated, which is a pointer to the node that will suffer the roration
         * to the left.
         * 
         * @return NodeRight, which is a pointer of the node that becomes the new root of the sub-tree
         * that resulted of the roration to the left perfomed by this method.
         * 
         * @note The depts of all nodes involved in this method are recalculated so no innecessary rotations
         * have to be performed.
         * 
         */ 
        AVLNode* leftRotation(AVLNode *nodeToBeRotated)
        {
            AVLNode* NodeRight = nodeToBeRotated->rightNode;
            AVLNode* NodeLeft = NodeRight->leftNode;

            NodeRight->leftNode = nodeToBeRotated;
            nodeToBeRotated->rightNode = NodeLeft;

            nodeToBeRotated->depth = getMaxHeight(depthNode(nodeToBeRotated->leftNode),depthNode(nodeToBeRotated->rightNode)) + 1;
            NodeRight->depth = getMaxHeight(depthNode(NodeRight->leftNode),depthNode(NodeRight->rightNode)) + 1;
           
            return NodeRight;
        }

        /**
         * rightRotation is in charge of performing simple Rorations to the right in case
         * it is needed if the AVL gets unbalanced by an insertion or elimination. Multiple 
         * pointers are moved inside this function so the tree's balancing can be performed adequately.
         * 
         * @param nodeToBeRotated, which is a pointer to the node that will suffer the roration
         * to the right.
         * 
         * @return NodeRight, which is a pointer of the node that becomes the new root of the sub-tree
         * that resulted of the roration to the right perfomed by this method.
         * 
         * @note The depts of all nodes involved in this method are recalculated so no innecessary rotations
         * have to be performed.
         * 
         */
        AVLNode* rightRotation(AVLNode *nodeToBeRotated)
        {
           
            AVLNode* NodeRight = nodeToBeRotated->leftNode;
            AVLNode* NodeLeft = NodeRight->rightNode;

            NodeRight->rightNode = nodeToBeRotated;
            nodeToBeRotated->leftNode = NodeLeft;

            nodeToBeRotated->depth = getMaxHeight(depthNode(nodeToBeRotated->leftNode), depthNode(nodeToBeRotated->rightNode)) + 1;
            NodeRight->depth = getMaxHeight(depthNode(NodeRight->leftNode),depthNode(NodeRight->rightNode)) + 1;
           
            return NodeRight;
        }  

        /**
         *insertNode is responsible of introducing every single node to be part of the AVLTree 
         generated by this program. It is worth mentioning that it works as a recursive funtion, as
         it constantly checks if the node has reached the ideal postion to be introduced and also
         manages the balancing factors of the nodes in the tree.
         * 
         * @param nodeToBeIntroduced, which is a pointer to the node to be introduced by this method.
         * @param value, a generic element that serves as the nodeKey/value of the node to be inserted into
         * the AVLTree.
         * 
         * @return Multiple returns are possible with this method:
         *  1) cretaNewNode(value) in case the nodeToBeIntroduced is empty.
         *  2) nodetoBeIntroduced in case the node is ready to be introduced and the tree is balanced.
         *  3) rightRotation(nodeToBeIntroduced) in case a right roration is needed for balance.
         *  4) leftRotation(nodeToBeIntroduced) in case a left roration is needed for balance.
         * 
         * @note insertNode contemplates the 4 possible rotations inside an AVL tree by implementing
         * the leftRotation and rightRotation methods in different manners.
         * 
         */
        AVLNode* insertNode(AVLNode* nodeToBeIntroduced, V value)
        {
            if(nodeToBeIntroduced==NULL)
            {
                return cretaNewNode(value);
            }
            if(value>nodeToBeIntroduced->value)
            {
                nodeToBeIntroduced->rightNode = insertNode(nodeToBeIntroduced->rightNode, value);
            }
            else if(value<nodeToBeIntroduced->value)
            {
                nodeToBeIntroduced->leftNode = insertNode(nodeToBeIntroduced->leftNode, value);
            }
            else
            {
                return nodeToBeIntroduced;
            }

            nodeToBeIntroduced->depth = getMaxHeight(depthNode(nodeToBeIntroduced->leftNode),depthNode(nodeToBeIntroduced->rightNode)) + 1;

            int balancingFactorNumber = balancingFactor(nodeToBeIntroduced);
           
            if(balancingFactorNumber>1 && value>nodeToBeIntroduced->leftNode->value)
            {
                nodeToBeIntroduced->leftNode = leftRotation(nodeToBeIntroduced->leftNode);
                return rightRotation(nodeToBeIntroduced);
            }
            if(balancingFactorNumber<(-1) && value<nodeToBeIntroduced->rightNode->value)
            {
                nodeToBeIntroduced->rightNode = rightRotation(nodeToBeIntroduced->rightNode);
                return leftRotation(nodeToBeIntroduced);
            }
            if(balancingFactorNumber>1 && value<nodeToBeIntroduced->leftNode->value)
            {
                return rightRotation(nodeToBeIntroduced);
            }
            if(balancingFactorNumber<(-1) && value>nodeToBeIntroduced->rightNode->value)
            {
                return leftRotation(nodeToBeIntroduced);
            }
            return nodeToBeIntroduced;
        }

        /**
         *eliminateNode is responsible of eliminating every single node that is part of the AVLTree 
         generated by this program. It is worth mentioning that it works as a recursive funtion, as
         it constantly checks if the node can be safely eliminated without losing connection with other 
         nodes and also manages the balancing factors of the remaining nodes in the tree.
         * 
         * @param survivingRoot, which is a pointer to the node to be eliminated by the eliminateNode method.
         * @param value, a generic element that serves as the nodeKey/value of the node to be eliminated 
         * from the AVLTree.
         * 
         * @return Multiple returns are possible with this method:
         *  1) survivingRoot in case the node to be ELIMINATED is empty.
         *  2) rightRotation(nodeToBeIntroduced) in case a right roration is needed for balance.
         *  3) leftRotation(nodeToBeIntroduced) in case a left roration is needed for balance.
         * 
         * @note eliminateNode contemplates the 4 possible rotations inside an AVL tree by implementing
         * the leftRotation and rightRotation methods in different manners.
         * 
         */
        AVLNode* eliminateNode(AVLNode* survivingRoot, V value)
        {
            if(survivingRoot==NULL)
            {
                return survivingRoot;
            }
            if(value>survivingRoot->value)
            {
                survivingRoot->rightNode = eliminateNode(survivingRoot->rightNode, value);
            }
            else if(value<survivingRoot->value)
            {
                survivingRoot->leftNode = eliminateNode(survivingRoot->leftNode, value);
            }
            else
            {
                if((survivingRoot->rightNode==NULL)||(survivingRoot->leftNode==NULL))
                {
                    AVLNode* temp;
                    if(survivingRoot->leftNode)
                    {
                        temp = survivingRoot->leftNode;
                    }
                    else
                    {
                        temp = survivingRoot->rightNode;
                    }

                    if(temp==NULL)
                    {
                        temp = survivingRoot;
                        survivingRoot = NULL;
                    }
                    else
                    {
                        *survivingRoot = *temp;
                    }
                    free(temp);
                }  
                else
                {
                    AVLNode* temp = nodeMinimum(survivingRoot->rightNode);
                    survivingRoot->value = temp->value;
                    survivingRoot->rightNode = eliminateNode(survivingRoot->rightNode, temp->value);
                }
            }
            if(survivingRoot==NULL)
            {
                return survivingRoot;
            }
            survivingRoot->depth = getMaxHeight(depthNode(survivingRoot->leftNode),depthNode(survivingRoot->rightNode)) + 1;

            int tempBalance = balancingFactor(survivingRoot);

            if(tempBalance>1 && balancingFactor(survivingRoot->leftNode)<0)
            {
                survivingRoot->leftNode = leftRotation(survivingRoot->leftNode);
                return rightRotation(survivingRoot);
            }
            if(tempBalance>1 && balancingFactor(survivingRoot->leftNode)>=0)
            {
                return rightRotation(survivingRoot);
            }
            if(tempBalance<(-1) && balancingFactor(survivingRoot->rightNode)>0)
            {
                survivingRoot->rightNode = rightRotation(survivingRoot->rightNode);
                return leftRotation(survivingRoot);
            }
            if(tempBalance<(-1) && balancingFactor(survivingRoot->rightNode)<=0)
            {
                return leftRotation(survivingRoot);
            }
            return survivingRoot;
        }
       
       /**
         * Gets the maximun height of two nodes so at the moment of performing 
         * rotations (either to the left or right), the node's height is upgraded.
         * 
         * @param height1 represents the height of the first node to be compared.
         * @param height2 represents the height of the second node to be compared.
         * 
         * @return either heigth1 or height2; the largest of the heights is returned
         *
         * @note Any time a rotation is performed, this method is used.
         * 
         */
        int getMaxHeight(int height1, int height2)
        {
            if(height1>height2)
            {
                return height1;
            }
            return height2;
        }

        /**
         * Gets the node with the smallest value/nodeKey of all the tree.
         * 
         * @param nodeBeingAnalyzed is a pointer to the node which is being checked
         * to identify if it is the one with the smallest value in all the tree.
         * 
         * @return nodeBeingAnalyzed, which is the node that up to certain point, has
         * being identifies as the one with the smallest value in all the AVL tree.
         *
         * @note This method is employed to facilitate the elimination method.
         * 
         */
        AVLNode* nodeMinimum(AVLNode* nodeBeingAnalyzed)
        {
            AVLNode* temp = nodeBeingAnalyzed;

            while(nodeBeingAnalyzed->leftNode!=NULL)
            {
                nodeBeingAnalyzed = nodeBeingAnalyzed->leftNode;
            }
            return nodeBeingAnalyzed;
        }

        /**
         * Gets the depth/height of the node introduced to the function as a parameter.
         * 
         * @param nodeToBeAnalyzed is a pointer to the node which is being checked
         * to then obtain its depth.
         * 
         * @return can be either the depth of the node in the form of nodeToBeAnalyzed->depth or
         * 0 if the node has no other adacent or connected to any other.
         * 
         * @note This method is employed whenever a rotation is performed inside the AVL tree or
         * when the balancing factor of any node is updated.
         * 
         */
        int depthNode(AVLNode* nodeToBeAnalyzed)
        {
            if(nodeToBeAnalyzed!=NULL)
            {
                return nodeToBeAnalyzed->depth;
            }
            else
            {
                return 0;
            }    
        }
        
        /**
         * Gets the balancing factor of the node introduced to the function as a parameter.
         * 
         * @param nodeToBeAnalyzed is a pointer to the node which is being checked
         * to then obtain its balancing factor.
         * 
         * @return can be either the balancing factor of the node in the form of 
         * depthNode(nodeToBeAnalyzed->leftNode)-depthNode(nodeToBeAnalyzed->rightNode)
         * or 0 if the node is empty and is not part of any sub-tree inside the AVL tree.
         * 
         * @note This method is employed whenever a rotation is performed inside the AVL tree or
         * when the balancing factor of any node is updated.
         * 
         */
        int balancingFactor(AVLNode *nodeToBeAnalyzed)
        {
            if(nodeToBeAnalyzed!=NULL)
            {
                return (depthNode(nodeToBeAnalyzed->leftNode)-depthNode(nodeToBeAnalyzed->rightNode));
                return 0;
            }
            else
            {
                return 0;
            }
        }

        /**
         * Searches for the node required by the user. This method searches the node
         * according to the desired value to be found.
         * 
         * @param root is a pointer to the node in which the value introduced by
         * the user will be search
         * @param value represents the number or element to be introduced as the 
         * value/nodeKey of the node to be searched.
         * 
         * @note This method is applied to any node entering the tree in the completeImplementation
         * method found below in this code. If the element is not found, the program will print a 
         * message indicating the failure of the search of that value.
         * 
         */
        void searchValue(AVLNode* root, V value)
        {
           if(root!=NULL)  
            {  
               if(root->value==value)
               {

               }
               else if(root->value>value)
               {
                   searchValue(root->leftNode,value);
               }
               else if(root->value<value)
               {
                    searchValue(root->rightNode,value);
               }
            }  
            else if(root==NULL)
            {
                cout<<"No encontrado"<<endl;
            }
        }
