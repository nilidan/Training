#pragma once
//disable var may be unsafe for strcpy strncpy strncat
#pragma warning(disable : 4996)
#include<iostream>
#include<cstring>
using namespace std;

//InbuiltFunctions
//strlen() - get length of the char arra
//strcmp() - check if string are equal
//strcpy(s1, s2) - copy strings note strcpy copys null char also
//strncpy(s1, s2, n) - copy first n chars not if n is greater than str2 null char are added
//strcat(s1,s2) - s2 will be added to str1;


void charStrInBuilt() {
	char str1[100] = "abcd";
	cout << "Enter str1\n";
	cin >> str1;
	int len = strlen(str1);

	char str2[100] = "efg";;
	cout << "Enter str2\n";
	cin >> str2;

	if (strcmp(str1, str2) == 0) {
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

	cout << "\nBefore Copy str2 to str1\n";
	cout << "str1 : " << str1 <<endl;

	strcpy(str1, str2);

	cout << "\nAfter Copy str2 to str1\n";
	cout << "str1: " << str1 << endl;
	
	cout << "\n Copy first 3 letters of hello to str1\n";
	strncpy(str1, "hello", 3);
	
	cout << str1 <<endl;

	cout << "\n Catenate word cat to str1\n";
	strncat(str1, "cat", 3);

	cout << str1 << endl;

}

//Print char array suffixes of input string
//Ex: Input "abcd"
//    Output d
//           cd
//           bcd
//           abcd

void printAllsuffixes(char str[]) {

	for (int i = strlen(str)-1; i >=0; i--) {
		for (int j = i; j <= strlen(str) - 1; j++) {

			cout << str[j];
		}
		
		cout << endl;

	}
}