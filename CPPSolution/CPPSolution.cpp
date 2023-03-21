// Copyright Jakub Urbanek. All Rights Reserved.

#include "CPPSolution.h"
#include "Examples1.h"
#include "Examples2.h"
#include "Examples3.h"
#include "Examples4.h"
#include "SharedTemplates.h"

using namespace SharedTemplates;

int main()
{
	MainNamespace::SelectSection();
	return 0;
}


void MainNamespace::SelectSection()
{
	char Selection{'.'};
	const char AvailableChoices[]{ 'x','X','a','A','b','B','c','C','d','D', 'e','E', 'f','F', 'g','G','h', 'H', 'i', 'I', 'j', 'J', 'k', 'K'};

	bool bUserSelectedProperChar{false};
	do
	{
		cout << "Please choose a section to launch: " << endl;
		cout << "x. All. " << endl;
		cout << "a. Section6 - Calculating room price" << endl;
		cout << "b. Section7 - Arrays and vectors" << endl;
		cout << "c. Section8 - Statements and operators" << endl;
		cout << "d. Section9 - Flow Control" << endl;
		cout << "	e. Section9 - Challenge" << endl;
		cout << "f. Section10 - Strings" << endl;
		cout << "g. Section11 - Functions" << endl;
		cout << "h. Section12 - Pointers and References" << endl;
		cout << "i. Section13 - OOP - Classes and Objects" << endl;
		cout << "j. Section14 - Operator Overloading" << endl;
		cout << "k. Section15 - Inheritance" << endl;
		
		cin >> Selection;
		bUserSelectedProperChar = ArrayContainsItem(Selection, AvailableChoices);
		if (!bUserSelectedProperChar)
		{
			cout << "Please select a valid section" << endl;
		}

	} while (!bUserSelectedProperChar);

	switch (Selection)
	{
	case 'x':
	case 'X':
		Section6::Exec();
		ConstructFromClass<Section7>();
		Section8::Exec();
		Section9::Exec();
		Section10::Exec();
		Section11::Exec();
		ConstructFromClass<Section12>();
		ConstructFromClass<Section13>();
		break;
	case 'a':
	case 'A':
		Section6::Exec();
		break;
	case 'b':
	case 'B':
		ConstructFromClass<Section7>();
		break;
	case 'c':
	case 'C':
		Section8::Exec();
		break;
	case 'd':
	case 'D':
		Section9::Exec();
		break;
	case 'e':
	case 'E':
		Section9::Challenge();
		break;
	case 'f':
	case 'F':
		Section10::Exec();
		break;
	case'g':
	case'G':
		Section11::Exec();
		break;
	case'h':
	case'H':
		ConstructFromClass<Section12>();
		break;
	case'i':
	case'I':
		ConstructFromClass<Section13>();
		break;
	case'j':
	case'J':
		Section14::Exec();
	case'k':
	case'K':
		Section15::Exec();
	default:
		break;
	}
}

