#include "avltree.h"

int main(int argc, char** argv) {
	int i;
	int a = {5, 9, 1, 8, 3, 2, 4, 6, 7};
	AVLTree<int> tree = new AVLTree<int>();
	for (i = 0; i < sizeof(a)/sizeof(int); i++) {
		tree.InsertNode(NULL, a[i]);
	}
	tree.InOrder();
	Delete tree;
	
	return 0;
}
