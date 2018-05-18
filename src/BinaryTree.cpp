#include "BinaryTree.h"
#include <string>
#include <iostream>

BinaryTree::BinaryTree() {
	root = new treeNode;
	root->right = nullptr;
	root->left = nullptr;
}

void BinaryTree::output(treeNode * node) {	//prints nodes in order
	if (node->left != nullptr) output(node->left);
	if (node->sequence != "") printf("the string %-8shas %-2d occurrences\n", node->sequence.c_str(), node->occurrences);
	if (node->right != nullptr) output(node->right);
}

void BinaryTree::push(treeNode * node, std::string a) {
	if (root->sequence == "") {
		root->sequence = a;
		increment(root);
	}
	else if (a == node->sequence) increment(node);	//if character string is the same as the node's then increment occurrences
	else if (a > node->sequence) {
		if (node->right == nullptr) {
			node->right = new treeNode;
			node->right->sequence = a;
			node->right->occurrences = 1;
			node->right->left = nullptr;
			node->right->right = nullptr;
		} else BinaryTree::push(node->right, a);
	}
	else if (a < node->sequence) {
		if (node->left == nullptr) {
			node->left = new treeNode;
			node->left->sequence = a;
			node->left->occurrences = 1;
			node->left->left = nullptr;
			node->left->right = nullptr;
		} else BinaryTree::push(node->left, a);
	}
}

void BinaryTree::increment(treeNode * node) {
	node->occurrences++;
}

BinaryTree::~BinaryTree() {}
