//Q1. Write a program to calculate mathematical expressions. An expression could contain the
//following operations: add, subtraction, multiplication, division, power, also, It may contain
//brackets, i.e., ( )
//Input: String contains the expression, use std::cin>>
//Output: Evaluation of input expression
//You have to write main function to test your code:
//Note: You can use stl::stack as underlaying data structure for you program.
//  Created by Anton David Guaman Davila on 2022-06-09.
//

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

//PEMDAS priority Function
int priorityPEMDAS(char Operator){
    //Exponent highest priority
    if(Operator == '^'){
        return 3;
    }
    //Multiplication and Division second highest priority
    else if(Operator == '*' || Operator == '/'){
        return 2;
    }
    //Addition and Substraction third highest priority
    else if(Operator == '+'|| Operator == '-'){
        return 1;
    }
    return 0;
}

//Convert string from infix to postfix notation
string convertpostfix(string infixstring){
    //Variable that aids for the traversal of the infixstringstring
    int j = 0;
    //Variable that will store the new postfixstring
    string postfixstring = "";
    //Object that stores the operators of the infixstring
    stack<char> OperatorStack;
    //Check if the string is empty or reaches it last content
    while(infixstring[j] != '\0'){
        //Check if the index of the string is a number
        if (isdigit(infixstring[j]) != 0){
            //While loop to capture all digits of a number and insert to postfixstring
            while(isdigit(infixstring[j]) != 0 && infixstring[j] != '\0'){
             postfixstring+=infixstring[j];
                    j++;
            }
            //Add a space to help differentiate numbers and operators within the infixstring
            postfixstring += " ";
        }
        //Check if there is an open bracket in the infixstring and insert it to the stack
        else if (infixstring[j] == '(' ){
            OperatorStack.push(infixstring[j]);
            j++;
        }
        //Check for end bracket
        else if (infixstring[j] == ')'){
            //While loop to insert operators from stack to the postfixstring
            while(!OperatorStack.empty() && OperatorStack.top()!= '('){
                postfixstring += OperatorStack.top();
                OperatorStack.pop();
                postfixstring += " ";
            }
            //Delete the parenthese '('
            OperatorStack.pop();
            j++;
        }
        //Check if there is an operator
        else if ((infixstring[j] == '+' || infixstring[j] == '-' || infixstring[j] == '*' ||infixstring[j] == '/' || infixstring[j] == '^')){
            //Addres situation where there are no more 'C' or the stack is empty
            //Push the operator into the stack
             if(OperatorStack.empty()||OperatorStack.top() == '('){
                OperatorStack.push(infixstring[j]);
                j++;
            }
            //Address situation where there is an existing operator in the top of the stack and it has a higher priority than the incoming operator
            else{
                while((!OperatorStack.empty()) && (OperatorStack.top() != 'C') && (priorityPEMDAS(OperatorStack.top()) >= priorityPEMDAS(infixstring[j]))){
                //Add the operator of the stack that has priority into the postfixstring
                postfixstring += OperatorStack.top();
                //
                postfixstring += " ";
                //Delete the operator that was inserted into the postfixstring
                OperatorStack.pop();
                }
                //Insert the current output into the stack
                OperatorStack.push(infixstring[j]);
                j++;
            }
        }
    }
    //Insert all remaing elements of the stack into the postfixstring
    while(!OperatorStack.empty()){
        postfixstring += OperatorStack.top();
        postfixstring += " ";
        OperatorStack.pop();
    }

    cout << "Postfix is : " << postfixstring<< endl;
    return postfixstring;
}

string StackCalculation(string postfixstring){
    int j = 0;
    stack<string> Calculation;
    //Run while the postfixstring is not null
    while (postfixstring[j] != '\0'){
        //Address situation where there is a number in the postfixstring
        if(isdigit(postfixstring[j]) != 0){
            string temp = "";
            while (postfixstring[j] != ' '){
                temp+= postfixstring[j];
                j++;
            }
            Calculation.push(temp);
        }
        //Address scenario where there is a space in the string
        else if(postfixstring[j] == ' '){
            j++;
        }
        //Address scenario where there are operands
        else if(postfixstring[j] == '+'||postfixstring[j] == '-' ||postfixstring[j] == '*' ||postfixstring[j] == '/' ||postfixstring[j] == '^'){
            string temp1 = "";
            string temp2 = "";
            string result = "";
            temp1 += Calculation.top();
            Calculation.pop();
            temp2 += Calculation.top();
            Calculation.pop();
            //Case scenario to preform the corresponding operation depending on the operand
            switch(postfixstring[j]){
                case '+':
                    result = to_string(stoi(temp1) + stoi(temp2));
                    Calculation.push(result);
                    j++;
                    break;
                case '-':
                    result = to_string(stoi(temp2) - stoi(temp1));
                    Calculation.push(result);
                    j++;
                    break;
                case '*':
                    result = to_string(stoi(temp2) * stoi(temp1));
                    Calculation.push(result);
                    j++;
                    break;
                case '/':
                    result = to_string(stoi(temp2) / stoi(temp1));
                    Calculation.push(result);
                    j++;
                    break;
                case '^':
                    result = to_string(pow(stoi(temp2),stoi(temp1)));
                    Calculation.push(result);
                    j++;
                    break;
            }
        }
    }
    //The result is stored in the top of the stack
    cout << "Result is : " << Calculation.top() << endl;
    return Calculation.top();
}


int main() {
    //Program that works with st::cin>>. Will iterate for the times the user wanting to calculate something -------
    string userdecision = "y";
    while (userdecision == "y" || userdecision == "Y" || userdecision == "Yes" || userdecision == "yes" ){
        cout << "Welcome to the Calculator program" << endl;
                string infixstring;
                cout<< "Please enter your expression: " ;
                cin>> infixstring;
                string output;
                output = convertpostfix(infixstring);
                string result;
                result = StackCalculation(output);
        cout << "Would you like to perform another calculation?" << endl;
        cout << "Type Y or yes to repeat. Press any other key to exit. Thank you!" << endl;
        cin >> userdecision;
        if(userdecision == "y" || userdecision == "Y" || userdecision == "Yes" || userdecision == "yes" ){
            infixstring = "";
            output = "";
            result = "";
        }
    }
    //-----------
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "Test Cases will begin now " << endl;
    //Test 1 Begins no parentheses with all operators
            cout << "Test 1 " << endl;
            string infixstringthree = "100+21*8-20/2*2^4";
            string outputthree;
            outputthree = convertpostfix(infixstringthree);
            string resultthree;
            resultthree = StackCalculation(outputthree);
            cout << " " << endl;
    //Expected Result 108
    //Test 1 Ends
    //Test 2 Begins Calculation with parentheses
            cout << "Test 2 " << endl;
            string infixstringone = "(1+2*24)/6+7";
            string outputone;
            outputone = convertpostfix(infixstringone);
            string resultone;
            resultone = StackCalculation(outputone);
            cout << " " << endl;
//Expected Result: 15
//Test 2 Ends

//Test 3 Begins Calculation with parentheses within parentheses using all operators
            cout << "Test 3 " << endl;
            string infixstringtwo = "5+(23*91/(4-1))+(2+123*9)*2^9";
            string outputtwo;
            outputtwo = convertpostfix(infixstringtwo);
            string resulttwo;
            resulttwo = StackCalculation(outputtwo);
            cout << " " << endl;
//Expected Result: 568510
//Test 3 Ends
}
