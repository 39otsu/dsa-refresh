#include <iostream>
struct Node {
	int value;
	Node * left;
	Node * right;
};

void createPerfectBinaryTree(int a, Node * root) {
	a++;
	root->value = a;
	if (root == nullptr) {
		return;
	}
	if (a < 3) {
	   	root->left = new Node();
    	root->right = new Node();
    	createPerfectBinaryTree(a, root->left);
    	createPerfectBinaryTree(a, root->right); 
	}
}

void deleteTree(Node * tree) {
	if (root != nullptr) {
		deleteTree(tree->left);
		deletetree(tree->right);
		delete this;
	}
}
// visit current node before child nodes
void preOrder(Node * root)
{
	if (root != nullptr) {
		std::cout << root->value << '\n';
		preOrder(root->left);
		preOrder(root->right);
	}
}

// visit child nodes before current node
void postOrder(Node * root)
{
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->value << '\n';
	}
}

// visit left branch, then the current node and finally the right branch
void inOrder(Node * root) {
	if (root != nullptr) {
		inOrder(root->left);
		std::cout << root->value << '\n';
		inOrder(root->right);
	}
}

int main()
{
	Node * tree = new Node();
	int a = 0;
	createPerfectBinaryTree(a, tree);
	std::cout << "== IN ORDER TRAVERSAL ==\n";
	inOrder(tree);
	std::cout << "== PRE ORDER TRAVERSAL ==\n";
	preOrder(tree);
	std::cout << "== POST ORDER TRAVERSAL ==\n";
	postOrder(tree);
	
	deleteTree(tree);
	if (tree == nullptr) {
		std::cout << "deletion worked\n";
	}
	return 0;
}