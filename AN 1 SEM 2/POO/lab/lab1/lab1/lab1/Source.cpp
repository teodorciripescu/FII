#pragma warning(disable:4996)
#define WINPAUSE system("pause")
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[20];
int a;
int v[1000], n;
bool sorted;
int main() {
	int i, aux;
	FILE * file;
	file = fopen("input.in", "r");
	if (file == NULL) perror("Error opening file");
	else {
		while (fgets(str, 20, file) != NULL) {
			puts(str);
			a = atoi(str);
			v[n++] = a;
		}
		fclose(file);
		
		do {
			sorted = true;
			for(i=0;i<n-1;i++)
				if (v[i] > v[i + 1]) {
					aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					sorted = false;
				}
		} while (!sorted);
	}
	for (i = 0; i < n; i++)cout << v[i] << " ";
	WINPAUSE;

	return 0;
}