// CPPSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
		ConstructFromClass<Section6>();
		ConstructFromClass<Section7>();
		ConstructFromClass<Section8>();
		ConstructFromClass<Section9>();
		break;
	case 'a':
		ConstructFromClass<Section6>();
		break;
	case 'b':
		ConstructFromClass<Section7>();
		break;
	case 'c':
		ConstructFromClass<Section8>();
		break;
	case 'd':
		ConstructFromClass<Section9>();
		break;
	default:
		break;
	}
}

