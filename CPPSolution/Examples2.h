// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once
#include <string>
#include <vector>

/* Examples2 contains sections 10-12 of the course*/

/*strings and chars*/
class Section10
{
public:
	static void Execute();
private:
	static void CStyleFullNameExample();
	static void CPPStyleStringsExample();
	static void EncryptionChallenge();
	static void PyramidChallenge();
};

/*functions*/
class Section11
{
public:
	static void Execute();

private:
	static void GetEvenNumbersInRand(const int LineSeparator = 10, const int ModuloNumber = 2);
	static void OverloadsExample();
	static void SayHello(const std::string PersonToGreet);
	static void SayHello(const int Iterations = 10);

	enum Language : int 
	{
		English,
		Polish,
		German
	};
	static void SayHello(const Language TextLanguage = English);
	static void PassArrayToFunctionExample();
	static void RecieveArray(int InArray[], const size_t Size);
	static void PassVariableByRef();
	static void NegateVectorByRefElem(std::vector<int>& InVectorNumbers, const int Index = 0);
	static void CreateStaticVariable();
	static void PowStaticVariable();
	static void FibonacciRecursiveExample();
	static unsigned long long FindNFibonacci(int Number);

};


/*Pointers and References*/
class Section12SubClass;

class Section12 
{
public:
	Section12();
private:
	void GetAdressOfPtr() const;
	void ArraySubscriptOffsetNotation() const;
	void IncrementArrayPtr() const;

private:
	Section12SubClass* S12SubPtr {nullptr};
	int* UninitialisedPtr;
};

class Section12SubClass
{
public:
	Section12SubClass();
};
