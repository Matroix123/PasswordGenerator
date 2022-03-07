#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

	int length = 0, count = 0;
	string name, password = "";
	fstream passwords("passwords.txt", fstream::in | fstream::out | fstream::app);

	time_t nTime;
	string abcLower = "abcdefghijklmnopqrstuvwxyz";
	string abcUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numbers = "1234567890";
	string signs = "!@#$%^&*()";

	cout << "Vnesi ime na passwordot" << endl;
	getline(cin, name);
	cout << "Vnesi dolzina na passwordot \n";
	cin >> length;

	srand((unsigned)time(&nTime));

	if (passwords.is_open())
	{
		while (count < length)
		{
			int k, i;

			if (count == 0)
				k = 1;
			else
				k = rand() % 4;

			switch (k)
			{
			case 0:
				i = rand() % 26;
				password += abcLower[i];
				count++;
				break;
			case 1:
				i = rand() % 26;
				password += abcUpper[i];
				count++;
				break;
			case 2:
				i = rand() % 9;
				password += numbers[i];
				count++;
				break;
			case 3:
				i = rand() % 9;
				password += signs[i];
				count++;
				break;

			default:
				break;
			}
		}
	}

	cout << name << ": " << password << '\n';
	passwords << name << ": " << password << endl;

	passwords.close();

	system("pause");
}