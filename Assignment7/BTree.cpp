//Q1. Write a C++ functions to implement functions: insertNonFull and splitChild which are
//helper functions in insert function in B-Tree
//  main.cpp
//  Assign7
//
//  Created by Anton David Guaman Davila on 2022-07-08.
//

// Searching a key on a B-tree in C++

#include <iostream>

using namespace std;

class Btreenode {
      int *keys;
    //Variable of minimum number of keys
      int min_number_keys;
    //Array of child pointers of a node
      Btreenode **ChildPtrs;
    //Present value of keys in a node
      int num_keys;
    //Variable that stores the statues of a node wether it is a leaf or not
    //The variable is true when it is a leave
      bool leaf;

   public:
    //Constructor of Node
    Btreenode(int min_degree_para, bool leaf_state){
        //Pass Parameters of node
        min_number_keys = min_degree_para;
        leaf = leaf_state;
        //Allocate memory for ChildPtrs and max number of keys
        keys = new int[2 * min_number_keys - 1];
        ChildPtrs = new Btreenode * [2 * min_number_keys];
        //Initialize current number of keys to 0
        num_keys = 0;
    }
    //Helper function that aids with the insert process of B - tree when the Node is not Full
    void insertNonFull(int new_key) {
    //Initialize the key index i to the last index of the node (rightmost key)
      int i = num_keys - 1;
    //Address scenario if the node is a leaf
      if (leaf == true) {
        //If the new_key wanting to be inserted is less than the keys in the node keep traversing
        //Shift the current keys in the node to the right by one
        //The i >= 0 condition verifies if the keys array of the node has been traversed
        while (i >= 0 && keys[i] > new_key) {
        //Move greater keys by one
          keys[i + 1] = keys[i];
        //Decrease the index
          i--;
        }
        //Insert the key at the location found during the traverse of the while loop preformed previously
        keys[i + 1] = new_key;
        //Increment the amount of keys by one
        num_keys = num_keys + 1;
      }
    //Address scenario where the node is not a leaf
      else {
        //Determine which childe of the node will have the new_key
        //The index for the ChildPtrs of the current node will be determined
        //If the new_key wanting to be inserted is less than the keys in the node
        //The i >= 0 condition verifies if the keys array of the node has been traversed
        while (i >= 0 && keys[i] > new_key)
          i--;
          //Address scenario where the child that will store the new_key is full
          if (ChildPtrs[i + 1]->num_keys == 2 * min_number_keys - 1) {
        //Utilize the splitChild function to split the full node
          splitChild(i + 1, ChildPtrs[i + 1]);
        //After splitChild is executed two new nodes are generated
        //The following will determine which of the new nodes will the new_key be inserted
          if (keys[i + 1] < new_key)
            i++;
        }
        //After determininig the index for the ChildPtrs of where the new_key should be inserted
        //Call the inserNonFull to finally insert the new_key in the corresponding place
        ChildPtrs[i + 1]->insertNonFull(new_key);
      }
    }
    //Helper function that aids with the insert process of B - tree when Node is Full
    void splitChild(int i, Btreenode *y) {
        //Create new node that copies the information of the parameter node y passed in.
        Btreenode *CopyNode = new Btreenode(y->min_number_keys, y->leaf);
        CopyNode-> num_keys = min_number_keys - 1;
        //Copy the last (t-1) keys array of y and insert it to keys array of the CopyNode
        //Hence this is the reason for the condition to iterate for j < min_number_keys
        for (int j = 0; j < min_number_keys - 1; j++){
            CopyNode->keys[j] = y->keys[j + min_number_keys];
        }
        //Address the scenario if the Node passed as a parameter is not a Leaf copy the ChildPtrs array
        //to the ChildPtrs of the new array CopyNode
        //Hence, when the root is full
      if (y->leaf == false) {
        for (int j = 0; j < min_number_keys; j++)
            //Manage the childpointers of the CopyNode
            CopyNode->ChildPtrs[j] = y->ChildPtrs[j + min_number_keys];
      }
        //Reduce the number of keys in the node y passed as a parameter due to transfering a number key in the previous lines
        y->num_keys = min_number_keys - 1;
        //Create a space in the ChildPtrs array for the new child that is generated
      for (int j = num_keys; j >= i + 1; j--)
        ChildPtrs[j + 1] = ChildPtrs[j];
    //Make the parameter passed y next child pointer to the new CopyNode generated
      ChildPtrs[i + 1] = CopyNode;
        // A key of the node parameter passed y will move to this node.
        //Additionally it will Find the location of the new_key and move all greater keys one space ahead
        for (int j = num_keys - 1; j >= i; j--){
            keys[j + 1] = keys[j];
        }
        //Pop the middle key of the node parameter passed y into this node
        keys[i] = y->keys[min_number_keys - 1];
    //Increment the amount of keys in the node
      num_keys = num_keys + 1;
    }
  friend class BTree;
};

class BTree {
    //Variable the is the root of the tree
  Btreenode *root;
    //Variable of the minimum degree of the tree
  int min_degree_tree;
   public:
    //Constructor for the Btree
  BTree(int temp) {
      //Initialize the root to null
    root = NULL;
      //Initialize min degree of the the tree
    min_degree_tree = temp;
  }
    void insert(int new_key){
    //Address scenario were the root node is empty
      if (root == NULL) {
          //Make the new node equal the root node
        root = new Btreenode(min_degree_tree, true);
          //Add the new_key at index 0 of the array of keys
        root->keys[0] = new_key;
          //Increment the current amount of keys to 1
        root->num_keys = 1;
      }
    //Address scenerio were the root node is not empty
      else {
        //Check if the root number of keys is full.
        //If condition is true the tree will grow in height
        if (root->num_keys == 2 * min_degree_tree - 1) {
          Btreenode *NEWNodeTreeGrow = new Btreenode(min_degree_tree, false);
        //Make the NEWNode Child pointers to the root. The root becomes a child of the NEWNode
          NEWNodeTreeGrow->ChildPtrs[0] = root;
        //Call helper function splitChild for management of insertion
        //Pass two parameters the root which is going to be split
          NEWNodeTreeGrow->splitChild(0, root);
        //Once returing from split Child determine which child will have the new_key
          int i = 0;
          if (NEWNodeTreeGrow->keys[0] < new_key)
            i++;
          NEWNodeTreeGrow->ChildPtrs[i]->insertNonFull(new_key);
        //Update to the new root
            root = NEWNodeTreeGrow;
        }
        //Otherwise if root is not full just insert directly to the root node
        else{
            root->insertNonFull(new_key);
        }
      }
    }
};

int main() {
    //Btree of minimum degree 2
  BTree t(2);
    //Inserting 1
  t.insert(1);
    //Inserting 14
  t.insert(14);
    //Inserting 49
  t.insert(49);
    //Inserting 13
  t.insert(13);
    //Inserting 15
  t.insert(0);
    //Inserting 91
  t.insert(91);
}
