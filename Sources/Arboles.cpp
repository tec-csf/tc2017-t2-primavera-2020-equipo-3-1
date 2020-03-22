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

        /**
         * Performs all the operations needed for the insertion, search and elimination
         * of the number of nodes the user decides to work with in an AVL tree and also with
         * a BTree
         * 
         * @param numberElemets, which represent the number of nodes that the AVL and Btree will work
         * with. For instance, if numberElemets is 1000, the AVL will perform all its operations
         * with 1000 nodes.
         * @param btree, which is a pointer to the BTree to be implemented by this program
         * 
         * @note Inside this method, the function that generates the random numbers to be used
         * for the nodes is contemplated (lines 463 to 470).
         * @note Files with the numbers generated and the times for each insertion, search and elimination
         * operations are also generated by this method. This help as an additional resource to visualize
         * the functionment of both trees.
         * 
         */
        void completeImplementation(int numberElemets, BTree* btree)
        {
          int  possibleNumbers[2070000];
          int i, j, temp;
          srand(time(NULL)); //SYSTEM CLOCK FOR GENERATION OF RANDOM NUMBERS
          for(i = 0; i<2070000; i++)
          {
               possibleNumbers[i] = ((rand() % 10000000) + 1) *(i);
          }
           
          ofstream numbersFile;
          numbersFile.open("Numbers.txt");

          ofstream insertionTimes;
          ofstream searchTimes;
          ofstream eliminationTimes;

          insertionTimes.open("InsertionTimes.txt");
          searchTimes.open("SearchTimes.txt");
          eliminationTimes.open("EliminationTimes.txt");

          insertionTimes<<"0"<<" "<<"0";
          insertionTimes<<'\n';
          searchTimes<<"0"<<" "<<"0";
          searchTimes<<'\n';
          eliminationTimes<<"0"<<" "<<"0";
          eliminationTimes<<'\n';

          for(i = 0; i<numberElemets; i++)
          {  
               auto beginTime = chrono::high_resolution_clock::now();
               node = insertNode(node, possibleNumbers[i]);
               auto endTime = chrono::high_resolution_clock::now();
               auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
               insertionTimes<<i+1<<" "<<duration;
               insertionTimes<<'\n';

               beginTime = chrono::high_resolution_clock::now();
               searchValue(node, possibleNumbers[i]);
               endTime = chrono::high_resolution_clock::now();
               duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
               searchTimes<<i+1<<" "<<duration;
               searchTimes<<'\n';

               numbersFile<<possibleNumbers[i];
               numbersFile<<", ";
               }
               cout<<" "<<endl;
               numbersFile.close();
               insertionTimes.close();
               searchTimes.close();
               
               for(int i=0; i<numberElemets; i++)
               {
                    if(node==NULL)
                    {
                         break;
                    }
                    auto beginTime = chrono::high_resolution_clock::now();
                    node = eliminateNode(node, node->value);
                    auto endTime = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
                    eliminationTimes<<i+1<<" "<<duration;
                    eliminationTimes<<'\n';

               }
               eliminationTimes.close();

               numbersFile.open("NumbersB.txt");

               ofstream insertionTimesB;

               insertionTimesB.open("InsertionTimesB.txt");
               searchTimes.open("SearchTimesB.txt");
               eliminationTimes.open("EliminationTimesB.txt");

               insertionTimesB<<"0"<<" "<<"0";
               insertionTimesB<<'\n';
               searchTimes<<"0"<<" "<<"0";
               searchTimes<<'\n';
               eliminationTimes<<"0"<<" "<<"0";
               eliminationTimes<<'\n';

               for(i = 0; i<numberElemets; i++)
               {
                    auto beginTime = chrono::high_resolution_clock::now();
                    insertNodeb(btree, i);
                    auto endTime = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
                    insertionTimesB<<i+1<<" "<<duration;
                    insertionTimesB<<'\n';

                    beginTime = chrono::high_resolution_clock::now();
                    search(btree, i);
                    endTime = chrono::high_resolution_clock::now();
                    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
                    searchTimes<<i+1<<" "<<duration;
                    searchTimes<<'\n';

                    numbersFile<<possibleNumbers[i];
                    numbersFile<<", ";  
               }

               numbersFile.close();
               insertionTimesB.close();
               searchTimes.close();
               
               for(int i=0; i<numberElemets; i++)
               {
                    auto beginTime = chrono::high_resolution_clock::now();
                    deleteT(btree, i);
                    auto endTime = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count();
                    eliminationTimes<<i+1<<" "<<duration;
                    eliminationTimes<<'\n';
               }
               eliminationTimes.close();
               }
          
};

/**
 * Performs the operation fseek and fread, which allows this program to set a pointer
 * to an specific position of the binary file (which contains the elements of the tree)
 * and then search, insert or eliminate elements, depending on what function is calling
 * this method.
 * 
 * @param tree, is a pointer to th BTree being used by this program.
 * @param valueSeek, is the value to be seeked by the fseek method inside readDisk().
 * @param node, is a pointer to the "node" in which the information is being seeked.
 * 
 * @return int, it may be a -1 (in case an error occurs or the fseek or fread does not
 * finds what it is intended) or 0 when the method is succesful.
 * 
 * @note readDisk may be considered as an auxiliary method for the funcitons to insert, eliminate
 * and search elements inside the Btree.
 * 
 */
int readDisk(BTree* tree, int valueSeek, BtreeNode* node)
{
     if(fseek(tree->file, valueSeek, SEEK_SET)==(-1))
     {
          return -1;
     }
     char *buffer = (char*)calloc(1, sizeof(BtreeNode));
     if(fread(buffer, sizeof(BtreeNode), 1, tree->file)==(-1))
     {
          return -1;
     }
     memcpy(node, buffer, sizeof(BtreeNode));
     return 0;
}

/**
 * Performs the operation fseek and fwrite, which allows this program to set a pointer
 * to an specific position of the binary file (which contains the elements of the tree)
 * and then search and write the parameter "valueSeek".
 * 
 * @param tree, is a pointer to th BTree being used by this program.
 * @param valueSeek, is the value to be introduced by the fwrite method inside writeDisk().
 * @param node, is a pointer to the "node" in which the information is being managed.
 * 
 * @return int, it may be a -1 (in case an error occurs or the fseek or fwrite does not
 * finds what it is intended) or 0 when the method is succesful.
 * 
 * @note writeDisk may be considered as an auxiliary method for the funcitons to insert, eliminate
 * elements and to split nodes inside the Btree.
 * 
 */
int writeDisk(BTree* tree, int valueSeek, BtreeNode* node)
{
     if(fseek(tree->file, valueSeek, SEEK_SET)==(-1))
     {
          return -1;
     }
     if(fwrite((void*)node, sizeof(BtreeNode), 1, tree->file)==(-1))
     {
          return -1;
     }     
     return 0;
}

/**
 * This method allows the program to find the index of the certain node containing
 * an sepecific key. 
 * 
 * @param node, is a pointer to the "node" in which the information is being managed.
 * @param nodeKey, is the key of the element which requieres the finding of its index inside a node.
 * 
 * @return lowValue, highValue or middleValue, which are ints that indicate the position of the
 * elements with a certain key inside an specific node.
 * 
 * @note writeDisk may be considered as an auxiliary method for the funcitons to insert, search and
 * eliminate values.
 * 
 */
int getIndex(BtreeNode* node, int nodeKey)
{
     int lowValue = 0;
     int highValue = node->numberOfKey - 1;
     int middleValue = (lowValue + highValue) / 2;
     while(lowValue<=highValue)
     {
          if(node->nodeKey[middleValue]=nodeKey)
          {
               return middleValue;
          }
          else if(node->nodeKey[middleValue]>nodeKey)
          {
               highValue = middleValue - 1;
          }
          else
          {
               lowValue = middleValue + 1;
          }
          middleValue = (lowValue + highValue) / 2;
     }
     return highValue + 1;
}

/**
 * Performs the operation fseek and ftel, which allows this program to set a pointer
 * at the end of a node or tree for a correct split of nodes and elements when introducing
 * elements with its keys and values.
 * 
 * @param tree, is a pointer to th BTree being used by this program.
 * 
 * @return int, it may be a -1 (in case an error occurs or the fseek does not
 * finds what it is intended) or the actual position of the end pointer of a certain node
 * in the BTree.
 * 
 * @note searchEnd is used in the function split(), which main objective is the separation 
 * of full nodes or roots when introducing elements into the tree 
 * 
 */
int searchEnd(BTree* tree)
{
     if(fseek(tree->file, 0, SEEK_END)==(-1))
     {
          return -1;
     }
     return ftell(tree->file);
}

/**
 * Allocates the memory for a new node inside the tree, but DOES NOT inserts any value
 * or key.
 * 
 * @return BtreeNode, which is a pointer to the newly created node of the BTree. This new node
 * will then be used to have a value and a key inserted into it.
 * 
 * @note No parameters are received by this methid as its main obective is not to introduce any
 * value to the tree but rather to save the neccesary memory for a new node of the BTree. 
 * 
 */
BtreeNode* createNode()
{
     BtreeNode* node = (BtreeNode*)malloc(sizeof(BtreeNode));
     node->ownReference = -1;
     node->nodePointer = -1;

     int i;
     for(i = 0; i<199; i++)
     {
          node->nodeKey[i] = 0;
     }
     for(i = 0; i<199; i++)
     {
          node->seek[i] = -1;
     }

     node->numberOfKey = 0;
     return node;
}

/**
 * Performs a reading inside the binary file and helps in the elimination of nodes
 * if it is found that the node next to another node is empty or with the value -1.
 * 
 * @param tree, is a pointer to th BTree being used by this program.
 * @param node, is a pointer to the "node" in which the information is being managed.
 * @param followingNode, is a pointer to a node next to the parameter node.
 * @param index, which represents the index of an element indside a node of the tree.
 * 
 * @return int, it may be a -1 (in case an error the method readDisk() founds a value considered
 * as error) or 0 when the method is succesful and the following node to the one being analyzed is found.
 * 
 * @note findNext() is a auxilary method used in one of the main methods used for this BTree implementation:
 * eliminateT(), whcih is in charge of eliminating nodes.
 * 
 */
int findNext(BTree* tree, BtreeNode* node, BtreeNode* followingNode, int index)
{
     if(node->seek[0]==(-1))
     {
          return -1;
     }

     if(readDisk(tree, node->seek[index], followingNode)==(-1))
     {
          return -1;
     }
     while(followingNode->seek[0]!=(-1))
     {
          if(readDisk(tree, followingNode->seek[0], followingNode)==(-1))
          {
               return -1;
          }
     }
     return 0;
}

/**
 * Creates a file where the data of the BTree will be introduced (binary) and
 * also allocates the neccesary memory for the actual structure of the tree.
 * 
 * @param file, which is the name of the file to be produced by the BTree.
 * 
 * @return a pointer to a BTree strcuture or NULL in case the file or btree were not created
 * correctly (the writeDisk fuction can fail to work in a correct way).
 * 
 * @note This method is the one of actually starting the whole implementation and creation
 * of a BTree.
 * 
 */
BTree* createBTree(char* file)
{
     FILE* filee = fopen(file, "w+");

     if(filee==NULL)
     {
          return NULL;
     }

     BTree* tree = (BTree*)calloc(1, sizeof(BTree));
     if(tree==NULL)
     {
          return NULL;
     }
    
     tree->file = filee;
     tree->root = createNode();
     tree->root->ownReference = 0;

     if(writeDisk(tree, tree->root->ownReference, tree->root)==(-1))
     {
          return NULL;
     }
     return tree;
}

/**
 * This method is used for the actual search of certian elements inside
 * any BTree generated by this program (given an specific key).
 * 
 * @param tree, which is a pointer to the BTree generated by the function createBTree()
 * @param nodeKey, which represents the key of the element to be searched in the tree
 * 
 * @return a pointer to the Node in which the value being searched is located. If the object
 * is not found, the method returns NULL
 * 
 * @note a pointer to a new node is generated at the beggining of the method to avoid memory
 * allcoation issues.
 *  
 */
BtreeNode* search(BTree* tree, int nodeKey)
{
     BtreeNode* node = (BtreeNode*)calloc(1, sizeof(BtreeNode));
     if(node == NULL)
     {
          return NULL;
     }

     *node = *tree->root;

     int index = getIndex(node, nodeKey);
     while(node->seek[0]!=(-1) && node->nodeKey[index]!=nodeKey)
     {
          if( readDisk(tree, node->seek[index], node)==(-1))
          {
               return NULL;
          }
          index = getIndex(node, nodeKey);
     }

     if(node->nodeKey[index]==nodeKey)
     {
          return node;
     }
     return NULL;
}

/**
 * This method introduces a value, with its respective key, into the Btree.
 * 
 * @param tree, which is a pointer to the BTree generated by the function createBTree()
 * @param nodeKey, which represents the key of the element to be introduced in the tree
 * 
 * @return an int that can be -1 (in case the method is unable to insert the value into the tree)
 * or 0, which indicates that the insertion was generated correctly.
 * 
 * @note a pointer to a new node is generated at the beggining of the method to avoid memory
 * allcoation issues.
 *  
 */
int insertNodeb(BTree* tree, int nodeKey)
{
     BtreeNode* node = (BtreeNode*)calloc(1, sizeof(BtreeNode));

     if(node==NULL)
     {
          return -1;
     }

     *node = *tree->root;
     if(split(tree, node)==(-1))
     {
          return -1;
     }
     int index = getIndex(node, nodeKey);
     while(node->seek[0]!=(-1))
     {
          if(readDisk(tree, node->seek[index], node)==(-1))
          {
               return -1;
          }
          if(split(tree, node)==(-1))
          {
               return -1;
          }
          index = getIndex(node, nodeKey);
     }

     int i;
     for(i = node->numberOfKey; i>index; i--)
     {
          node->nodeKey[i] = node->nodeKey[i - 1];
     }
     node->nodeKey[index] = nodeKey;
     node->numberOfKey++;
     if(writeDisk(tree, node->ownReference, node)==(-1))
     {
          return -1;
     }

     if(tree->root->ownReference==node->ownReference)
     {
          *tree->root = *node;
     }
     return 0;
}

/**
 * This method splits a node/root inside the BTree in case it has reach its maximum capacity.
 * 
 * @param tree, which is a pointer to the BTree generated by the function createBTree()
 * @param node, which is a pointer to the node that might be splitted in case it has no space left
 * for more values.
 * 
 * @return an int that can be -1 (in case the method is unable to split the node due to problems with
 * the read or write disk operations) or 0, which indicates that the node was correclty splitted.
 * 
 * @note a pointer to a new node is generated at the beggining of the method to avoid memory
 * allcoation issues.
 *  
 */
int split(BTree* tree, BtreeNode* node)
{
     if(node->numberOfKey<199)
     {
          return 0;
     }

     BtreeNode* node2 = createNode();

     node2->ownReference = searchEnd(tree);
     int key1 = node->nodeKey[99];

     int i;
     for(i = 100; i<node->numberOfKey; i++)
     {
          node2->nodeKey[i - 100] = node->nodeKey[i];
     }
     if(node->seek[0]!=(-1))
     {
          for(i = 100; i<node->numberOfKey + 1; i++)
          {
               node2->seek[i - 100] = node->seek[i];
               BtreeNode* nodeCh = (BtreeNode*)calloc(1, sizeof(BtreeNode));
               if(nodeCh==NULL)
               {
                    return -1;
               }
               if(readDisk(tree, node->seek[i], nodeCh)==(-1))
               {
                    return -1;
               }
               nodeCh->nodePointer = node2->ownReference;
               if(writeDisk(tree, nodeCh->ownReference, nodeCh)==(-1))
               {
                    return -1;
               }
          }
     }    

     node->numberOfKey = node2->numberOfKey = 99;
     BtreeNode* nodePointer = (BtreeNode*)calloc(1, sizeof(BtreeNode));

     if(nodePointer==NULL)
     {
          return -1;
     }

     if(node->nodePointer==(-1))
     {
          nodePointer = createNode();
          tree->root = nodePointer;
          nodePointer->ownReference = node2->ownReference + sizeof(BtreeNode);
          node->nodePointer = nodePointer->ownReference;
     }
     if(readDisk(tree, node->nodePointer, nodePointer)==(-1))
     {
          return -1;
     }

     int index = getIndex(nodePointer, node->nodeKey[0]);
     for(i = nodePointer->numberOfKey; i>index; i--)
     {
          nodePointer->nodeKey[i] = nodePointer->nodeKey[i - 1];
     }
     nodePointer->nodeKey[i] = key1;

     for(i = nodePointer->numberOfKey + 1; i>index + 1; i--)
     {
          nodePointer->seek[i] = nodePointer->seek[i - 1];
     }
     nodePointer->seek[index] = node->ownReference;
     nodePointer->seek[index + 1] = node2->ownReference;
     nodePointer->numberOfKey++;
     node2->nodePointer = node->nodePointer;

     writeDisk(tree, nodePointer->ownReference, nodePointer);
     writeDisk(tree, node2->ownReference, node2);
     writeDisk(tree, node->ownReference, node);

     if(readDisk(tree, tree->root->ownReference, tree->root)==(-1))
     {
          return -1;
     }

     *node = *nodePointer;
     return 0;
}

/**
 * This method deletes a element of a node (BTree) given an specific node key
 * 
 * @param tree, which is a pointer to the BTree generated by the function createBTree()
 * @param nodeKey, which represents the key of the element to be eliminated from the tree
 * 
 * @return an int that can be -1 (in case the method is unable to eliminate the value from the tree)
 * or 0, which indicates that the deletion was generated correctly.
 * 
 * @note a pointer to a new node is generated at the beggining of the method to avoid memory
 * allcoation issues.
 * @note the methods readDisk and writeDisk are used as the tree has to be updated after the elimination
 * from the tree.
 *  
 */
int deleteT(BTree* tree, int nodeKey)
{
     BtreeNode* node = search(tree, nodeKey);
     if(node==NULL)
     {
          return -1;
     }

     int index = getIndex(node, nodeKey);
     if(node->seek[0]!=(-1))
     {
          BtreeNode* following = createNode();
          if(findNext(tree, node, following, index + 1)==(-1))
          {
               return -1;
          }

          node->nodeKey[index] = following->nodeKey[0];
          if(writeDisk(tree, node->ownReference, node)==(-1))
          {
               return -1;
          }

          if(node->ownReference==tree->root->ownReference)
          {
               *tree->root = *node;    
          }

          node = following;
          index = 0;
     }

     int i;
     for(i = index; i<node->numberOfKey - 1; i++)
     {
          node->nodeKey[i] = node->nodeKey[i + 1];
     }

     node->numberOfKey--;
     writeDisk(tree, node->ownReference, node);
     while(node->numberOfKey<99 && node->ownReference!=tree->root->ownReference)
     {
          BtreeNode* nodePointer = createNode();
          if(readDisk(tree, node->nodePointer, nodePointer)==(-1))
          {
               return -1;
          }

          index = getIndex(nodePointer, node->nodeKey[0]);
          if(nodePointer->numberOfKey==(index + 1) && nodePointer->nodeKey[index]==node->nodeKey[0])
          {
               index++;
          }
          BtreeNode* node2 = createNode();
          if(index==nodePointer->numberOfKey)
          {
               if(readDisk(tree, nodePointer->seek[index - 1], node2)==(-1))
               {
                    return -1;
               }
               if(node2->numberOfKey>99)
               {
                    for(i = node->numberOfKey; i>0; i--)
                    {
                         node->nodeKey[i] = node->nodeKey[i - 1];
                    }
                    for(i = node->numberOfKey + 1; i>0; i--)
                    {
                         node->seek[i] = node->seek[i - 1];
                    }
                    node->nodeKey[0] = nodePointer->nodeKey[nodePointer->numberOfKey - 1];
                    node->seek[0] = node2->seek[node2->numberOfKey];

                    if(node->seek[0]!=(-1))
                    {
                         BtreeNode* nodeCh = createNode();
                         if(readDisk(tree, node2->seek[node2->numberOfKey], nodeCh)==(-1))
                         {
                              return -1;
                         }

                         nodeCh->nodePointer = node->ownReference;
                         if(writeDisk(tree, nodeCh->ownReference, nodeCh)==(-1))
                         {
                              return -1;
                         }

                    }

                    node->numberOfKey++;
                    nodePointer->nodeKey[nodePointer->numberOfKey - 1] = node2->nodeKey[node2->numberOfKey - 1];
                    node2->numberOfKey--;
               }
               else
               {
                    mergeT(tree, node2, node, nodePointer);
               }
          }
          else
          {
               if(readDisk(tree, nodePointer->seek[index + 1], node2)==(-1))
               {
                    return -1;
               }

               if(node2->numberOfKey>99)
               {
                    node->nodeKey[node->numberOfKey] = nodePointer->nodeKey[index];
                    nodePointer->nodeKey[index] = node2->nodeKey[0];
                    node->numberOfKey++;

                    for(i = 0; i<node2->numberOfKey - 1; i++)
                    {
                         node2->nodeKey[i] = node2->nodeKey[i + 1];
                    }
                    node->seek[node->numberOfKey] = node2->seek[0];
                    if(node->seek[node->numberOfKey]!=(-1))
                    {
                         BtreeNode* nodeCh = createNode();
                         if(readDisk(tree, node2->seek[0], nodeCh)==(-1))
                         {
                              return -1;
                         }

                         nodeCh->nodePointer = node->ownReference;
                         if(writeDisk(tree, nodeCh->ownReference, nodeCh)==(-1))
                         {
                              return -1;
                         }
                    }

                    for(i = 0; i<node2->numberOfKey; i++)
                    {
                         node2->seek[i] = node2->seek[i + 1];
                    }
                    node2->numberOfKey--;
               }
               else
               {
                    mergeT(tree, node, node2, nodePointer);
               }
          }

          writeDisk(tree, nodePointer->ownReference, nodePointer);
          writeDisk(tree, node->ownReference, node);
          writeDisk(tree, node2->ownReference, node2);
          
          if(tree->root->ownReference==nodePointer->ownReference)
          {
               *tree->root = *nodePointer;
          }

          *node = *nodePointer;
     }

     if(tree->root->ownReference==node->ownReference)
     {
          *tree->root = *node;
     }

     return 0;
}

/**
 * This method is desgined to join to nodes when reorganizing the tree's order.
 * 
 * @param tree, which is a pointer to the BTree generated by the function createBTree()
 * @param left, pointer to one of the nodes to be merged.
 * @param right, pointer to the second of the nodes to be merged.
 * @param nodePointer pointer to the node whete both nodes will be united.
 * 
 * @return an int that can be -1 (in case the method merge the nodes due to memory issues)
 * or 0, which indicates that the merge was generated correctly.
 * 
 */
int mergeT(BTree* tree, BtreeNode* left, BtreeNode* right, BtreeNode* nodePointer)
{
     int index = getIndex(nodePointer, left->nodeKey[0]);
     int key1 = nodePointer->nodeKey[index];
     int i;

     for(i = index; i<nodePointer->numberOfKey - 1; i++)
     {
          nodePointer->nodeKey[i] = nodePointer->nodeKey[i + 1];
     }
     for(i = index + 1; i<nodePointer->numberOfKey + 1; i++)
     {
          nodePointer->seek[i] = nodePointer->seek[i + 1];
     }
     nodePointer->numberOfKey--;

     left->nodeKey[left->numberOfKey] = key1;
     left->numberOfKey++;
     for(i = 0; i<right->numberOfKey; i++)
     {
          left->nodeKey[i + left->numberOfKey] = right->nodeKey[i];
     }
     if(right->seek[0]!=(-1))
     {
          for(i = 0; i<right->numberOfKey + 1; i++)
          {
               left->seek[i + left->numberOfKey] = right->seek[i];
               BtreeNode* nodeCh = (BtreeNode*)calloc(1, sizeof(BtreeNode));
               if(nodeCh==NULL)
               {
                    return -1;
               }

               if(readDisk(tree, right->seek[i], nodeCh)==(-1))
               {
                    return -1;
               }

               nodeCh->nodePointer = left->ownReference;
               if(writeDisk(tree, nodeCh->ownReference, nodeCh)==(-1))
               {
                    return -1;
               }
               free(nodeCh);
          }
     }

     left->numberOfKey += right->numberOfKey;
     if(tree->root->ownReference==nodePointer->ownReference && nodePointer->numberOfKey==0)
     {
          left->nodePointer = -1;
          *tree->root = *left;
     }

      writeDisk(tree, nodePointer->ownReference, nodePointer);
      writeDisk(tree, left->ownReference, left);
      writeDisk(tree, right->ownReference, right);
     
     return 0;
}

/**
 * Implementation of both trees with method completeImplementation
 * File for BTree is also created with method createBTree()
 * 
 */
int main()
{
    AVLTree <double> tree;
    BTree* btree = createBTree("bTreeFile");
    tree.completeImplementation(10, btree);
    return 0; 
}
