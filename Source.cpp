#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Initialization
// All those methods are equivalent.
int x = 0;
int y(0);
int z{ 0 };

// Automatic type deduction
int foo = 0;
auto bar = foo;

// Automatic declaration type
int foo1 = 1;
decltype(foo1) bar1;

// Constant
const float MYPI = 3.14;

#define NEWLINE '\n'

// Example logical expression

// Notice that this would be an error because at namespace scope
// only declarations are valid
//if ((foo < 10) && (++bar < MYPIC)) {foo1 = 2}

void superCoolFunction() {
	cout << "--- Function superCoolFunction" << endl;

	if ((foo < 10) && (++bar < MYPI)) {
		foo1 = 2;
	}
	// Ternary
	if (7 == 5 ? 4 : 3) {
		cout << "Result was 3" << endl;
	}
}

void functionCoolio1() {
	cout << "--- Function functionCoolio1" << endl;

	int i;
	float f = 3.14;
	// Explicit casting
	// Two notations - first with type in parantheses, second
	// with expression to convert in parantheses
	// NOTICE!:
	// All results assigned to ints are ints with casting or without
	i = (int)f * 2 - 1.2; // 4 <- int
	cout << "Value of i = " << i << endl;
	i = int(f * 2) - 1.2; // 4 <- int
	cout << "Value of i = " << i << endl;
	i = f * 2 - 1.2; // 5 <- int
	cout << "Value of i = " << i << endl;
	f = f * 2 - 1.2; // 5.08 <- float
	cout << "Value of f = " << f << endl;
	// You see that only part of expression can be converted
	f = (int)3.14 * 2 - 1.2; // 4.8 <- float
	cout << "Value of f = " << f << endl;
}

void gimmeDatum() {
	string str = "22";
	int i;
	string answer;
	// Stringstream converts string "22" into and integer
	stringstream(str) >> i;
	cout << "How ya doing? ";
	cin >> answer;
	cout << "Doing 3 * 22 with stream: " << 3 * i << endl;
	cout << "Wasn't that impressive? " << endl;
	// Previous cin leaves trailing '\n' character which will be
	// consumed automatically by getline and no other input will be requested.
	// cin.ignore() discards it.
	cin.ignore();
	getline(cin, answer);
	cout << answer << " - you say?" << " Might have guessed..." << endl;
}

void loopieLazy() {
	int n = 10;
	while (n > 0) {
		cout << n << endl;
		n--;
	}

	int max;
	cout << "Will count to: ";
	cin >> max;

	do {
		cout << n << (n == max ? "\n" : " -^- ");
		n++;
	} while (n <= max);

	string myStr;

	for (myStr = "str" ; myStr.size() < max; myStr+="str")
	{
		cout << myStr << endl;
	}

	// Range-based for loop
	// For loop can iterate over elements in 'range'.
	// Range is structure that has begin and end function, and these are:
	// strings, arrays, containers and others

	// Remember that char is data type holding a single letter
	for (char c : myStr) cout << "[" << c << "]";
	cout << endl;
}

int a = 5;
int b = 2;
int aInc = a + 1;
int result = aInc - b;

int main()
{	
	superCoolFunction();
	functionCoolio1();
	//gimmeDatum();
	loopieLazy();

	int d, e;
	float mynumber;

	string mystring;
	mystring = "This is a string.";

	std::cout << "Hello World!" << " " << "And other Worlds too!" << endl;
	cout << "Result is:" << result << NEWLINE;
	cout << "My string is: " << mystring << endl;

	return 0;
}