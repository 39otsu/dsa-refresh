#include <bits/stdc++.h>
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
int main() {
    Node * tree = new Node();
    createPerfectBinaryTree(0, tree);
    std::queue<Node*> q;
    q.push(tree);
    int level = 0;
    while (q.empty() == false) {
        std::cout << "Level: " << level << '\n';
        int level_size = q.size();
        int level_count = level_size;
        while (level_count != 0) {
            tree = q.front();
            q.pop();
            if (tree != nullptr) {
                std::cout << tree->value << '\n';
                q.push(tree->left);
                q.push(tree->right);
            }
            level_count--;
        }
        level++;
    }

    return 0;
}