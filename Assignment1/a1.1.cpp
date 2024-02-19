//Submitted and created by Anton Guaman; Student ID : 202014155
//Assign Question 1 main.cpp
//Write a C++ program to find the max of an integral data set.
//  * Write main function to ask a user to
//      - input the number of data values
//      - input all data values
//  * Write max function to print maximum value

#include <iostream>
#include <string>
using namespace std;

void maxfunction(int numberdatavalues){
    int userinput[numberdatavalues], maxvalue, minvalue;
    //For loop that stores the input of the user into the array variable
    for (int i = 0; i < numberdatavalues; i++){
        cout<< "Please enter a value:";
        cin >> userinput[i];
    }
    //Initial assignment for the max and min values of the data set
    maxvalue = userinput[0];
    minvalue = userinput[0];
    //For loop that iterates through the array variable with if statements to determine the new max and min values in each iteration
    for (int i = 0; i <numberdatavalues; i++){
        if (userinput[i] > maxvalue)
        {
            maxvalue = userinput[i];
        }
        
        if (userinput[i] < minvalue)
        {
            minvalue = userinput[i];
        }
    }
    cout<< "This is the max data set value: " << maxvalue << ". " << "This is the min data set value: " << minvalue<< endl;
}

int main() {
    //Variable that stores the input of the user regarding the number of data set values
    int numberdatavalues;
    cout << "Welcome! Type in the value of data values you will enter:";
    cin >> numberdatavalues;
    cout << "Great, " << numberdatavalues << " values!" <<endl;
    //userinput is the array variable that stores the input data values of the user, maxvalue stores the max value in the array set, minvalue stores the min value in the array set
    maxfunction(numberdatavalues);
    
    return 0;
}
