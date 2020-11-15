#include<bits/stdc++.h> 
using namespace std; 
typedef int KEY;
typedef int T;
class AVL 
{ 
public:
  struct Elem{
  	  
	struct Elem *left, *right; 
    KEY key;
	T data;
	int height;  
    bool rightThread; 
    Elem():left(0), right(0), height(-1), rightThread(false) {}
};
int size;
int check;
Elem *_root;
 

bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
//void printTree(ostream& out, int level, Elem *p) const;defined below 
//void destructCode(Elem *& p); defined below
void doubleRotateRight(Elem *& node);
void doubleRotateLeft(Elem *& node);

int Size(Elem* node)  
{  
    if (node == NULL)  
        return 0;  
    else
        return(Size(node->left) + 1 + Size(node->right));  
}  
	
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  

void updateHeight(Elem*& cur)
{
	 cur->height=max(height(cur->left),height(cur->right)) + 1;	
}
void rightRotate(Elem *& node)  
{  
    Elem *x = node->left;  
    Elem *T2 = x->right;  
   
    x->right = node;  
    node->left = T2;  
  
    updateHeight(node);
	updateHeight(x); 
  
    node=x;  
}  
  
  
void leftRotate(Elem *& node)  
{  
    Elem *y = node->right;  
    Elem *T2 = y->left;  
  
      
    y->left = node;  
    node->right = T2;  
  
      
    updateHeight(node);
	updateHeight(y);  
    node=y; 
}  
  
int balanceFactor(Elem *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
int height(Elem *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
Elem* leftMost(Elem* root) 
{ 
    while (root != NULL && root->left != NULL) 
        root = root->left; 
    return root; 
} 
void destructCode(Elem *& p)
{
	free(p);
}
	 
Elem* newElem(KEY key, T data)
{
	Elem *tmp = new Elem();
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->key = key;
	tmp->data= data;
	
	return tmp;
}
Elem* search(Elem* root, KEY key) 
{ 
    
    if (root == NULL || root->key == key) 
       return root; 
     
    
    if (root->key < key) 
       return search(root->right, key); 
       
    return search(root->left, key); 
}
Elem* Insert(Elem* root, KEY key , T data) 
{ 
    if (!root) 
	{  
		return newElem(key,data); 
	} 
  	if(search(root,key)!=NULL)
	{
		check = 1;
		return root;
	}
    if (key < root->key)  
        root->left = Insert(root->left, key, data);  
    else  
        root->right = Insert(root->right,key, data);   
  
    
    updateHeight(root);   
  
    
    int balance = balanceFactor(root);  
    if (balance > 1 && key < root->left->key)  
        rightRotate(root);  
  
     
    if (balance < -1 && key > root->right->key)  
        leftRotate(root);  
  
    if (balance > 1 && key > root->left->key)  
    {  
        leftRotate(root->left);  
        rightRotate(root);  
    }  
    
    if (balance < -1 && key < root->right->key)  
    {  
        rightRotate(root->right);  
        leftRotate(root);  
    }  
  
    
    return root;   
} 

void printTree(ostream& out, int level, Elem *p) const
{ 
    if (p == NULL) 
        return; 
 
    Elem* root1= p;
    while (root1 != NULL && root1->left != NULL) 
        root1 = root1->left; 
    Elem* cur = root1; 
    
    while (cur != NULL) { 
        out << cur->key << " "; 
        if (cur->rightThread) 
            cur = cur->right; 
  
        else  {
            root1= cur->right;
    		while (root1 != NULL && root1->left != NULL) 
        		root1 = root1->left;
			cur = root1; 
    }
}
} 

bool insert1(Elem *& root, const KEY &key, const T &data, Elem *lastLeft)
{
	
	check =0;
	root= Insert(root,key,data);
	if(check==1)
	{
		check=0;
		return false;
	}
	
	return true;
	
}
void populateQueue(Elem* root,  queue<Elem*>* q) 
{ 
    if (root == NULL) 
        return; 
    if (root->left) 
        populateQueue(root->left, q); 
    q->push(root); 
    if (root->right) 
        populateQueue(root->right, q); 
} 
  

void createThreadUtil(Elem* root,  queue<Elem*>* q) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->left) 
        createThreadUtil(root->left, q); 
    q->pop(); 
  
    if (root->right) 
        createThreadUtil(root->right, q); 
  
     
    else { 
        root->right = q->front(); 
        root->rightThread = true; 
    } 
} 
  

void createRightThread(Elem* root) 
{ 
    
     queue<Elem*> q; 
  
    
    populateQueue(root, &q); 
  
    
    createThreadUtil(root, &q); 
} 
  
 void preOrder(Elem* root,ostream& out) 
{ 
    if(root != NULL)  
    {  
        out << root->key << " " <<balanceFactor(root)<<endl;  
        preOrder(root->left,out);  
        preOrder(root->right,out);  
    }  
} 
};

int main() 
{ 
	AVL obj;
	obj._root = NULL; 
    obj.insert1(obj._root,20,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,10,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,60,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,15,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,30,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,55,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,70,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,2,30,obj.leftMost(obj._root));
     
    filebuf fb;
  	fb.open ("AVL.txt",ios::out);
  	ostream os(&fb);
  	obj.size= obj.Size(obj._root);
  	os<<"size of tree "<<obj.size<<endl;
  	os<<"before right threaded AVL Tree\n";
    obj.preOrder(obj._root,os);//checking balance factor;
    obj.createRightThread(obj._root);//turing tree to right threaded;
    os<<"After right threaded AVL Tree\n";
    obj.printTree(os,1,obj._root);
	obj.destructCode(obj._root); 
	return 0; 
} 


