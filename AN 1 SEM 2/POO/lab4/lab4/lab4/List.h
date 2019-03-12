#include "Container.h"

struct elem {
	elem *succ;
	int info;
};

class List : Container
{
	elem *head;
	elem *last;
	int count;

public:

	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();

	void printList();

	List();

	~List();
};

