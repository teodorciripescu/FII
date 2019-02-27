#pragma warning(disable:4996)
#include "MyString.h"
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

MyString::MyString()
{
	sir = new char[16];
	AllocatedSize = 16;
	Size = 0;
}

MyString::MyString(const char * text)
{
	Set(text);
}

MyString::~MyString()
{
	delete sir;
}

unsigned int MyString::GetSize()
{
	return Size;
}

void MyString::Set(const char * text)
{
	unsigned int s = strlen(text);
	//cout << s << " text size\n";
	if (s >= AllocatedSize) { 
		delete sir;
		sir = new char[s + 1];
		AllocatedSize = s + 1;
	}
	strcpy(sir, text);
	Size = s;
}

void MyString::Set(MyString & m)
{
	unsigned int s = m.GetSize();

	if (s >= AllocatedSize) {
		delete sir;
		sir = new char[s + 1];
		AllocatedSize = s + 1;
	}
	strcpy(sir, m.GetText());
	Size = s;
	//cout << sir << " size: " << Size << endl;
}

void MyString::Add(const char * text)
{
	unsigned int s = strlen(text);
	
	if (Size + s >= AllocatedSize) {
		char * newSir = new char[Size + s + 1];
		strcpy(newSir, sir);
		strcat(newSir, text);
		delete sir;
		sir = newSir;
		AllocatedSize = Size + s + 1;
	}
	else {
		strcat(sir, text);
	}
	Size = Size + s;
}

void MyString::Add(MyString & m)
{
	unsigned int s = m.GetSize();

	if (Size + s >= AllocatedSize) {
		char * newSir = new char[Size + s + 1];
		strcpy(newSir, sir);
		strcat(newSir, m.GetText());
		delete sir;
		sir = newSir;
		AllocatedSize = Size + s + 1;
	}
	else {
		strcat(sir, m.GetText());
	}
	Size = Size + s;
}

const char * MyString::GetText()
{
	return sir;
}

MyString * MyString::SubString(unsigned int start, unsigned int size)
{
	if ((start > Size) || (start + size > Size)) return NULL;
	MyString * str = new MyString();
	char * c = new char[size];
	strncpy(c, &sir[start], size);
	c[size] = '\0';
	str->Set(c);
	return str;
}

bool MyString::Delete(unsigned int start, unsigned int size)
{
	if ((start > Size) || (start + size > Size)) return false;
	//MyString * str = new MyString();
	char * c = new char[Size - size + 1];
	strncpy(c, &sir[0], start);
	c[start] = '\0';
	strcat(c, &sir[start + size]);
	Size = Size -size;
	delete sir;
	sir = c;
	return true;
}

int MyString::Compare(const char * text)
{
	return strcmp(sir, text);
}

int MyString::Compare(MyString & m)
{
	return strcmp(sir, m.GetText());
}

char MyString::GetChar(unsigned int index)
{
	if(index > Size) return 0;
	return sir[index];
}

bool MyString::Insert(unsigned int index, const char * text)
{
	if(index >= Size) return false;
	
	unsigned int s = strlen(text);
	char * newSir = new char[Size + s + 1];
	strncpy(newSir, sir, index);
	newSir[index] = '\0';
	strcat(newSir, text);
	strcat(newSir, &sir[index]);
	cout << newSir;
	delete sir;
	sir = newSir;
	AllocatedSize = Size + s + 1;
	/*
	if (Size + s >= AllocatedSize) {
		

	}
	else
	{
		char* c = new char[Size-index];
		strcpy(c, &sir[index]); c[s] = '\0';
		strncpy(sir, sir, index); sir[index] = '\0';
		strcat(&sir[index], c);
		delete c;
	}
	*/
	Size = Size + s;
	return true;
}

bool MyString::Insert(unsigned int index, MyString & m)
{
	if (index >= Size) return false;

	unsigned int s = strlen(m.GetText());
	char * newSir = new char[Size + s + 1];
	strncpy(newSir, sir, index);
	newSir[index] = '\0';
	strcat(newSir, m.GetText());
	strcat(newSir, &sir[index]);
	cout << newSir;
	delete sir;
	sir = newSir;
	AllocatedSize = Size + s + 1;
	Size = Size + s;
	return true;
}

int MyString::Find(const char * text)
{
	char* c = strstr(sir, text);
	if (c)return Size - strlen(c);
	return -1;
}

int MyString::FindLast(const char * text)
{
	char* c = strstr(sir, text);
	
	unsigned int index = -1, l = strlen(text);
	while (c) {
		index = Size - strlen(c);
		c += l;
		c = strstr(c, text);
	}
	return index;
}
