#define RES_MAX_SIZE 20
#include<iostream>
#include<cstring>
using namespace std;
char res[20]="",l;
bool Convert(unsigned int number, unsigned int toBase, char * result, unsigned int resultMaxSize) {
	int c;
	while (number) {
		c = number % toBase;
		number /= toBase;
		if (c > 9) {
			strcpy()
			strcat(result, (char)('A' + c - 10));

		}
	}
	
}

int main() {
	
	Convert(255, 16, res, RES_MAX_SIZE);
	cout << res;
	return 0;
}