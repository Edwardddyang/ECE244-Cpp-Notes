#include <iostream>
#include <fstream> 
using namespace std; 

/*
Need <fstream> 

1. ofstream - To write to a file: 

string food = "lemons"; 
ofstream file("foods.txt"); <-- Creates and opens file object 
file << food; <-- Output food into the file 
file.close(); 

2. ifstream - To read from a file: 

ifstream file("foods.txt"); 
string food; 
file >> food; <-- Takes in food from the file 
file.close(); 

Error Checking: cin 

1. .fail() <-- Failed read 
2. .eof() <-- End of line 
3. .good() <-- File good 
4. .ignore(int number, '\n') <-- Skips n characters, or until new line 
5. .clear() <-- If the stream enters a fail state, you can't use it again until you use .clear(); 
6. .getline(cin, string) <-- Allows you to get a string that includes spaces 

To open a file: outFile.open("file_name"); 
To close a file: outFile.close(); 

Stringstream - <sstream> 
- Allows you to treat a string like a stream
- Can extract/insert data into a string as if using cin and cout 

Extract values (cin): 

string line = "42 3.14 hello"; 
int x; 
double y; 
string word; 

stringstream ss(line); <- Creates a stream called ss from the string line 
ss >> x >> y >> word; 
cout << x << y << word; <-- 42 3.14 hello 

Build a string (cout): 

stringstream ss; 
ss << "The value is " << 42 << "!"; 
string result = ss.str(); // Gets the result 
cout << result; //The value is 42! 


Input streams: 
- Hold input from a data producer 
When keyboard is pressed while program is not expecting any input, the data is stored in an input stream  

ifstream inFile; <- Creates an input file stream called inFile 
int a; 
inFile.open("inputfile"); <- Attaches the input stream to the file called inFile 
inFile >> a; <- Reads from the input file stream into a 

inFile.close(); <- Closes the file 


Output streams: 
- Holds output for a particular data consumer 
When printer is not ready to print, data stored in output stream

ofstream outFile; <- Creates an output file stream called outFile 
int a = 8; 

outFile.open("outputfile"); <- Attaches output stream to the file called outputfile 
outFile << a; <- Writes to the output file from a

outFile.close(); <- Closes the file 

Output Stream Manipulators: 

Requires #include <iomanip> 

setw(number) <- Sets width of the variable, if setw(8) the minimum number of characters in the next output has to be 8
setfill('0') <- Fills the stream with this thing 
setprecision(number) <- Controls decimal precision 


*/