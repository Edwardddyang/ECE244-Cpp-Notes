/*
Inheritance allows a base class, and then create subclasses based off that base class
Subclasses must call base constructor 
General template: class subclass_name : public class base_class1, public base_class2{}
Avoids duplication 

//Base class 
class Entity{
public: 
  float X, Y; 

  void move(float x, float y){
    X += x; 
    Y += y; 
  }
};

//Subclass, includes all members of the entity class 
class Player : public Entity{
public: 
  const char* name; 
  void printName(){
    cout << name << endl; 
  }
}

Polymorphism: 

- Allows objects of different types to be treated as instances of the same type 
Compile time polymorphism: Function overloading, operator overloading 
Runtime polymorphism: Virtual functions 

Without polymorphism:

class Dog{
public: 
  void makeSound(){cout << "Woof";}
};

class Car{
public: 
  void makeSound(){cout << "Meow";}
}; 
void playWithDog(Dog& dog){dog.makeSound();}
void playWithCar(Car& cat)(car. makeSound();)

With polymophism: 

class Animal{
  public: 
    virtual void makeSound() = 0; //Pure virtual function
};
class Dog : public Animal{
  public: 
    void makeSound() override {cout << "Wolf";}
};
class Car : public Animal{
  public:
    void makeSound() override {cout << "Meow";}
}; 
void playWithAnimal(Animal& animal){//Only one function is needed 
  animal.makeSound(); 
}

Pure Virtual Function: 
- A virtual function that has not implementation and declared by assigning it to 0 
- Must be overriden by an non-abstract class 

Abstract class - Has at least one pure virtual function 

Destructors: 
Virtual functions with polymorphism usage NEED virtual destructors 

Rules: 
Deleting through derived pointer: Always calls full destructor chain (derived → base)
Deleting through base pointer with non-virtual destructor: Only calls base destructor
Deleting through base pointer with virtual destructor: Calls full destructor chain

Pointers: 

Can only assign pointers UP (Dessert = Icecream) the inheritance, never sideways (sibling classes) or DOWN (icecream = dessert) 
*/