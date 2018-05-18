#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <string>

class BinaryTree {
private:
	struct treeNode{
		treeNode * right = nullptr;
		treeNode * left = nullptr;
		std::string sequence = "";
		int occurrences = 0;
	};

public:
	treeNode * root;
	BinaryTree();
	void output(treeNode*);	//prints out all the characters in the tree and the amount of times they occur.
	void push(treeNode*, std::string);	//pushes input string onto tree
	void increment(treeNode*);	//increments a node's occurrences variable
	~BinaryTree();
};

#endif /* BINARYTREE_H_ */
