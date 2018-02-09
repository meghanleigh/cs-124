#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string myName = "Joseph";
	
	//myName += " Walker";
	
	cout << "Enter your name: ";
	getline(cin, myName);
	
	cout << "Hello, " << myName << endl;
}