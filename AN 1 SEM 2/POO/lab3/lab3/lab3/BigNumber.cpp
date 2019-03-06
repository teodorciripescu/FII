#define _CRT_SECURE_NO_WARNINGS
#include "BigNumber.h"
#include<iostream>
#include<cstring>
using namespace std;

BigNumber::BigNumber()
{
	for (int i = 0; i < 256; i++) Number[i] = '0';
	CharactersCount = 1;
}

BigNumber::BigNumber(int value)
{
	Set(value);
}

BigNumber::BigNumber(const char * number)
{
	Set(number);
}

BigNumber::BigNumber(const BigNumber & number)
{
	int i;
	for (i = 0; i < number.CharactersCount; i++)
		Number[i] = number.Number[i];
	CharactersCount = number.CharactersCount;
	if (number.Number[number.CharactersCount] == '-'){
		Number[CharactersCount] = '-';
		Number[CharactersCount + 1] = '\0';
	}
	else 
		Number[CharactersCount] = '\0';
}

bool BigNumber::Set(int value)
{
	int c;
	char sign = '0';
	if (value < 0)
		sign = '-';
	else
		sign = '\0';
	CharactersCount = 0;
	while (value) {
		c = abs(value % 10);
		value /= 10;
		Number[CharactersCount++] = 48 + c;
	}
	Number[CharactersCount] = sign;
	for (int i = 0; i <= CharactersCount; i++)
		cout << Number[i] << "  ";
	cout << endl;
	return true;
}

bool BigNumber::Set(const char * number)
{
	int i, len = strlen(number);
	
	for (i = 0; i < len; i++) Number[i] = number[len - i - 1];
	
	Number[len] = '\0';
	if (Number[len - 1] == '-')
		CharactersCount = len - 1;
	else
		CharactersCount = len;
	return true;
}

BigNumber BigNumber::operator+(const BigNumber & number)
{
	//cout << "\noperator+ =================== " << endl;
	int i, min;
	BigNumber n;
	n.CharactersCount = CharactersCount > number.CharactersCount ? CharactersCount : number.CharactersCount;
	min = CharactersCount < number.CharactersCount ? CharactersCount : number.CharactersCount;
	const char *p = CharactersCount > number.CharactersCount ? Number : number.Number;
	
	for (i = 0; i <= n.CharactersCount+1; i++)
		n.Number[i] = '0';
	int sign1 = Number[CharactersCount];
	int sign2 = number.Number[number.CharactersCount];
	if (sign1 == sign2) {
		for (i = 0; i < min; i++) {
			n.Number[i] = n.Number[i] + Number[i] + number.Number[i] - 96;
			if (n.Number[i] > 57){
				n.Number[i + 1]++;
				n.Number[i] -= 10;
			}
		}
		for (i = min; i < n.CharactersCount; i++) {
			n.Number[i] = n.Number[i] + p[i] -48 ;
			if (n.Number[i] > 57) {
				n.Number[i + 1]++;
				n.Number[i] -= 10;
			}
		}
		if (n.Number[n.CharactersCount] != '0')n.CharactersCount++;
		n.Number[n.CharactersCount] = (char)sign1;
		n.Number[n.CharactersCount + 1] = '\0';
}
	else{
		//aflu care e nr mai mare in lungime
		//in caz ca sunt egale in lungime trebuie comparate caracter cu caracter
		//scad numerele 
		char big[256], small[256];
		char big_sign, small_sign; 
		int big_cnt, small_cnt; 
		if(CharactersCount > number.CharactersCount){
			strcpy(big, Number);
			big_sign = Number[CharactersCount];
			big_cnt = CharactersCount;
			strcpy(small, number.Number);
			small_cnt = number.CharactersCount;
		}
		else if (CharactersCount < number.CharactersCount) {
			strcpy(big, number.Number);
			big_sign = number.Number[number.CharactersCount];
			big_cnt = number.CharactersCount;
			strcpy(small, Number);
			small_cnt = CharactersCount;
		}
		else {
			for (i = CharactersCount-1; i >= 0; i--) {
				if (Number[i] > number.Number[i]) {
					strcpy(big, Number);
					big_sign = Number[CharactersCount];
					big_cnt = CharactersCount;
					strcpy(small, number.Number);
					small_cnt = number.CharactersCount;
					break;
				}
				else if (Number[i] < number.Number[i]) {
					strcpy(big, number.Number); 
					big_sign = number.Number[number.CharactersCount];
					big_cnt = number.CharactersCount;
					strcpy(small, Number);
					small_cnt = CharactersCount;
					break;
				}
			}
		}
		strcpy(n.Number, big);
		int j;
		//cazul in care sunt egale in modul
		if (n.Number[0]<48 || n.Number[0]>57) {
			n.Number[0] = '0';
			n.Number[1] = '\0';
			n.CharactersCount = 1;
			return n;
		}
		for (i = small_cnt-1; i >= 0; i--){
			n.Number[i] = n.Number[i] - small[i] + 48;
			j = i;
			while (n.Number[j] < '0' && n.Number[j]!='\0') {
				n.Number[j] += 10;
				n.Number[j+1]--;
				j++;
			}
		}
		//eliminam zerourile redundante
		while (n.Number[n.CharactersCount - 1] == '0') {
			n.Number[n.CharactersCount - 1] = big_sign;
			n.Number[n.CharactersCount] = '\0';
			n.CharactersCount--;
		}
		//n.Number[n.CharactersCount] = '\0';
	}
	
	
	return n;
}

BigNumber BigNumber::operator*(const BigNumber & number)
{
	BigNumber n, Nmb1, Nmb2, decr;
	//numarul pe care il construim
	n.Number[0] = '0'; n.Number[1] = '\0'; n.CharactersCount = 1;
	//copiem modulul primului operand
	strcpy(Nmb1.Number, Number); Nmb1.CharactersCount = CharactersCount;
	if (Nmb1.Number[Nmb1.CharactersCount] == '-')
		Nmb1.Number[Nmb1.CharactersCount] = '\0';
	//copiem modulul celui de al doilea operand
	strcpy(Nmb2.Number, number.Number); Nmb2.CharactersCount = number.CharactersCount;
	if (Nmb2.Number[Nmb2.CharactersCount] == '-')
		Nmb2.Number[Nmb2.CharactersCount] = '\0';
	//decr il va decrementa pe Nmb cu 1
	decr.Number[0] = '1'; decr.Number[1] = '-'; decr.Number[2] = '\0'; decr.CharactersCount = 1;
	while(true){
		Nmb1 = decr + Nmb1 ;
		Nmb1.Number[Nmb1.CharactersCount] = '\0';
		n = n + Nmb2;
		n.Number[n.CharactersCount] = '\0';
		if (Nmb1.Number[1]== '\0' && Nmb1.Number[0] == '0') break;
	}
	//inmultire a 2 numere negative
	if (   Number[CharactersCount] == '\0' && number.Number[number.CharactersCount] == '-'
		|| Number[CharactersCount] == '-' && number.Number[number.CharactersCount] == '\0') {
		n.Number[n.CharactersCount] = '-';
		n.Number[n.CharactersCount + 1] = '\0';
	}
	return n;
}

BigNumber BigNumber::operator-(const BigNumber & number)
{
	BigNumber n;
	strcpy(n.Number, number.Number);
	n.CharactersCount = number.CharactersCount;
	if (n.Number[n.CharactersCount] == '-') 
		n.Number[n.CharactersCount] = '\0';
	else {
		n.Number[n.CharactersCount] = '-';
		n.Number[n.CharactersCount + 1] = '\0';
	}
	return this->operator+(n);
}

BigNumber BigNumber::operator/(const BigNumber & number)
{
	BigNumber n, Nmb1, Nmb2, incr;
	//numarul pe care il construim
	n.Number[0] = '0'; n.Number[1] = '\0'; n.CharactersCount = 1;
	//copiem modulul primului operand
	strcpy(Nmb1.Number, Number); Nmb1.CharactersCount = CharactersCount;
	if (Nmb1.Number[Nmb1.CharactersCount] == '-')
		Nmb1.Number[Nmb1.CharactersCount] = '\0';
	//copiem modulul celui de al doilea operand
	strcpy(Nmb2.Number, number.Number); Nmb2.CharactersCount = number.CharactersCount;
	if (Nmb2.Number[Nmb2.CharactersCount] == '-')
		Nmb2.Number[Nmb2.CharactersCount] = '\0';
	//incr il va incrementa pe n cu 1
	incr.Number[0] = '1'; incr.Number[1] = '\0'; incr.CharactersCount = 1;
	while (true) {
		Nmb1 = Nmb1 - Nmb2;
		Nmb1.Number[Nmb1.CharactersCount] = '\0';
		n = n + incr;
		n.Number[n.CharactersCount] = '\0';
		if (Nmb1 < Nmb2) break;
	}
	//div a 2 numere negative
	if (Number[CharactersCount] == '\0' && number.Number[number.CharactersCount] == '-'
		|| Number[CharactersCount] == '-' && number.Number[number.CharactersCount] == '\0') {
		n.Number[n.CharactersCount] = '-';
		n.Number[n.CharactersCount + 1] = '\0';
	}
	return n;
}

BigNumber::operator int()
{
	int n = 0, i, sign = 1;
	if (Number[CharactersCount] == '-')sign = -1;
	for (i = CharactersCount - 1; i >= 0; i--)
		n = n * 10 + Number[i] - 48;
	return sign * n;
}

char BigNumber::operator[](int index)
{
	if (index >= strlen(Number)) return '\0';
	return Number[strlen(Number) - index - 1];
}

BigNumber BigNumber::operator()(int start, int end)
{
	if (start > end || start < 0 || end < 0 || end > CharactersCount || (start == '0' && end=='0' && Number[CharactersCount] == '-'))
		return 0;
	BigNumber n;
	char c[256], cLen = 0;
	for (int i = start; i <= end; i++) {
		c[cLen++] = this->operator[](i);
	}
	c[cLen] = '\0';
	n.Set(c);
	return n;
}

bool operator==(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[0] == '0' && n.CharactersCount == 1)
		return true;
	return false;
}

bool operator!=(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[0] == '0' && n.CharactersCount == 1)
		return false;
	return true;
}

bool operator<(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[n.CharactersCount] == '-')
		return true;
	return false;
}

bool operator>(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[n.CharactersCount] == '-'
		|| (n.Number[0] == '0' && n.CharactersCount == 1))
		return false;
	return true;
}

bool operator>=(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[n.CharactersCount] == '-')return false;
	return true;
}

bool operator<=(const BigNumber & n1, const BigNumber & n2)
{
	BigNumber n(n1);
	n = n - n2;
	if (n.Number[n.CharactersCount] == '-'
		|| (n.Number[0] == '0' && n.CharactersCount == 1))
		return true;
	return false;
}
