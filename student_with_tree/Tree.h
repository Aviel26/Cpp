
#pragma once
#include <iostream>
using namespace std;


template <class T>
class Node
{
public:

	T value; // key
	Node * left; // pointer to the left Node of the tree
	Node * right; //pointer to the right NOde of th tree
	Node(T val) : value(val), left(NULL), right(NULL) {} // base
	Node(T val, Node<T> * l, Node<T> * r) : value(val), left(l), right(r) {} //init
};		

template <class T>
class Tree
{
protected:
	//data member of tree
	Node<T> * root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const; // return if tree empty
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); } 
	void inOrder() { inOrder(root); } 
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T const &val) = 0;

	int leaves() { return leaves(root); }//Returns the number of tree leaves (without child)
	int  height() { return height(root); }//returns the layer number of the tree
	void reflect() { reflect(root); }//to replaces the sons of each vertex tree and create a new tree reflect
	int  onlyLeftSon() { return onlyLeftSon(root); }//returns number of the son at the left

private:
	void  clear(Node<T> * current);
	void  preOrder(Node<T> * current);
	void  inOrder(Node<T> * current);
	void  postOrder(Node<T> * current);
	int   leaves(Node<T> * current);
	int   height(Node<T> * current);
	void  reflect(Node<T> * current);
	int   onlyLeftSon(Node<T> * current);
};

template <class T>
Tree<T>::~Tree() // destructor
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node<T> * current)
{
	if (current)
	{    
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

template <class T>  // preOrder 
void Tree<T>::preOrder(Node<T> * current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node<T> * current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node<T> * current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
//Returns the number of tree leaves (leaf is a vertex that has no children at all).
template <class T>
int  Tree<T>::leaves(Node<T> * current)
{
	int sum = 0;
	if (current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	if (current->left == NULL)
		return(sum += leaves(current->right));
	if (current->right == NULL)
		return(sum += leaves(current->left));
	return(sum += leaves(current->left) + leaves(current->right));
}
template <class T>
int Tree<T>::height(Node<T> * current)
{
	int sum = 0;
	int L;
	int R;
	if (current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	L = height(current->left);
	R = height(current->right);
	if (L < R)
		return(sum += R + 1);
	return(sum += L + 1);
}
template <class T>
void Tree<T>::reflect(Node<T> * current)
{

	if (current == NULL)
		return;
	if (current->left == NULL && current->right == NULL)
		return;
	Node<T>* temp = current->left;
	current->left = current->right;
	current->right = temp;
	reflect(current->left);
	reflect(current->right);
}
template <class T>
int  Tree<T>::onlyLeftSon(Node<T> * current)
{
	int sum = 0;
	if (current == NULL)
		return 0;
	if (current->left && current->right == NULL)
		return(sum += onlyLeftSon(current->left)) + 1;
	if (current->left == NULL)
		return (sum += onlyLeftSon(current->right));
	return(sum += onlyLeftSon(current->left) + 1);
}