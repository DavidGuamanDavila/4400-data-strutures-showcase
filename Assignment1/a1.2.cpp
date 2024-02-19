//Submitted and created by Anton Guaman; Student ID : 202014155
//Assign Question 2 main.cpp
//Write C++ program to swap two variables using pointers.
//  * Writing main function
//  * Write swap function
//  * Swap function must accept any type of pointer (uses generic)

#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
//Generic function for variable swap
void swapbyptr(T1* a, T2* b){
    //Temporary storage for variable swap
    T1 temporary_storage = *a;
    //Swap begins
    *a = *b;
    *b = temporary_storage;
    
    //Output test confirmation
    cout << *a<< endl;
    cout << *b << endl;
}

int main() {
    //Test 1 for same type
    cout << "Test 1:" << endl;

    char a = 'a';
    char b = 'b';

    char* ptra = &a;
    char* ptrb = &b;
    swapbyptr(ptra, ptrb);
    
    //Test 2 for different type
    cout << "Test 2:" << endl;
    
    int c = 21;
    long d = 12312;

    int* ptrc = &c;
    long* ptrd = &d;
    swapbyptr(ptrc, ptrd);
    
    return 0;
}
