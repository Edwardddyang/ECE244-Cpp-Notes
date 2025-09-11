#include <iostream>
#include <string> 
using namespace std;

/*
CLASSES:

Groups data members and functions in a single unit
Class definition (instantiation) does not have memeory allocated, but creating an object does 

To create a class: 
- Classes are private in default, meaning declared things cannot be used outside of the class 
- Class definition in header file
- Function implementations in a source file 

In a header file Student.h: 

#include <string>
using namespace std; 
class Student{
  private: 
    string name; 
    int ID;
  
  public: 
    void print(); <-- Declaring a function called print 
};

To implement the function memeber in class Student, create source file Student.cpp: 

#include <iostream>
#include "Student.h" --> Use header file to access Student class
using namespace std; 

void Student::print(){ --> :: specifies that print is part of Student class   
  cout << "Name: " << name << endl << "ID: " << ID << endl; 
}

To create instance of class: 

Student x;
x.name = "Cindy"; <-- CANNOT do this, name is private 

GETTER AND SETTER FUNCTIONS:
- Access/return value of a private member, and sets the value of a private member

1) Add getter and setter functions to header file (Student.h):

#include <string>
using namespace std; 
class Student{
  private: 
    string name; 
    int ID;
  
  public: 
    void print(); <-- Declaring a function called print 
    void setName(string name); --> will return value of name
    string getName(); --> will recieve string and assign it to name 
};

2) Add function declarations to source file (Student.cpp): 

#include <iostream>
#include "Student.h" 
using namespace std; 

void Student::print(){ -->    
  cout << "Name: " << name << endl << "ID: " << ID << endl; 
}
void Student::setName(string n){
  name = n
}
string Student::getName(){
  return name; 
}

3) Use main.cpp file:

#include <iostream>
#include "Student.h"
using namespace std; 

int main(){
Student x; 

x.setName("Cindy");
cout << x.getName(); 

x.print(); 
}


CONSTRUCTORS:
-Members of a class that are called when an object of the class is instantiated 
- Used to initialize the members of a class when an object is created 

Constructor MUST:
- Have same name as the class
- No return type 
- Called when an object is created 
- Must be public member 

EXAMPLE:

In Student.h (header):
#include <string> 
using namespace std; 

class Student{
  private: 
    string name; 
    int ID;

  public: 
    Student(); <-- Constructor 
    void print(); 
    void setName(string name);
    string getName(); 
}

In Student.cpp (source/function declaration):

#include <iostream>
#include "Student.h"
using namespace std; 

Student::Student(){
  ID = 0;
  name = "no name"; 
}
//Rest of function declarations 

OTHER CONSTRUCTORS: 

In Student.h: 

Add: 
Student(int id);
Student(int id, string n); 

In Student.cpp: 

Add: 
Student::Student(int id){
ID = id; 
name = "no name";
}

Student::Student(int id, string n){
ID = id; 
name = n; 
}

Function Overloading - The process of defining multiple constructors under the same name but different parameters 

DECONSTRUCTORS:
- Only need to create a manual deconstructor when you are dynamically allocating memory in your class 
- Destroys an object, uninitialize any objects created 
- Beings with ~CLASS_NAME

Order of deconstructor: 
1. Reverse of declaration order
2. Arrays - Last element to first
3. Class inheritance - Derived class -> Base class
4. Member of class - Reverse order of declaration 

DYNAMIC MEMEORY ALLOCATION: 

new - dynamically allocates memory on the heap, ANYTHING created with new MUST be manually deleted with delete or delete[]
delete - Calls deconstructor and frees the memeory in heap


Single variable: 
int* ptr = new int; 
*ptr = 10; 

Arrays: 
int* arr = new int[5]; 
delete[] arr; 

Class: 
Book* b = new Book("1985"); <-- Allocates memeory on heap, calls constructor, returns pointer to that object
delete b; 

STATIC:

1. Used outside a class
- Limits variable/function visibility to only the file it is declared in 
- Ensures a global variable/function does not hinder with another variable in another file 

For example: 

Instance 1) Global variables collide
File1: 

int x = 5; <-- global variable 

File 2: 

int x = 10; <-- global variable, will have error 

Instance 2) Using static 
File1: 

static x = 5; <-- Will only be seen in File1 

File 2: 

int x = 10; <-- This is now ok 

To reference variables from other files: 
extern int x; <-- looks for x in external files, x cannot be static 


2. Used inside a class 
- Share memeory with all instances with the class 
- A static variable in a class will count as 1 variable for all instances of the class, if that one variable is changed, it will be reflected for all instances of the class  

class Entity{
  public: 
    static int x, y; 

    static void print(){
    cout << x, y; 
    }
}

int Entity::x; <-- Need these to allocate memory for x and y 
int Entity::y; 
 
int main(){
  Entity e; <-- No need to create objects
  Entity::x = 2; 
  Entity::y = 5; 

  Entity e1; 
  Entity::x = 6; <-- These will change x and y that was declared before for both e and e1
  Entity::y = 7; 
  
  Entity::print(); 


}
*/
int main(){

}