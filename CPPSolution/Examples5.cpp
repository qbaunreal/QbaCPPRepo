// Copyright Jakub Urbanek. All Rights Reserved.

#include "Examples5.h"

void Section18::Exec()
{
	cout << "~~~~~~~~~~~ Section 13 ~~~~~~~~~~~~" << endl;
	S18_Exception::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S18_Exception::Exec()
{
	double Average{};
	const int Sum{0};
	int Total{1};
	Total--;
	
	try 
	{
		Average = CalculateAverage(Sum, Total);
	}
	catch (const int& Exception)
	{
		cerr << "Exception: Cant divide by zero" << endl;
	}
	catch (const string& Exception)
	{
		cerr << Exception << endl;
	}
	catch (...) //default catch
	{
		cerr << "Unknown Exception" << endl;
	}
	
	try
	{
		Average = CatchObjException(Sum, Total);
	}
	catch (const S18_DivideByZeroException& Exception)
	{
		cerr << Exception.what() << endl;
		cerr << Exception.ExampleString << endl;
		cerr << "Exception example float: " << Exception.ExampleFloat << endl;
	}
}

double S18_Exception::CalculateAverage(int Sum, int Total)
{
	if (Total == 0)
	{
		throw 0;
	}
	if (Sum == 0)
	{
		throw string{ "Sum cannot be 0" };
	}
	return static_cast<double>(Sum) / Total;
}

double S18_Exception::CatchObjException(int Sum, int Total)
{
	if (Total == 0)
	{
		throw S18_DivideByZeroException{};
	}
	return static_cast<double>(Sum) / Total;
}
