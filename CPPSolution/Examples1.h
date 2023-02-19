// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once

/* Examples1 contains sections 1-9 of the course*/
class Section6
{
public:
	Section6();

private:
	void CalculateRoomPrice();
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
	Section8();

private:
	void Increment();
	void MixedTypeExpressions();
	void CheckEquality();
	void CompoundAssignment();
	void ChangeChallange();

	int ChangeWithRate(int& InMoneyInCents, const int ExchangeRate);
};

/* Flow Control */
class Section9
{
public:
	Section9();

private:
	void IfPlayground();
	void SwitchPlayground();
	void ConditionalOperator();
	void LoopPlayground();
	void ReplaceCharactersInString();

};