#include <list>
#include <iterator>
#include <iostream>
using namespace std;

  typedef char Elem;
  struct Node {
    Elem    elt;
    Node*   par;
    Node*   left;
    Node*   right;
    Node() : elt(), par(NULL), left(NULL), right(NULL) { }
  };

  class Position {
    private:
      Node* v;
    public:
      Position(Node* _v = NULL) : v(_v) { }
      Elem& operator*()
        { return v->elt; }
      Position left() const
        { return Position(v->left); }
      Position right() const
        { return Position(v->right); }
      Position parent() const
        { return Position(v->par); }
      bool isRoot() const
        { return v->par == NULL; }
      bool isExternal() const
        { return v->left == NULL && v->right == NULL; }
      friend class LinkedBinaryTree;
    };
    typedef std::list<Position> PositionList;

  class LinkedBinaryTree {
    protected:
    // insert Node declaration here...
    public:
    // insert Position declaration here...
    public:
      LinkedBinaryTree();
      int size() const;
      bool empty() const;
      Position root() const;
      PositionList positions() const;
      void addRoot();
      void expandExternal(const Position& p);
      Position removeAboveExternal(const Position& p);
      void preorderRoot(const Position& p) const;
      void postorderRoot(const Position& p) const;
      void inorderRoot(const Position& p) const;
      // housekeeping functions omitted...
    protected:
      void preorder(Node* v, PositionList& pl) const;
    private:
      Node* _root;
      int n;
  };

  LinkedBinaryTree::LinkedBinaryTree()
    : _root(NULL), n(0) { }
  int LinkedBinaryTree::size() const
    { return n; }
  bool LinkedBinaryTree::empty() const
    { return size() == 0; }
  Position LinkedBinaryTree::root() const
    { return Position(_root); }
  void LinkedBinaryTree::addRoot()
    { _root = new Node; n = 1; }

  void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
  }

  Position LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;  Node* v = w->par;
    Node* sib = (w == v->left ?  v->right : v->left);
    if (v == _root) {
      _root = sib;
      sib->par = NULL;
    }
    else {
      Node* gpar = v->par;
      if (v == gpar->left) gpar->left = sib;
      else gpar->right = sib;
      sib->par = gpar;
    }
    delete w; delete v;
    n -= 2;
    return Position(sib);
  }

  PositionList LinkedBinaryTree::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
  }

  void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL)
      preorder(v->left, pl);
    if (v->right != NULL)
      preorder(v->right, pl);
  }

  void LinkedBinaryTree::preorderRoot(const Position& p) const {
    cout << p.v->elt;
    if (p.v->left != NULL)
      preorderRoot(p.left());
    if (p.v->right != NULL)
      preorderRoot(p.right());
  }

  void LinkedBinaryTree::postorderRoot(const Position& p) const {
      if (p.v-> left != NULL )
      postorderRoot(p.left());
      if (p.v->right != NULL)
        postorderRoot(p.right());
    cout << p.v->elt;
     

  }

  void LinkedBinaryTree::inorderRoot(const Position& p) const {
      if (p.v-> left != NULL)
      inorderRoot(p.left());
      cout << p.v->elt;
      if (p.v-> right != NULL)
      inorderRoot(p.right());
     
     
  }
