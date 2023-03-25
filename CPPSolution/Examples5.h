// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once

#include <iostream>
#include <functional>

using namespace std;
// Examples5 contains sections 18, 19, 21 and 22 of the course

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


/* I/O and Streams */
class Section19
{
public:
	static void Exec();
};

class S19_StreamManipulators
{
public:
	static void Exec();
};

class S19_ReadTextFile
{
public:
	static void Exec();
};


/* The Standard Template Library (STL) */
class Section20
{
public:
	static void Exec();
};

class S20_MacrosTemplates
{
public:
	static void Exec();
};

template<typename Type, typename Type2, typename SomeClass>
class S20_TemplateClass
{
public:
	S20_TemplateClass(Type ValueA, Type2 ValueB, const SomeClass&) :SomeValue{ ValueA }, OtherValue{ ValueB }
	{
		ExamplePtr = new SomeClass();
	}

	~S20_TemplateClass()
	{
		ExamplePtr = nullptr;
		delete ExamplePtr;
	}

private:
	Type SomeValue;
	Type2 OtherValue;
	SomeClass* ExamplePtr;
};


class S20_Iterators
{
public:
	static void Exec();
};

class S20_Player
{
public:
	S20_Player(std::string PlayerName, int PlayerLevel)
		:Name{ PlayerName }, Level{ PlayerLevel } {};

	bool operator==(const S20_Player& Rhs) const;
	
	inline const std::string& GetPlayerName() const { return Name; };
	inline int GetPlayerLevel() const { return Level; };

private:
	string Name;
	int Level;
};

struct Square_Functor
{
	void operator()(int X)
	{
		std::cout << X * 100 << " ";
	}
};


class S20_SequenceContainer
{
public:
	static void Exec();
};

class S20_AssociativeContainer
{
public:
	static void Exec();
};

class S20_ContainerAdaptors
{
public:
	static void Exec();
};


/* Lambdas */
class Section21
{
public:
	static void Exec();
};

class S21_Functor
{
public:
	void operator()(int X)
	{
		std::cout << X * 100 << " ";
	}
};

class S21_Lambdas
{
public:
	static void Exec();
};
