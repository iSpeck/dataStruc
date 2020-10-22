#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
using namespace std;
int getIndex(vector <string> v, string K) 
{ 
    auto it = find(v.begin(), 
                   v.end(), K); 
    int index = distance(v.begin(), it); 
        
      return index;
 
   }

int main(){
  
    
  string line; //grabs each line of txt
  regex reg("\\w+[A-Za-z]"); // parses the string using the tab delimeter
  vector <string> wordList; //declares the vector that will hold all the words
  vector <int> wordCount;  //declares the vector that will hold the count
  
  ifstream myfile ("bible-test.txt"); //opens txt file
  if (myfile.is_open())
  {
    while (getline(myfile,line)) //goes throught the file line by line
    {
     

      char tab = '\t'; // sets the delimeter "Tab"
      line = line.substr(tab); //starts the string after the tab

     transform(line.begin(), line.end(), line.begin(), ::tolower); // makes each character lowercase


    for( sregex_iterator word(line.begin(), line.end(),reg), word_end; word != word_end; ++word ){ 

      if (find(wordList.begin(),wordList.end(), (*word)[0]) != wordList.end()){
        
          
        wordCount[getIndex(wordList,(*word)[0])]++;
        
      }else{
            wordList.push_back((*word)[0]); //Adds the parsed words into the vector word by word
            wordCount.push_back(1);
      }

      
    }; //for regex loop

    }//while loop for the line
    for (int i = 0; i <= wordList.size(); i++){
      cout << wordList[i] << ": appears " << wordCount[i] << " times."<<endl;
    }


  
   
    myfile.close();
  } //if statement
  

  else cout << "Unable to open file"; 


    return 0;
}