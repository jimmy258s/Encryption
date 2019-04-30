//Vigenere Cipher(decryption)
//Have to create file(.txt) that you want to decrypt first
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int SIZE = 100;

int strLen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char determine(char x)
{
	if(x < 10)
		x += '0';
	else if(x > 9 && x < 36)
		x += '7';
	else
		x += '=';
	return x;
}

int main()
{
	ofstream outFile;
	ifstream inFile;
	char key[SIZE], filename[SIZE];
	char ch;
	int L, i = 0;

	cout << "Enter name of input file: ";  
	cin.getline(filename, SIZE);
	inFile.open(filename);    //Read the input file
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << ".\n";
		cout << "Programing terminating.\n";
		exit(EXIT_FAILURE);
	}
	outFile.open("decryptionResult.txt");    //Read the output file

	cout << "Please enter the key: ";
	cin.getline(key, SIZE);
	L = strLen(key);

	inFile >> ch;
	while (inFile.good())    //Access to read data
	{
		if (isdigit(ch))
		{
			ch = determine((ch - key[i % L] - '=' - '0' + 183) % 61);
		        outFile << char(ch);
			i++;
		}
		else if (isupper(ch))
		{
			ch = determine((ch - key[i % L] - '=' - '7' + 183) % 61);
                        outFile << char(ch);
			i++;
		}
		else if (islower(ch))
		{
			ch = determine((ch + key[i % L] - '=' - '=' + 183) % 61);
			outFile << char(ch);
			i++;
		}
		else
		{
			outFile << char(ch);
		}
		inFile >> ch;
	}    //Output will write in decryptResult.txt 
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";

	if (i == 0)
		cout << "No data processed.\n";
	else
		cout << "Above is the result of decryption.\n";

	inFile.close();
	outFile.close();
	//system("pause");
	return 0;
}
