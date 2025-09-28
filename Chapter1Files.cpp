#include <iostream>
using namespace std; 

void swap(int* a, int* b);

int main(){

  
  //Entering and outputting a value 
  int value = 0; 
  cout << "Enter a value: "; 
  cin >> value; 
  cout << "The entered value is " << value << endl; 
 
  
  /*
  Data types: 

  Integers - 32 bit, 4 bytes 
  Short - int but 16 bit, 2 bytes
  Long - int that is more than 32 bit 

  Float - Number using 32 bit, 7 decimal precision 
  Double - Number using 64 bit, 15 decimal precision 

  Bool - 8 bit
  
  Char - 8 bit
  -> char letter = 'a'; 

  Arrays 
  -> int array[7]; 

  //#include <string>
  String - Can store characters without array 
  -> string sentence = "This course is"; 
  -> can use + or == to concatenate or compare them 
  
  */

  //Using Strings
  string pre = "This course is ";
  string post = " Programming Fundamentals\n";
  string blank = "______"; 

  cout << "Fill in the blank: \n"; 
  cout << pre << blank << post;
  cin >> blank; 

  if(blank == "ECE244"){
    cout << pre << blank << post; 
  }
  else
  cout << "Wrong"; 

  /*
  Control Structures: 

  If, while, do-while, for 
  -> Same as C 


  FUNCTIONS: 

  Same as C 
  ->return_type function_name(parameter_list){}

  1. Pass by value
  2. Pass by address
  3. Pass by reference 
  --> references cannot be NULL
  --> if a is an int, int& ra = a; creates a reference to a;
    --> ra is int& type,
    --> any changes made to ra is also made to a; 
  --> int a = 5;
      int& ra = a; 
      ra = 10 makes a = 10; 
      ra = b makes a = b; 

  When passing to function, 
  Declaration: int function(int& a); 
  Calling: function(a); 

    a) Reference must be initialized when it is first declared 
    b) Reference cannot be reintialized to another variable
    c) Reference is not a seperate variable, same address
    

  Splitting Code into Multiple Files: 

  1. Function declarations in header file (.h)
  2. Function definitions in source file (.cpp)


  EXAMPLE CODE: 

  void printNum(int x);
  int userInputNum();

int main(void) {
  int num = userInputNum();
  printNum(num);
  return 0;
}

void printNum(int x) {
  cout << "The number is " << x << endl;
}

int userInputNum() {
  int x;
  cout << "Enter a number: ";
  cin >> x;
  return x;
}

  Header files: Used for a particular set of functions
    --> print.h 
      -> Function declaration of printNum: void printNum(int x);

    --> input.h
      -> Function declartion of userInputNum: int userInputNum();

  Source files: Implementation of the functions in the header file 
  //SHOULD include function definitions at the top for whatever functions are used in the source file
    --> print.cpp 
      -> Function definition for printNum: 
    void printNum(int x) {
    cout << "The number is " << x << endl;
      
      } 
      -> #include <iostream>
      -> using namespace std;
      -> #include "print.h";

    --> input.cpp  
      -> Function definition for userInputNum:

    int userInputNum() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    return x;
    }
      -> #include <iostream>
      -> #include "input.h";
      -> using namespace std;

    --> main.cpp 
      -> main function: 

    int main(void) {
    int num = userInputNum();
    printNum(num);
    return 0;
    }
      -> #include "print.h";
      -> #include "input.h"; 

a) Compile and link all at once: 
g++ main.cpp print.cpp input.cpp -o main (compiles each source file seperately and generates one executable called main)
  ./main to run 

b) Compile seperately (Can compile only the source files that have been changed): 
g++ -c main.cpp -o main.o 
g++ -c print.cpp -o print.o
g++ -c input.cpp -o input.o 
g++ main.o print.o input.o -o main (Compiles only the source files that have been changed)
-c means compile only, dont link yet

HEADER GUARDS (If a source file includes a header file multiple times):

- To include header files only once, checks if the header file has been included before  
- Defined at the start of the header file 

EXAMPLE: 

#ifndef FILE_NAME_H - checks if FILE_NAME_H has been defined before 
#define FILE_NAME_H

//Contents of header file 

#endif

Creating pointer that points to pointer of array of ints 

int** ptr = new int*[4]; 

for(int i = 0; i < 4; i++){
  ptr[i] = new int; 
}
for(int i = 0; i < 4; i++){
  *ptr[i] = i; 
}

Deleting: 

for(int i = 0; i < 4; i++){
  delete ptr[i]; 
  ptr[i] = nullptr; 
}

delete [ptr]; 
ptr = nullptr; 

*/

  
  
}



//Swapping using pointers 
//swap(&a, &b); 
void swap(int* a, int* b){

  int temp = *a; 
  *a = *b; 
  *b = temp; 

}

//Swapping using references
//swapByRef(a, b);

void swapByRef(int& ra, int& rb){

  int temp = ra;
  ra = rb; 
  rb = temp; 
}
