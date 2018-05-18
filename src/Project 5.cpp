#include <iostream>
#include <fstream>
#include <cctype>
#include "BinaryTree.h"
using namespace std;

int main() {
	int length;
	int count = 1;
	BinaryTree * tree = new BinaryTree;
	cout << "Input maximum string length to search for: ";
	cin >> length;
	while (!length || length < 1) {	//checking input for incorrect input
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a positive integer.";
		cin >> length;
	}
	string temp;
	string input = "";
	ifstream * file = new ifstream("input.txt");
	if (file->fail()) cout << "File read error.";

	while (*file >> temp) {	//takes input from file pointer and puts it in temp and appends temp to input
		*file >> temp;
		input.append(temp);
		for (unsigned int i = 0; i < input.length(); i++) {
			if (!isalpha(input[i])) input.erase(i);	//removes non-alphanumeric characters
			if (isupper(input[i])) input[i] = tolower(input[i]);	//changes upper case characters to lower case
		}
	}

	for (int  i = 0; i < length; i++) {	//push characters from input string onto the tree
		for (unsigned int j = 0; j < input.length()-i; j++) {
			tree->push(tree->root, input.substr(j,count));
		}
	count++;
	}

	tree->output(tree->root);
	return 0;
}
