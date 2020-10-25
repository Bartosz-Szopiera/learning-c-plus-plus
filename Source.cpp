#include <iostream>
#include <string>
#include <sstream>
#include <array>

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
// - make bar1 inherit type of foo1
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

void switcheroo(int x) {
	switch (x)
	{
	case 1:
	case 2:
		cout << "One two!\n";
		break;
	case 3:
	case 4:
	case 5:
		cout << "Three four five!";
	default:
		cout << "Default!\n";
		break;
	}
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

	// Break
	// Will exit the loop early
	for (n = 10; n > 0; n--)
	{
		cout << n << ", ";
		if (n == 3)
		{
			cout << "countdown aborted!" << endl;
			break;
		}
	}

	// Continue
	// Will skip part of the routine
	for (int n = 10; n > 0; n--) {
		if (n == 5) continue;
		cout << n << ", ";
	}
	cout << "liftoff!\n";

	// goto
	// Kinds sketchy because visible control flow goes potentially
	// out of the window and code runs from all over the place,
	// but also kinda powerfull escape hatch if you have no other way.
	n = 10;
	mylabel:
		cout << n << ", ";
		switcheroo(n);
		n--;
		if (n > 0) goto mylabel;
		cout << "liftoff!\n";
}

// Pass arguments by reference
// In effect whatever is passed as 'a' this function mutates
//
// NOTE!: refrence is not a pointer - it is internally implemented
// with pointers but it really is an alias.
// That is why you don't have to dereference reference to get to the value -
// - it just isn't a pointer.
void referencorMutator(int& a, int b) {
	a = a * b;
}

// Pass big data structure by reference to avoiding potentially
// expensive copying.
// Also prevent mutating data with const.
void useBigFatData(const string& strData1) {
	// Doing stuff
}

void functionWithDefaultValues(int a = 12, int b = 44) {
	//
}

bool imUsedBasedOnDeclaration(int, int);

void iLikeDoingStuff() {
	int a = 1, b = 2;
	cout << "Is " << a << " > " << b << " ?\n";
	cout << (imUsedBasedOnDeclaration(1, 2) ? "yes" : "no") << endl;
}

// Function called before it's implementation based
// on earlier declaration.
bool imUsedBasedOnDeclaration(int x, int y) {
	return x > y;
}


// Function Overload
//
// two functions with the same name that handle
// similar but in the end different input.
// Example below is not a good use case because operations
// performed by both functions are very differnt, so it may
// confuse user that they call them for similar data
// but get very counter-intuitive behaviour.
int operate(int a, int b)
{
	return (a * b);
}

double operate(double a, double b)
{
	return (a / b);
}

// Function Template - function with generic type
//
// If contrary to previous overload example function does the same
// operation but for wider range of data types we can use templates.

//template <typename T> // this is the same as with class
template <class T>
T sumStuff(T a, T b) {
	return a + b;
}

// Multiple type arguments
template <class A, class B>
bool checker(A a, B b) {
	return a == b;
}

// Constant value as type argument
template <class A, int B>
A fixedMultiply(A a) {
	return a * B;
}

void operationCaller() {
	x = 1, y = 2;
	operate(x, y);
	sumStuff(x, y);

	double x = 1.11, y = 2.22;
	operate(x, y);
	sumStuff(x, y);

	// We could convert the type by explicitly defining type argument
	sumStuff<int>(12.12, 13.13);

	checker(11, 11.000);

	// Value passed to template and known at compile time
	fixedMultiply<int, 4>(11);
}

// Namespaces
//
// we can declare and use napespaces to avoid name collisions.
namespace fooSpace {
	int value() { return 5; }
}

namespace barSpace {
	const double pi = 3.1416;
	double value() { return 2 * pi; }
}

float referenceFromNamespace() {
	return fooSpace::value() + barSpace::value();
}

// using
//
// Here we explicitly use entire napespace
float explicitUseOfNamespace() {
	using namespace fooSpace;
	return value() + barSpace::value();
}

// Here we take specific identifier from one namespace
// to not have to refer it by namespace again in that scope
float explicitUseOfPartOfNamespace() {
	using fooSpace::value;
	return value() + barSpace::value();
}

void adventuresWithArrays() {
	// Array with defined values and automatically sized
	int foo[] = { 16, 2, 77, 40, 12071 };

	// Array with defined size
	int bar[5];

	// Multi-dimensional array
	int baz[3][5];

	// Function that requires array argument
	// omitting size here is required syntax
	void procedure(int arg[]);

	// Argument has multidimensional array
	void procedure2(int myarray[][3][4]);

	// Standard library arrays are very rough data structure.
	// To provide some convenience there is a container class array
	// that comes with additional helper functions.
	// Very important difference between container array and basic array
	// is that container is by default copier instead of passed as a pointer.
	array<int, 3> myarr{ 10,20,30 };

	for (int i = 0; i < myarr.size(); ++i)
		++myarr[i];

	for (int elem : myarr)
		cout << elem << '\n';
}

void pointerest() {
	// Address of - &
	// Reference identifier address with &
	array<int, 3> myArr;
	auto arrAddr = &myArr;

	// Notice that type of reference is identifier type
	// appended with *
	int myInt = 123;
	int* intAddr = &myInt;
	cout << "Value of variable we point to: " << myInt << endl;

	// NOTE!: do not confuse above with the line below.
	// Below we create a reference to myInt.
	// Reference doesn't have to be dereferenced to give a value.
	//
	// ALSO!: Notice how the fact of creating reference is conveyed
	// by the symbol accompanying the type (int&), not the identifier (myInt). 
	int& intRef = myInt;
	cout << "This is reference, thus it gives a value: " << intRef << endl; // 123

	// Assigning pointer yields a pointer
	int* addressCopy = intAddr;
	intAddr += 2; // <- Now be "broke" the pointer
	cout << "Value of pointer to that variable: " << intAddr << endl;
	cout << "Value of mutated pointer: " << intAddr << endl;

	// Dereference - *
	// Pointer preceded with * allows you to operate on value itself
	auto valueCopy = *intAddr; // <- Value from broken pointer is impossible to guess and reading it may crash app.
	cout << "Value of 'value' from dereferenced mutated pointer: " << valueCopy << endl;
	auto valueCopy2 = *addressCopy; // Notice that copy of mutated pointer still yields proper 123 value
	cout << "Value of 'value' from dereferenced copy of original pointer before mutation: " << valueCopy2 << endl;

	// Pointer declaration
	// Pointer needs to know to what type it points to
	array<array<array<float, 3>, 3>, 3>* pointToArr;
	
	// Prevent dereferenced value mutation with const pointer
	//
	const string* pointToStr;
	string myStr = "qweqwe";
	pointToStr = &myStr;
	//*pointToStr = "asd"; // <- error
	auto newStr = *pointToStr;

	// In C++ if you are crazy you can also point to pointers:
	char a;
	char* b;
	char** c;
	a = 'z'; // a -> 'z'
	b = &a; // b -> a -> 'z'
	c = &b; // c -> b -> a -> z
	bool test = (**c == 'z'); // true


	// void pointer
	//
	// Just so you know. This guy is useless until you collapse it to
	// pointer to specific data type like below.
	// It's advantage that is here presented is that it can be
	// used to capture pointer to data of any type - but you need to be able
	// to decide the type later.
	auto increase = [](void* data, int psize) {
		if (psize == sizeof(char)) {
			char* pchar; pchar = (char*)data; ++(*pchar);
		}
		else if (psize == sizeof(int)) {
			int* pint; pint = (int*)data; ++(*pint);
		}
	};

	auto funPointer = &increase;

	auto printSum = [](int x, int y) {
		cout << (x + y) << endl;
	};

	auto printPoint = &printSum;
}

// Pass function pointer as parameter
//
void iTakeFunPointer(void (*f)(int, int)) {
	int x = 123;
	int y = 111;
	f(x, y);
}

// Lambdas are awesome
//
// lambda by default has no access to enclosing scope.
void lambdaFun() {
	int x = 11, y = 22;
	auto helper1 = [](int a, int b) { return a + b; };

	int result = helper1(x, y); // 33

	// Capturing by pointer allows mutation
	// of variables from enclosing scope.
	//
	// This is equivalent of what I would expect to happen in JS
	auto printResult = [&](int incVal = 1) {
		cout << "Result before print: " << result << endl;
		cout << "Inrementing in print by: " << incVal << endl;
		result+=incVal;
		cout << "Result in print is: " << result << endl;
	};

	printResult(); // 33, 1, 34
	printResult(10); // 34, 10, 44

	// Here is something I would not expect in JS
	//
	// We capture all enclosing scope with "=" by value
	// and we do mutating operations inside on it
	// to our hearts content to produce some derivative.
	//
	// But we do all this without mutating enclosing scope in the result!
	// (Despit using the word 'mutable' which may be confusing).
	auto produceValue = [=]() mutable {
		result *= 5;
		return result;
	};

	auto derivedResult = produceValue();

	// You can also capture part of enclosing scope as pointers
	// (to make it mutable),
	// and capture part as value to prevent either local (in-lambda)
	// or global(ish) in-eclosing-scope mutations.
	auto equalizeResult = [&, derivedResult]() {
		while (result < derivedResult) {
			result++;
			//derivedResult--; // <- would be error
		};
	};
}

void memoryAllocation() {
	int* intMem;
	float* floatMem;
	string* stringMem;
	//try {
	//	// We allocate memory for given data type and given number of those types
	//	// with new[number].
	//	intMem = new int[10];
	//	floatMem = new float[10];
	//	stringMem = new string;
	//} catch (const exception&) {
	//	cout << "Error trying to allocate the memory: " << endl;
	//	return;
	//}
	intMem = new int[10];
	floatMem = new float[10];
	stringMem = new string;

	// Since pointer indicates start of memory block allocated we
	// can use it as a cursor to access our data types.
	//
	// Block of memory can be accessed like an array:
	intMem[0] = 111;
	int firstInt = intMem[0];
	cout << "Intiger in memory block 0: " << firstInt << endl;
	int secondInt = intMem[1];
	// It can also be accesed by incerementing the pointer
	// - remember that pointer increments by number of bytes
	// occupied by single instance of data type they point to,
	// so single increment neatly shifts the cursor to the beginning
	// of next data type instance:
	int thirdInt = *(intMem + 2);
	int fourthInt = *(intMem + 3);

	// We release the memory.
	delete[10] intMem;
	// Since we used vector in allocation "[]" we also
	// use it to delete
	delete[] floatMem;
	delete stringMem;
}

// Basic structure
//
// This will be a bread and butter of my Static Data
struct quest_t {
	string id;
	string name;
};

quest_t quest;
quest_t* quest_p = &quest;
// Here you see that structure pointer has special
// way of being dereferenced for member access
string questName = quest_p->name;
// But it can also be done with a syntax valid for "normal" pointers:
quest_t questInst = *quest_p; // valid
string qName = questInst.name; // valid
string qName2 = (*quest_p).name; // valid

// Below in fact we see dereference of member "name" as if it would be a pointer
//string questName = *quest_p.name; //invalid

// You could also access pointer to the member:
string* qName_p = &(quest_p->name);

// Union
//
// Union is to make the same space in memory to be acessed by different
// data types. Space allocated will equal size of the largest type.
//
// The use case is for when you want a single variable 
union mytype_t {
	char c;
	int i;
	float f;
};

void unite() {
	mytype_t myVar;
	myVar.i = 123;
	myVar.f = 11.22;
	cout << myVar.c << endl; // "undefined"
	cout << myVar.i << endl; // "undefined"
	cout << myVar.f << endl; // 11.22
}

void enumerate() {
	// Enum is awesome
	//
	// As you see this enum goes with "class" word.
	// Don't ask why but prefer it.
	// Also when used you see that it's referenced with funny: enum_name::value.
	// Stick to that.
	// Don't bother with converting enums to values although it's possible.
	enum class color_t { black, blue, green, cyan, red, purple, yellow, white };

	color_t mycolor = color_t::blue;

	switch (mycolor) {
	case color_t::red:
		cout << "color_t::red" << endl;
		break;
	case color_t::blue:
		cout << "color_t::blue" << endl;
		break;
	case color_t::green:
		cout << "color_t::green" << endl;
		break;
	};
}

enum class Day { mon, tue, wed, thu, fri, sat, sun };

// Here is an example of overloading operator
//Day& operator++(Day& d) { // This is original implementation
Day operator++(Day d) { // Funny enough, without this weird pointer mention it also works.
	return d = (d == Day::sun) ? Day::mon : static_cast<Day>(static_cast<int>(d) + 1);
};

void enumerateWithNiceOverload() {
	auto printTheDay = [](Day d) {
		cout << "The day is: ";
		switch (d)
		{
		case Day::mon:
			cout << "It's Monday." << endl;
			break;
		case Day::tue:
			cout << "It's Tuesday." << endl;
			break;
		default:
			cout << "It's neither Monday nor Tuesday." << endl;
			break;
		}
	};

	Day today = Day::mon;
	printTheDay(today);
	cout << "Calling overloaded ++ on the Day type..." << endl;
	Day tomorrow = ++today;
	printTheDay(tomorrow);

	// To check if operator did not mutate
	cout << "But today still is: " << endl;
	printTheDay(today); // It's Monday
}

class CVector {
public:
	int x, y;
	// This colon (:) initialization notation is equivalent with two
	// other notations below.
	//
	// BTW! - class constructor, class access modifier (e.g. public:),
	// switch-case (case:), ternary (? :), labels (myLabel:)
	// are only places in C++ where single colon (:) is used.
	//
	// Other relevant colon meaning is double colon (::) for namespace
	// management e.g.:
	// to reference our operator - CVector::operator+
	// or we could reference length method - CVector::length
	//
	// NOTE!
	// When you use - ::someIdentifier
	// you assure that someIdentifier comes from the global namespace
	// in case you would have identical identifier in namespace proper for
	// your current scope.
	CVector(int a = 1, int b = 1) : x(a), y(b) {}
	//CVector(int a = 1, int b = 1) : x(a) { y = b; }
	//CVector(int a = 1, int b = 1) { x = a;  y = b; }

	// Here we declare our class-specific operator overload
	CVector operator + (const CVector&);
	CVector& operator = (const CVector&);
	float length() {
		//return ((this->x ^ 2 + this->y ^ 2) ^ (1/2));
		return ((x ^ 2 + y ^ 2) ^ (1 / 2));
	}
};

// Notice that this overloaded operator has as it's argument
// only right-hand-side 
CVector CVector::operator+ (const CVector& param) {
	// CVector temp serves only as a container for our return value
	CVector temp;
	temp.x = this->x + param.x;
	temp.y = this->y + param.y;
	return temp;
}

CVector& CVector::operator= (const CVector& param)
{
	x = param.x;
	y = param.y;
	// Notice that we are dereferencing pointer "this" getting and object.
	// But we want to return reference, and, again, this fact is assured
	// by us defining the return type as CVector& - merely this type definition
	// will make the function return the reference instead of the object.
	return *this;
}

// Effectively the same operator overload but as a non-member
// function and thus taking 2 arguments (this is how it works,
// op. overloads require less arguments if they are member functions).
CVector operator+ (const CVector& lhs, const CVector& rhs) {
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
	return temp;
}

void simpleOverload() {
	CVector v1(1, 1);
	CVector v2(3, 4);
	auto vSum = v1 + v2;
	cout << "Sum of vectors: [" << vSum.x << "," << vSum.y << "]" << endl;

	CVector v3;
	v3 = v1;
}

class Dummy {
public:
	// static class member is the same for all class instances and
	// is available on the class itself (Class::staticMember).
	static int n;
	Dummy() { n++; };
};

// static member has to be initialized in scope outside the class.
int Dummy::n = 0;

void useDummies() {
	// static function variable is different than static class member.
	// static here refers to the lifetime of memory allocated for it and means
	// that throughout the program life-span it will never be de-allocated,
	// and so variable value will be carried through separate runs of the function.
	static int i = 123;
	Dummy a;
	Dummy b[5];
	cout << a.n << '\n';
	Dummy* c = new Dummy;
	// You see that static is accessible on class itself
	cout << Dummy::n << '\n';
	delete c;
	cout << a.n << '\n';
}


// Class template
template <class T>
class mypair {
	T a, b;
public:
	mypair(T first, T second)
	{
		a = first; b = second;
	}
	// Needs implementing
	T getmax();
};

// Implementing method of templated class
template <class T>
T mypair<T>::getmax()
{
	T retval;
	retval = a > b ? a : b;
	return retval;
}

// class template:
template <class T>
class mycontainer {
	T element;
public:
	mycontainer(T arg) { element = arg; }
	T increase() { return ++element; }
};

// class specialization:
template <> // <- we indicate that this is specialization
class mycontainer <char> { // <- we specialize for T=char
	char element;
public:
	mycontainer(char arg) { element = arg; }
	// Notice that there is no inrease() and instead we have uppercase() method.
	char uppercase()
	{
		if ((element >= 'a') && (element <= 'z'))
			element += 'A' - 'a';
		return element;
	}
};

void useSpecializedClass() {
	mycontainer<int> myint(7);
	mycontainer<char> mychar('j');
	cout << myint.increase() << endl;
	cout << mychar.uppercase() << endl;
}

// Class with special members: destructor and copy constructor
class Example5 {
	string* ptr;
public:
	// constructor which performs dynamic memory allocation
	Example5(const string& str = "abc") : ptr(new string(str)) {}
	// destructor
	~Example5() { delete ptr; }
	// copy constructor:
	Example5(const Example5& x) : ptr(new string(x.content())) {}
	// copy assignment
	Example5& operator= (const Example5& x) {
		delete ptr;                      // delete currently pointed string
		ptr = new string(x.content());  // allocate space for new string, and copy
		return *this;
	}
	// access content:
	const string& content() const { return *ptr; }
};

void useClassWithSpecialMembers() {
	Example5 foo;
	Example5 bar(foo);       // object initialization: copy constructor called
	Example5 baz = foo;       // object initialization: copy constructor called
	foo = bar;               // object already initialized: copy assignment called 

	// Destructors will be called at the end of objects
	// lifetime, here it's at the end of this function.
}

/*
* There was also about move contructors and assignment but I skip that.
* TBH both copy and move operations are something that I feel I don't
* want to touch and should design things so that those are not needed.
*/


// Inheritance
//
class Polygon {
protected:
	int width, height;
public:
	Polygon(int a, int b) : width(a), height(b) {}
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
};

class Rectangle : public Polygon {
public:
	// We need to include constructor - and there is no "super" in C++
	Rectangle(int a, int b) : Polygon(a, b) {}
	int area()
	{
		return width * height;
	}
};

class Output {
public:
	static void print(int i);
};

void Output::print(int i) {
	cout << i << '\n';
}

// Multiple inheritance
//
class Triangle : public Polygon, public Output {
public:
	Triangle(int a, int b) : Polygon(a, b) {}
	int area()
	{
		return width * height / 2;
	}
};

void funWithFigures() {
	Rectangle rect(4, 5);
	Triangle trgl(4, 5);
	trgl.print(trgl.area());
	//Triangle::print(trgl.area()); // <- equivalent of above
}

void polymorphised() {
	Rectangle rect(2,5);
	Triangle trgl(3,5);
	// Pointers of type Polygon to objects of type Rectangle and Triangle
	//
	// NOTE!: This way we can carry out operation on derived classes (Ractangle and Triangle)
	// but with their range restriction to one of their base classes (Polygon).
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trgl;
	// Despite pointer being of base type it allows to execute methods
	// on both object instances
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	// area is onl defined on descendant classes
	cout << rect.area() << '\n';
	cout << trgl.area() << '\n';
}

class Polygon2 {
protected:
	int width, height;
public:
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
	// Base class does have notion of area
	//
	// Denoting it as virtual allows us to redefine it in derived classes.
	virtual int area()
	{
		return 0;
	}
};

class Rectangle2 : public Polygon2 {
public:
	int area()
	{
		return width * height;
	}
};

class Triangle2 : public Polygon2 {
public:
	int area()
	{
		return (width * height / 2);
	}
};

void virutalized() {
	// Notice that with no constructors we don't have to neither call
	// nor pass arguments
	Rectangle2 rect;
	Triangle2 trgl;
	Polygon2 poly;
	// Again pointers of base type to child classes
	Polygon2* ppoly1 = &rect;
	Polygon2* ppoly2 = &trgl;
	Polygon2* ppoly3 = &poly;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);
	// However! Pointers being of base class
	// allow us to call area() since base class has notion of this method
	// - it being denoted "virtual" will call implementations of this method
	// from objects pointer to by respective pointers.
	cout << ppoly1->area() << '\n';
	cout << ppoly2->area() << '\n';
	cout << ppoly3->area() << '\n';
}


// Abstract class
//
// It cannot be used without extending it
// and providing implementation for virtual members.
class Polygon3 {
protected:
	int width, height;
public:
	Polygon3(int a, int b) : width(a), height(b) {}
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
	// pure virtual function
	//
	// Since it has no implementation whatsoever
	// it renders entire class an abstract class.
	virtual int area() = 0;
	void printarea()
	{
		cout << this->area() << '\n';
	}
};

class Rectangle3 : public Polygon3 {
public:
	Rectangle3(int a, int b) : Polygon3(a, b) {}
	int area(void)
	{
		return (width * height);
	}
};

class Triangle3 : public Polygon3 {
public:
	Triangle3(int a, int b) : Polygon3(a, b) {}
	int area(void)
	{
		return (width * height / 2);
	}
};

void abstract() {
	/*
	Rectangle3 rect(4,5);
	Triangle3 trgl(4,5);
	Polygon3* ppoly1 = &rect;
	Polygon3* ppoly2 = &trgl;
	*/
	// Above is the save that this below with the "new".
	// 
	// NOTE!: You may wonder, how is that that we get a pointer
	// to the new object? Does the contructor return a pointer?
	// Do I need to return pointer from custom constructor?
	// The answer is: the "new" keyword makes the compiler to:
	// 1) allocate required memory and call the constructor to create a new object there,
	// 2) to return the pointer to that memory block.
	Polygon3* ppoly1 = new Rectangle3(4, 5);
	Polygon3* ppoly2 = new Triangle3(4, 5);
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	cout << ppoly1->area() << '\n';
	cout << ppoly2->area() << '\n';
	ppoly1->printarea();
	ppoly2->printarea();
}


int a = 5;
int b = 2;
int aInc = a + 1;
int result = aInc - b;

int main()
{	
	//superCoolFunction();
	//functionCoolio1();
	//gimmeDatum();
	//loopieLazy();
	//iLikeDoingStuff();
	//operationCaller();
	//pointerest();
	//lambdaFun();
	//memoryAllocation();
	//unite();
	//enumerate();
	//enumerateWithNiceOverload();
	simpleOverload();

	int d = 10, e = 5;
	cout << "d before: " << d << endl;
	referencorMutator(d, e);
	cout << "d after: " << d << endl;

	float mynumber;

	string mystring;
	mystring = "This is a string.";

	std::cout << "Hello World!" << " " << "And other Worlds too!" << endl;
	cout << "Result is:" << result << NEWLINE;
	cout << "My string is: " << mystring << endl;

	return 0;
}