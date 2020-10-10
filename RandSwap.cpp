#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Your function should work for int vectors v of any 
size, not just 52.  For i running from the index of the last 
element of v down to 1, a random integer r ranging from 0 to i is generated.
 The ith element of v is swapped with the rth element.  
 The function rand returns a random integer, 
 and we use the fact that rand()%(i+1) generates a random number between 0 and i. */


int main(int argc, char const *argv[]){
    int cards[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v;
    v.assign(cards,cards+10);
for (int i = 9; i >= 0; i--){
    cout <<"Vector before swap: " << v[i]<< endl;
    int r = rand()% (i+1);

    swap(v[i],r);

   // cout << "Random Int:" << r <<endl;
    //cout << "\n";
    
    cout << "Vector swapped: " << v[i] << endl;
    cout << "----------------" << endl;
}


    return 0;
}
