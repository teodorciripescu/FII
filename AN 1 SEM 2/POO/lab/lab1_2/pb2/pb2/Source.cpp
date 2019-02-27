#define WINPAUSE system("pause")
#define MATRIX_HEIGHT 6
#define MATRIX_WIDTH 5
#include<iostream>
#include<cmath>
using namespace std;
int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
struct P {
	int x, y;
};
P P1, P2;
void Circle(int* ptr, int cx, int cy, int ray) {
	int i, j, dist;
	P2.x = cx;
	P2.y = cy;
	ptr[0*MATRIX_WIDTH + ray] = 1;
	ptr[cx*MATRIX_WIDTH + 0] = 1;
	ptr[cx * MATRIX_WIDTH + (cy+ray)] = 1;
	ptr[(cx+ray) * MATRIX_WIDTH + cy] = 1;

	for (i = 0; i < MATRIX_HEIGHT; i++){
		for (j = 0; j < MATRIX_WIDTH; j++) {
			P1.x = i;
			P1.y = j;
			dist = (P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y);
			if (dist == ray) ptr[i*MATRIX_WIDTH + j] = 1;
			cout << (ptr[i*MATRIX_WIDTH + j]) << " ";
		}
		cout << endl;
	}
}
int main() {
	Circle(&Matrix[0][0], 2, 2, 2);
	WINPAUSE;
	
	return 0;
}