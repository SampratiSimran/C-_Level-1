// ----------------------------------------------------------------------------
//
// ----------------------------- Fluid Units Conversion ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To convert Fluid Ounces to other units
//
//  Author   : Chetan Kumar Parakh
//  Date     : 1/12/2016
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

int main()
{
	int fluid_ounces;
	int barrel, gallon, quart, cup, gill, tablespoons;
	int pint;

	//Asking for fluid ounces
	cout << "How many fluid ounces do you have? ";
	cin >> fluid_ounces;

	//Allocating and displaying the fluid ounces in various units

	cout << fluid_ounces << " fluid ounces can be divided into:" << endl;

	barrel = fluid_ounces / 5376;
	fluid_ounces = fluid_ounces % 5376;

	gallon = fluid_ounces / 128;
	fluid_ounces = fluid_ounces % 128;

	quart = fluid_ounces / 32;
	fluid_ounces = fluid_ounces % 32;

	pint = fluid_ounces / 16;
	fluid_ounces = fluid_ounces % 16;

	cup = fluid_ounces / 8;
	fluid_ounces = fluid_ounces % 8;

	gill = fluid_ounces / 4;
	fluid_ounces = fluid_ounces % 4;

	tablespoons = fluid_ounces * 2;

	cout << barrel << " barrel (s)" << endl;
	cout << gallon << " gallon (s)" << endl;
	cout << quart << " quart (s)" << endl;
	cout << pint << " pint (s)" << endl;
	cout << cup << " cup (s)" << endl;
	cout << gill << " gill (s)" << endl;
	cout << tablespoons << " tablespoons (s)" << endl << endl;

	return 0;
}