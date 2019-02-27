// sumaElemPare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int suma_pare_vector(int *, int)
{
	int todiv = 2;
	_asm
	{
		// completati
		mov ebx, [ebp+8]
		mov ecx, 0
		ffor:
		mov eax, [ebx + ecx*4]
		add ecx, 1
		mov edx, 0
		div todiv
		cmp dx, 0
		je suma
		testt:
		cmp ecx, 5
		jb ffor
		jmp sfarsit
			suma:
		mov eax, [ebx + ecx*4 - 4]
		mov edx, [ebp+12]
		add edx, eax
		mov [ebp+12], edx
		jmp testt
			sfarsit:
		mov eax, [ebp+12]
	}
}


int main()
{
	int v[5] = { 5,1,2,3,6 };
	int *p = v;
	int s=0;

	_asm
	{
		// completati
		push s
		push p
		call suma_pare_vector
		mov s, eax
		add esp, 8
	}

	printf("Suma: %d", s);
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
