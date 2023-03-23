// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once

#include <iostream>
#include <vector>

using namespace std;
// Examples5 contains section 18 of the course

/* Exception Handling */
class Section18
{
public:
	static void Exec();
};

class S18_Exception
{
public:
	static void Exec();
	static double CalculateAverage(int Sum, int Total);
	static double CatchObjException(int Sum, int Total);
};

class S18_DivideByZeroException: public std::exception
{
public:
	virtual const char* what() const noexcept { return "You cannot divide by zero!"; };

	float ExampleFloat {2137.f};
	string ExampleString{ "ExampleString" };
};
