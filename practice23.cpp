#include <iostream>
#include <math.h>

using namespace std;

int getPowers();
void displayPowers(int powers);

int main()
{
	int powers = getPowers();
	displayPowers(powers);
}

int getPowers()
{
	int powers;
	cout << "How many powers of two: ";
	cin >> powers;
	return powers;
}

void displayPowers(int powers)
{
	int product;
	for (int i = 0; i < powers; i++)
	{
		product =  pow(2, i);
		cout << "\t2^" << i << "\t" << product << endl;
	}
}