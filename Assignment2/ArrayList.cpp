//  Assignment 2 Array Class main.cpp
//  Question 2 Array List
//Q2. Write a full class to implement Array list with its complete operations: initialization, insertion, delete,
//binary search. The class should accept any type of data (use templates). Also, write the main function to
//test your code.
//  Created by Anton David Guaman Davila on 2022-05-18. Student ID: 202014155

#include <iostream>
using namespace std;

template <typename T>
class Array{
    
    public:
        T* array;
        T* tempArr;
        int size_array;
        int count_elements = 0;
        
        //Array Constructor
        Array(int Size){
            array = new T[Size];
            size_array = Size;
        }
    
        //Array Insert Element
        void Insert_Element(T value){
            //Check if there is enough space to insert a value
            if(count_elements == size_array){
                cout << "Array size limit reached. Creating new array!" << endl;
                //Creating an array that has double the size of the original
                size_array*=2;
                tempArr = new T[size_array];
                //Copy elements of initial array to the temporary array
                for(int i = 0; i < (count_elements) ; i++){
                    //cout << i << endl;
                    tempArr[i]= array[i];
                    //cout << "Copying elements" << endl;
                }
                cout << "New array has been created. Ready for insertion of new elements!" << endl;
                //Copying the temporary arrray with twice the size to the array
                array = tempArr;
                //Delete the temporary array
                delete [] tempArr;
                
                cout << "Inserting value "<< value << " to array index "<< count_elements << endl;
                //Add the new element to the array
                array[count_elements] = value;
                count_elements++;
                
            }
            else
            {
                cout << "Inserting value "<< value << " to array index "<< count_elements << endl;
                //Add the new element to the array
                array[count_elements] = value;
                count_elements++;
            }
        }
        
        //Array Delete Element
        void Delete_Element(T value){
            //Variable that helps verify if an element was deleted.
            int initial_elements = count_elements;
            //Loop through the array to find the value to delete. It will delete all instances of the value passed inside the array
            for(int i = 0; i < count_elements; i++){
                if (array[i] == value)
                {
                    cout << "Value "<< value << " is found in the array. " << value << " was deleted." << endl ;
                    //Accomodates all elements of the array by shifting them to the right, deleting the value entered.
                    for (int j = i; j < (count_elements-1); j++){
                        array[j] = array[j+1];
                    }
                    count_elements--;
                }
            }
            //Verification if the value was found in the array and deleted
            if (initial_elements == count_elements){
                cout << "Value "<< value << " is not found in the array. Nothing was deleted" << endl ;
            }
 
        }
    
        //Binary Search
        bool binary_search(T value){
            int low = 0;
            int high = size_array - 1;
            bool element_found = true;
            //Check if element is in the array
            for(int i = 0; i < count_elements; i++){
                if (array[i] != value)
                {
                    element_found = false;
                }
                else if(array[i] == value){
                    element_found = true;
                    break;
                }
            }
            //End binary search if the value is not in the array
            if (element_found == false){
                cout << "Binary search did not find the value "<< value << " inside the function." << endl;
                return false;
            }
            //Begin binary search!
            else{
                while(low <= high){
                    //Medium value of the array
                    int mid  = (high + low) / 2;
                    //Will return true if the value searched for is in the array
                    if (array[mid] == value){
                        cout << "Binary search found the value "<< value << " inside the array!"<<endl ;
                        return true;
                    }
                    //The value is on the right side
                    else if (array[mid] < value){
                        low = mid + 1;
                    }
                    //The value is on the left side
                    else{
                        high = mid - 1;
                    }
                }
            }
            return false;
        }
            
        //Print function of the Array
        void Print(){
            cout << "Your array contains:" << endl;
            for(int i = 0; i < count_elements; i++){
                cout << array[i] << endl;
            }
        }
    
        //Array Destructor
        Array(){
            delete [] array;
        }
    
    private:
    
};

int main() {
    
// *****************************************************************************************************************************
//    //Program that runs the array class with user interaction
//    string perform = "yes";
//    string innerperform = "yes";
//    int size, option, value;
//    cout << "Welcome to the array program, to begin please enter the size of the array you would like to create." << endl;
//    cin >> size;
//    Array<int> array1(size);
//    cout << "Great we are ready to begin. These are the following options:" << endl;
//    cout << "Enter 1 if you would like to insert a value into the array." << endl;
//    cout << "Enter 2 if you would like to delete a value of the array." << endl;
//    cout << "Enter 3 if you would like to preform binary search for a value inside the array." << endl;
//    cout << "Enter 4 if you would like to visualize all the values inside your array." << endl;
//    cin >> option;
//    while (perform == "yes" || perform == "Yes" || perform == "y"){
//        //Insert element
//        if (option == 1){
//            do{
//                cout << "Type in the value you would like to insert inside the array.";
//                cin >> value;
//                array1.Insert_Element(value);
//                cout << "Would you like to insert another element? Type yes to repeat or any key to exit insertion of values. ";
//                cin >> innerperform;
//            }
//            while (innerperform == "yes" || innerperform == "Yes" || innerperform == "y");
//            option = 0;
//        }
//        //Delete element
//        else if (option == 2){
//            do{
//                cout << "Type in the value you would like to delete inside the array.";
//                cin >> value;
//                array1.Delete_Element(value);
//                cout << "Would you like to delete another element? Type yes to repeat or any key to exit delete values. ";
//                cin >> innerperform;
//            }
//            while(innerperform == "yes" || innerperform == "Yes" || innerperform == "y");
//            option = 0;
//        }
//        //Binary search in an element
//        else if (option == 3){
//            do{
//                cout << "Type in the value you would like to perform binary search inside the array.";
//                cin >> value;
//                array1.binary_search(value);
//                cout << "Would you like to search for another element? Type yes to repeat or any key to exit binary search. ";
//                cin >> innerperform;
//            }
//            while(innerperform == "yes" || innerperform == "Yes" || innerperform == "y");
//            option = 0;
//        }
//        //Print the elements inside the array
//        else if (option == 4){
//            do{
//                cout << "These are the values inside your array:" << endl;
//                array1.Print();
//                cout << "Would you like to print your array again? Type yes to repeat or any key to exit print values. ";
//                cin >> innerperform;
//            }
//            while(innerperform == "yes" || innerperform == "Yes" || innerperform == "y");
//            option = 0;
//        }
//
//        cout << "Would you like to continue editing/viewing the array? Type yes if you would like to continue or any key to exit the program." << endl;
//        cin >> perform;
//
//        if (perform == "yes" || perform == "Yes" || perform == "y"){
//            cout << "These are the following options:" << endl;
//            cout << "Enter 1 to insert a value into the array. Enter 2 to delete a value of the array. Enter 3 to preform binary search for a value inside the array. Enter 4 to visualize all the values inside your array." << endl;
//            cin >> option;
//        }
//        else{
//            cout << "Thank you for using the program! Until next time." << endl;
//        }
//
//
//    }
// *****************************************************************************************************************************
    
//Test 1 using type float
    Array<float> arrayfloat(3);
    arrayfloat.Insert_Element(-1.1);
    arrayfloat.Insert_Element(2.1);
    arrayfloat.Insert_Element(3.1);
    //Testing new array creation. Insertion of elements exceeds limit of array size
    arrayfloat.Insert_Element(4.1);
    //Testing delete an element inside the array
    arrayfloat.Delete_Element(4.1);
    //Testing delete an element that is not inside the array
    arrayfloat.Delete_Element(5.1);
    //Testing binary search of a value inside the array
    arrayfloat.binary_search(2.1);
    //Testing binary search of a value that is not inside the array
    arrayfloat.binary_search(5.1);
    //Testing the print function
    //Expected output -1.1, 2.1,  and 3.1
    arrayfloat.Print();

//Test 2 performing all tasks on an array with size 1 using type int
    Array<int> arrayint(1);
    arrayint.Insert_Element(100);
    //Testing search for value within array
    arrayint.binary_search(100);
    //Testing search for value that is not not within the array
    arrayint.binary_search(-991);
    //Testing delete value that is within the array
    arrayint.Delete_Element(100);
    //Testing delete value that is not within the array. The array is empty too.
    arrayint.Delete_Element(1.1);
    //Testing Inserting a negative value
    arrayint.Insert_Element(-100);
    //Testing binary search for negative number
    arrayint.binary_search(-100);
    //Testing delete for a negative number
    arrayint.Delete_Element(-100);
    //Testing array output
    //Expected output 0 elements printed
    arrayint.Print();
    
//Test 3 using type long
    Array<long> arraylong(3);
    arraylong.Insert_Element(10000000000000);
    arraylong.Insert_Element(1093143414951);
    arraylong.Insert_Element(1006769696986);
    arraylong.Insert_Element(10012132131231233);
    //Searching for different type;
    arraylong.binary_search(0.1);
    //Deleting for different type
    arraylong.Delete_Element(-0.00012);
    //Testing searching
    arraylong.binary_search(10012132131231233);
    //Testing deleting
    arraylong.Delete_Element(10012132131231233);
    //Testing print function
    arraylong.Print();
}
