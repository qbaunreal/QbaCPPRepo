// Copyright Jakub Urbanek. All Rights Reserved.

#include "CPPSolution.h"
#include "Examples1.h"
#include "Examples2.h"
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
	const char AvailableChoices[]{ 'x','X','a','A','b','B','c','C','d','D', 'e','E', 'f','F', 'g','G','h', 'H'};

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
		Section6::Execute();
		ConstructFromClass<Section7>();
		Section8::Execute();
		Section9::Execute();
		Section10::Execute();
		Section11::Execute();
		ConstructFromClass<Section12>();
		break;
	case 'a':
	case 'A':
		Section6::Execute();
		break;
	case 'b':
	case 'B':
		ConstructFromClass<Section7>();
		break;
	case 'c':
	case 'C':
		Section8::Execute();
		break;
	case 'd':
	case 'D':
		Section9::Execute();
		break;
	case 'e':
	case 'E':
		Section9::Challenge();
		break;
	case 'f':
	case 'F':
		Section10::Execute();
	case'g':
	case'G':
		Section11::Execute();
	case'h':
	case'H':
		ConstructFromClass<Section12>();
	default:
		break;
	}
}

