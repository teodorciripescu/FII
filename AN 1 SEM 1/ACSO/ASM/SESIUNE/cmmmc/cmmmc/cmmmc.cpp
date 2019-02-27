// cmmmc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void rez_cmmdc(int a, int b) {
	_asm {
		WHILE:
			mov eax, [ebp+8]
			mov ebx, [ebp+12]
			mov edx, 0
			div ebx
			mov ecx, [ebp+12]
			mov [ebp+8],ecx
			mov [ebp+12], edx
			cmp [ebp+12], 0
			jg WHILE

		sfarsit:
			mov eax, [ebp+8]
	}
}


int main()
{
	//cout << cmmdc(10, 15);
	int a=10, b=15;
	_asm {
		push b
		push a
		call rez_cmmdc
		mov ecx, eax
		mov eax, a
		mov ebx, b
		mul ebx
		div ecx
		mov a, eax
		add esp,8
	}
	//cout << "Cmmdc= " << a;
	cout << "Cmmmc= " << a;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
