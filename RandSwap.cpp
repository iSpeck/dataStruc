#include <vector>
#include <iostream>
using namespace std;

/* Your function should work for int vectors v of any 
size, not just 52.  For i running from the index of the last 
element of v down to 1, a random integer r ranging from 0 to i is generated.
 The ith element of v is swapped with the rth element.  
 The function rand returns a random integer, 
 and we use the fact that rand()%(i+1) generates a random number between 0 and i. */


int main(int argc, char const *argv[]){
int v[] = {1,2,3,4,5,6,7,8,9,10};
for (int i = 0; i <= 10; i++ ){
    
    cout << v[i] << endl;
    
}


    return 0;
}
