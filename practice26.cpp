#include <iostream>
#include <fstream>

using namespace std;

void doSomething(int x)
{
  cout << x << endl;
  x = 7;
}

void getFilename(char filename[])
{
  cout << "Enter the filename: ";
  cin >> filename;
}

float readFile(char filename[])
{
  ifstream fin(filename);

  if(fin.fail())
    {
      return -1;
    }
  int temperature;

  float sum = 0;
  int count = 0;

  while(fin >> temperature)
    {
      sum += temperature;
      count++;
    }
  return sum / count;
}

int main()
{
  int x = 5;
  doSomething(x);
  cout << x << endl;

  char filename[256];
  getFilename(filename);

  cout << filename << endl;

  float average = readFile(filename);

  cout << "Average was: " << average << endl;
}
