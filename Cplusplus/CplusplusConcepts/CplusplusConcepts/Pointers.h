#pragma once
#include <iostream>

//& gives us memory address 
//pointer variable(*var)are  variables  that can store address of other variables
//it does not know how many bytes and how to interpret these bytes, dont know if float or double etc
//to delcare point int *p = &i; reading from right to left tells it to read 4 bytes and interpret as int
/*
char  : 1 byte
short : 2 bytes
int   : 4 bytes
long  : 4 bytes
float : 4 bytes
double: 8 bytes

 size of pointers are fixed and in bytes
*/


using namespace std;
void pointersConcepts() {

	int i = 10;
	cout << &i << endl; //output is mem addr for i;
	int *p = &i;
	cout << p << endl;  // out is same mem addr for i;

	cout << sizeof(p) << endl;
	char c;
	char * p2 = &c;
	cout << sizeof(p2) << endl;

	cout << i << endl;
	cout << *p << endl; //dereference the addresse store location in p;

	// 2 ways to access the memory location for this through i and
	// through dereference (*p)
	i = 23;
	cout << i << endl;
	*p = 32;
	cout << i << endl;

	//

	int a = 50;
	int *ptr = &a;
	int *q = ptr; // copy the address in ptr to q
	(*q)++; //increment the  derefernce value which is a =50;

	cout << a << endl; //output 51
	cout << &ptr << endl; //out is ptr mem addr if ptr it has a mem addr of a stored
	cout << &q << endl; //out is q mem addr if q it has mem addr of a stored

	a = 50;
	ptr = &a;
	cout << (*ptr)++<<endl; //output is 50 because of post increment
	cout << a; // output is 51;
	
	// always initialize pointers to null, never derefernece any garbase addr
	// below leads to sematiion fault
	//  *p = &i
	//  *p =Null 
	// *p=50 crash

}