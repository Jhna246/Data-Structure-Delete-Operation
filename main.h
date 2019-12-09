#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class BST
{
	struct node
	{
		std::string data;
		node* left;
		node* right;
	};

	node* root;

	node* insert(node* root, std::string data)
	{
		if (root == NULL)
		{
			root = new node;
			root->data = data;
			root->left = root->right = NULL;
		}
		else if (data < root->data)
		{
			root->left = insert(root->left, data);
		}
		else if (data > root->data)
		{
			root->right = insert(root->right, data);
		}

		return root;
	}

	void inorder(node* root)
	{
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	node* findMinValue(node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else if (root->left == NULL)
		{
			return root;
		}
		else
		{
			return findMinValue(root->left);
		}
	}

	node* erase(node* root, std::string data)
	{
		if (root == NULL) return root;

		if (data < root->data)
		{
			root->left = erase(root->left, data);

		}
		else if (data > root->data)
		{
			root->right = erase(root->right, data);
		}

		else
		{
			if (root->left == NULL)
			{
				node *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				node *temp = root->left;
				free(root);
				return temp;
			}
			node* temp = findMinValue(root->right);

			root->data = temp->data;

			root->right = erase(root->right, temp->data);
		}
		return root;
	}

	bool search(node* root, std::string data)
	{
		while (root != NULL)
		{
			if (data < root->data)
			{
				return search(root->left, data);
			}
			else if (data > root->data)
			{
				return search(root->right, data);
			}
			else
			{
				return true;
			}
		}
		return false;
	}


public:

	BST()
	{
		root = NULL;
	}

	void insert(std::string data)
	{
		root = insert(root, data);
	}

	void erase(std::string data)
	{
		root = erase(root, data);
	}

	void display()
	{
		inorder(root);
		cout << endl;
	}

	bool search(std::string data)
	{
		return search(root, data);
	}
};
