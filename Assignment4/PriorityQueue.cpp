//  Assignment 4 Priority Queue .cpp
//Q1. Implement priority queue generic class that has the following functions:
//• Enqueue: insert element into the queue
//• Dequeue: return an element with highest priority and remove it from the queue
//• Merge: merge two priority queues. Here is the function signature:
//• PriorityQueue merge(PriorityQueue pq1, PriorityQueue pq2)
//Merge function takes two priority queues as parameters and return one priority queue  contains all elements.
//• Write Main function to test your code, the test should be as follows:
//  o Create two instances of priority queue
//  o Enqueue set of elements with different priorities in both queues
//  o Merge these two queues
//  o Dequeue the merged priority queue, the elements in the merged priority queue must be dequeued based on their original priorities
//  Created by Anton David Guaman Davila on 2022-06-03.
//

#include <iostream>

using namespace std;

// Item Class
template < typename T >
  class item {
    public:
      T value;
    int priority;
  };

// Priority Queue Class using Array
template < typename T >
  class PQ: public item < T > {
    public:

      //Object that stores the priority queue
      item < T > pq[1000];
    //Variable that stores the size of the priority queue
    int sizePQ = -1;

    //SizePQ starts at -1 since our first element to insert will be in index 0

    //Function to Insert elements into the priority
    //Two parameters passed the value being inserted and the priority of the value
    void enqueue(T value, int priority) {
      //Increment size of sizePQ
      sizePQ++;

      //Insert the value and priority
      pq[sizePQ].value = value;
      pq[sizePQ].priority = priority;

    }

    //Function that returns the index where the highest priority is the highest value
    int highpeek() {
      //Create two variables that will store the highest priority
      int highestpriority;
      //Set the highest priority and lowest priority to the same element
      highestpriority = pq[0].priority;
      //Variable that will store the index number of the highest priority
      int index = -1;
      //For loop that will iterate through the priority queue and find the highest priority
      for (int i = 0; i < (sizePQ + 1); i++) {
        //Address scenario where there is a higher priority in another element
        if (pq[i].priority > highestpriority) {
          highestpriority = pq[i].priority;
          index = i;
        }
        //Address scenario where two elements have the same priority. Pick the one with the highest value
        else if ((pq[i].priority == pq[index].priority) && (index > -1) && (pq[index].value < pq[i].value)) {
          highestpriority = pq[i].priority;
          index = i;
        }
        //Address scenario that the highestpriority is in the first index
        else if (highestpriority == pq[0].priority) {
          index = 0;
        }
      }
      return index;
    }

    //Function that returns the index where the highest priority is the lowest value
    //Requested in assignment 4 description
    int lowpeek() {
      //Create two variables that will store the highest priority
      int highestpriority;
      //Set the highest priority and lowest priority to the same element
      highestpriority = pq[0].priority;
      //Variable that will store the index number of the highest priority
      int index = -1;
      //For loop that will iterate through the priority queue and find the highest priority
      for (int i = 0; i < (sizePQ + 1); i++) {
        //Address scenario where there is a lower priority in another element
        if (pq[i].priority < highestpriority) {
          highestpriority = pq[i].priority;
          index = i;
        }
        //Address scenario where two elements have the same priority. Pick the one with the highest value
        else if ((pq[i].priority == pq[index].priority) && (index > -1) && (pq[index].value < pq[i].value)) {
          highestpriority = pq[i].priority;
          index = i;
        }
        //Address scenario that the highestpriority is in the first index
        else if (highestpriority == pq[0].priority) {
          index = 0;
        }
      }
      return index;
    }

    //Function to push items out of the Priority Queue
    //No parameters passed
    void dequeue(int typedequeue) {
      int index;
      if (typedequeue == 1) {
        //Call the function peek2 to return the index of the highest priority being the lowest value.
        index = lowpeek();
      } else if (typedequeue == 2) {
        //Call the function peek2 to return the index of the highest priority being the lowest value. Ex: 0
        index = highpeek();
      } else {
        cout << "Invalid input";
        return;
      }

      //Store values of item being dequeued
      T highestpriorityvalue = pq[index].value;
      T highestpriority = pq[index].priority;
      //Shift elements one index from where the highestpriority element is found
      for (int i = index; i < sizePQ; i++) {
        pq[i] = pq[i + 1];
      }
      //Decrease size of priority queue
      sizePQ--;
      cout << "The value being dequeued is " << highestpriorityvalue << " with priority value " << highestpriority << endl;
    }

    //Function that Prints the Array
    void printPQ() {
      for (int i = 0; i <= sizePQ; i++) {
        if (i == sizePQ) {
          cout << pq[i].value << endl;
        } else {
          cout << pq[i].value << ", ";
        }
      }
    }
    //Function that merges two priority queues and returns a new priority queue
    //The function takes two objects as parameters
    PQ < T > merge(PQ < T > pq1, PQ < T > pq2) {
      //Create new object
      PQ < T > pq3;
      //
      //Insert pq1 to pq3
      for (int i = 0; i <= pq1.sizePQ; i++) {
        //Use function enqueue to insert
        pq3.enqueue(pq1.pq[i].value, pq1.pq[i].priority);
      }
      //Insert pq2 to pq3
      for (int i = 0; i <= pq2.sizePQ; i++) {
        //Use function enqueue to insert
        pq3.enqueue(pq2.pq[i].value, pq2.pq[i].priority);
      }
      cout << "Lists have been merged" << endl;
      return pq3;
    }
    //Function to access the size of the priority queue
    int accessorsizePQ() {
      return sizePQ + 1;
    }

    //Destructor empty. No nede to delete array. Nothing was allocated dynamically
    ~PQ() {}
  };

int main() {

  //1. Two instances of Priority Queue ----------------
  PQ < int > FirstPQ;
  PQ < int > SecondPQ;
  PQ < int > ThirdPQ;

  //2. Enqueue set of elements ----------------
  FirstPQ.enqueue(100, 8);
  FirstPQ.enqueue(15, 5);
  FirstPQ.enqueue(11, 2);
  FirstPQ.enqueue(10, 1);
  FirstPQ.enqueue(2, 3);
  FirstPQ.enqueue(1, 0);
  //Print Priority Queue One to verify
  FirstPQ.printPQ();
  cout << " " << endl;
  cout << " " << endl;
  SecondPQ.enqueue(21, 11);
  SecondPQ.enqueue(20, 10);
  SecondPQ.enqueue(8, 9);
  SecondPQ.enqueue(5, 4);
  SecondPQ.enqueue(3, 7);
  SecondPQ.enqueue(0, 6);
  //Print Priority Queue One to verify
  SecondPQ.printPQ();

  //    3. Merge the two queues --------------------
  cout << "Merge two lists." << endl;
  ThirdPQ = ThirdPQ.merge(FirstPQ, SecondPQ);
  cout << "Current list: ";
  ThirdPQ.printPQ();
  cout << " " << endl;
  cout << " " << endl;

  //    4. Dequeue the Merged Priority Queue ----------------
  int typedequeue;
  cout << "Would you like to dequeue the the priority queue with the lowest value or the highest value." << endl;
  cout << "For dequeue with the lowest value of priority please type 1. (Requested in assignment 4 description)" << endl;
  cout << "For dequeue with the highest value of priority please type 2." << endl;
  cin >> typedequeue;
  while (ThirdPQ.accessorsizePQ() != 0) {
    ThirdPQ.dequeue(typedequeue);
    if (ThirdPQ.accessorsizePQ() != 0) {
      cout << "Current list: ";
      ThirdPQ.printPQ();
      cout << " " << endl;
      cout << " " << endl;
    } else {
      cout << "Current list: EMPTY ";
      ThirdPQ.printPQ();
      cout << " " << endl;
      cout << " " << endl;
    }
  }
}
