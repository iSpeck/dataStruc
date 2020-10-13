#include <iostream>
using namespace std;

class Progression{
    public: 
        Progression(long f = 0)
        :first(f),cur(f){}
        virtual ~Progression(){};
        void printProgression(int n);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long first;
        long cur;
};

void Progression::printProgression(int n){
    cout << firstValue();
    for (int i =2; i <= n; i++)
        cout << ' ' << nextValue();
        cout << endl;
}

long Progression::firstValue(){                         //reset 
    cur = first;
    return cur;
}

long Progression::nextValue(){                          //advance
    return cur++;
}

class FibonacciProgression : public Progression {
    public:
        FibonacciProgression(long f = 0, long s = 1);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long second;
        long prev;
};

FibonacciProgression::FibonacciProgression(long f,long s)
    :Progression(f),second(s),prev(second - first){ }

long FibonacciProgression::firstValue(){
        cur = first;
        prev = second - first;
        return cur;
    }

long FibonacciProgression::nextValue(){
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}

/*class FibonacciPlus : public FibonacciProgression {
    public :
        FibonacciPlus
    
}

*/

int main(){
Progression* prog;

cout <<"Fibonacci progression with default start values:\n";
prog = new FibonacciProgression();
prog->printProgression(10); 
cout <<"Fibonacci progression with start values 4 and 6:\n"; 
prog = new FibonacciProgression(3, 4);
prog->printProgression(10); 
return EXIT_SUCCESS;


    return 0;
}