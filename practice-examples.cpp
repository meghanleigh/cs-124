#include <iostream>
using namespace std;

int main() {
	char one[] = "CS 124";
	char two[] = "CS";
	char *p;
	
	if (one == two)
		p = two;
	else {
		p = one;
		
	cout << p << endl;
	
	p = one;
	cout << p << endl;
	}
}
