#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include <string>

#include <iostream>

using namespace std;

class bigNumber
{

	public:
		bigNumber();
		bigNumber(string);
		string multiplyBy(string);
		string addBy(string);
		void setBigNumber(string);
		string getBigNumber();
	protected:
	
	private:
		string bigValue;
		


};
#endif