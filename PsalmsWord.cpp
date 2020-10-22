#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

int main(){
    
string line; //grabs each line of txt
  regex reg("\\t(.*)"); // parses the string using the tab delimeter
   
  
  
  ifstream myfile ("bible-test.txt"); //opens txt file
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      //TODO: FIND THE TAB IN THE LINE 
      // POP OFF TAB
      
      sregex_iterator currenMatch(line.begin(), line.end(), reg);
      sregex_iterator lastMatch;

      while (currenMatch != lastMatch){
      smatch match = *currenMatch;
      string alt = match.str();
      currenMatch ++;
      
      
   
      }// for the nested while loop

    }//while loop for the line
    
      cout << line << endl;
      
      
    myfile.close();
  } //if statement
  

  else cout << "Unable to open file"; 


    return 0;
}