#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	// search trees
	void add(T value);//add func
	bool  search(T value)// return is 
	{
		return search(this->root, value);
	}
	
	void okev(Node<T> * &, T);//found 
	void remove(T const& data);//remove func
	int level(T val)
	{
		if (this->search(val))
			return  this->level(this->root, val);
		return -1;
	}
private:
	void add(Node<T> *, T);
	bool  search(Node<T>*, T);
	int level(Node<T>*, T);//returns vertex level of the tree that contains the value "val".
};


template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!this->root)
	{
		this->root = new Node<T>(val);
		return;
	}
	add(this->root, val);
}

template <class T>
bool SearchTree<T>::search(Node<T> * current, T val)
{
	// see if argument value occurs
	if (!current)
		return false;	// not occured
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
void SearchTree<T>::add(Node<T>* current, T val)
{
	if (current->value < val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new Node<T>(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new Node<T>(val);
			return;
		}
		else add(current->left, val);
}

template<class T>
void SearchTree<T>::okev(Node<T> * &current, T val)//found the limb okev
{
	if (current->right == NULL)
		current = NULL;
	if (current->right)
	{
		current = current->right;
		while (current->left)
			current = current->left;
	}
}
template<class T>
int SearchTree<T>::level(Node<T>* current, T value)
{
	if (!search(value))
		return -1;
	if (current->value == value)
		return 0;
	if (value < current->value)
	{
		return (level(current->left, value) + 1);
	}
	else return (level(current->right, value) + 1);
}
template<class T>
void SearchTree<T>::remove(T const& data)
{
	Node<T>* temp = this->root;
	Node<T>* parent = this->root;
	if (!this->root)
		return;
	while (temp->value != data)//search in the tree
	{
		if (temp->value > data)
		{
			parent = temp;
			temp = temp->left;
		}
		else
		{
			parent = temp;
			temp = temp->right;
		}
	}
	if (temp->right == NULL && temp->left == NULL)//if data isleaf
	{
		if (parent->left->value == temp->value)
			parent->left = NULL;
		if (parent->right->value == temp->value)
			parent->right = NULL;
		return;
	}
	if ((temp->right == NULL && temp->left) || (temp->left == NULL && temp->right))//if data have one child
	{
		if (temp->right == NULL && temp->left)//have just a left child
		{
			if (parent->left->value == temp->value)
				parent->left = temp->left;
			if (parent->right->value == temp->value)
				parent->right = temp->left;
		}

		if (temp->right  && temp->left == NULL)//have just a right child
		{
			if (parent->left->value == temp->value)
				parent->left = temp->right;
			if (parent->right->value == temp->value)
				parent->right = temp->right;
		}

		return;
	}
	if (temp->left != NULL && temp->right != NULL)
	{
		Node<T> *curr_right = temp->right;
		if (curr_right->left == NULL && curr_right->right == NULL)
		{
			temp->value = curr_right->value;
			if (curr_right)

				temp->right = NULL;
		}
		else
		{ // right child has children
		  //if the node's right child has a left child
		  // Move all the way down left to locate smallest element

			if ((temp->right)->left != NULL)
			{
				Node<T>* lcurr;
				Node<T>* lcurr_parent;
				lcurr_parent = temp->right;
				lcurr = (temp->right)->left;
				while (lcurr->left != NULL)
				{
					lcurr_parent = lcurr;
					lcurr = lcurr->left;
				}
				temp->value = lcurr->value;

				lcurr_parent->left = NULL;
			}
			else
			{ // (curr->right)->right != nullptr
				Node<T> *otherTmp = temp->right;
				temp->value = otherTmp->value;
				temp->right = otherTmp->right;

			}
		}
	}
}
