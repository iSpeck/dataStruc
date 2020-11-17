#include <iostream>
#include "LinkedBinaryTree.h"
using namespace std;

int main ()
{
  LinkedBinaryTree    btree;
  Position broot;
  // Build the binary tree shown in textbook Figure 7.11
  // Create the empty linked binary tree (btree)
    btree = LinkedBinaryTree();
  // Create the root and load with data
    btree.addRoot();
    broot = btree.root();
    *broot = '-';
  // Create the level-1 children and load with data
    btree.expandExternal(broot);
    *broot.left() = '/';
    *broot.right() = '+';
  // Create the level-2 children and load with data
    btree.expandExternal(broot.left());
    *broot.left().left() = 'x';
    *broot.left().right() = '+';
    btree.expandExternal(broot.right());
    *broot.right().left() = 'x';
    *broot.right().right() = '6';
  // Create the level-3 children and load with data
    btree.expandExternal(broot.left().left());
    *broot.left().left().left() = '+';
    *broot.left().left().right() = '3';
    btree.expandExternal(broot.left().right());
    *broot.left().right().left() = '-';
    *broot.left().right().right() = '2';
    btree.expandExternal(broot.right().left());
    *broot.right().left().left() = '3';
    *broot.right().left().right() = '-';
  // Create the level-4 children and load with data
    btree.expandExternal(broot.left().left().left());
    *broot.left().left().left().left() = '3';
    *broot.left().left().left().right() = '1';
    btree.expandExternal(broot.left().right().left());
    *broot.left().right().left().left() = '9';
    *broot.left().right().left().right() = '5';
    btree.expandExternal(broot.right().left().right());
    *broot.right().left().right().left() = '7';
    *broot.right().left().right().right() = '4';
  // Done building binary tree shown in textbook Figure 7.11
  cout << "There are " << btree.size() << " nodes in the tree.";

  // Put your code here to do a preorder, postorder, and inorder
cout << endl;
  cout << "Preorder: " << endl;
  btree.preorderRoot(broot);
  cout << endl;
  cout << "Postorder:" << endl;
  
  btree.postorderRoot(broot);
  cout << endl;
  cout << "Inorder:" << endl;
  
  btree.inorderRoot(broot);


}
