//Vigenere Cipher(encryption)
#include <iostream>
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
	char key[SIZE];
	char ch;
	int L, i = 0, j = 0;

	cout << "Please enter the key(LOWERCASE ENGLISH LETTERS ONLY): ";
	cin.getline(key, SIZE);
	L = strLen(key);

	cout << "Please enter the input(ENGLISH LETTERS OR NUMBERS): ";
	cin.get(ch);
	while (ch != '\n')    //Access to read data
	{
		if (isdigit(ch))
		{
			ch = determine((ch + key[i % L] - '=' - '0') % 61);
		        cout << char(ch);
			i++;
		}
		else if (isupper(ch))
		{
			ch = determine((ch + key[i % L] - '=' - '7') % 61);
                        cout << char(ch);
			i++;
		}
		else if (islower(ch))
		{
			ch = determine((ch + key[i % L] - '=' - '=') % 61);
			cout << char(ch);
			i++;
		}
		else
		{
			j++;
		}
		cin.get(ch);
	}
	
	if (i == 0)
		cout << "\nNo data processed.\n";
	else
		cout << "\nAbove is the result of encryption, " << i << " valid characters and " << j << " invalid characters input.\n";

	return 0;
}
