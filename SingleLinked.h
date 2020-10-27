#include <iostream>
#include <string>
using namespace std;

class StringNode { 

private:
string elem; 
StringNode* next;
int elemCount = 0;
int position;
friend class StringLinkedList;
};

class StringLinkedList { // a linked list of strings
public:
StringLinkedList();             // empty list constructor
~StringLinkedList();            // destructor
bool empty() const;             // is list empty?
const string& front() const;    // get front element
void addFront(const string& e); // add to front of list
void removeFront();              // remove front item list
void print();                   //Print list
void elemIndex(string pos);
bool listCheck(string pos);
private:
StringNode* head;               // pointer to the head of list
};

StringLinkedList::StringLinkedList()        // constructor
: head(NULL) { }

StringLinkedList::~StringLinkedList()       // destructor
{ while (!empty()) removeFront(); }

bool StringLinkedList::empty() const        // is list empty?
{ return head == NULL; }

const string& StringLinkedList::front() const       // get front element
{ return head->elem; }

void StringLinkedList::addFront(const string& e) {      // add to front of list
StringNode* v = new StringNode;                         // create new node
v->elem = e;                                            // store data
v->next = head;                                          // head now follows v
head = v;                                                // v is now the head
}

void StringLinkedList::removeFront() {                      // remove front item
StringNode* old = head;                                     // save current head
head = old->next;                                           // skip over old head
delete old;                                                 // delete the old head
}

void StringLinkedList::print() {
   StringNode* ptr = head;
   cout << "{";
   while (ptr)
   {
     cout << ptr->elem << " : " << ptr->elemCount; 
     cout << (ptr->next ? ", " : "}");
     ptr = ptr->next;
   }
   cout << endl;
 }

 void StringLinkedList::elemIndex(string pos){
     StringNode* ptr=head;
     
        while(ptr){
           if(pos==ptr->elem){
               ptr->elemCount++;
               break;
           } 
           ptr=ptr->next;
        }
 }

 bool StringLinkedList::listCheck(string pos){
     StringNode* ptr=head;
        while(ptr){
            if(pos==ptr->elem){
                return true;
            }   
        ptr=ptr->next;
        }
    return false;
 }