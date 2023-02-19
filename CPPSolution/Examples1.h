// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once
#include <vector>

/* Examples1 contains sections 1-9 of the course*/
class Section6
{
public:
	static void Execute();

private:
	static void CalculateRoomPrice();
};

/* Arrays and vectors */
class Section7
{
public:
	Section7();

	void PrintAllArraysAndVectors();

private:
	struct TestArrays
	{
		int TestArray1[5]{0};
		int TestArray2[4]{ 2,1,3,7 };
		int TestArray3[10]{ 2,7 };
		float TestFloatArray1[3]{ 0.1f, 30.f, 60.2f };
		float MultiDimension[2][3]
		{ 
			{ 2, 1 ,0 },
			{3, 5, 10} 
		};
		char CharArray[5]{ 'a', 'b', 'c', 'd', 'e' };
	};
};

/* Statements and operators */
class Section8
{
public:
	static void Execute();

private:
	static void Increment();
	static void MixedTypeExpressions();
	static void CheckEquality();
	static void CompoundAssignment();
	static void ChangeChallange();

	static int ChangeWithRate(int& InMoneyInCents, const int ExchangeRate);
};

/* Flow Control */
class Section9
{

public:
	static void Execute();
	static void Challenge();

private:
	static void IfPlayground();
	static void SwitchPlayground();
	static void ConditionalOperator();
	static void LoopPlayground();
	static void ReplaceCharactersInString();
	static void FindNextFibonacciNumber();

	/* Section challenge */
	static void PrintChallangeMenu();
	static void ChallengePrintNumbers();
	static void ChallengeAddNumber();
	static void ChallengeDisplayMean();

	enum NumberType : int
	{
		Smallest,
		Biggest
	};
	static void ChallengeShowSmallestBiggest(NumberType NumberToChoose);


	static inline std::vector<int> ChallengeNumbers{1,2};
	static inline bool bIsChallengeFinished{false};
};
