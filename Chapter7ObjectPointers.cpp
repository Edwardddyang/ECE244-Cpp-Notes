#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std; 

/*
//Use -> to deference pointer first, then access members of the class 

class ComplexNumber{
  private: 
    int real;
    int imaginary; 

  public: 
    ComplexNumber();
    ComplexNumber(int x, int y){
      real = x; 
      imaginary = y; 
    } 
    void displayData(){
      cout << real << " " << imaginary; 
    }
    int getReal(){
      return real; 
    }
    int getImage(){
      return imaginary; 
    }
};

ComplexNumber add(const ComplexNumber& n1, const ComplexNumber& n2){ 
  int r; 
  int o; 
  r - n1.getReal() + n2.getReal(); 
  o = n1.getImage() + n2.getImage(); 
  ComplexNumber temp(r, o); 
  return temp; 
}

int main(){

  ComplexNumber comp1(5, 4); 
  ComplexNumber comp2(5, 4); 
  ComplexNumber comp3 = add(comp1, comp2); 

  ComplexNumber* ptr; 
  ptr = &comp3; 
  ptr->displayData(); 

}

*/ 