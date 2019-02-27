// sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
void sortcpp(int n,int v[5]) {
	bool sortat = false; int i, aux;
	do {
		sortat = true;
		for (i = 0; i < n - 1; i++) {
			if (v[i] < v[i + 1]) {
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
		}
	} while (!sortat);

}
//void rez(int v[5]) {
void rez(int *,int n) {
	_asm {
		mov ebx, [ebp+8]
		mov eax, [ebx]
		
		WHILE:
		mov ecx, 1 // flag daca vectorul e sortat, plecam cu premisa ca da
		mov esi, -1
		ffor:
		add esi, 1

			mov eax, [ebx + 4 * esi]
			mov edx, [ebx + 4 * esi + 4]
			cmp eax, edx
			ja interschimb
			back:

		mov eax, [ebp + 12]
		sub eax, 2
		cmp esi, eax
		je sfarsit_for
		jmp ffor
			interschimb:
			mov eax, [ebx + 4 * esi]
			mov edx, [ebx + 4 * esi + 4]
			mov [ebx + 4 * esi], edx
			mov [ebx + 4 * esi + 4],eax
			mov ecx, 0
			jmp back
		sfarsit_for:
			cmp ecx, 0
			je WHILE
		//mov ebx, [eax+4]

	}
}

int main()
{
	int n=5;
	int v[5] = { 5,4,3,2,1 };
	_asm {
		mov eax, n
		push n
		lea eax, v
		push eax
		call rez
		add esp, 8
	}
	for (int i = 0; i < n; i++)cout << v[i] << " ";

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
