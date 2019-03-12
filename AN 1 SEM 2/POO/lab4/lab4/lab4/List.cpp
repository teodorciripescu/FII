#include "List.h"
#include <iostream>
using namespace std;

bool List::Add(int value) {
	if (!head) {
		head = new elem();
		head->info = value;
		last = head;
		count++;
	}
	else{
		elem *a = new elem();
		a->info = value;
		last->succ = a;
		last = a;
		count++;
	}
	return true;
}

bool List::Del(int value)
{
	bool deleted = false;
	elem *a,*b;

	a = head;
	while (a) {
		if (a->succ && a->succ->info == value) {
			b = a->succ->succ;
			delete a->succ;
			a->succ = b;
			count--;
			deleted = true;
		}
		else
			a = a->succ;
	}
	if (head && head->info == value) {
		b = head->succ;
		delete head;
		head = b;
		count--;
		deleted = true;
	}


	return deleted;
}

int List::Count(int value)
{
	int cnt = 0;
	elem *a = head;
	while (a) {
		if (a->info == value)
			cnt++;
		a = a->succ;
	}
	return cnt;
}

bool List::Exists(int value)
{
	bool exists = false;
	elem *a = head;
	while (a) {
		if (a->info == value) {
			exists = true;
			break;
		}
		a = a->succ;
	}
	return exists;
}

int * List::GetSortedArray()
{
	int *arr = new int[count], i = 0, aux;
	elem *a = head;
	while (a) {
		arr[i++] = a->info;
		a = a->succ;
	}
	bool sorted;
	do {
		sorted = true;
		for(i=0;i<count-1;i++)
			if (arr[i] > arr[i + 1]) {
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				sorted = false;
			}

	} while (!sorted);
	return arr;
}

int List::GetCount()
{
	return count;
}

void List::printList()
{
	elem *a = head;
	while (a) {
		cout << a->info << " ";
		a = a->succ;
	}
	cout << endl;
}

List::List()
{
	count = 0;
}


List::~List()
{
}
