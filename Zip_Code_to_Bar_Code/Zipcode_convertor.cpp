// ----------------------------------------------------------------------------
//
// ----------------------------- Zipcodeconvertor----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To convert the zipcode into a barcode format.
//
//  Author   : Chetan Kumar Parakh
//  Date     : 2/04/2016
//
// ----------------------------------------------------------------------------


#include <iostream>
#include<string>
using namespace std;

// USER DEFINED FUNCTIONS DECLARED HERE AND THE STATEMENTS FOR THESE USER DEFINED FUNCTION ARE WRITTEN AFTER THE MAIN FUNCTION
int makeCheckDigit(int zipcode);
string barcode(int zipcode);
string convertDigit(int value);

// DECLARING AND INITILIZING GLOBAL VARIABLES TO BE USED IN THIS PROGRAM.
const string HALF = ":";
const string FULL = "|";

// MAIN FUCNCTION BEGINS HERE
int main(void)
{
	int zipcode;
	string bar_code_print;
	cout << "Please enter your zipcode: ";
	cin >> zipcode;
	if (zipcode>=0)
	{
		bar_code_print = barcode(zipcode);
		cout << bar_code_print << endl << endl;
	}
	else
	{
		cout << "Error: Invalid Zipcode";
	}
}

// PROGRAM 2 : USER DEFINED FUNCTION TO FIND THE CHECK DIGIT
int makeCheckDigit(int zipcode)
{
	int check_digit = 0;

	for (int i = 0; i < 5; i++)
	{
		check_digit += zipcode % 10;
		zipcode = zipcode / 10;
	}

	if (check_digit % 10 != 0)
	{
		int multiple_ten;
		multiple_ten = check_digit / 10;
		multiple_ten += 1;
		check_digit = (10 * multiple_ten) - check_digit;
	}
	else
	{
		check_digit = 0;
	}

	return(check_digit);
}

// PROGRAM 3 : USER DEFINED FUNCTION TO GENERATE BARCODE FOR EACH DIGIT
string convertDigit(int value)
{
	string bar_code;

	switch (value)
	{
	case 1: bar_code = HALF + HALF + HALF + FULL + FULL;
		break;
	case 2: bar_code = HALF + HALF + FULL + HALF + FULL;
		break;
	case 3:bar_code = HALF + HALF + FULL + FULL + HALF;
		break;
	case 4:bar_code = HALF + FULL + HALF + HALF + FULL;
		break;
	case 5:bar_code = HALF + FULL + HALF + FULL + HALF;
		break;
	case 6:bar_code = HALF + FULL + FULL + HALF + HALF;
		break;
	case 7:bar_code = FULL + HALF + HALF + HALF + FULL;
		break;
	case 8:bar_code = FULL + HALF + HALF + FULL + HALF;
		break;
	case 9:bar_code = FULL + HALF + FULL + HALF + HALF;
		break;
	case 0:bar_code = FULL + FULL + HALF + HALF + HALF;
		break;
	default:
		break;
	}

	return (bar_code);
}

// PROGRAM 4: USER DEFINED FUNCTION TO GENERATE A GABCODE FOR THE ZIPCODE. THIS FUNCTION CALLES THE "convertDigit(int value)" and "makeCheckDigit(int zipcode)" FUNCTION
string barcode(int zipcode)
{
	string bar_code2 = FULL;	//Initilizing a fullbar at beignning of the barcode as required by the question.
	string to_add;				//This variable stores barcode that is passed by the convertDigit(int value) function.
	int last_digit;				//This variable stores digit that needs to be passed to convertDigit(int value) function to convert digit to barcode.
	int checkdigit = makeCheckDigit(zipcode);

	for (int i = 10000; i>0; i = i / (10))
	{
		last_digit = zipcode / i;
		last_digit = last_digit % 10;
		to_add = convertDigit(last_digit);
		bar_code2 = bar_code2 + to_add;
		zipcode = zipcode % i;
	}

	to_add = convertDigit(checkdigit);
	bar_code2 = bar_code2 + to_add;
	bar_code2 += FULL;				////Initilizing a fullbar at end of the barcode as required by the question.
	
	return(bar_code2);
}