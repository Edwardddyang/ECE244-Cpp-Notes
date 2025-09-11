#include <iostream> 
using namespace std; 

/*
Operator Overloading - Giving it a new meaning, or adding parameters, creating 
- Changes the behaviour of an operator 

General layout: 

//Defining the class 
Class Vector2{
public: 
  int x, y; 

  Vector2(int x_, int y_){ <-- Constructor 
    x = x_ ;
    y = y_;
  }
}

//Defining the Add function 
Vector2 Add(const Vector2& other){
  return Vector2(x + other.x, y + other.y); <- Using the constructort to create another Vector2  
}

//Redefining the '+' operator 
Vector2 operator+(const Vector2& other){ <-- The + can be any operator 
  return Add(other); 
{

To call it: 
Vector2 function_name = Class1 + Class2;   

BOOL Operator Overloading: 

bool operator==(const Vector2& other){
  if(x == other.x && y == other.y){
    return true; 
  }
  return false; 
}

Friends:
Can make operator overload a friend of the class so that when you overload as a non member function it can still access private members 

class Foo{
  private: 
    int x; 
  public: 
    friend Foo operator+(const Foo& lhs, const Foo& rhs); 
};

Foo operator+(const Foo& lhs, const Foo& rhs){
  Foo t(lhs.x + rhs.x); 
  return t; 
}


TIPS: 
1. C++ CREATES MANUAL COPY CONSTRUCTOR 
2. Const before function does not allow you to change any members in the object. Only use const when you are not modifying the current object. Dont use const when modifying *this. 
3. Putting & in the parameters makes sure you do not call the parameter 
4. Use Foo& operator=(...) because you are not creating a new object, so pass by reference makes sure you do not pass a copy but the real thing. Use Foo& to modify current object. 
5. No need to create a deconstructor if all your objects are in the stack, c++ deconstructs for you  
If Foo operator+(...) to return new object. 
6. If your class has data members that are pointers to other data, then create your own default constructor, copy constructor, assignment operator, and destructor 

If creating new object: Use Foo and const 
If modifying object: use Foo& and no const, return *this 
*/

int main(){




}