#include<iostream>
#include"List.h"
#include"BinaryTree.h"
using namespace std;

int main(){
	/*
	List l;
	l.Add(3);
	l.Add(2);
	l.Add(1);
	l.Add(3);
	l.Add(3);
	l.printList();
	///*
	l.Del(1);
	l.printList();
	l.Del(3);
	l.printList();
	//
	cout << "GetCount(): " << l.GetCount() << endl;
	cout << "Count(): " << l.Count(2) << endl;
	cout << "Exists(): " << l.Exists(1) << endl;
	int *a = l.GetSortedArray(),i=0;
	while (i<l.GetCount()) {
		cout << a[i++] << " ";
	}
	cout << endl;
	*/
	BinaryTree t;
	t.Add(1);
	t.Add(2);
	t.Add(3);
	t.Add(4);
	t.Add(5);
	t.Add(6);
	t.Add(7);
	t.Add(8);
	t.Add(9);
	t.printTree();
	t.Del(1);
	t.printTree();
	t.Del(2);
	t.printTree();
	t.printTree();
	int *a = t.GetSortedArray(), i = 0;
	cout << endl<<t.GetCount()<<endl;
	while (i < t.GetCount()) {
		cout << a[i++] << " ";
	}
	system("pause");
	return 0;
}