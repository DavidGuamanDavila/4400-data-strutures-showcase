// Q1. Write a program in C++ to print first 50 natural numbers using recursion
//  main.cpp
//  Assign6.1
//  Created by Anton David Guaman Davila on 2022-06-28. Student ID: 202014155

#include <iostream>
using namespace std;

void firstfifty(int number){
    if(number <= 50){
        cout << number << "   ";
        firstfifty(number+1);
    }
}

int main() {
    cout << "The following program prints the first 50 natural numbers using recursion." << endl;
    cout << "The result is the following:" << endl;
    int x = 1;
    firstfifty(x);
    
    return 0;
}
