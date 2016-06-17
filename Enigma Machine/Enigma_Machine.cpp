// ----------------------------------------------------------------------------
//
// ----------------------------- Enigma Machine ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To Encode and Decode a message using algorithm used in Enigma Machine.
//
//  Author   : Chetan Kumar Parakh
//  Date     : 1/12/2016
//
// ----------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;


char encryption1(char g, int wheel1);
char decryption1(char g, int wheel1);
char encryption2(char g, int wheel2);
char decryption2(char g, int wheel2);
char encryption3(char g);
char decryption3(char g);


int main(void)
{
	int wheel1;
	int wheel2;
	cout << "Enter Wheel1: ";
	cin >> wheel1;
	cout << "Enter Wheel2: ";
	cin >> wheel2;
	char c;
	do
	{
		cout << "Enter a character to encrypt: ";
		cin >> c;

		if (c >= 'A' && c <= 'Z')
		{
			cout << c << " encrypts to " << encryption3(encryption2(encryption1(c, wheel1), wheel2)) << ". " << c << " decrypts to " << decryption1(decryption2(decryption3(c), wheel2), wheel1);
			wheel1 = (wheel1++) % 26;

		}
		else if (c == '$')
		{
			break;
		}
		else
		{
			cout << "#";
		}
		cout << endl;
	} while (c != '$');
	return 0;
}

char encryption1(char g, int wheel1)
{
	return(((7 * wheel1 + (25 - (g - 65))) % 26)+65);
}

char decryption1(char g, int wheel1)
{
	return((25 - ((g - 65) + 7 * (26 - wheel1)) % 26) + 65);
}

char encryption2(char g, int wheel2)
{
	return((((g - 65) + 23 * wheel2) % 26) + 65);
}

char decryption2(char g, int wheel2)
{
	return((((g - 65) + 23 * (26 - wheel2)) % 26) + 65);
}


char encryption3(char g)
{
	if ((g - 65) < 13)
	{
		return((2 * (g - 65) + 1) + 65);
	}
	else
	{
		return((2*((g - 65) - 13)) + 65);
	}
}

char decryption3(char g)
{
	if (((g - 65) % 2) == 1)
	{
		return((((g - 65) - 1) / 2) + 65);
	}
	else
	{
		return((((g - 65)/2) + 13) + 65);
	}
}