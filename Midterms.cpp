#include <iostream> 
#include <string> 
#include <fstream> 
#include <sstream> 
using namespace std; 

//MIDTERM 2022: 

1. 8 
2. e
3. b
4. A, C 
5. hello function is not defined before calling it 
6. Stack: n = 4 bytes, size = 4 bytes, i = 4 bytes, q = 4 bytes 
    Heap: 6 ints x 4 bytes 
7. 4, 4, 8 
8a) a = 1, 
failed.. failed.. a = 3, 
failed.. failed.. forever 
8b) a = 1 
failed.. failed.. forever 
failed.. failed.. foever 
9a) void swap_by_p(int* a, int* b){
  int temp = *a;
  *a = *b; 
  *b = temp; 
}
void swap_by_r(int& a, int& b){
  int temp = a; 
  a = b; 
  b = temp; 
}
9b) swap_by_p(&a, &b); 
9c) swap_by_r(a, b); 

10a) g++ ECE.cpp main.cpp student.cpp -o small_database_exe
10b) student.h should include header guards 
10c) g++ -c ECE.cpp -o ECE.o 
g++ -c student.cpp -o student.o 
g++ main.cpp -o main.o 
g++ ECE.o student.o main.o -o small_database_exe 
10d) g++ ECE.cpp -o ECE.o 
g++ ECE.o student.o main.o -o small_database_exe 
11. vector_2d& operator+=(const vector_2d& other){
  x += other.x; 
  y += other.y; 
  return *this; 
}
12. 0, 2, 4 Checkpoint 1 
    1 Checkpoint 2
13. 
#include <string>
using namespaces std;

class Follower{
  private: 
    string name;
    int age; 
  public: 
    Follower(const string& _name, int _age){
      name = _name; 
      age = _age; 
    }
    string get_name() const{
      return name; 
    }
    int get_age() const{
      return age; 
    }
};

class Vtuber{
  private: 
    string name; 
    Follower** followers;
    int follower_max;
    int follower_num; 
  public: 
    Vtuber(const string& _name);
    ~Vtuber(); 
    void insert_follower(const string& follower_name, int follower_age); 
    void remove_follower(const string& follower_name); 
}

Vtuber::Vtuber(const string& _name){
  name = _name; 
  follower_max = 2; 
  follower_num = 0;
  followers = new Follower*[follower_max]; 
  for(int i = 0; i < follower_max; i++){
    followers[i] = NULL; 
  }
}

void Vtuber::insert_follower(const string& follower_name, int follower_age){

  follower_num++; 
  Follower* newFollow = new Follower(follower_name, follower_age); 
  for(int i = 0; i < follower_max; i++){
    if(followers[i] == NULL){
      followers[i] = newFollow; 
      return; 
    }
  }
  int new_follower_max = follower_max * 2; 
  Follower** newarray = new Follower*[new_follower_max]; 
  for(int i = 0; i < follower_max; i++){
    newarray[i] = followers[i]; 
  }
  for(int i = follower_max; i < new_follower_max; i++){
    newarray[i] = NULL; 
  }
  newarray[follower_max] = newFollow; 
  delete[] followers; 
  followers = newarray; 
  follower_max = new_follower_max; 
}

void Vtuber::remove_follower(const string& follower_name){

  for(int i = 0; i < follower_max; i++){
    if(followers[i] == NULL){
      continue;
    }
    if(followers[i]->get_name() == follower_name){
      follower_num--; 
      delete followers[i]; 
      followers[i] = NULL; 
      break; 
    }
  }
  return; 
}

Vtuber::~Vtuber(){

for(int i = 0; i < follower_max; i++){
  delete followers[i]; 
}
delete[] followers; 

}

//2022 MIDTERM: 

1. true, false, true, false, true, false, false, 
b, d, b 

2. 
g++ -c First.cpp -o First.o 
g++ -c Second.cpp -o Second.o 
g++ -c Third.cpp -o Third.o 
g++ -c main.cpp -o main.o 
g++ First.o Second.o Third.o main.o -o main.exe 

g++ -c Second.cpp -o Second.o 
g++ First.o Second.o Third.o main.o -o main.exe 

g++ -c First.cpp -o First.o 
g++ -c Second.cpp -o Second.o 
g++ -c main.cpp -o main.o 
g++ First.o Second.o Third.o main.o -o main.exe 

3. 
4. 4 4, F, 
5. 
int temp = head->ID; 
head-> ID = head->next->next->ID 
head->next->next->ID = temp;  

node* temp_ptr = head->next; 
head->next = head->next->next; 
head->next->next = temp_ptr; 
temp_ptr->next = nullptr; 

6. 1 //Point X 
+4 //Point Y: 5
+8 //Point W: 13  
+1 //Point Z: 14 

7. 
class Foo{
  private: 
    int priv; 
  public: 
    Foo(int pv){priv = pv;} //Fine 
    Foo(const Foo src){priv = src.priv;} //Use & so that it doesnt make a copy 
    Foo& operator=(Foo& rhs)const{ //Get rid of the const so that you can modify the members
      priv = rhs.priv; 
      return this; //return *this 
    }
    int getPriv()const{return priv;}
    void setPriv(int pv){priv = pv;}
}
8. 
Method 1 
Compile Error //No default constructor  
None  
Method 4 //Wrong, right answer is compile error since no default constructor
Method 1, Method 2
Method 1, Method 2 since you are creating object so it creates a copy. 
Method 1, Method 4, Method 2 since = passes by value so it create a copy, Method 3 since the copy goes out of scope 

9. 
Constructor 2 5 
Constructor 3 5 
Constructor 3 5 
Operator= 5 
Destructor 
Constructor 1 0 
Constructor 1 0 
Constructor 3 5
Operator= 0 
Destructor 
5
Constructor 3 5 
5 
Destructor 
5
Destructor

10. 
Copy function: aVector(const aVector other); 
Default constructor: aVector(); 
Operator overload: aVector& operator=(const aVector other); 
Destructor: ~aVector(); 

11. Put the destructor ~Mystery(); as a private member 

12. 
for(int i = 0; i < n; i++){
  delete *(p[i])
  delete p[i]; 
}

delete[] p; 

13. 

 myVector operator+(const myVector& other) const{
      myVector product(size); 
      for(int i = 0; i < size; i++){
      product.theVector[i] = theVector[i] + other.theVector[i]; 
      }
    return product; 
  }

//MUST change to int getElement(int i)const{return theVector[i];}
myVector operator+(const myVector& other, const myVector& other2){

  myVector product(other.getSize()); 
  for(int i = 0; i < product.getSize(); i++){
    product.setElement(i, other.getElement(i) + other2.getElement(i)); 
  }
  return product; 
}

14. 

Mystery& operator=(const Mystery other){
  *leftside = *(other.leftside); 
  *rightside = *(other.rightside);
  return *this; 
}
int main(){



}


