#include <iostream> 
#include <string> 
#include <fstream> 
#include <cmath> 


using namespace std; 

//2021

//Question 1: 

Generates error, no default constructor 
No error 
up_length is private 
len is private 
no error 
error, set_length is not with an object 

//Question 2: 
/*
Puesdocode: 
  Create a string and int variable. Cin and cout the int variable until it fails. clear the variable and cin it as a string. 
*/
int main() {

  string character; 
  int read; 

  cin >> read; 
  while(!cin.fail()){
    cout << read << endl; 
    cin >> read; 
  }
  cin.clear(); 
  cin >> character; 
  if(character == ".")
    cout << "Done\n";
  else 
    cout << "Error\n";
}

//Question 3: 

cout << *p; 
cout << (**s)/2; 
cout << **t; 

//Question 4: 

Shape*** a = new Shape**[n]; //An dynamically allocated array that stores n Shape**, pointer of pointers. 
for(int i = 0; i < n; i++){
  a[i] = new Shape*; //Each a[i] holds a pointer, which now stores a pointer to a object of Shape; 
  *(a[i]) = new Shape(); //The values of these pointers are an object of Shape 
}

//Question 5: 

B* helper_one(B& b){
  A a(5); // + 1 
  A x(4); // +1 
  B q; // +1 
  B* p; 
  q = b; 
  p = &b;
  //Point Y
  return(p); 
}

B* helper_two(B b){// +1, creates copy of object y; 
  B a; // +1 
  B q; // +1 
  B* p; 
  q = b; 
  p = new B(); // +1 
  //Point W 
  return (p); 
}

int main(){
  B x; //a = new A(0); creates object of A, 1
  B y; //2
  B z; //3 
  //Point X // +3
  z = *helper_one(x); //Point Y +3 
  //Point Z // -2 
  z = *helper_two(y); //0, because helper_two uses B constructor, which creates type A objects in the heap, and they are not deleted after the function  
  //Point V
  return (0); 
}

//Question 6: 

void traverse(ListNode* h){
  if(h == nullptr)return; 
  ListNode** ptr = &(h->next); 
  cout << h->key << endl; 
  while(*(ptr) != nullptr){
    cout << *(ptr)->key; 
    ptr = &(*ptr->next);  
  }
}

//Question 7: 

void RemoveNode(ListNode* node){ //Move the data from the next to the one you want to remove, then remove the next 

  ListNode* next = node->next;
  node->key = next->key; 
  node->next = next->next; 
  delete next; 
}

//Question 8: 

void push_back(int k){
  data.insertKeyatTail(k); 
}

int front(){
  int d = -1;
  if(data.deleteHead(d))
    data.insertKeyatHead(d);
  return d; 
}

bool isempty(){

  int d = 0; 
  bool empty = data.deleteTail(d); 
  data.insertKeyatTail(d); 
  if(empty)
    return false; 
  else return true; 
}

int pop_front(){

  int d = -1; 
  data.deleteHead(d); 
  return d; 
}

//Question 9 

void prefixsum(int* arr, int left, int right, int psum){

  if(right < 0) return; //Once you reached the end of the list 
  psum += arr[left]; //Total sum of all past traverses + arr[left]
  arr[left] = psum; //arr[left] because the sum of itself + everything beforehand 
  return prefixsum(arr, left + 1, right - 1, psum); //Moves to the next unit in the list, and gives the new total sum 

}

//Question 10:

//Preorder: 1, 2, 3, 4, 5, 6, 7 
//Inorder: 3, 2, 4, 1, 5, 7, 6
//Postorder: 3, 4, 2, 7, 6, 5, 1

//Question 12: 

int count_interior(TreeNode* r){
  int count = 0; 
  if(r == nullptr)
    return 0; 
  if(r->left != nullptr || r->right != nullptr)
    count = 1; 
  count += count_interior(r->left); 
  count += count_interior(r->right); 
  return count; 
}

//Question 13: 

void Tree::post(){

  TreeNode* temp = root; 
  if(root == nullptr) 
    return; 
  root = root->getLeft(); 
  post(); 
  root = root->getRight(); 
  post(); 
  root = temp; 
  cout << root->key << endl; 
}

//Question 14: 

//This function only checks each individual node and its children, not the entire tree
//Tree would come out as true 
    3
  2   5
1  4 
bool isBST(TreeNode* node){
  if(node == NULL)
    return true;
  if(node->left != NULL && node->left->data >= node->data)
    return false; 
  if(node->right != NULL && node->right->data <= node->data)
    return false; 
  if(isBST(node->left) && isBST(node->right))
    return true; 
  return true; 
}

//Question 16:

//first for loop O(n)
//second for loop j^2 < n, j < sqrt(n) 
//O(n) * O(sqrt(n)) = O(n^(3/2)) 

//first for loop O(n)
//second for loop O(1)
//O(n)

//first for loop O(log n)
//second for loop O(n)
//O(n log n)

//Question 17: 

Both work 
Amy: O(2^n)//2 more calls are needed for every node on a level that Amy is called. 
//If 
        Amy(3)
  Amy(2)     Amy(2)
Amy(1) Amy(1) Amy(1) Amy(1)

John: O(n)

//Question 18: 

1. Invalid, Base is an abstract class since it has a pure virtual function 
2. Invalid, pr = r is not possible since pr is a subclass of r, 
3. Valid, r is the base class of pr
4. Invalid, Derived A and Derived B are different types of objects 
5. Valid, uses a member of the base class 
6. Valid 
7. Valid, pointer of same object 
8. Valid, pointer of a subclass 
9. Invalid, subclass pointer cannot store base class 
10. Invalid, r_p is of DerivedA base class, so it cannot access getP() in DerivedAA  
11. Valid, print() is in DerivedA class 

//Question 19: 

1. 
Person with ID 1 lives at 123 
The person's name is A 
2. 
Student with ID 2 has a GPA of 3.9 
The student's name is EMPTY 
//Constructor of student does not store the name, address, and id, to do so, the constructor must include :person(l_name, l_address, l_id); 
//Cannot do name = l_name because those are private members of the person class 
3. 
The person's name is A 
4. 
The person's name is EMPTY //Uses the person class because p_ptr is of person type 
5. 
Person with ID 0 lives at EMPTY
6. 
Cannot compile 

//Question 20: 

//2019: 

//Question 1: 

Mystery doSomething((Mystery*)& p);

11
13.5

10 16 

//Question 2: 

void create_line(int x_a, int y_a, int x_b, int y_b){
  Line* line_ptr; 
  Line** pptr = &line_ptr; 

  *pptr = new Line; 
  (*pptr)->a = new Point; 
  (*pptr)->a->x = new int(x_a); 
  (*pptr)->a->y = new int(y_a); 
  (*pptr)->b = new Point; 
  (*pptr)->b->x = new int(x_b);
  (*pptr)->b->y = new int(y_b); 
  delete (*pptr)->b->y; 
  delete (*pptr)->b->x
  delete (*pptr)->b; 
  delete (*pptr)->a->y; 
  delete (*pptr)->a->x; 
  delete (*pptr)->a; 
  delete *pptr; 
}

//Question 3: 

int main(){
  int n; 
  cin >> n; 

  Shape*** p = new Shape**[n]; 
  for(int i = 0; i < n; ++i){
    p[i] = new Shape*; 
    *(p[i]) = new Shape; //Element in the array holds a pointer 
  }

  for(int i = 0; i < n; ++i){
    (*(p[i]))->setType("circle"); 
  }

  for(int i = 0; i < n; ++i){
    delete *(p[i]); //Each element in the array holds a pointer 
    delete p[i]; //Each element in the array holds a pointer to a pointer 
  }
  delete[] p; 
}

//Question 4: 

a. 1 (3 == b), because you cannot overload the == operator for an int 
b. 2 (a == b) and (a == 3) can both be in the class 
c. 1 (b == a) can be in the class 
d. Yes, they can all be non member functions 

//Question 5: 

25 45 
1 2 
3 5 
7 8 
6 12 
12 36 
6 12 

//Question 6: 

void traverse(ListNode* h){
  if(h == nullptr) 
    return;
  cout << h->id;  
  ListNode* current = h->next; 
  while(current != nullptr && current != h){
    cout << current->id; 
    current = current->next; 
  }
}

void delete(ListNode*& h, ListNode* p){
  if(h == nullptr)  
    return; 
  if(h == p){
    delete h; 
    h = nullptr; 
    return; 
  }
  if(p->next == h){
    h = h->next; 
  } 
  ListNode* temp = p->next; 
  p->next = temp->next;
  delete temp;  
  return; 
}

bool isCircular(ListNode* h){
  if(h == nullptr)  
    return true; 
  ListNode* current = h->next; 
  while(current != nullptr && current != h){
    current = current->next; 
  }
  return current == h; 
}

//Question 7 

16 11 6 1 -4 1 6 11 16 

//Question 8

void reverseArray(int* array, int left, int right){
  if(left > right)
    return; 
  int temp = array[left];
  array[left] = array[right];
  array[right] = temp; 
  reverseArray(array, left + 1, right - 1); 
}

//Question 9

void preorder(kAryTree* myroot){
  if(myroot == nullptr)
    return; 
  cout << myroot->key; 
  for(int i = 0; i < K; ++i){
    if(myroot->child[i] != nullptr)
      preorder(myroot->child[i]);
  }
  return; 
}

//Question 10: 

//Question 11: 

Just put them in ascending order from left to right 

//Question 12 

bool cycle(TreeNode* root){
  if(root == nullptr)
    return false; 
  if(root->visited == true)
    return true; 
  root->visited = true;                                  
  if(cycle(root->left) || cycle(root->right)); 
    return true; 
  return false; 
}

//Question 13

//Question 14: 

Error, Shape is an abstract class 
Error, circle is an abstract class
Good 
Error, length is protected 

//Question 15: 

Error, a is private member 
Good, child class can access protected member 
Good
Good 

//Question 16: 

circuit element with code 
capacitor 
circuit element with code 
resistor 
power resistor 
no power resistor 
no resistor 
no circuit element 
no capacitor 
no circuit element 

circuit element with code 
resistor 
power resistor 
no circuit element //Other destructors are no seen because the destructor in circuit element is not virtual 

compile error, capacitor is a child class of base class circuit element 

compile error  

circuit element with code 
resistor 
power resistor 
circuit element 
no circuit element 
no power resistor 
no resistor 
no circuit element 

circuit element with code 
capacitor 
power capacitor 
Capacitor: 500 
Power Capacitor: 1000 
//No destructor because e is dynamically allocated, meaning it HAS to be manually destroyed 

//Question 18: 

O(n) * O(sqrt(n)) = O(n^(3/2))
