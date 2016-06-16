// ----------------------------------------------------------------------------
//
// ----------------------------- Blood Alcohol Content (BAC)---------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To calculate BAC and display BAC chart.
//
//  Author   : Chetan Kumar Parakh
//  Date     : 2/14/2016
//
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Declaring user defined function.
int promptForInteger(string const &message, int lower, int upper);
char promptForMorF(string const &message);
void showImpairmentChart(int weight, int duration, bool isMale);
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC);
string impairment(double bac);

//Declaring global constant.
const double safe = 0.00;
const double someImpairment = 0.04;
const double significantAffected = 0.08;
const double someCriminalPenalties = 0.10;
const double deathPossible = 0.30;
const string SAFE = "Safe To Drive";
const string SOMEIMPAIR = "Some Impairment";
const string SIGNIFICANT = "Driving Skills Significantly Affected";
const string MOST_STATES = "Criminal Penalties in Most US States";
const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
const string YOURE_DEAD = "Death is Possible!";

//Main Function
int main()
{
	int weight;
	int duration;
	char gender;
	bool m_or_f;

	weight=	promptForInteger("Enter your weight <in lbs>: ", 0, 10000);
	duration =	promptForInteger("How many minutes has it been since your last drink? ", 0, 10000);
	gender = promptForMorF("Enter your sex as M or F: ");

	if (gender == 'M' || gender == 'm')
	{
		m_or_f = true;
	}
	else
	{
		m_or_f = false;
	}

	showImpairmentChart(weight, duration, m_or_f);
}

//Displays the message that is passed as an argument. Then allows the user to enter an integer. If the integer is within the range, it is returned or else the user is again prompted for an input.
int promptForInteger(string const &message, int lower, int upper)
{
	int number;
	do
	{
		cout << message;
		cin >> number;
	} while (number<lower || number>upper);
	return (number);
}

//Displays the message that is passed as an argument. Then allows the user to enter a character. If the character is either 'M' or 'm' or 'F' or 'f', it is returned or else the user is again prompted to enter a caracter.
char promptForMorF(string const &message)
{
	char c;
	do
	{
		cout << message;
		cin >> c;
	} while (c != 'M' && c != 'm' && c != 'F' && c != 'f');
	return(c);
}

//Calculates the BAC. Does not return any value rather makes changes in the variable whose value is passed to maleBAC and femaleBAC variable.
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
	maleBAC = ((double)numDrinks / (double)weight)*3.8;
	femaleBAC = ((double)numDrinks / (double)weight)*4.5;
	maleBAC -= (0.01)*((double)duration / 40.0);
	femaleBAC -= (0.01)*((double)duration / 40.0);;
	if (maleBAC <= 0.00)
	{
		maleBAC = 0.00;
	}
	if (femaleBAC <= 0.00)
	{
		femaleBAC = 0.00;
	}
}

//Determines the status of the person based on BAC value.
string impairment(double bac)
{
	if (bac == safe){
		return (SAFE);
	}
	if (bac>safe && bac < someImpairment){

		return(SOMEIMPAIR);
	}
	if (bac >= someImpairment && bac < significantAffected){
		return(SIGNIFICANT);
	}
	if (bac >= significantAffected && bac < someCriminalPenalties){
		return(MOST_STATES);
	}
	if (bac >= someCriminalPenalties && bac <= deathPossible){
		return(ALL_STATES);
	}
	if (bac > deathPossible){
		return(YOURE_DEAD);
	}
}

//This fuction displays the BAC chart, with proper formatting, based on weight, gender and time ellapsed since last drink.
void showImpairmentChart(int weight, int duration, bool isMale)
{	
	cout << fixed << setprecision(3);
	string status;
	cout << weight << " pounds,";
	if (isMale)
	{
		cout << " male, ";
	}
	else
	{
		cout << " female, ";
	}

	cout << duration << " minutes since last drink \n";

	cout << setw(8) << left << "# drinks" << setw(6) << right << "BAC" << setw(8) << right << "Status\n";
	
	for (int num_drinks = 0; num_drinks <= 11; num_drinks++)
	{
		double male_bac = 0.00;
		double female_bac = 0.00;
		computeBloodAlcoholConcentration(num_drinks, weight, duration, male_bac, female_bac);
		cout << setw(8) << right << num_drinks;
		if (isMale)
		{
			cout << setw(6) << right << male_bac;
			status = impairment(male_bac);
		}
		else
		{
			cout << setw(6) << right << female_bac;
			status = impairment(female_bac);
		}
		cout << setw(1) << left<<"";
		cout << status << "\n";
	}
}

/*********************END*********************/