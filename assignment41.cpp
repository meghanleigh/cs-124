#include <iostream>

using namespace std;

int getLength();

int main()
{
	int length = getLength();
	
	
	char* text = new(nothrow) char[length];
	
	if (text == NULL)
	{
		cout << "Allocation failure!" << endl;
	}
	else 
	{
		cout << "Enter Text: ";
		cin.ignore();
		cin.getline(text, length + 1);
		
		cout << "Text: " << text << endl;
		delete [] text;
	}
	
}

int getLength()
{ 
	int length;
	cout << "Number of characters: ";
	cin >> length;
	return length;
}