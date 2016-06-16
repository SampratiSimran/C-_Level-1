// ----------------------------------------------------------------------------
//
// ----------------------------- Time in Other Cities ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To print time in other cities in military format
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
	int philadelphia;
	cout << "What is the time in Philadelhia? ";
	cin >> philadelphia;
	int honolulu, seattle, london, moscow, hong_kong, auckland;

	//Calculating time in other cities
	honolulu = philadelphia + 1800;
	honolulu = honolulu % 2400;

	seattle = philadelphia + 2100;
	seattle = seattle % 2400;

	london = philadelphia + 500;
	london = london % 2400;

	moscow = philadelphia + 800;
	moscow = moscow % 2400;

	hong_kong = philadelphia + 1200;
	hong_kong = hong_kong % 2400;

	auckland = philadelphia + 1700;
	auckland = auckland % 2400;
	
	//Printing time in other cties 
	cout << "Honolulu  " << setfill('0') << setw(4) << honolulu << endl;
	cout << "Seattle   " << setfill('0') << setw(4) << seattle << endl;
	cout << "London    " << setfill('0') << setw(4) << london << endl;
	cout << "Moscow    " << setfill('0') << setw(4) << moscow << endl;
	cout << "Hong Kong " << setfill('0') << setw(4) << hong_kong << endl;
	cout << "Auckland  " << setfill('0') << setw(4) << auckland << endl << endl;
	
	return 0;
}