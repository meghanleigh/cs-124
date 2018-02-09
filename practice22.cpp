#include <iostream>

using namespace std;

char getInput();
void compareValues(char input);


int main()
{
	char input = getInput();
	compareValues(input);
	
}

char getInput() {
	char input;
	cout << "Which value would you like to guess: ";
	cin >> input;
	return input;
}


void compareValues(char input) {
	int count = 0;
	int value;
	
	do {
		
		cout << "What is the value of '" << input << "'? ";
		cin >> value;
		count++;
		
		if (input < value) {
			cout << "Too high" << endl;
		}
		else if (input > value) {
			cout << "Too low" << endl;
		}
		else {
			cout << "You got it in " << count << " guesses." << endl;
		}
		
		
	} while (input != value);
}