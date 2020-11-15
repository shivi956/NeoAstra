
#include<bits/stdc++.h> 
using namespace std; 
typedef int KEY;
typedef int T;
class BST 
{ 
public:
  struct Elem{	  
	struct Elem *left, *right; 
    KEY key;
	T data;  
    bool rightThread; 
};
int size;
int check;
Elem *_root;
 

	bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
	//void printTree(ostream& out, int level, Elem *p) const; defined below
	//void destructCode(Elem *& p); defined below
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

	if (key > root->key) 
	{ 
		root->right = Insert(root->right, key,data); 
	} 
	else
	{  
		root->left = Insert(root->left, key,data); 
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
	if(root==NULL)
	root= Insert(root,key,data);
	
	else{
		Insert(root,key,data);
	}
	if(check==1)
	{
		check=0;
		return false;
	}
	
	return true;
	
}
void RTQueue(Elem* root,  queue<Elem*>* q) 
{ 
    if (root == NULL) 
        return; 
    if (root->left) 
        RTQueue(root->left, q); 
    q->push(root); 
    if (root->right) 
        RTQueue(root->right, q); 
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
  
    
    RTQueue(root, &q); 
  
    
    createThreadUtil(root, &q); 
} 
  
 
};

int main() 
{ 
	BST obj;
	obj._root = NULL; 
    obj.insert1(obj._root,20,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,10,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,60,30,obj.leftMost(obj._root));
    obj.insert1(obj._root,5,30,obj.leftMost(obj._root));
     
    obj.createRightThread(obj._root);
  	filebuf fb;
  	fb.open ("BST.txt",ios::out);
  	ostream os(&fb);
  	os<<"Binary Search Tree\n";
    obj.printTree(os,1,obj._root);
	obj.destructCode(obj._root); 
	return 0; 
} 



