// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once

#include <iostream>
#include <vector>

namespace SharedTemplates
{
	using namespace std;

	template<typename T>
	void SafeCin(T& Input)
	{
		cin >> Input;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Entered value does not match the required type. " << endl;
			cin >> Input;
		}
	}

	template<typename T, int ArraySize>
	void PrintArrayElems(const T(&Array)[ArraySize])
	{
		const T ArrayLenght = sizeof(Array) / sizeof(T);
		for (int i = 0; i < ArrayLenght; i++)
		{
			cout << "Array elem on position: " << i << " is: " << Array[i] << endl;
		}
	}

	template<typename T>
	void PrintVectorElems(const vector<T>& InVector)
	{
		for (int i = 0; i < InVector.size(); i++)
		{
			cout << "Vector elem on position: " << i << " is: " << InVector.at(i) << endl;
		}
	}

	template<typename T>
	void Print2DVectorElems(const vector<vector<T>>& InVector)
	{
		/* This check was made only for the training purpouse and does nothing useful in this function */
		if constexpr (!is_integral_v<T>)
		{
			cout << "Could not convert to int" << endl;
		}

		for (int i = 0; i < InVector.size(); i++)
		{
			for (int j = 0; j < InVector[i].size(); j++)
			{
				cout << InVector[i][j] << endl;
			}
		}
	}

	template<typename T, int FirstDimention, int SecondDimention>
	void Print2DArrayElems(const T(&Array)[FirstDimention][SecondDimention])
	{
		for (int i = 0; i < FirstDimention; i++)
		{
			for (int j = 0; j < SecondDimention; j++)
			{
				cout << "Row: " << i << " column: " << j << " value: " << Array[i][j] << endl;
			}
		}
	}

	template<typename T>
	void InputValueGreaterThan(T& ValueA, T ValueB, string PromptMessage)
	{
		bool bUserEnteredPositiveNumber;
		do
		{
			cout << PromptMessage;
			SafeCin(ValueA);
			bUserEnteredPositiveNumber = ValueA > ValueB;
			if (!bUserEnteredPositiveNumber)
			{
				cout << "Entered Value must be greater than " << ValueB << endl;
			}
		} while (!bUserEnteredPositiveNumber);
	}
	template<typename T>
	void InputValueInRange(T& InputValue, T MinValue, T MaxValue, string PromptMessage)
	{
		bool bIsWithinRange;
		do
		{
			cout << PromptMessage << MinValue << " and " << MaxValue << endl;
			SafeCin(InputValue);
			bIsWithinRange = InputValue >= MinValue && InputValue <= MaxValue;
			if (!bIsWithinRange) cout << "Provided input is not within the range " << endl;
		} while (!bIsWithinRange);
	}
	
	template<typename T, int ArraySize>
	bool ArrayContainsItem(T ItemToFind, const T(&Array)[ArraySize])
	{
		const int ArrayLenght = sizeof(Array) / sizeof(T);

		for (int i = 0; i < ArrayLenght; i++)
		{
			if (ItemToFind == Array[i]) return true;
		}
		return false;
	}

	/* Constructs from class and deletes it instantly */
	template<class T>
	void ConstructFromClass()
	{
		T* Section = new T();
		delete Section;
	}
}