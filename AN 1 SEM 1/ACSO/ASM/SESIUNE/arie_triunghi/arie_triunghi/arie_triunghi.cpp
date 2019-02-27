// arie_triunghi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
struct triunghi {
	unsigned a;
	unsigned b;
	unsigned c;
};
unsigned radical(unsigned x)
{
	return sqrt(x);
}
void aria(triunghi *t) {
	_asm {
		mov ebx,[ebp+8]
		mov ecx, [ebx]
		mov edx, [ebx+4]
		add ecx, edx
		mov edx, [ebx+8]
		add ecx, edx
		mov eax, ecx
		mov edx, 0
		mov ecx, 2
		div ecx
		mov ecx, eax

		sub ecx, [ebx]
		mul ecx

		add ecx, [ebx]
		sub ecx, [ebx+4]
		mul ecx
		
		add ecx, [ebx+4]
		sub ecx, [ebx+8]
		mul ecx

		push eax
		call radical
		add esp, 4
		//mul eax, ecx-[ebx]

	}
}

int main()
{
	int r;
	triunghi t;
	t.a = 4;
	t.b = 5;
	t.c = 7;

	_asm {
		lea eax, t
		push eax
		call aria
		mov r, eax
		add esp, 4
	}
	std::cout << r;
	return 0;
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
