#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;


int main () {
  string line; //grabs each line of txt
  regex reg("\\t(.*)"); // parses the string using the tab delimeter
   int ASCII[127]={}; 
  
  
  ifstream myfile ("bible-psalms.txt"); //opens txt
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      sregex_iterator currenMatch(line.begin(), line.end(), reg);
      sregex_iterator lastMatch;

      while (currenMatch != lastMatch){
      smatch match = *currenMatch;
      string alt = match.str();
      currenMatch ++;
      
      for(int i = 0; i <= alt.size(); i++){
      int value = (int)alt[i];
      ASCII[value]++;}
   
      }// for the nested while loop

    }//while loop for the line
    
      for (int j = 32; j < 127; j++){
            if ( ASCII[j] > 0){
              char charConverted = (char)j;
              cout << "There are " << ASCII[j] <<" of the Ascii value "<< charConverted <<endl;
            }
      }
      
    myfile.close();
  } //if statement
  

  else cout << "Unable to open file"; 

  return 0;
} //main