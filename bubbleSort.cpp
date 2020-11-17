#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;


int main () {
  int i, j, x, y, z;
  int k[15000];
  string s[15000];
  string line;
  string word;
  time_t curtime;
  ifstream myfile ("bible-complete.txt");

  // initialize the arrays
  for (i = 0; i < 15000; i++) {
    s[i].clear();
    k[i] = 0;
  }

  // open the file specified above
  time(&curtime);
  cout << "Before count: " << ctime(&curtime) << endl;
  if (myfile.is_open())
  {
    // read a line at a time from the text file
    while (getline(myfile,line))
    {
      z = line.length();
      // set i to the tab after Psalms C:V
      i = 0;
      while (line[i] != '\t') i++;
      // walk the line for each word !alphanumeric delimiters
      while (i < z) {
        // skip past all non-alphanumeric
        while (!isalnum(line[i]) && i<z) i++;
        j = i;
        // skip to the end of the word
        while (isalnum(line[j]) && j<z) j++;
        word = line.substr(i,j-i);
        // convert word to all lowercase
        for (x=0; x<word.length(); x++) {
          word[x] = tolower(word[x]);
        }
        // word ready, add it to the arrays
        y = 0;
        while (s[y] != word && !s[y].empty()) y++;
        s[y] = word;
        k[y]++;
        // prime i to for the next word search
        i = j + 1;
      }
    }
    myfile.close();
    time(&curtime);
    cout << "Before sort: " << ctime(&curtime) << endl;
 
    for(int i = 0;!s[i].empty(); i++ ){
        for(int j = 0;!s[j].empty(); j++){
        if(s[j] > s[j+1] && !s[j+1].empty()){
            swap(s[j],s[j+1]);
            swap(k[j],k[j+1]);
            } 
        }//j
    }//i

    y = 0;
    while (!s[y].empty()) {
      cout << s[y] << "," << k[y] << endl;
      y++;
    }
    cout << "Different word count:" << y << endl;
    time(&curtime);
    cout << "Program end: " << ctime(&curtime) << endl;
  }
}
