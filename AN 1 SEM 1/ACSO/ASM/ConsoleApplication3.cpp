// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	//cati biti de 1 sunt in componenta unui nr (se poate si cu impartiri repetate la 2)
	int a, bit, c=1, i,n;
	a = 7;
	//for(i=0;i<32;i++)
	while(a)
	_asm {	
		shl c, 1;
//		test a, c;
		shr a, 1;
	}
	//mai e
   cout << a; 
}


//factorial 
/*
int a=1, b, c, i,n;
	n = 4;

	for (int i = 1; i <= n; i++) {
		_asm {
			mov eax, a;
			mov ecx, i;
			mul ecx;
			mov a, eax;
		}
		//daca as pune aici un cout de exemplu se vor folosi registrii si le pot fi alterate valorile
	}
   cout << a;

*/

//inmultire intre 3 numere
/*
	_asm {
		mov eax, a;
		mov ebx, 20;
		mov ecx, b;

		mul ecx;
		mul ebx;
		mov a, eax;
	}
	*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
