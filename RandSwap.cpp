#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

/* Your function should work for int vectors v of any 
size, not just 52.  For i running from the index of the last 
element of v down to 1, a random integer r ranging from 0 to i is generated.
 The ith element of v is swapped with the rth element.  
 The function rand returns a random integer, 
 and we use the fact that rand()%(i+1) generates a random number between 0 and i. */

void cardNumber(int card){

        vector<int> v; //declares a vector
    
        for (int i = 0; i <= card;i++ ){ // loops and adds an element into the vector
       
        v.push_back(i+1); //assigns the array of cards to the vector
        }

        srand (time(NULL)); // syncs the time of computer to the rand function

        for (int i = card-1; i >= 0; i--){ //loops down from the ith element -1 
        int r = rand()% (i+1);
        swap(v[i],v[r]); // swaps the ith element with the random element

        }

        for (int k =0; k < card; k++){ //prints the output to the screen each time.
            cout <<" " << v[k];}
    
}



int main(int argc, char const *argv[]){
    cardNumber(52); //outputs the function
    return 0;
}
