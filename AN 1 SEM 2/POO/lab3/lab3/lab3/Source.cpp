#include<iostream>
#include "BigNumber.h"
using namespace std;

int main() {
	BigNumber n("14");
	BigNumber nn("-8");
	//if (n > nn)cout << "n m mare ca nn"<<endl;
	cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << endl;
	cout << endl << n * nn << endl;
	cout << n(0, 1)<<endl;
	cout << endl << n / nn;
	//cout << endl<<(int)nn;
	system("pause");
	return 0;
}