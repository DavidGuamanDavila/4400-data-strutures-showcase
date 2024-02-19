//  Assignment 3 Single Linked List main.cpp
// Q1. Write C++ program to reverse the order of a singly linked list
//  • Function name : reverseLinkedList(headnode * node)
//  • Write Main function to test your code
//  Created by Anton David Guaman Davila on 2022-05-27.
#include <iostream>

using namespace std;

// Node Class Begins
template < typename T >
  class Node {
    public:
      // Creation of data
      T data;
    // Creation of pointer next
    Node < T > * next;
    Node(T new_data) {
      // Creation of data
      this -> data = new_data;
    }
  };
// Node Class Ends

// Singly Linked List Class Begins
template < typename T >
  class SLL {
    public:
      // Declare head node and set it to NULL
      Node < T > * head_ref;
    // Constructor
    SLL() {
      head_ref = NULL;
    }

    // Funciton that traverses the SLL and prints the data
    void printSLL() {
      // Temporary variable that holds the head reference
      Node < T > * temp = head_ref;

      while (temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> next;
      }
    }
    // Function that inserts elements in the front of the SLL
    void pushSLL(T new_data) {
      // Allocate new node
      Node < T > * new_node = new Node(new_data);
      // Address scenario if the SLL is empty
      if (head_ref == NULL) {
        // Set new node next to head reference
        new_node -> next = head_ref;
        // Set the head reference to the new node
        head_ref = new_node;
      }
      // Address scenario in which SSL has nodes already created
      else {
        // Set new node next to head reference
        new_node -> next = head_ref;
        // Set the head reference to the new node
        head_ref = new_node;
      }
    }
    void endSLL(T new_data) {
      Node < T > * new_node = new Node(new_data);
      Node < T > * last = head_ref;
      // Set next of last node to NULL
      new_node -> next = NULL;
      // Address scenario if the SLL is empty
      if (head_ref == NULL) {
        head_ref = new_node;
        return;
      }
      // Address scenario where there are nodes existing with SLL
      while (last -> next != NULL) {
        // Update traversal
        last = last -> next;
      }
      last -> next = new_node;
      return;
    }
    // Function that deletes a node
    void deleteNode(T key) {
      Node < T > * temp = head_ref;
      // Stores the node previous to the temp node
      Node < T > * prev = NULL;
      // Address situation if head node is going to be deleted
      if (temp != NULL && temp -> data == key) {
        head_ref = temp -> next;
        delete temp;
        return;
      }
      // Address situation where the node to be deleted is not the head node
      else {
        while (temp != NULL && temp -> data != key) {
          prev = temp;
          // Traverse through SLL
          temp = temp -> next;
        }
      }
      // Address situation where the key is not within the SLL
      if (temp == NULL) {
        cout << "The key is not inside the SLL" << endl;
        return;
      }
      // Update nodes
      prev -> next = temp -> next;
      // Free memory
      delete temp;
    }

    // Function that reverses the order of the SLL
    void reverseSLL() {
        // Creation of pointer to the current node
        Node < T > * current = head_ref;
        // Creation of pointer to the previous node with respect to current node
        Node < T > * prev = NULL;
        // Creation of pointer to the next node with respect to current node
        Node < T > * next = NULL;
        // Loop that runs until the current node is NULL
        while (current != NULL) {
          // Store the next value
          next = current -> next;
          // Shift direction of current node
          current -> next = prev;
          // Update pointers to move through the SLL
          prev = current;
          current = next; // Use the saved next
        }
        // Set the head reference to previous instead of current to prevent head
        // reference to become NULL
        head_ref = prev;
      }
      // Destructor
      ~SLL() {
        Node < T > * temp = head_ref;
        // Stores the node previous to the temp node
        Node < T > * prev = NULL;
        while (temp != NULL) {
          prev = temp;
          // Traverse through SLL
          temp = temp -> next;
          delete prev;
        }
      }
  };

// Test Main Function

int main() {
  SLL < int > First;
  // First Test
  cout << "First Test type int" << endl;
  cout << " " << endl;
  First.pushSLL(10);
  First.endSLL(111);
  First.endSLL(2121);
  First.endSLL(112131);
  First.endSLL(9132);
  First.pushSLL(15614);
  First.deleteNode(10);
  cout << "SLL before reverse " << endl;
  First.printSLL();
  cout << " " << endl;
  // Test reverse the order of SLL with integers
  First.reverseSLL();
  cout << "SLL after reverse " << endl;
  First.printSLL();
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;

  // Second Test
  cout << "Second Test type float " << endl;
  cout << " " << endl;
  SLL < float > Second;
  Second.endSLL(10.121);
  Second.pushSLL(1112.90);
  Second.pushSLL(0.1381);
  Second.endSLL(111131.131);
  Second.endSLL(0.25);
  Second.deleteNode(0.1381);
  cout << "SLL before reverse " << endl;
  Second.printSLL();
  cout << " " << endl;
  // Test reverse the order of SLL with integers
  Second.reverseSLL();
  cout << "SLL after reverse " << endl;
  Second.printSLL();
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
}
