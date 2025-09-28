#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;


void readInts() {

  // Your code here
  int number = 0;
  while(number != '.'){
    cin >> number; 
    if(cin.fail()){
      cin.clear();
      cin.ignore(1000, '\n'); 
      cout << "Error"; 
      break; 
    }
    else{
      cout << number; 
    }
  }
  if(number == '.')
    cout << "Done"; 

}

int main(){
    readInts(); 
    return 0; 
}