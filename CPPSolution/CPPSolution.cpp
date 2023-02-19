// Copyright Jakub Urbanek. All Rights Reserved.

#include "CPPSolution.h"
#include "Examples1.h"
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
	char AvailableChoices[]{'x','a','b','c','d', 'e', 'f', 'g', 'h'};

	bool bUserSelectedProperChar{false};
	do
	{
		cout << "Please choose a section to launch: " << endl;
		cout << "x. All. " << endl;
		cout << "a. Section6 - Calculating room price" << endl;
		cout << "b. Section7 - Arrays and vectors" << endl;
		cout << "c. Section8 - Statements and operators" << endl;
		cout << "d. Section9 - Flow Control" << endl;
		
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
		Section6::Execute();
		ConstructFromClass<Section7>();
		Section8::Execute();
		Section9::Execute();
		break;
	case 'a':
		Section6::Execute();
		break;
	case 'b':
		ConstructFromClass<Section7>();
		break;
	case 'c':
		Section8::Execute();
		break;
	case 'd':
		Section9::Execute();
		break;
	default:
		break;
	}
}

