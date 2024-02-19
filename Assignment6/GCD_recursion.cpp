//Q2. Write a program in C to find GCD of two numbers using recursion. Go to the editor
//Test Data :
//Input 1st number: 10
//Input 2nd number: 50
//Expected Output :
//The GCD of 10 and 50 is: 10
//  main.cpp
//  Assign6.2
//  Created by Anton David Guaman Davila on 2022-06-28. Student ID: 202014155

#include <iostream>
using namespace std;

int GCD(int numberone, int numbertwo){
    if (numbertwo!= 0){
        return GCD(numbertwo, numberone % numbertwo);
    }
    else{
        return numberone;
    }
}

int main() {
    
    int numa = 10, numb = 50;
    cout << "Test data:" << endl;
    cout << "   Input 1st number: " << numa<< endl;
    cout << "   Input 2nd number: " << numb<< endl;
    int x = GCD(numa, numb);
    cout << "Test output:" << endl;
    cout << "   The GCD of " << numa << " and "<< numb<< " is: " << x << endl;
    
    return 0;
}
