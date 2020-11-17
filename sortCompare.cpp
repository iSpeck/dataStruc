#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Sort array of size 10 million
const int SORT_SIZE = 1000;

long int a[SORT_SIZE];

double getRand() {
  long int temp = ((long int)rand() << 12) | ((long int)rand() & (long int)0x00000FFF);
  long int maxv = 0x0FFFFFFF; // 268435456
  return (double)temp / (double)maxv;
}





void testArray() {
    long int k = 0;
    for (long int i = 0; i < SORT_SIZE; i++) {
        if (a[i] < k) {
            cout << "SORT FAILURE" << endl;
        } else {
            k = a[i];
        }
    }
}


void selectionSort(long int a[], long int n) {
    long int i, j, min, temp;
    auto start = chrono::high_resolution_clock::now();
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
   }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<milliseconds>(end - start);
    cout << '\t' << float(duration.count())/1000.0 << " seconds" << endl;
}



void cppSort(long int a[], long int n) {
    auto start = chrono::high_resolution_clock::now();
    sort(a, a + n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<milliseconds>(end - start);
    cout << '\t' << float(duration.count())/1000.0 << " seconds" << endl;
}


void merge(long int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   long int *larr;
   long int *rarr;
   //size of left and right sub-arrays
   nl = m-l+1; 
   nr = r-m;
 // long int larr[nl], rarr[nr];
 larr = (long int *) malloc(nl*sizeof(long int));
 rarr = (long int *) malloc(nr*sizeof(long int));
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
   free(larr);
   free(rarr);
}

void mergeSort(long int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
void loadArray() {
    for (long int i = 0; i < SORT_SIZE; i++) {
        a[i] = (long int) (getRand() * 268435456.0);
    }
}

int main () {
    srand(time(0));



    loadArray();
    cout << "Starting selectionSort..." << endl;
    selectionSort(a, SORT_SIZE);
    testArray();
    
    loadArray();
    cout << "Starting mergeSort..." << endl;
   auto start = chrono::high_resolution_clock::now();
    mergeSort(a, 0 ,SORT_SIZE-1 );
   auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<milliseconds>(end - start);
    cout << '\t' << float(duration.count())/1000.0 << " seconds" << endl;

    /* for(int i = 0; i < SORT_SIZE; i++){
        cout << a[i] << endl;
    } */
    testArray();



    loadArray();
    cout << "Starting C++ Built-in Sort..." << endl;
    cppSort(a, SORT_SIZE);
    testArray();
}