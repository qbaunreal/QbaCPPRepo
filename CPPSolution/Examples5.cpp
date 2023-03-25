// Copyright Jakub Urbanek. All Rights Reserved.

#include "Examples5.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <stack>
#include <queue>

void Section18::Exec()
{
	cout << "~~~~~~~~~~~ Section 18 ~~~~~~~~~~~~" << endl;
	S18_Exception::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S18_Exception::Exec()
{
	double Average{};
	const int Sum{0};
	int Total{1};
	Total--;
	
	try 
	{
		Average = CalculateAverage(Sum, Total);
	}
	catch (const int& Exception)
	{
		cerr << "Exception: Cant divide by zero" << endl;
	}
	catch (const string& Exception)
	{
		cerr << Exception << endl;
	}
	catch (...) //default catch
	{
		cerr << "Unknown Exception" << endl;
	}
	
	try
	{
		Average = CatchObjException(Sum, Total);
	}
	catch (const S18_DivideByZeroException& Exception)
	{
		cerr << Exception.what() << endl;
		cerr << Exception.ExampleString << endl;
		cerr << "Exception example float: " << Exception.ExampleFloat << endl;
	}
}

double S18_Exception::CalculateAverage(int Sum, int Total)
{
	if (Total == 0)
	{
		throw 0;
	}
	if (Sum == 0)
	{
		throw string{ "Sum cannot be 0" };
	}
	return static_cast<double>(Sum) / Total;
}

double S18_Exception::CatchObjException(int Sum, int Total)
{
	if (Total == 0)
	{
		throw S18_DivideByZeroException{};
	}
	return static_cast<double>(Sum) / Total;
}

void Section19::Exec()
{
	cout << "~~~~~~~~~~~ Section 19 ~~~~~~~~~~~~" << endl;
	S19_StreamManipulators::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S19_ReadTextFile::Exec();
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S19_StreamManipulators::Exec()
{
	cout << boolalpha;
	cout << true << endl;

	const int Number{ 255 };
	cout << hex;
	cout << showbase;
	cout << uppercase;
	cout << showpos;
	cout << Number << endl;

	const float ExampleFloat{ 2137.213721372137f };

	cout << setprecision(100);
	cout << noshowpos;
	cout << noshowpoint;
	
	cout << ExampleFloat<< endl;
	
	cout << setprecision(6);
	const string ExampleString{ "Hello" };
	const double ExampleNumber{ 1234.5678 };
	cout << std::setw(10) << ExampleNumber << std::setw(10) << ExampleString << setfill('_') << std::setw(10) << ExampleString  <<  endl;

}

void S19_ReadTextFile::Exec()
{
	const string FileName{ "../MyFile.txt"};
	fstream InFile{};

	InFile.open(FileName);
	
	if (InFile.is_open())
	{
		string InFileLine{};

		while(std::getline(InFile, InFileLine))
		{
			cout << InFileLine << endl;
		}
		const string StringToInsert{"ExampleWord"};
		InFile << StringToInsert;
	}
	else
	{
		cout << "Could not find your file" << endl;
	}

	InFile.close();
}

void Section20::Exec()
{
	cout << "~~~~~~~~~~~ Section 20 ~~~~~~~~~~~~" << endl;
	S20_MacrosTemplates::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S20_Iterators::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S20_SequenceContainer::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S20_AssociativeContainer::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S20_ContainerAdaptors::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S20_MacrosTemplates::Exec()
{
#define MAX(ValueA,ValueB) ((ValueA > ValueB) ? ValueA : ValueB) // uses preprocess == does not know c++

	const int ExampleInt{ 2137 };
	const float ExampleFloat{ 21.37f };

	cout << MAX(ExampleInt, ExampleFloat) << endl;

	const S20_TemplateClass <int, float, S18_Exception> InstanceFromTemplate (12,15.f, S18_Exception());
}

void SquareFunctionPointer(int X)
{
	std::cout << X * X << " ";
}

void S20_Iterators::Exec()
{
	const vector <int> SomeVector{ 5,10,151 };
	vector <int>::const_iterator IntIterator = SomeVector.cbegin();

	for (IntIterator; IntIterator < SomeVector.cend(); IntIterator++)
	{
		cout << *IntIterator << endl;
	}

	const S20_Player PlayerA{ "Andrzej", 32 };
	const S20_Player PlayerB{ "Adam", 15 };
	const S20_Player PlayerC{ "Andrzej", 72 };

	const vector <S20_Player> VectorOfPlayers{ PlayerA,PlayerB,PlayerC };

	const vector <S20_Player>::const_iterator FoundPlayer = find(VectorOfPlayers.cbegin(), VectorOfPlayers.cend(), PlayerC);

	if (FoundPlayer!= VectorOfPlayers.cend())
	{
		cout << "Found Player C: " << endl;
		cout << "Name: " << FoundPlayer->GetPlayerName() << endl;
		cout << "Level: " << FoundPlayer->GetPlayerLevel() << endl;
	}
	else
	{
		cout << "Could not find PlayerC that you're looking for" << endl;
	}

	cout << "Functor (function object): " << endl;
	const Square_Functor Square;
	for_each(SomeVector.cbegin(), SomeVector.cend(), Square);
	cout << "\n";

	cout << "Function pointer: " << endl;
	for_each(SomeVector.cbegin(), SomeVector.cend(), SquareFunctionPointer);
	cout << "\n";

	cout << "Lambda expression: " << endl;
	for_each(SomeVector.cbegin(), SomeVector.cend(), [](int X) { cout << X * X << " "; });
	cout << "\n";

	const int FoundNumbers = count_if(SomeVector.cbegin(), SomeVector.cend(), [](int X) { return X % 5 == 0; });
	cout << "Found X % 5: " << FoundNumbers << endl;
}

bool S20_Player::operator==(const S20_Player& Rhs) const
{
	if (GetPlayerName() == Rhs.GetPlayerName() && GetPlayerLevel() == Rhs.GetPlayerLevel())
	{
		return true;
	}
	 return false;
}

void S20_SequenceContainer::Exec()
{
	const std::array<int, 5> ExampleArray {2, 1, 3, 7, 15};

	cout << "ArraySize: " << ExampleArray.size() << endl;
	cout << "Last elem: " << ExampleArray.back() << endl;
	cout << "Third elem: " << ExampleArray.at(3) << endl;

	cout << "Sum of the elements: " << std::accumulate(ExampleArray.cbegin(), ExampleArray.cend(), 0) << endl;
	
	const int* Data = ExampleArray.data();

	std::deque<int> ExampleDeque{ 1, 2, 3, 4, 5 };

	for (const int& Element : ExampleArray)
	{
		ExampleDeque.push_front(Element);
	}
	
	for (int Element : ExampleDeque)
	{
		cout << Element << endl;
	}

	std::list<int> ExampleList{ 1, 2, 3, 4, 5 };
	/*ExampleList.at(3) cannot directly access elements in list*/

	std::list<int>::iterator Iterator = std::find(ExampleList.begin(),ExampleList.end(), 3);

	ExampleList.emplace_back(-5);
	ExampleList.emplace_front(-1);
	ExampleList.insert(Iterator, -3);
	Iterator++;
	ExampleList.emplace(Iterator, -4);
	ExampleList.resize(10);

	cout << "List elems: " << endl;
	for (std::list<int>::iterator It = ExampleList.begin(); It != ExampleList.end(); It++)
	{
		cout << *It << ", ";
	}
	cout << "\n";

	std::forward_list<int> ForwardList{ 1, 2, 3, 4, 5 };
	const std::forward_list<int>::iterator ForwardIterator = std::find(ForwardList.begin(), ForwardList.end(), 3);

	ForwardList.insert_after(ForwardIterator, 10);
	ForwardList.emplace_front(-100); //has only front

}

void S20_AssociativeContainer::Exec()
{
	std::set<int> ExampleSet{ -50, -50, -49, -49, -48, -47, -46 };
	ExampleSet.insert(15);

	std::set<int>::iterator SetIterator = ExampleSet.begin();

	for (SetIterator; SetIterator!= ExampleSet.end(); SetIterator++)
	{
		cout << *SetIterator << "_";
	}
	cout << "\n";

	std::map<string, int> ExampleMap
	{
		{"Andrzej", 18},
		{"Siemowit", 69}
	};

	ExampleMap.insert(std::pair<string, int>( "Jozef", 33 ));
	ExampleMap.at("Siemowit") = 55;

	for (const std::pair<string, int>& Element : ExampleMap)
	{
		cout << "Name: " << Element.first << endl;
		cout << "Age: " << Element.second << endl;
	}
	
	const std::map<string, int>::iterator MapIterator = ExampleMap.find("Jozef");
	if (MapIterator != ExampleMap.end())
	{
		cout << "Found: " << MapIterator->first << " with age: " << MapIterator->second;
	}

	cout << "\n";
}

void S20_ContainerAdaptors::Exec()
{
	cout << "Stack (last in first out): " << endl;
	std::stack<int> ExampleStackDeque;

	ExampleStackDeque.push(15);
	cout << ExampleStackDeque.top() << endl;
	cout << ExampleStackDeque.size() << endl;
	ExampleStackDeque.push(20);
	cout << ExampleStackDeque.top() << endl;
	cout << ExampleStackDeque.size() << endl;
	ExampleStackDeque.push(30);
	cout << ExampleStackDeque.top() << endl;
	cout << ExampleStackDeque.size() << endl;
	ExampleStackDeque.pop();
	cout << ExampleStackDeque.top() << endl;
	cout << ExampleStackDeque.size() << endl;

	cout << "Queue (first in first out): " << endl;

	std::queue<int> ExampleQueue;
	ExampleQueue.push(15);
	cout << ExampleQueue.front() << endl;
	cout << ExampleQueue.size() << endl;
	ExampleQueue.push(20);
	cout << ExampleQueue.front() << endl;
	cout << ExampleQueue.size() << endl;
	ExampleQueue.pop();
	cout << ExampleQueue.front() << endl;
	cout << ExampleQueue.size() << endl;
	ExampleQueue.pop();

	cout << "Priority_Queue (largest number is on top): " << endl;
	std::priority_queue<int> ExamplePriorityQueue;
	ExamplePriorityQueue.push(10000);
	ExamplePriorityQueue.push(50);
	ExamplePriorityQueue.push(2137);
	ExamplePriorityQueue.push(100000);
	cout << ExamplePriorityQueue.top() << endl;
	cout << ExamplePriorityQueue.size() << endl;
	ExamplePriorityQueue.pop();
	cout << ExamplePriorityQueue.top() << endl;
	cout << ExamplePriorityQueue.size() << endl;
	ExamplePriorityQueue.pop();
	cout << ExamplePriorityQueue.top() << endl;
	cout << ExamplePriorityQueue.size() << endl;
	ExamplePriorityQueue.pop();
	cout << ExamplePriorityQueue.top() << endl;
	cout << ExamplePriorityQueue.size() << endl;
	ExamplePriorityQueue.pop();
}

void Section21::Exec()
{
	cout << "~~~~~~~~~~~ Section 21 ~~~~~~~~~~~~" << endl;
	S21_Lambdas::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

template<typename T>
void FilterVector(const std::vector<T>& VectorToFilter, std::function<bool(T)> Func)
{
	for (const T& Item : VectorToFilter)
	{
		if (Func(Item))
		{
			cout << Item << ", ";
		}
	}
	cout << "\n";
};


void S21_Lambdas::Exec()
{
	const std::vector<int> SomeVector{ 2, 1, 3, 7, 15, 26, 14, 20 };
	float LambdaMultiplier{ 100 };
	int ExampleInt = 1000;
	
	for_each(SomeVector.cbegin(), SomeVector.cend(), S21_Functor());
	cout << "\n";

	for_each(SomeVector.cbegin(), SomeVector.cend(), [](int X) -> int { cout << X * 100 << " "; return X * 100; }); // you can ommit -> int (return type) for simple types
	cout << "\n";

	// unnamed function object capable of capturing variables in scope
	auto Lambda = [LambdaMultiplier](int X) { cout << X * LambdaMultiplier << " "; return X * LambdaMultiplier;  };

	auto ZeroElement = [LambdaMultiplier]() mutable { LambdaMultiplier = 0; }; // mutable allows = for inVariable
	auto OneElement = [&LambdaMultiplier]() mutable { LambdaMultiplier = 1; }; // or just pass it by ref
	auto TwoElement = [=, &LambdaMultiplier]() mutable { LambdaMultiplier = 2; ExampleInt = 50000000; }; // default pass by value but Multiplier by ref. 
	auto ThreeElement = [&]() { LambdaMultiplier = 3; }; // default capture by ref
	
	ZeroElement();
	cout << "LambdaMultiplier, ZeroElement: " << LambdaMultiplier << endl;
	OneElement();
	cout << "LambdaMultiplier, OneElement: " << LambdaMultiplier << endl;
	TwoElement();
	cout << "ExampleInt, TwoElement: " << ExampleInt << endl;
	ThreeElement();
	cout << "LambdaMultiplier, ThreeElement: " << LambdaMultiplier << endl;

	
	for_each(SomeVector.cbegin(), SomeVector.cend(), Lambda);
	cout << "\n";

	Lambda(2137); //you can call it

	int TestScore1{ 88 };
	float TestScore2{ 22 };

	auto SetScoresTo = [](int* Score1, auto& Score2, int NewValue)
	{
		*Score1 = NewValue;
		Score2 = NewValue;
	};

	SetScoresTo(&TestScore1, TestScore2, 100);
	cout << TestScore1 << " " << TestScore2 << endl;

	cout << "Displaying numbers < 7" << endl;
	std::function<bool(int)> Filter = [](auto Value) {return Value < 7; }; //predicate lambda
	FilterVector(SomeVector, Filter);

	cout << "Displaying even numbers: " << endl;
	std::function<bool(int)> SecondFilter = [](auto Value) {return Value % 2 == 0; };
	FilterVector(SomeVector, SecondFilter);
}

