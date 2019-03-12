#include "Container.h"
struct node {
	node *st, *dr, *father;
	int info;
};
class BinaryTree : Container
{
	int count;
	node *root;
	void printInOrder(node *a);
	void CountNodes(node *a, int value, int &cnt);
	node* GetLeaf(node *a);
	node* SearchNode(node *a, int value);
	void deleteNode(node * d);
	void ArrayAsign(node *a, int *arr);
public:

	BinaryTree();

	~BinaryTree();

	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();

	void printTree();
};


