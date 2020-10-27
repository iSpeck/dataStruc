#include <iostream>
#include <string>
#include "SingleLinked.h"
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
using namespace std;
const int HASH_MAX = 100;
int getIndex(vector <string> v, string K) 
{ 
    auto it = find(v.begin(), 
                   v.end(), K); 
    int index = distance(v.begin(), it); 
        
      return index;
 
   }


int hashCode(const char* p, int len) { // hash a character array
unsigned int h = 0;
for (int i = 0; i < len; i++)
{ h = (h << 5) | (h >> 27); // 5-bit cyclic shift
h += (unsigned int) p[i]; // add in next character
}
return h % HASH_MAX;
}


int main(){
  string line; //grabs each line of txt
  regex reg("\\w+[A-Za-z]"); // parses the string using the tab delimeter
  vector <StringLinkedList> wordList(HASH_MAX); //declares the vector that will hold all the words
  int count = 0;
  string wordH;
  int hashValue;
  
  
  ifstream myfile ("bible-psalms.txt"); //opens txt file
  if (myfile.is_open())
  {
    while (getline(myfile,line)) //goes throught the file line by line
    {
     

      char tab = '\t'; // sets the delimeter "Tab"
      line = line.substr(tab); //starts the string after the tab

     transform(line.begin(), line.end(), line.begin(), ::tolower); // makes each character lowercase


    for( sregex_iterator word(line.begin(), line.end(),reg), word_end; word != word_end; ++word ){ 
      wordH = (*word)[0];
      hashValue = hashCode(&wordH[0],wordH.length());
      if(wordList[hashValue].listCheck(wordH)){
        wordList[hashValue].elemIndex(wordH);
      }else{
        wordList[hashValue].addFront(wordH);
        wordList[hashValue].elemIndex(wordH);
      }
      
    }; //for regex loop

    }//while loop for the line
    for(int i = 0; i < HASH_MAX; i++){
      cout << i;
      wordList[i].print();
      cout << "\n";

    }

  
   
    myfile.close();
  } //if statement
  

  else cout << "Unable to open file"; 


    return 0;



    
}