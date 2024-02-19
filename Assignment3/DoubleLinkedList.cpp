//  Assignment 3 Double Linked List main.cpp
// Q2. Write C++ function to delete a node from double linked list
//• You have to write the main function test the function
//  Created by Anton David Guaman Davila on 2022-05-27.

#include <iostream>

using namespace std;

// Node Class Begins
template < typename T >
  class Node {
    public:
      // Creation of data
      T data;
    // Creation of pointer to next node
    Node < T > * next;
    // Creation of pointer to previous node
    Node < T > * prev;

    Node(T new_data) {
      this -> data = new_data;
      next = NULL;
      prev = NULL;
    }
  };
// Node Class Ends

// Double Linked List Class Begins
template < typename T >
  class DLL {
    public:
      Node < T > * head_ref;
    // Constructor
    DLL() {
      head_ref = NULL;
    }
    // Function to print the DLL elements
    void printDLL() {
      Node < T > * temp = head_ref;

      if (head_ref == NULL) {
        cout << "List is empty!" << endl;
      } else {
        while (temp != NULL) {
          cout << temp -> data << ", ";
          temp = temp -> next;
        }
      }
    }
    // Function that inserts data to the begining of the DLL and returns a node
    // The function returns a node to facilitate deleting nodes
    Node < T > * pushDLL(T new_data) {
      Node < T > * new_node = new Node(new_data);
      if (head_ref == NULL) {
        // Make the new node next equal to the head reference
        new_node -> next = head_ref;
        // Make the head reference equal the new node
        head_ref = new_node;
        // Make the previous of the new node equal to NULL
        new_node -> prev = NULL;
      } else {
        // Make the new node next equal the head reference
        new_node -> next = head_ref;
        // Make the previous of head reference to the new node
        head_ref -> prev = new_node;
        // Make head reference point to the new node
        head_ref = new_node;
        // Make the previous node of the new_node point to NULL
        new_node -> prev = NULL;
      }
      return new_node;
    }
    // Function to delete nodes of the DLL adapted from Pesudo Code given in the
    // slides (Lecture 7 pg 16)
    void deleteNodepseudoDLL(Node < T > * nodedelete) {
      // Check if DLL is empty
      if (head_ref == NULL || nodedelete == NULL) {
        if (nodedelete == NULL && head_ref != NULL) {
          cout << "Nothing was deleted." << endl;
        } else {
          cout << "Nothing to be deleted. DLL is empty." << endl;
        }
        return;
      } else {
        // Address situation if head reference is being deleted
        Node < T > * curr = head_ref;
        Node < T > * prev = NULL;
        // Traverse through the DLL
        while (curr != nodedelete) {
          prev = curr;
          curr = curr -> next;
        }
        // Check if the node found is the only node in the list
        if (curr == nodedelete && curr -> next == NULL && curr -> prev == NULL &&
          curr == head_ref) {
          // Update the head reference to the next node
          head_ref = NULL;
          free(curr);
          cout << "Head node was deleted. Head node was the only node in the DLL" <<
            endl;
          return;
        }
        // Check if the node deleted is the first node and the DLL has more nodes
        else if (curr == head_ref) {
          head_ref = head_ref -> next;
          // Make sure the previous of the head reference is pointing to NULL
          head_ref -> prev = NULL;
          cout << "Head node was deleted. Head node was not the only node in the "
          "DLL" <<
          endl;
          delete curr;
        }
        // Check if the node deleted is the last node
        else if (curr -> next == NULL) {
          prev -> next = NULL;
          cout << "Last node was deleted" << endl;
          free(curr);
        }
        // Address the last situation where the node is not in the front or end of
        // the DLL
        else {
          prev -> next = curr -> next;
          (curr -> next) -> prev = curr -> prev;
          cout << "Node deleted. Found within the DLL. Not head or last node." <<
            endl;
          delete curr;
        }
      }
    }
    // Function to delete Node given from Lecture Slides (Lecture 7 pg 26)
    void deleteNodeDLL(Node < T > * nodedelete) {
      // Check if DLL is empty
      if (head_ref == NULL || nodedelete == NULL) {
        if (nodedelete == NULL && head_ref != NULL) {
          cout << "Nothing was deleted." << endl;
        } else {
          cout << "Nothing to be deleted. DLL is empty." << endl;
        }
        return;
      }
      // Check if the node deleted is the head of DLL
      if (head_ref == nodedelete) {
        head_ref = nodedelete -> next;
        cout << "Head node was deleted." << endl;
      }
      // Change next if node to be deleted is not the last node on the DLL
      if (nodedelete -> next != NULL) {
        (nodedelete -> next) -> prev = nodedelete -> prev;
        cout << "Node deleted is not the last Node." << endl;
      }
      // Change prev if node to be deleted is not the head node on the DLL
      if (nodedelete -> prev != NULL) {
        (nodedelete -> prev) -> next = nodedelete -> next;
        cout << "Node deleted is not the first Node." << endl;
      }
      // Free space
      free(nodedelete);
      return;
    }
    // Function to delete nodes of the DLL adapted from Pesudo Code given in the
    // slides (Lecture 7 pg 16)
    //The value passed
    void deletevalueDLL(T key) {
        // Check if DLL is empty
        if (head_ref == NULL || key == NULL) {
          if (head_ref == NULL) {
            cout << "Nothing to be deleted. DLL is empty." << endl;
          } else {
            cout << "Nothing was deleted. Key parameter is NULL" << endl;
          }
          return;
        } else {
          // Address situation if head reference is being deleted
          Node < T > * curr = head_ref;
          Node < T > * prev = NULL;
          // Traverse through the DLL
          while (curr -> data != key) {
            prev = curr;
            curr = curr -> next;
            //Address situation where the key is not withing the SLL
            if (curr == NULL) {
              cout << "The key is not inside the SLL" << endl;
              return;
            }

          }
          // Check if the node found is the only node in the list
          if (curr -> data == key && curr -> next == NULL && curr -> prev == NULL &&
            curr == head_ref) {
            // Update the head reference to NULL
            head_ref = NULL;
            free(curr);
            cout << "Head node was deleted. Head node was the only node in the DLL" <<
              endl;
            return;
          }
          // Check if the node deleted is the first node and the DLL has more nodes
          else if (curr == head_ref) {
            head_ref = head_ref -> next;
            // Make sure the previous of the head reference is pointing to NULL
            head_ref -> prev = NULL;
            cout << "Head node was deleted. Head node was not the only node in the "
            "DLL" <<
            endl;
            delete curr;
          }
          // Check if the node deleted is the last node
          else if (curr -> next == NULL) {
            prev -> next = NULL;
            cout << "Last node was deleted" << endl;
            free(curr);
          }
          // Address the last situation where the node is not in the front or end of
          // the DLL
          else {
            prev -> next = curr -> next;
            (curr -> next) -> prev = curr -> prev;
            cout << "Node deleted. Found within the DLL. Not head or last node." <<
              endl;
            delete curr;
          }
        }
      }
      // Destructor
      ~DLL() {
        Node < T > * curr = head_ref;
        Node < T > * prev = NULL;
        // Traverse through the DLL
        while (curr != NULL) {
          // Update curr and prev
          prev = curr;
          curr = curr -> next;
          delete curr;
        }
      }
  };
// Double Linked List Class Ends

// Test Main Function

int main() {
  // Test 1 using the deleteNodepseudoDLL. This function implements the pesudo
  // code given in the class slides (Lecture 7 pg 16)
  //The value passed as a parameter is a Node<T>* variable_name
  cout << "First Test with type int  " << endl;
  cout << " " << endl;
  DLL < int > DLL1;
  Node < int > * a = DLL1.pushDLL(10);
  Node < int > * b = DLL1.pushDLL(11);
  Node < int > * c = DLL1.pushDLL(291);
  Node < int > * d = DLL1.pushDLL(112);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;

  // Test to delete head reference
  DLL1.deleteNodepseudoDLL(d);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;
  // Test delete node in the middle of DLL
  DLL1.deleteNodepseudoDLL(b);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;
  // Test to delete last node
  DLL1.deleteNodepseudoDLL(a);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;
  // Test to delete NULL
  DLL1.deleteNodepseudoDLL(NULL);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;
  // Test to delete only element in list
  DLL1.deleteNodepseudoDLL(c);
  cout << "Current List: ";
  DLL1.printDLL();
  // Test to delete in an empty list
  DLL1.deleteNodepseudoDLL(NULL);
  cout << "Current List: ";
  DLL1.printDLL();
  cout << " " << endl;
  cout << " " << endl;

  // Test 2 using deleteNodeDLL. This function is the implemented delete
  // function for DLL given in the slides (Lecture 7 pg 26)
  //The value passed as a parameter is a Node<T>* variable_name
  cout << "Second Test with type float " << endl;
  cout << " " << endl;
  DLL < float > DLL2;
  Node < float > * e = DLL2.pushDLL(10.12312);
  Node < float > * f = DLL2.pushDLL(11.12313);
  Node < float > * g = DLL2.pushDLL(291.0985);
  Node < float > * h = DLL2.pushDLL(0.112);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;

  // Test to delete head reference
  DLL2.deleteNodeDLL(h);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;
  // Test delete node in the middle of DLL
  DLL2.deleteNodeDLL(f);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;
  // Test to delete last node
  DLL2.deleteNodeDLL(e);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;
  // Test to delete NULL
  DLL2.deleteNodeDLL(NULL);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;
  // Test to delete only element in list
  DLL2.deleteNodeDLL(g);
  cout << "Current List: ";
  DLL2.printDLL();
  // Test to delete in an empty list
  DLL2.deleteNodeDLL(NULL);
  cout << "Current List: ";
  DLL2.printDLL();
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;

  // Test 3 using deletevalueDLL. This function is the implemented delete
  // function for DLL given in the slides (Lecture 7 pg 26) This function takes
  //a value as a parameter
  cout << "Third Test with type long " << endl;
  cout << " " << endl;
  DLL < long > DLL3;
  DLL3.pushDLL(1012311);
  DLL3.pushDLL(1113141324);
  DLL3.pushDLL(413241321234);
  DLL3.pushDLL(123452667723);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;

  // Test to delete head reference
  DLL3.deletevalueDLL(123452667723);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  // Test delete node in the middle of DLL
  DLL3.deletevalueDLL(1113141324);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  // Test to delete last node
  DLL3.deletevalueDLL(1012311);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  // Test to delete element not inside list
  DLL3.deletevalueDLL(19);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  // Test to delete only element in list
  DLL3.deletevalueDLL(NULL);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  // Test to delete only element in list
  DLL3.deletevalueDLL(413241321234);
  cout << "Current List: ";
  DLL3.printDLL();
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
}
