#include "BinaryTree.h"
#include<iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	count = 0;
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::Add(int value)
{
	if (root == nullptr) {
		root = new node();
		root->info = value;
		count++;
		return true;
	}
	node **p = new node*[count], *a;
	node *insert = new node();
	insert->info = value; insert->st = NULL; insert->dr = NULL; insert->father = NULL;
	int pcnt = 1,i;
	p[0] = root;
	while (p) {
		a = p[0];
		if (a->st && a->dr) {
			p[pcnt++] = a->st;
			p[pcnt++] = a->dr;
			for (i = 0; i < pcnt - 1; i++)
				p[i] = p[i + 1];
			pcnt--;
		}
		else
			if (!a->st) {
				insert->father = a;
				a->st = insert;
				count++;
				delete[] p;
				return true;
		}
		else 
			if (!a->dr) {
				insert->father = a;
				a->dr = insert;
				count++;
				delete[] p;
				return true;
		}
		
	}

	return false;
}



bool BinaryTree::Del(int value)
{
	//caut primul element frunza si il inlocuiesc elementul de sters cu el

	node *d;
	bool deleted = false;
	//d = SearchNode(root, value);
	do {
		d = NULL;
 		d = SearchNode(root, value);
		if (d && d->info != value) break;
		if(d){
			deleteNode(d);
			deleted = true;
		}
	} while (d);

	return deleted;
}
void BinaryTree::deleteNode(node *d) {
	node *swp;
	swp = GetLeaf(root);
	d->info = swp->info;
	//a node points to the deleted node
	///*
	if (swp->father  && swp->father->st == swp)
		swp->father->st = NULL;
	else
		if (swp->father && swp->father->dr == swp)
			swp->father->dr = NULL;
	//*/
	delete swp;
	count--;
	d = NULL;
	//deleted = true;
	
}
node* BinaryTree::SearchNode(node *a, int value) {
	if (a) {
		if (a->info == value) return a;
		if(a->st) return SearchNode(a->st, value);
		if(a->dr) return SearchNode(a->dr, value);
	}
}
node* BinaryTree::GetLeaf(node *a) {
	if (a) {
		if (!a->st && !a->dr) return a;
		if (a->st) return GetLeaf(a->st);
		if (a->dr) return GetLeaf(a->dr);
	}
}
int BinaryTree::Count(int value)
{
	int cnt = 0;
	CountNodes(root, value, cnt);
	return cnt;
}
void BinaryTree::CountNodes(node *a, int value, int &cnt) {
	if (a) {
		if (a->st) CountNodes(a->st, value, cnt);
		if (a->info == value) cnt++;
		if (a->dr) CountNodes(a->dr, value, cnt);
	}
}
bool BinaryTree::Exists(int value)
{
	node *a = SearchNode(root, value);
	if (a && a->info == value) 
		return true;
	return false;
}

int * BinaryTree::GetSortedArray()
{
	int *arr = new int[count+1], i = 0, aux, *b;
	arr[0] = 0;
	ArrayAsign(root, arr);
	arr++;
	bool sorted;
	do {
		sorted = true;
		for (i = 0; i < count - 1; i++)
			if (arr[i] > arr[i + 1]) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				sorted = false;
			}
	} while (!sorted);
	
	return arr;
}
void BinaryTree::ArrayAsign(node *a, int *arr) {
	if (a) {
		if (a->st) ArrayAsign(a->st, arr);
		++arr[0];
		arr[arr[0]] = a->info;
		//cout << arr[arr[0]] << " ";
		if (a->dr) ArrayAsign(a->dr, arr);
	}
}
int BinaryTree::GetCount()
{
	return count;
}

void BinaryTree::printTree()
{
	printInOrder(root);
	cout << endl;
}

void BinaryTree::printInOrder(node *a) {
	if (a) {
		if (a->st) printInOrder(a->st);
		cout << a->info << " ";
		if (a->dr) printInOrder(a->dr);
	}
}