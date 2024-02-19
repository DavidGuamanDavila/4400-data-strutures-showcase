//Submitted and created by Anton Guaman; Student ID : 202014155
//Assign Question 3 main.cpp
//Write a program uses a class template to perform addition, subtraction, multiplication, and division of two variables num1 and num2. The variables can be of any type.
//  * Write main function
//  * Write the generic class

#include <iostream>
using namespace std;

template <typename T>
class basicoperations{
public:

    //Constructor Implementation
    basicoperations(T _num1, T _num2){
        num1 = _num1;
        num2 = _num2;
    }
    //Basic operations using functions
    //Add num1 to num2
    T sum(){
        return num1 + num2;
    }
    //Substract num2 from num1
    T substraction(){
        return num1 - num2;
    }
    //Multiply num1 to num2
    T multiplication(){
        return num1 * num2;
    }
    //Divide num2 into num1
    T division(){
        return num1 / num2;
    }
    //Method that modifies num1
    T getnum1(T newnum1){
        num1 = newnum1;
    }
    //Method that modifies num2
    T getnum2(T newnum2){
        num2 = newnum2;
    }
    //Method that returns num1
    T getnum1(){
        return num1;
    }
    //Method that returns num2
    T getnum2(){
        return num2;
    }
    
    //Function that prints all calculations at once
    
    void printusingfunctions()
    {
        cout << "The addition result: " << sum() << endl;
        cout << "The substraction result: " << substraction() << endl;
        cout << "The multiplication result: " << multiplication() << endl;
        cout << "The division result: " << division() << endl;
    }
    
private:
    T num1;
    T num2;
};

//Operator overloading

//Overloading addition operator
template <typename T>
basicoperations<T> operator+(const basicoperations<T> &num1, const basicoperations<T> &num2){
    T sum;
    sum = num1 + num2;
    return sum;
};
//Overloading substraction operator
template <typename T>
basicoperations<T> operator-(const basicoperations<T> &num1, const basicoperations<T> &num2){
    T substraction;
    substraction = num1 - num2;
    return substraction;
};
//Overloading multiplication operator
template <typename T>
basicoperations<T> operator*(const basicoperations<T> &num1, const basicoperations<T> &num2){
    T multiplication;
    multiplication = num1*num2;
    return multiplication;
};
//Overloading division operator
template <typename T>
basicoperations<T> operator/(const basicoperations<T> &num1, const basicoperations<T> &num2){
    T division;
    division = num1/num2;
    return division;
};


int main() {
    cout << "Welcome to the basic calculator program";
    basicoperations<float> basicoperations(8.2,2);
    cout << "Would you like to perform the operations yourself? Or would you like all the operations to be calculate?"<< endl;
    cout << "For the first option press 1 for the second option press 2. Thank you!"<< endl;
    
    int option;
    cin >> option;
    
    //Option one to manually calculate.
    if (option == 1){
        string repeat = "yes";
        while (repeat == "yes" or repeat == "y" or repeat == "Yes"){
            char operation;
            cout << "Please type the operation you would like +, -, *, or /.";
            cin >> operation;
            
            if (operation == '+'){
                cout << basicoperations.sum()<< endl;
                cout << "If you would like to repeat another operation type yes. If not type anything to end the program."<<endl;
                cin >> repeat;
            }
            if (operation == '-'){
                cout << basicoperations.substraction()<< endl;
                cout << "If you would like to repeat another operation type yes. If not type anything to end the program."<<endl;
                cin >> repeat;
            }

            if (operation == '*'){
                cout <<basicoperations.multiplication()<< endl;
                cout << "If you would like to repeat another operation type yes. If not type anything to end the program."<<endl;
                cin >> repeat;
            }
            
            if (operation == '/'){
                cout << basicoperations.division()<< endl;
                cout << "If you would like to repeat another operation type yes. If not type anything to end the program."<<endl;
                cin >> repeat;
            }
        }
    }
    //Option two that uses a function to calculate and print all the results of the mathematical operations
    if (option == 2){
        cout << "The following claculations for the number you enetered are:" << endl;
        basicoperations.printusingfunctions();
    }

    //Calculations done with operator overloading
    cout <<"Now using operator overloading:"<< endl;
    //Addition
    cout <<"The addition result: " << basicoperations.getnum1()<<" + "<<basicoperations.getnum2() << " = "<< basicoperations.getnum1()+basicoperations.getnum2()<< endl;
    //Substraction
    cout <<"The substaction result: " << basicoperations.getnum2()<<" - "<<basicoperations.getnum1() << " = " << basicoperations.getnum2()-basicoperations.getnum1()<< endl;
    //Multiplication
    cout <<"The multiplication result: " << basicoperations.getnum1()<<" * "<<basicoperations.getnum2() << " = " << basicoperations.getnum2()*basicoperations.getnum1()<< endl;
    //Division
    cout <<"The division result: " << basicoperations.getnum2()<<" / "<<basicoperations.getnum1() << " = " << basicoperations.getnum2()/basicoperations.getnum1()<< endl;
    
    return 0;
}
