#ifndef __AVLTREE__H__
#define __AVLTREE__H__

template<class T>
class TreeNode {
public:
	TreeNode():height(0),left(NULL),right(NULL) {}
	T data;
	int height;
	struct TreeNode * left;
	struct TreeNode * right;
}

template<class T>
class AVLTree {
public: 
	AVLTree():root(NULL) {}
	TreeNode<T>* Find(T x);
	void InsertNode(T x);
	void DeleteNode(T x);
	void InOrder();
private:
	int Height(TreeNode<T>* node) {
		if (NULL == node)
			return -1;
		return node->height; 
	}

	int Max(int a, int b) {
		return a > b ? a : b;
	}

	void Insert(TreeNode<T>* k, T x) {
		if (NULL = k) {
			k = new TreeNode<T>();
			k->data = x;
			return ;
		}		
		
		if (k->data > x) {
			Insert(k->left, x);
			if (TREE_HEIGHT_DIFF == (Height(k->left) - Height(k->right))) {
				if (x < k->left->data) {
					RightRotate(k);
				} else {
					DoubleRightLeftRotate(k);
				}
			}
		} else if (k->data < x) {
			Insert(k->right, x);
			if (TREE_HEIGHT_DIFF == (Height(k->right) - Height(k->left))) {
				if (x > k->right->data) {
					LeftRotate(k);
				} else {
					DoubleLeftRightRotate(k);
				}
			}
		} else {
		
		}
		k->height = Max(Height(k->left), Height(k->right));		
	}

	void Delete(TreeNode<T>* node, T x) {
	
	}

/*	              RR                                            
 *                                                                 
 *       k2                       k1                               
 *      / \                      /  \
 *     /   \                    /    \
 *    A    k1                  k2     B                            
 *        /  \                / \      \
 *       /    \       =>     /   \      \
 *      C      B            A     C      D                           
 *              \
 *               \
 *                D                                                
 *
 */

	void LeftRotate(TreeNode<T>* k2) {
		TreeNode<T>* k1;
		k1 = k2->right;
		k2->right = k1->left;
		K1->left = k2;

		k1->height = Max(Height(K1->left), Height(k1->right)) + 1;
		k2->height = Max(Height(K2->left), Height(K2->right)) + 1;
	}

 /*	           right rotate                                            
 *                                                                 
 *          k2                       k1                               
 *         / \                      / \
 *        /   \                    /   \
 *       k1    A                  B     k2                            
 *      / \                      /     / \
 *     /   \            =>      /     /   \
 *    B     C                  D     C     A                           
 *   /                                                            
 *  D                                                             
 *                                                                
 *
 */

	void RightRotate(TreeNode<T>* k2) {
		TreeNode<T>* k1;
		k1 = k2->left;
		k2->left = k1->right;
		K1->right = k2; 
		
		k1->height = Max(Height(K1->left), Height(k1->right)) + 1;
		k2->height = Max(Height(K2->left), Height(K2->right)) + 1;
	}

/*	      double rotate, left rotate, right rotate                                            
 *                                                                 
 *          k3                        k3                    k2             
 *         / \                       / \                   / \
 *        /   \                     /   \                 /   \
 *       k1    A                   K2    A               k1    k3           
 *      / \                       / \                   /     / \
 *     /   \            =>       /   \         =>      /     /   \
 *    B     k2                   k1    D               B     D     A                           
 *           \                 /                                           
 *            \               /                                    
 *             D             B                                       
 *
 */ 

	void DoubleLeftRightRotate(Tree<T>* k3) {
		K3->left = RightRotate(k3->left);
		LeftRotate(K3);
	}

/*           double rotate, right rotate, left rotate                                           
 *                                                                 
 *	    k3                       k3                       k2             
 *         / \                      / \                      / \
 *        /   \                    /   \                    /   \
 *       A     k1                 A    k2                  k3    k1           
 *            / \                      / \                / \     \
 *           /   \       =>           /   \       =>     /   \     \
 *          K2    B                  D    k1            A     D     B                               
 *         /                                \
 *        /                                  \
 *       D                                    B                                       
 *
 */ 

	void DoubleRightLeftRotate(Tree<T>* node) {
		k3->right = LeftRotate(k3->right);
		RightRotate(k3);
	}
private: 
	TreeNode<T> *root;
	const static TREE_HEIGHT_DIFF = 2; 
}


#endif 	// __AVLTREE__H__
