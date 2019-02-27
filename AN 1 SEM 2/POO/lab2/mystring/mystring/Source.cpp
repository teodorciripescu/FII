#define WINPAUSE system("pause")
#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	MyString s = MyString();
	
	s.Set("regerggbgfbgbfgbgffgbfgerg");
	cout << "Find: " << s.Find("ger")<<endl;
	cout << "Find last: " << s.FindLast("ger")<<endl;
	cout << "String comparison: " << s.Compare("regerggbgfbgbfgbgffgbfgerg")<<endl;
	s.Insert(3, "1234");
	cout << "String insert    : " << s.GetText()<<endl;
	MyString s2 = MyString();
	s2.Set(s);
	s2.Add(" mama mia.");
	s2.Add(s);
	cout << "String comparison: " << s.Compare(s2) << endl;

	cout << s2.GetText() <<s2.GetSize()<< endl;
	s2.Delete(3, 6);
	cout << s2.GetText() <<s2.GetSize()<< endl;
	int a = s.GetSize();
	const char* c = s.GetText();
	cout << a <<endl<<c<<endl;
	cout << s.SubString(2, 5)->GetText()<<endl;
	cout << "------------------------";
	//const char * cc = ;
	MyString ss = MyString("un string corect.");
	cout << endl << ss.GetText();
	WINPAUSE;
	return 0;
}