#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#include "List.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List clist;
	int k;
	char d;
	string s;

	cout << "enter string: ";
	getline(cin, s);
	
	int stringLength = s.length();
	cout << "string length: " << stringLength << endl;
	for(int i = 0; i < stringLength; i++)
	{
		d = s[i];
		cout << d << endl;
		clist.insertEnd(i, d);
	}
	clist.traverse();
	clist.callFun2();
	return 0;
}

