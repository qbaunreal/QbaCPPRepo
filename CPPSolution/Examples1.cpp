
#include "Examples1.h"
#include "SharedTemplates.h"

using namespace SharedTemplates;

Section6::Section6()
{
	cout << "~~~~~~~~~~~ Section 6 ~~~~~~~~~~~~" << endl;
	CalculateRoomPrice();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}


Section7::Section7()
{
	cout << "~~~~~~~~~~~ Section 7 ~~~~~~~~~~~~" << endl;
	PrintAllArraysAndVectors();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}


Section8::Section8()
{
	cout << "~~~~~~~~~~~ Section 8 ~~~~~~~~~~~~" << endl;
	Increment();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	MixedTypeExpressions();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	CheckEquality();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	CompoundAssignment();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ChangeChallange();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

Section9::Section9()
{
	cout << "~~~~~~~~~~~ Section 9 ~~~~~~~~~~~~" << endl;
	IfPlayground();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	SwitchPlayground();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ConditionalOperator();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	LoopPlayground();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ReplaceCharactersInString();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section6::CalculateRoomPrice()
{
	cout << "This example calculates price for given amount of rooms. " << endl;
	const unsigned int EstimateDays{ 30 };
	const float PricePerRoom{ 30.f };
	const float TaxRate{ 0.06f };

	int NumberOfRooms{};

	InputValueGreaterThan(NumberOfRooms,0, "Please enter a number of rooms: ");

	const float CostOfRooms = PricePerRoom * NumberOfRooms;
	const float Tax = CostOfRooms * TaxRate;
	const float TotalPrice = CostOfRooms + Tax;

	cout << "Costs for " << NumberOfRooms << " rooms are:" << endl << endl;
	cout << "Cost of rooms only: " << CostOfRooms << endl;
	cout << "Tax: " << Tax << endl;
	cout << "Total Price: " << TotalPrice << endl;
	cout << "This estimate is valid for: " << EstimateDays << " days." << endl;
}

void Section7::PrintAllArraysAndVectors()
{
	cout << "This example prints all elements of arrays and vectors. " << endl;
	char ContinueChar;
	cout << "Press Y/N to print arrays .. ";
	SafeCin(ContinueChar);
	bool bAllowExecution {false};

	switch (ContinueChar)
	{
	case 'y':
	case 'Y':
		bAllowExecution = true;
		break;
	case 'n':
	case 'N':
		bAllowExecution = false;
		break;
	default:
		break;
	}

	if (!bAllowExecution) return;

	cout << "------ Printing Arrays ---------" << endl;
	TestArrays Section7Array = TestArrays();
	PrintArrayElems(Section7Array.TestFloatArray1);
	Print2DArrayElems(Section7Array.MultiDimension);
	PrintArrayElems(Section7Array.CharArray);

	cout << "------ Printing 1d Vectors ---------" << endl;
	vector <float> SomeVectorRecord{ 2,1,3,7 };
	SomeVectorRecord.push_back(2137);
	PrintVectorElems(SomeVectorRecord);
	vector <float> OtherVector(10, 21.37f);
	PrintVectorElems(OtherVector);

	cout << "------ Printing 2d Vectors ---------" << endl;
	vector<vector<float>> TwoDimensionalVector;
	TwoDimensionalVector.push_back(SomeVectorRecord);
	TwoDimensionalVector.push_back(OtherVector);
	Print2DVectorElems(TwoDimensionalVector);
}

void Section8::Increment()
{
	cout << "This example shows pre-increment and post-increment effect on value " << endl;
	int BaseValue {0};
	cout << "Enter your base value: " << endl;
	SafeCin(BaseValue);
	int CurrentValue = BaseValue;

	const int PreIncrementInt = ++CurrentValue;
	CurrentValue = BaseValue;

	const int PostIncrementInt = CurrentValue++;

	cout << "PreIncrement: " << PreIncrementInt << endl;
	cout << "PostIncrement: " << PostIncrementInt << endl;
}


void Section8::MixedTypeExpressions()
{
	cout << "This example shows how the static_cast changes the result of int division " << endl;
	int NumberA {13};
	int NumberB {5};
	cout << "Enter int NumberA: ";
	SafeCin(NumberA);
	InputValueGreaterThan(NumberB, 0, "Enter int NumberB: ");

	float Result {0.f}; 

	Result = NumberA / NumberB;
	cout << "Division result A/B is : " << Result << endl; 
	Result = 0.f;

	Result = static_cast<float>(NumberA) / NumberB;
	cout << "Division result A/B is with static_cast<float> is: " << Result << endl; 
}

void Section8::CheckEquality()
{
	cout << "This example checks if numbers are equal and which one is greater. Then check if they are positve " << endl;
	int NumberA {2137};
	int NumberB {2137};
	cout << "Enter integers: NumberA and NumberB separated by space: " << endl;
	SafeCin(NumberA);
	SafeCin(NumberB);

	const bool bIsAEqualToB = NumberA == NumberB;
	const bool bIsAGreaterThanB = NumberA > NumberB;

	cout << boolalpha;

	if (bIsAEqualToB) cout << "A is equal to B: " << bIsAEqualToB << endl;
	else if (bIsAGreaterThanB) cout << "A is greater than B: " << bIsAGreaterThanB << endl;
	
	else cout << "B is greater than A: " << !bIsAGreaterThanB << endl;
	
	if (NumberA > 0 && NumberB > 0) cout << "Both numbers are positive " << endl;
	else if (NumberA > 0 || NumberB > 0) cout << "At least one of the numbers is positive " << endl;
}

void Section8::CompoundAssignment()
{
	cout << "This example shows effect of compount assigmnet on two values " << endl;
	cout << boolalpha;

	int DefaultValue {5};
	int SecondValue {2};
	
	cout << "Enter First Value: " << endl;
	SafeCin(DefaultValue);
	InputValueGreaterThan(SecondValue, 0, "Enter Second Value: ");
	
	int CurrentValue = DefaultValue;

	cout << "Current Value: " << CurrentValue << ". Second Value: " << SecondValue << endl;

	CurrentValue += SecondValue;
	cout << "+= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue -= SecondValue;
	cout << "-= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue *= SecondValue;
	cout << "*= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue /= SecondValue;
	cout << "/= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue %= SecondValue;
	cout << "%= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	cout << "Bitwise Assignment: " << endl;
	CurrentValue >>= SecondValue;
	cout << ">>= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue <<= SecondValue;
	cout << "<<= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue &= SecondValue;
	cout << "&= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue ^= SecondValue;
	cout << "^= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;

	CurrentValue |= SecondValue;
	cout << "|= : " << CurrentValue << endl;
	CurrentValue = DefaultValue;
}

void Section8::ChangeChallange()
{
	cout << "This example changes amount of cents to dollar banknots and coins: " << endl;
	int MoneyToProcess {0};

	InputValueGreaterThan(MoneyToProcess, 0, "Please enter cents to convert: ");

	const int NickelsToCentRate {5};
	const int DimesToCentRate = NickelsToCentRate * 2;
	const int QuarterToCentRage = NickelsToCentRate * 5;
	const int DollarToCentRate = QuarterToCentRage * 4;
	const int FiveDollarsToCentRate = DollarToCentRate * 5;
	const int TenDollarsToCentRate = DollarToCentRate * 10;
	const int TwentyDollarsToCentRate = DollarToCentRate * 10;;
	const int FiftyDollarsToCentRate = DollarToCentRate * 50;;
	const int HundredDollarsToCentRate = DollarToCentRate * 100;
	
	int HundredDollarsToGive {0};
	int FiftyDollarsToGive {0};
	int TwentyDollarsToGive {0};
	int TenDollarsToGive {0};
	int FiveDollarsToGive{0};
	int DollarToGive {0};
	int QuartersToGive {0};
	int DimesToGive {0};
	int NickelsToGive {0};
	int PenniesToGive {0};

	HundredDollarsToGive = ChangeWithRate(MoneyToProcess, HundredDollarsToCentRate);
	FiftyDollarsToGive = ChangeWithRate(MoneyToProcess, FiftyDollarsToCentRate);
	TwentyDollarsToGive = ChangeWithRate(MoneyToProcess, TwentyDollarsToCentRate);
	TenDollarsToGive = ChangeWithRate(MoneyToProcess, TenDollarsToCentRate);
	FiveDollarsToGive = ChangeWithRate(MoneyToProcess, FiveDollarsToCentRate);
	DollarToGive = ChangeWithRate(MoneyToProcess, DollarToCentRate);
	QuartersToGive = ChangeWithRate(MoneyToProcess, QuarterToCentRage);
	DimesToGive = ChangeWithRate(MoneyToProcess, DimesToCentRate);
	NickelsToGive = ChangeWithRate(MoneyToProcess, NickelsToCentRate);
	PenniesToGive = MoneyToProcess;

	cout << "---" << endl;
	cout << "Banknotes: " << endl;
	cout << "Hundred Dollars to give: " << HundredDollarsToGive << endl;
	cout << "Fifty Dollars to give: " << FiftyDollarsToGive << endl;
	cout << "Twenty Dollars to give: " << TwentyDollarsToGive << endl;
	cout << "Ten Dollars to give: " << TenDollarsToGive << endl;
	cout << "Five Dollars to give: " << FiveDollarsToGive << endl;
	cout << "Dollars to give: " << DollarToGive << endl;

	cout << "---" << endl;
	cout << "Coins: " << endl;
	cout << "Quarters to give: " << QuartersToGive << endl;
	cout << "Dimes to give: " << DimesToGive << endl;
	cout << "Nickels to give: " << NickelsToGive << endl;
	cout << "Pennies to give: " << PenniesToGive << endl;

}

/* as far as i know Int by ref is bad, but i want to change the InMoneyInCents in this function. 
Is there something that could be done better? only thing i fugured out is to make it a global variable but I'm not sure which one is better to have
*/
int Section8::ChangeWithRate(int& InMoneyInCents, const int ExchangeRate)
{
	int MoneyToGive = InMoneyInCents / ExchangeRate;
	InMoneyInCents %= ExchangeRate;
	return MoneyToGive;
}


void Section9::IfPlayground()
{
	cout << "This example checks if provided value fits within the range: " << endl;
	int SomeInt {0};
	const int MinValue {21};
	const int MaxValue {37};

	cout << "Please enter a number from a range of: " << MinValue << " and " << MaxValue << endl;
	SafeCin(SomeInt);

	if (SomeInt >= MinValue && SomeInt <= MaxValue)
	{
		cout << "Good. " << endl;
		return;
	}
	if (SomeInt <= MinValue)
	{
		const int Difference = MinValue - SomeInt;
		cout << "Bad. Value is less than MinValue. Difference: " << Difference << endl;
		return;
	}
	if (SomeInt >= MaxValue)
	{
		const int Difference = SomeInt - MaxValue;
		cout << "Bad. Value is greater than MaxValue. Difference: " << Difference << endl;
		return;
	}
}

void Section9::SwitchPlayground()
{
	cout << "This example translates numbers and colors to polish words : " << endl;
	int SomeInt{ 0 };
	const int MinValue{ 1 };
	const int MaxValue{ 6 };

	InputValueInRange(SomeInt, MinValue, MaxValue, "Choose an integer in range of: ");

	switch (SomeInt)
	{
	case 1:
		cout << "Jeden " << endl;
		break;
	case 2:
		cout << "Dwa " << endl;
		break;
	case 3:
		cout << "Trzy " << endl;
		break;
	case 4:
		cout << "Cztery " << endl;
		break;
	case 5:
	cout << "Piec " << endl;
		break;
	case 6:
		cout << "Szesc " << endl;
		break;
	default:
		break;
	}
	
	enum Color : int
	{
		red,
		green,
		blue
	};
	
	int Selection;
	InputValueInRange(Selection, 0, 2, "Choose a color (0 = red, 1 = green, 2 = blue) \n Enter a value from range: ");
	
	const Color CurrentColor {Selection};

	switch (CurrentColor)
	{
	case Color::red:
		cout << "Czerwony " << endl;
		break;
	case Color::green:
		cout << "Zielony " << endl;
		break;
	case Color::blue:
		cout << "Niebieski " << endl;
		break;
	default:
		break;
	}
}

void Section9::ConditionalOperator()
{
	cout << "This example shows the behaviour of conditional operator (checks if numbers are equal) " << endl;
	cout << "(expr ? expr1 : expr2) " << endl << endl;
	cout << "Enter two numbers separated by space: " << endl;

	int NumberA;
	int NumberB;
	SafeCin(NumberA);
	SafeCin(NumberB);

	string SentenceToPrint {""};

	SentenceToPrint = (NumberA == NumberB) ? "The numbers are equal" : "The numbers are not equal";
	cout << SentenceToPrint << endl;
}

void Section9::LoopPlayground()
{
	cout << "This example prints checks if X numbers can be divided by 3, 7 and 11" << endl;

	int LoopSize;
	cout << "Enter max numbers to check: " << endl;
	SafeCin(LoopSize);
	vector<int> NumbersThatMeetCondition{};

	for (int i = 1; i <= LoopSize; i++)
	{
		bool bMeetsTestCondition = i%3 == 0 && i%7 == 0 && i%11 == 0;
	
		if (bMeetsTestCondition) NumbersThatMeetCondition.push_back(i);
	}
	
	cout << "Numbers that meet the testing condition are: " << endl;
	for (int Number : NumbersThatMeetCondition)
	{
		cout << Number;
		cout << ((Number % 10 == 0) ? "\n" : " ");
	}
	cout << endl;
}

void Section9::ReplaceCharactersInString()
{
	cout << "This example replaces all letters in word to other character" << endl;
	const char TargetCharacter = 'x';

	string WordToProcess = "HelloWorld";
	cout << "Word that will be processed is: " << WordToProcess << endl;
	char CharacterToChange{};

	bool bFoundCharacterInWord {false};
	do 
	{
		cout << "Enter a character that is a part of this word: ";
		SafeCin(CharacterToChange);
		size_t CharacterIndex = WordToProcess.find(CharacterToChange);
		if (CharacterIndex != string::npos)
		{
			cout << endl << "Changing all occurances of " << CharacterToChange << " to " << TargetCharacter << endl;
			bFoundCharacterInWord = true;
		}
		else
		{
			cout << CharacterToChange << " is not a part of the " << WordToProcess<< " string. Please provide a valid character.. " << endl;
		}
	}
	while (!bFoundCharacterInWord);

	for (int i = 0; i < WordToProcess.length(); i++)
	{
		if (WordToProcess[i] == CharacterToChange) WordToProcess[i] = TargetCharacter;
	}
	
	cout << "Your new word is: " << WordToProcess << endl;
}
