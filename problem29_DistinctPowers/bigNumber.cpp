#include "bigNumber.h"
#include <sstream>
/**
	default constructor
*/
bigNumber::bigNumber()
{
	bigValue = "0";
}

/**
	constructor for setting the bigValue
	@param string value-- the value that will be set to big value
*/
bigNumber::bigNumber(string value)
{
	//i should do a regex check on this value make sure it is only 0-9
	bigValue = value;
}

/**
	operator to multiple by another value;
*/
string bigNumber::multiplyBy(string value)
{

	return "";
}


string bigNumber::addBy(string value)
{

	//casting from string to int
	stringstream digit0;
	stringstream digit1;
	
	string hold0;
	string hold1;

	string reverseResult = "";

	int tempInt0 = 0;
	int tempInt1 = 0;
	int tempResult = 0;
	int carry = 0;
	int valuePlace = 0;
	int tenMod = 10;
	//reverse iterate through the bigValue and value

	int stringLength = 0;

	//turn this into a single for loop
	if (bigValue.length() > value.length())
	{
		stringLength = bigValue.length();
	}
	else
	{
		stringLength = value.length();
	}
	//compare the lengths of each string
	//check if one has terminated
	//add the carry at the right location

	std::string::reverse_iterator ritBigVal = bigValue.rbegin();
	std::string::reverse_iterator ritVal = value.rbegin();

	// the case of when the strings are not the same size...
	for (int ndx = 0; ndx < stringLength; ndx++)
	{
		if (ritBigVal != bigValue.rend() && ritVal != value.rend())
		{
			hold0 = *ritBigVal;
			hold1 = *ritVal;
			digit0.str(hold0);
			digit1.str(hold1);
			digit0 >> tempInt0;
			digit1 >> tempInt1;


			tempResult = tempInt0 + tempInt1 + carry;
			carry = tempResult / tenMod;
			valuePlace = tempResult % tenMod;
			reverseResult += to_string(valuePlace);

			/*
			cout << "tempInt0: " << tempInt0 << endl;
			cout << "tempInt1: " << tempInt1 << endl;
			cout << "tempResult: " << tempResult << endl;
			*/

			++ritBigVal;
			++ritVal;
		}
		else if (ritBigVal != bigValue.rend())
		{
			hold0 = *ritBigVal;
			digit0.str(hold0);
			digit0 >> tempInt0;
			tempResult = tempInt0 + carry;
			carry = tempResult / tenMod;
			valuePlace = tempResult % tenMod;
			reverseResult += to_string(valuePlace);
			++ritBigVal;
		}
		else if (ritVal != value.rend())
		{
			hold1 = *ritVal;
			digit1.str(hold1);
			digit1 >> tempInt1;
			tempResult = tempInt1 + carry;
			carry = tempResult / tenMod;
			valuePlace = tempResult % tenMod;
			reverseResult += to_string(valuePlace);
			++ritVal;
		}

		//reset streams
		digit0.str(std::string());
		digit0.clear();
		digit1.str(std::string());
		digit1.clear();

	}
	if (carry != 0)
	{
		reverseResult += to_string(carry);
	}

	string actualResult = "";
	for (int ndx = reverseResult.length() - 1; ndx >= 0 ; ndx--)
	{
		actualResult += reverseResult[ndx];
	}
		
	//reverse the string
	//cout << " result: " << bigValue << " + " << value << " = " << actualResult << endl;
	/*
	cout << endl;*/
	return actualResult;
}



void bigNumber::setBigNumber(string value)
{
	bigValue = value;
}

string bigNumber::getBigNumber()
{
	return bigValue;
}








