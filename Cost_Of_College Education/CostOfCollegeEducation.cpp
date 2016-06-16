// ----------------------------------------------------------------------------
//
// ----------------------------- Cost of College Education ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To projects the cost of a college education for high school students who are looking for a college.
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

int main(void)
{
	// To get the initial tution amount from the user
	long int  tuition;
	cout << "Enter the initial tuition amount in dollars : ";
	cin >> tuition;

	//changing tuition from dollars to cents
	tuition = tuition * 100;

	//To get the percentage increase for tuition cost
	double rate;
	std::cout << "Enter the percentage increase : ";
	cin >> rate;
	rate = (rate / 100) + 1;		// dividing by 100 to change percentage to number. And then adding 1 to make our simplification for calculating tuition cost later easy. [ Formula --> T=(1+rate)*tuition ]

	// Calculating and displaying total tution and tuition cost each year
	long int total_tuition = 0;

	tuition = tuition;
	cout << "First year tuition cost  =  $" << tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl;

	tuition = tuition*rate;
	total_tuition = total_tuition + tuition;
	cout << "Second year tuition cost =  $" << tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl;

	tuition = tuition*rate;
	total_tuition = total_tuition + tuition;
	cout << "Third year tuition cost  =  $" << tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl;

	tuition = tuition*rate;
	total_tuition = total_tuition + tuition;
	cout << "Fourth year tuition cost =  $" << tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl;

	tuition = tuition*rate;
	total_tuition = total_tuition + tuition;
	cout << "Fifth year tuition cost  =  $" << tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl;

	cout << "Total cost of tution     =  $" << total_tuition / 100 << "." << setfill('0') << setw(2) << tuition % 100 << endl << endl;

	return 0;

}