#include "main.h"

int main()
{
	BST root;
	std::string value;

	std::ifstream file("ex04.txt");

	std::string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			root.insert(line);
		}
	}

	root.display();

	
	while (true)
	{
		cout << "Enter the word to delete : ";
		cin >> value;
		cout << root.search(value) << endl;


		if (root.search(value) != NULL)
		{
			root.erase(value);
			cout << "the word " << value << " is deleted\n";
		}
		else
		{
			cout << "the word " << value << " does not exist\n";
		}
		root.display();
	}
}
