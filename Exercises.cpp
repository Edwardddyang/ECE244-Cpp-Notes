#include <iostream>
using namespace std; 

// CHAPTER 1: PROGRAMMING BASICS

//Question 1: 

Function is not declared before it is called 

//Question 2: 

4
4
8

//Question 3:

void swap_by_p(int* a, int* b) {
  int temp = *a; 
  *a = *b; 
  *b = temp; 
  }
  void swap_by_r(int& a, int& b) {
  int temp = a; 
  a = b; 
  b = temp; 
  }
  
  swap_by_p(&x, &y);
  swap_by_r(x, y); 

//Question 4: 

g++ ECE.cpp student.cpp main.cpp -o small_database 

#ifndefine student 
#define student 

g++ -c ECE.cpp -o ECE.o
g++ -c student.cpp -o student.o
g++ -c main.cpp -o main.o
g++ main.o ECE.o student.o -o small_database 

g++ -c ECE.cpp -o ECE.o 
g++ main.o ECE.o student.o -o small_database 

//Question 5: 

g++ -c First.cpp -o First.o 
g++ -c Second.cpp -o Second.o 
g++ -c Third.cpp -o Third.o 
g++ -c main.cpp -o main.o 
g++ First.o Second.o Third.o main.o -o main 

g++ -c Second.cpp -o Second.o
g++ First.o Second.o Third.o main.o -o main 

g++ -c First.cpp -o First.o 
g++ -c Second.cpp -o Second.o 
g++ -c main.cpp -o main.o 
g++ First.o Second.o Third.o main.o -o main 


//CHAPTER 2: CLASSES: 

//Question 1: 

A new book is added.
Book Pride and Prejudice is added. 
A new book is added. 
Book Wuthering heights is added. 
Book Pride and Prejudice is removed. 
A new book is added. 
A new book is added.
Book Wuthering heights is removed. //b4 is created in the stack in the if statement, so it is deleted once out of if loop
Book ECE244 is removed. //As return from main, b3 is removed 
//b5 is not removed since it is created with new and it is never deleted 

//Question 2: 

A and C //num_student and get_num_instructor() are private 

//Question 3: 

Constructor 2 5
Constructor 1 0 
Constructor 1 0
5
0
Destructor 
Destructor 
Destructor 

//CHAPTER 3: INPUT/OUTPUT: 

//Question 1: 

int main() {
  int a;
  ifstream inFile; 
  inFile.open("input.txt");
  if (inFile.fail()) {
    return 1;
  }
  while (1) {
    inFile >> a;
    if (inFile.fail()) {
      cout << "failed.." << endl;
      inFile.clear();
      inFile.ignore(100, '\n');
      continue;
    }
    cout << "a = " << a << endl;
    break;
  }
  return 0;
}

1. 1
2. failed... //a is int, not a32 
failed... //a is int, not b86 
a = 3
3. failed... //a is int, not a32 
failed... //a is int, not b86 
//Infinite loop 
4. 1 
5. failed... //Infinite loop 
6. failed... //Infinite loop 

//Question 2: 

void readInts(){
  int x; 
  string dot; 
  cin >> x; 
  while(!cin.fail()){ //Inputted an integer 
    cout << x << endl; 
    cin >> x; 
  }
  cin.clear(); //If cin fails, clear it 
  cin >> dot; 
  if(dot == '.'){
    cout << "Done";
  }
  else{
    cout << "Error"; 
  }
}

//Question 3: 

//Question 4: 

1. 10 
2. 10 

//Question 5: 

void readInts() {

  int x; 
  cin >> x; 
 
  while(!cin.eof()){
    if(cin.fail()){
      cout << "Invalid Input" << endl; 
      cin.clear(); 
      cin.ignore(1000, '\n'); 
      cin >> x; 
    }
    else{
      cout << x << endl; 
      cin >> x; 
    }
    }
    cout << "End of file reached" << endl; 
  }


//CHAPTER 4 POINTERS:

//Question 1: 

0
2
4
Check Point 1
1
Check Point 2

//Question 2:

cout << *p; 
cout << **t;  
cout << (**s) / 2; 
//r is not answer because 

//Question 3: 

1. 4 4
2. 2 and 4 

//Question 4: 

(3, 4)
(3, 3) //Because y was only incremented on the copy 


//CHAPTER 5: DYNAMIC MEMORY ALLOCATION

//Question 1:

Stack:  
n - 4 bytes 
size - 4 bytes 
q - 4 bytes 
i - 4 bytes 

Heap: 
24 bytes 

//Question 2:

Point 1: 
a: 1
*b: 1
**c: 1
*g: nullptr 
*f = 5 

Point 2: 
a: 2
*b: 6
*c: 6  
*g: 11 
*f: 6 

//Question 3: 


Vtuber::Vtuber (const string& _name){  

  name = _name;
  follower_max = 2; 
 
  followers = new Follower*[follower_max]; 
  for(int i = 0; i < 2; i++){
    followers[i] = NULL; 
  }
}

void Vtuber::insert_follower(const string& follower_name, int follower_age){

  follower_num++; 
  for(int i = 0; i < follower_max; i++){
    if(followers[i] == NULL){
      followers[i] = new Follower(follower_name, follower_age); 
      return; 
    }
  }
  
    int new_max = 2 * follower_max; 
    Follower** new_followers = new Follower*[new_max]; 

    for(int j = 0; j < follower_max; j++){
      new_followers[j] = followers[j]; 
    }
    for(int j = follower_max; j < new_max; j++){
      new_followers[j] = NULL; 
    }
    new_followers[follower_max] = new Follower(follower_name, follower_age); 

    delete[] followers; 
    followers = new_followers;
    follower_max = new_max;  
    return; 
  }

  void Vtuber::remove_follower(const string& follower_name) {

  for(int i = 0; i < follower_max; i++){


    if(followers[i] != nullptr && follower_name == followers[i]->get_name()){
      follower_num--; 
      delete followers[i]; 
      followers[i] = nullptr; 
    }

  }

}

//CHAPTER 6 OPERATOR OVERLOADING: 

//Question 1: 

#include <iostream>
using namespace std;
#include “Nova.h”
int main() {
  Nova a(3, 8.1); //Constructor needed here: Nova(int x, double y); 
  Nova* p; 
  Nova b(a); 
  ++a.it; //int or double it 
  a.setAll(1, 7.8); //Function needed here: void setAll(int x, double y); 
  p = new Nova(9, 12.7);
  if (a != b) //Operator overloading here: bool operator!=(const Nova& other); 
    *p = a + b; //Operator overloading here: Nova operator+(const Nova& other); 
  delete p;
  return 0;
}

//Question 2: 

class Foo {
 private:
  int priv;

 public:
  Foo(int pv) { priv = pv; }
  Foo(const Foo/*&*/ src) { priv = src.priv; } //Use & or else you will be calling the constructor 
  Foo& operator=(Foo& rhs) /*const*/ { //Get rid of const since you are modifying the current object 
    priv = rhs.priv;
    return /**this*/this; //Use *this since this is a pointer to the object, but you want to return the object 
  }
  int getPriv() const { return priv; }
  void setPriv(int pv) { priv = pv; }
};

//Question 3: 

 Shape circle(5); //Constructor 2 5
  Shape* line1[2]; 
  Shape* polygon = new Shape(circle); //Constructor 3 5 
  line1[0] = polygon; 
  line1[1] = polygon;
  *polygon = circle; //Constructor 3 5
  //Operator = 5  
  //Deconstructor 
  Shape line2[2]; //Constructor 1 0 
  //Constructor 1 0 
  line2[0] = *polygon; //Constructor 3 5 
  //Operator= 0 
  //Deconstructor 
  cout << (*(line1[0])).getID() << endl; //5 
  cout << getID(*line1[1]) << endl; //Constructor 3 5 
  //5 
  //Deconstructor 
  cout << getShapeID(*line1[0]) << endl; //5 
  //Deconstructor, from circle
  //Deconstructor, from line2[0]
  //Deconstructor, from line2[1] 
  //There is memeory leak from polygon, line1 points to polygon 

//Question 4: 

string n = "hello";
  Mystery x(3, n); //Constructor: Mystery(int, string); 
  Mystery* p = new Mystery(n, 4); //Constructor: Mystery(string, int); 
  Mystery y(x); //Copy constructor; Mystery(const Mystery&);
  x.invert(1, n); //Function: void invert(int, string); 
  if (x == y) //Operator: bool operator==(const Mystery& other); 
    x = y / *p; //Operator: Mystery operator/(const Mystery& other); 
    //Operator: Mystery& operator=(const Mystery& other); 
  delete p; //Deconstructor: ~Mystery(); 
  return 0;

  //Question 5: 

  vector_2d& operator+=(const vector_2d& rhs) {
  x += rhs.x; //No need for get_x() since the function is declared within the class, so x and y are accessible 
  y += rhs.y;
  return *this; //this returns vector_2d* type, so deference it 
}

//Question 6: 

//Inside the class 
Fraction operator*(const Fraction& other);
Fraction operator*(int number); 

//Outside the class 
Fraction Fraction::operator*(const Fraction& other){
  return Fraction(numerator * other.numerator, denominator * other.denominator); 
}
Fraction Fraction::operator*(int number){
  return Fraction(numerator * number, denominator); 
}

//CHAPTER 7: OBJECTS WITH POINTERS:

//Question 1: 

1. No problem, returning a DayofYear object 
2. No problem, returning a single copy of the DayofYear object 
3. DayOfYear& doIt(DayOfYear& arg) {
  DayOfYear temp;
  temp = arg;
  return (*this);
}
Has a problem. this can only be used in a member function. Question states non member function 
4. DayOfYear& doIt(DayOfYear& arg) {
  DayOfYear temp;
  temp = arg;
  return (temp);
}
Has a problem. temp is a local variable in the function. Returning it by reference when temp is out of scope will be undefined. 

//Question 2: 

int main() {
  Duo X(3, 5); //*p = 3, *q = 5
  Duo Y(8, 9); //p = 8, *q = 9
  Duo Z(2, 4); //p = 2, *q = 4
  Z = X.funnyMultiply(Y); //Z: *p = 24, temp *q = 45 
  //Y: *p = 7 *q = 8 
  Z.print();  // Statement 1: 24 45 
  Z.set_a(1); //Z: *p = 1, *q = 2; 
  Z.set_b(2);
  Z.print();  // Statement 2: 1 2
  X.print();  // Statement 3: 3 5
  Y.print();  // Statement 4: 7 8
  Duo W(6, 12); 
  Duo V(2, 3);
  W.print().funnyMultiply(V).print();  
  // Statement 5: 6 12 
                //12 36 
//W: *p = 6, *q = 12; 
  W.print(); // Statement 6: 6 12
  // Point A
  cout << "Program is done" << endl;
  return (0);
}

Memory leak: 

Duo Z(2, 4) dynamically allocated 2 integers to the heap. 
Z = X.funnyMultiply(Y) created a Duo temp(0,0), making Z lose access to the first assigned pointers 


//CHAPTER 8: LINKED LIST:

//Question 1: 

class ListNode {
 public:
  int key;
  ListNode* next;
};

ListNode* head;

// Non-member function invoked as traverse(head)

void traverse(ListNode* h) {
  if (h == nullptr)
    return;
  ListNode** ptr = &(h->next); 
  // Line 1 removed
  cout << h->key << endl; 

  while (*ptr != nullptr) {
    // Line 2 removed
    cout << (*ptr)->key << endl; 
    // Line 3 removed
    ptr = &((*ptr)->next); 
  }
}

//Question 2: 

void removeNode(ListNode* node){
    
  ListNode* temp = node->next; 
  node->key = temp->next; 
  node->next = temp->next;
  delete temp; 

}

//Question 3: 

void push_back(int k){

  data.insertKeyatTail(k); 

}

int front(){
  int d; 
  bool empty = data.deleteHead(d); 
  if(empty == false){
    return -1;
  }
  else{
    data.insertKeyatHead(d); 
    return d; 
  }
}

bool isempty(){
  int d; 
  bool empty = data.deleteTail(d); 
  if(empty == false){
    return true; 
  }
  else{
    data.insertKeyatTail(d);
    return false; 
  }
}

int pop_front(){
  bool empty = data.deleteHead(d); 
  if(empty == false){
    return -1; 
  }
  else{
    return d;  
  }
}

//Question 4: 

class ListNode {
 public:
  int id;
  ListNode* next;
};
ListNode* head;

void traverse(ListNode* h) {

if(h == nullptr)
  return; 

ListNode* current = h; 
while(current->next != h){
  cout << current->id <<endl; 
  current = current->next; 
}
}

void deleteNode(ListNode*& h, ListNode* p) {

  if(h == nullptr){
    return; 
  }
  if(h->next = h){
    delete h; 
    h = nullptr; 
    return; 
  }
  if(p->next == h){
    h = h->next; 
    ListNode* gone = p->next;
    p->next = gone->next;
    delete gone;  
  }
  else{
  ListNode* gone = p->next; 
  p->next = gone->next; 
  delete gone;  
  }

}

bool isCircular(ListNode* h) {

  if(h == nullptr)
  return true; 

  ListNode* current = h; 
  while(current->next != h && current->next != nullptr){
    current = current->next;
  }
  return current ->next == h;

}

//CHAPTER 10 COMPLEXITY ANALYSIS:

//Question 1: 

for (int i = 0; i < n; i++) {//Goes up to n, O(n) 
  for (int j = 0; j * j < n; j++) {//Goes up to j^2 < n, j < sqrt(n), O(sqrt(n)) 
    // some code with o(1)
  }
}
//O(n) * O(sqrt(n)) = O(n^(3/2)

for (int i = 0; i < n; i++) {//Goes up to n, O(n)
  for (int j = 0; j * j < 1000000; j++) {//Goes up to j < sqrt(1000000), O(1) since its a constant 
    // some code with O(1)
  }
}
//O(n) * O(1) = O(n)

for(int i = 1; i < n ; i = i*2){ //i is doubling, so as n gets bigger, itll take less time to reach it, O(log2 n)
  for(int j = 0; j < n; j++){ //Goes up to n 
    // some code with O(1)
  }
}
//O(log n) * O(n) = O(nlog n)


//Question 2:

int Amy(int n) {
  if (n == 0) {
    return 1;
  } else {
    return Amy(n - 1) + Amy(n - 1);
  }
}
//Makes 2 recursive calls for each level, creating a binary tree. O(2^n)

int John(int n) {
  if (n == 0) {
    return 1;
  } else {
    return (2 * John(n - 1));
  }
}
//Creates a linear chain of recursive calls. +1 for each time it is called. O(n) 


//CHAPTER 11 INHERITANCE: 

//Question 1: 

Constructor 1 of firstOne done 

Constructor 2 of firstOnedone 

Constructor 1 of firstOne done 
Constructor 1 of secondOne done 

Constructor 2 of firstOne done 
Constructor 2 of secondOne done 

//Question 2: 

#include <iostream>
using namespace std;
class Shape { //Abstract class 
 protected:
  int shapeID; 

 public:
  int getID() { return shapeID; }
  void setID(int k) { shapeID = k; }
  virtual void draw() = 0; //Pure virtual function 
  virtual void print() = 0; //Pure virtual function 
};
class Circle : public Shape {
 protected:
  float radius; 

 public:
  float getRadius() { return radius; }
  void setRadius(float r) { radius = r; }
  virtual void draw() { 
    // code to draw
  }
};
class Rectangle : public Shape {
 protected:
  float length;
  float width;

 public:
  float getLength() { return length; }
  void setLength(float x) { length = x; }
  float getWidth() { return width; }
  void setWidth(float x) { width = x; }
  virtual void draw() {
    // Code to draw
  }
  virtual void print() {
    // Code to print
  }
};

Shape is an abstract class, cannot create objects of that type 

Circle is also an abstract class since print is also a pure virtual function 

No error, Rectangle is not an abstract class and setID is a public function 

Error, length is a protected memeber, it cannot be accessed in outside code 

//Question 3: 

int main() {
  Dessert a; //Won't compile, Dessert is an abstract class 
  Cookies b(2, 300);
  IceCream c("Vanilla", 2, 350);
  return 0;
} 

int main() {
  Dessert* pc; 
  IceCream* pi;
  pc = new Cookies(2, 250); //we have desserts 
  //we have cookies 
  pi = new IceCream("mint", 1, 250); //we have desserts 
  //we have mint icecream 
  delete pc; //no more dessert, no "no more cookies" because the destructor isnt virtual, so the destructor for cookies is not used since it doesnt override it.  
  delete pi; //no more icecream 
  //no more dessert 
  return 0;
}

int main() {
  Sundae* ps; 
  IceCream* pi;
  pi = new IceCream("mint", 1, 250); //Calls base and derived constructor 
  //we have dessert 
  //we have mint icecream 
  ps = pi; //Cannot be compiled, 
  delete ps;
}

int main() {
  Dessert* ps = new IceCream("vanilla", 2, 350); 
  //we have dessert 
  //we have vanilla icecream 
  cout << ps->cost() << endl; 
  //700 
  return 0;
}

//Question 4: 

No, a is a private member in the base function 

Yes, b is a protected member, so the derived class has access to it 

Yes, x is part of the DerivedC class 

Yes, w is part of DerivedC class 

//Question 5: 

int main() {
  Capacitor c(150); 
  //circuit element with code 
  //capacitor 
  PowerResistor p(180, 350); 
  //circuit element
  //resistor 
  //power resistor 
  
  return 0;
  //no power resistors 
  //no resistor 
  //no circuit element 
  //no capacitor 
  //no circuit element 
}

int main() {
  CircuitElement* pr; 
  pr = new PowerResistor(200, 250);
  //circuit element 
  //resistor 
  //power resistor 
  delete pr;
  //no circuit element 
  //Destructor isnt virtual, so the program only knows that pr is of CircuitElement type, virtual tells the program to decide what type it is at runtime 
  return 0;
}

int main() {
  Capacitor* c; 
  //compile warning, cant make a derived class be a base class type 
  c = new CircuitElement(5);
  delete c;
  return 0;
}

int main() {
  PowerResistor* pr; 
  Resistor* r;
  r = new Resistor(450);
  //resistor 
  pr = r;
  //compile warning, cant make a derived class to base class type 
  delete pr;
  return 0;
}

int main() {
  PowerResistor r(250, 1000); 
  //circuit element with code 
  //resistor 
  //power resistor 
  CircuitElement e;
  //circuit element with code 
  e = r;
  return 0;
  //no circuit element 
  //no power resistor 
  //no resistor
  //no circuit element 
}

int main() {
  CircuitElement* e = new PowerCapacitor(500, 1000); 
  //circuit element with code
  //capacitor 
  //power capacitor 
  e->print();
  //Capacitor: 500 
  //Power capacitor: 1000 
  return 0;
} 

int main() {
  Capacitor* c = new PowerCapacitor(300, 100); 
  //circuit element with code 
  //capacitor 
  //power capacitor 
  cout << c->getPower() << endl;
  0.0 
  return 0;
}

int main() {
  PowerResistor pr(20, 100); 
  //circuit element with power
  //resistor 
  //power resistor 
  Resistor* r = &pr;
  cout << r->powerResistance() << endl;
  //compile error, powerResistance does not exist in Resistor 
  return 0;
  }

//Question 6: 

//student is an abstract class since it has pure virtual functions. eng_student is also an abtract function since it does not implement virtual void print_department. Abstract classes cannot be initialized. 

student
cs student
student 
eng student
ece student 
student 
eng student 
mie student 
student 
eng student 
ece student 

Department: 

//CHAPTER 12 BINARY SERACH TREE: 

//Question 1: 

1, 2, 3, 4, 5, 6, 7
3, 2, 4, 1, 5, 7, 6
3, 4, 2, 7, 6, 5, 1