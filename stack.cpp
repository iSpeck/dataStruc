#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

int main(){

    string line; //grabs each line of txt
    stack <char> myStack; // declares the stack
   
  ifstream myfile ("SingleLinked.cpp"); //sets a varible for the file
  if (myfile.is_open()) //checks if the file is open
  {
    while (getline(myfile,line)) // if the file is open, get the first line.
    {

      for( int i = 0; i < line.length(); i++){
        
          if(line[i] == '(' || line[i] == '{' || line[i]=='['){
              myStack.push(line[i]);
          }
            //if the stack has the characters "(,{, or ["
          if(line[i]== ')' && myStack.top()=='('){ 
          myStack.pop();}

        if(line[i]== '}' && myStack.top()=='{'){
          myStack.pop();}

         if(line[i]== ']' && myStack.top()=='['){
             myStack.pop();}

         } //for loop

    }//while loop for the line
    
     
        if(myStack.empty()){ // if the stack is empty, then the program contains no syntax errors with the values provided
            cout<< "Program contains no syntax errors" <<endl;
        }
        else { while(!myStack.empty()){ // if the stack has elements, it prints out which elements it contains.
           cout << "There is an extra " << myStack.top() <<" in the stack!"<<endl;
           myStack.pop();} 

        }

      
    myfile.close();
  } //if statement
  

  else cout << "Unable to open file"; 


    return 0;
}