# NeoAstra
Please find my code for the recruitment test.
Assignment:
Implement a right-threaded BST in C++ and then later convert that into a AVL tree.
So, you must submit two .CPP files, one for BST and another for AVL
Add the below method signatures to respective header files and do not modify the
below signatures.
BSL method signatures
struct Elem {
KEY key;
T data;
Elem *left;
Elem *right;
bool rightThread; //normal right child link or a threadlink
};
Elem *_root; // a dummy root sentinel
int _size;
// helper method for inserting record into tree.
bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
// helper method for print tree
void printTree(ostream& out, int level, Elem *p) const;
// common code for deallocation
void destructCode(Elem *& p);
AVL method signatures
struct Elem {
Elem():left(0), right(0), height(-1), rightThread(false) {}
KEY key;
T data;
Elem *left;
Elem *right;
int height;
bool rightThread; //normal right child link or a threadlink
};
Elem *_root; // a dummy root sentinel
int _size;
// helper method for inserting record into tree.
bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
Recruitment Test: C++
Recruitment Test: C++
// helper method for print tree
void printTree(ostream& out, int level, Elem *p) const;
// common code for deallocation
void destructCode(Elem *& p);
void rotateRight(Elem *& node);
void rotateLeft(Elem *& node);
void doubleRotateRight(Elem *& node);
void doubleRotateLeft(Elem *& node);
int balanceFactor(Elem *cur);
void balance(Elem*& cur, const KEY &key);
int height(Elem *node);
void updateHeight(Elem*& cur);
Submission:
1. Upload your code to any private source control providers such as GIT/Bitbucket/Gitlab
2. Share the application GIT link with us
3. Code once submitted should not be altered. Hence, please make sure you the code is
well tested and uploaded before the deadline.
All the best 
����
