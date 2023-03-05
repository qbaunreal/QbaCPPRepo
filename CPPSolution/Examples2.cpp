// Copyright Jakub Urbanek. All Rights Reserved.

#include "Examples2.h"
#include "SharedTemplates.h"
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace SharedTemplates;
using namespace std;

void Section10::Execute()
{
	cout << "~~~~~~~~~~~ Section 10 ~~~~~~~~~~~~" << endl;
	CStyleFullNameExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	CPPStyleStringsExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	EncryptionChallenge();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	PyramidChallenge();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section10::CStyleFullNameExample()
{
	cout << "This example uses c style strings to count characters in name and surname. Concetrates them to Fullname(uppercase) afterward " << endl;
	char FirstName[20]{};
	char LastName[20]{};
	char FullName[50]{};
	
	cout << "Enter your first name: ";
	cin >> FirstName;
	cout << "Enter your last name: ";
	cin >> LastName;

	cout << "Your first name has: " <<  strlen(FirstName) << " letters while last name has: " << strlen(LastName) << endl;

	strcpy_s(FullName, FirstName);
	strcat_s(FullName, " ");
	strcat_s(FullName, LastName);

	for (static int i{0}; i < strlen(FullName); i++)
	{
		if (isalpha(FullName[i]))
		{
			FullName[i] = static_cast<char>(toupper(FullName[i]));
		}
	}
	cout << "Your full name is: " << FullName << endl;
}

void Section10::CPPStyleStringsExample()
{
	cout << "This example uses c++ style strings to replace one of the fruits with your own" << endl;
	const string Apple {"Apple"};
	const string Banana {"Banana"};
	const string KiwiUppercase {"KIWI"};
	const string KiwiLowercase {"kiwi"};
	string UserFruit{};

	cout << "Your Base strings are: \n" << Apple << "\n" << Banana << "\n" << KiwiUppercase << "\n" << KiwiLowercase << "\n" << endl;
	
	cout << "Add another fruit by typing its name: " << endl;
	cin.ignore();
	getline(std::cin, UserFruit);

	cout << "Your fruit is: " << UserFruit << endl;
	cout << "Replacing uppercase KIWI with your fruit: " << endl;
	string AllFruitsCombined = Apple + ", " + Banana + ", " + KiwiUppercase + ", " + KiwiLowercase;

	const size_t PositionOfTheWord = AllFruitsCombined.find(KiwiUppercase);
	if (PositionOfTheWord != string::npos)
	{
		AllFruitsCombined.replace(PositionOfTheWord, KiwiUppercase.length(), UserFruit);
	}
	cout << "Your fruits are: " << AllFruitsCombined << endl;

	cout << "Now changing all letters to uppercase: " << endl;
	for (char& Character : AllFruitsCombined)
	{
		Character = static_cast<char>(toupper(Character));
	}
	cout << AllFruitsCombined << endl;
}

void Section10::EncryptionChallenge()
{
	cout << "This example encrypts and decrypts given word based on the simple encryption key " << endl;
	const string Alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const string Key {"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"};
	string UserWord{};
	
	cout << "Enter a word you want to encrypt: ";
	getline(cin, UserWord);
	
	cout << "Encrypting..." << endl;

	for (char & Character: UserWord)
	{
		size_t LetterPosition = Alphabet.find(Character);
		if (LetterPosition == string::npos)
		{
			continue;
		}
		Character = Key[LetterPosition];
	}

	cout << "Your new word is: " << UserWord << endl;
	cout << "Decrypting... " << endl;

	for (char& Character : UserWord)
	{
		size_t LetterPosition = Key.find(Character);
		if (LetterPosition == string::npos)
		{
			continue;
		}
		Character = Alphabet[LetterPosition];
	}
	cout << "Your original word was: " << UserWord << endl;
}

void Section10::PyramidChallenge()
{
	cout << "This example creates a pyramid made out of letters" << endl;
	string UserWord{};

	cout << "Press y to load example pyramid, or anything else to enter your custom one " << endl;
	char LoadExampleInput{};
	SafeCin(LoadExampleInput);

	if (LoadExampleInput == 'y' || LoadExampleInput == 'Y')
	{
		UserWord = "ABCDEFGHIJKLMNOPRSTUWYZ";
	}

	else
	{
		cout << "Enter a string of characters: " << endl;
		cin.ignore();
		getline(cin, UserWord);
	}

	for (size_t i = UserWord.size() -1 ; i > 0; i--)
	{
		string Spacebars{};
		string RowFirstHalf{};
		string RowSecondHalf{};

		for (size_t j = i - 1; j > 0 ; j--)
		{
			Spacebars += " ";
		}
	
		for (size_t k = 0; k < UserWord.size() - i; k++)
		{
			RowFirstHalf += UserWord[k];	
		}

		for (size_t l = RowFirstHalf.size() - 1; l > 0; l--)
		{	
			RowSecondHalf += RowFirstHalf[l-1];
		}

		const string FinalRow = Spacebars + RowFirstHalf + RowSecondHalf + "\n";
		cout << FinalRow;
	}
}

void Section11::Execute()
{
	cout << "~~~~~~~~~~~ Section 11 ~~~~~~~~~~~~" << endl;
	GetEvenNumbersInRand();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	OverloadsExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	PassArrayToFunctionExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	PassVariableByRef();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	CreateStaticVariable();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	FibonacciRecursiveExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section11::GetEvenNumbersInRand(const int LineSeparator, const int ModuloNumber)
{
	cout << "This example finds X random even numbers in range of 0-1000 " << endl;
	cout << "Enter how much numbers to find:  " << endl;
	
	const int RangeMin {0};
	const int RangeMax {1000};

	int TargetCount{0};
	cin.ignore();
	SafeCin(TargetCount);
	
	srand(time(nullptr));

	bool bFoundRequiredNumbers{false};
	int FoundNumbersCount {0};
	
	while (!bFoundRequiredNumbers) 
	{
		const int RandomNumber = rand() % RangeMax + RangeMin;
		const bool bMatchesRequirement = RandomNumber % ModuloNumber == 0;
		
		if (bMatchesRequirement)
		{
			cout << RandomNumber << " ";
			++FoundNumbersCount;

			if (FoundNumbersCount % LineSeparator == 0)
			{
				cout << "\n";
			}
		}

		if (FoundNumbersCount == TargetCount)
		{
			bFoundRequiredNumbers = true;
		}
		
	}
	cout << "\n";
}

void Section11::OverloadsExample()
{
	cout << "This example overloads SayHello method " << endl;
	SayHello("Andrzej");
	SayHello(Language::Polish);
	SayHello(Language::German);
	SayHello(5);
}

void Section11::SayHello(const std::string PersonToGreet)
{
	cout << "Hello " << PersonToGreet << endl;
}

void Section11::SayHello(const int Iterations)
{
	for (int i = 0; i < Iterations; i++)
	{
		cout << "Hello. " << endl;
	}
}

void Section11::SayHello(const Language TextLanguage)
{
	switch (TextLanguage)
	{
	case English:
		cout << "Hello. " << endl;
		break;
	case Polish:
		cout << "Czesc. " << endl;
		break;
	case German:
		cout << "Hallo. " << endl;
		break;
	default:
		break;
	}
}

void Section11::PassArrayToFunctionExample()
{
	cout << "This example passes pure c++ array into the function (is not being copied) and sets all of elements to 0 " << endl;

	int ArrayToPass[10] {2,1,3,7,2,1,3,7,2,5};
	RecieveArray(ArrayToPass, 10);
}

void Section11::RecieveArray(int InArray[], const size_t Size)
{
	cout << "Recieved elements are: " << endl;
	for (size_t i = 0; i < Size; i++)
	{
		cout << InArray[i] << " ";
	}

	cout << "\n Now setting all elements of passed array (not copy) to 0" << endl;
	for (size_t i = 0; i < Size; i++)
	{
		InArray[i] = 0;
		cout << InArray[i] << " ";
	}
	cout << "\n";
}

void Section11::PassVariableByRef()
{
	cout << "This example passes a number by ref and changes it to negative one. " << endl;
	cout << "Please provide a number: " << endl;

	int UserNumber;
	SafeCin(UserNumber);

	vector<int> UserVector;
	UserVector.push_back(UserNumber);
	NegateVectorByRefElem(UserVector);
	
	cout << "Your number is now: ";
	PrintVectorElems(UserVector);
	cout << "\n";
}

void Section11::NegateVectorByRefElem(std::vector<int>& InVectorNumbers, const int Index)
{
	if (InVectorNumbers.size() > 0)
	{
		InVectorNumbers[Index] *= -1;
	}
	else
	{
		cout << "Recieved vector is empty, cannot negate the number. ";
	}
}

void Section11::CreateStaticVariable()
{
	cout << "This example prints x numbers of 2^i by iterating on static variable. " << endl;
	cout << "Enter amount of numbers: " << endl;
	int TargetCount;
	SafeCin(TargetCount);
	
	cout << "Your numbers are: " << endl;
	for (size_t i = 0; i < TargetCount; i++)
	{
		PowStaticVariable();
	}
	
}

void Section11::PowStaticVariable()
{
	static int CurrentNumber{2};

	CurrentNumber *= 2;
	cout << CurrentNumber << endl;
}

void Section11::FibonacciRecursiveExample()
{
	cout << "This example uses a recursive function to calculate N fibonacci element. (bad performance) " << endl;
	cout << "Enter N element: " << endl;
	int NElement;
	SafeCin(NElement);

	const unsigned long long FoundNumber = FindNFibonacci(NElement);
	cout << "Your Fibonacci number is: " << FoundNumber << endl;
}

unsigned long long Section11::FindNFibonacci(int Number)
{
	if (Number <= 1)
	{
		return Number;
	}
	return FindNFibonacci(Number - 1) + FindNFibonacci(Number - 2);
}

Section12::Section12()
{
	cout << "~~~~~~~~~~~ Section 12 ~~~~~~~~~~~~" << endl;
	GetAdressOfPtr();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ArraySubscriptOffsetNotation();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	IncrementArrayPtr();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ConstPtrs();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	PassByRefPtrExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ReturnPtrsExample();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	PtrSectionChallenge();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section12::GetAdressOfPtr() const
{
	cout << "This example shows how to get adress of ptr and how you can initialise them" << endl;
	cout << "Value of Uninitialised Ptr is: " << UninitialisedPtr << endl;
	cout << "Adress of Uninitialised Ptr is: " << &UninitialisedPtr << endl;
	cout << "Sizeof of Uninitialised Ptr is: " << sizeof UninitialisedPtr << endl;
	
	long long* InitializedNullPtr {nullptr};
	cout << "Value of Initialized Null Ptr is: " << InitializedNullPtr << endl;
	cout << "Adress of Initialized Null Ptr is: " << &InitializedNullPtr << endl;
	cout << "Sizeof of Initialized Null Ptr is: " << sizeof InitializedNullPtr << endl;

	int* InitializedPtr = new int{6};
	cout << "Dereferenced Value of Initialized Ptr is (using new keyword): " << *InitializedPtr << endl;
	cout << "Adress of Initialized Ptr is (using new keyword): " << &InitializedPtr << endl;
	cout << "Sizeof of Initialized Ptr is (using new keyword): " << sizeof InitializedNullPtr << endl;
	delete InitializedPtr;	

	int IntNumber {2137};
	int* SecondInitializedPtr = &IntNumber;
	cout << "Dereferenced Value of Second Initialized Ptr is (assigned to adress of variable): " << *SecondInitializedPtr << endl;
	cout << "Adress of Second Initialized Ptr is (assigned to adress of variable): " << &SecondInitializedPtr << endl;
	cout << "Sizeof of Second Initialized Ptr is (assigned to adress of variable): " << sizeof SecondInitializedPtr << endl;

	cout << "Changing value of pointer to 210.." << sizeof SecondInitializedPtr << endl;
	*SecondInitializedPtr = 210;
	cout << "Dereferenced Value of Second Initialized Ptr is: " << *SecondInitializedPtr << endl;
	cout << "Changing dereferenced pointer's value also changes the int that it is assigned to to: " << IntNumber << endl;
	SecondInitializedPtr = nullptr;
}

void Section12::ArraySubscriptOffsetNotation() const
{
	cout << "This example shows how to create a new array pointer and get offset from it. Numbers in array are: 1,2,3,4,5" << endl;
	cout << "Compares Subscript and Offset notation" << endl;
	int ArrayNumbers[]{1,2,3,4,5};
	int* ArrayPtr = ArrayNumbers;

	//Subscript notation
	cout << "Subscript Value[0]: " << ArrayPtr[0] << endl;
	cout << "Subscript Value[1]: " << ArrayPtr[1] << endl;
	cout << "Subscript Value[2]: " << ArrayPtr[2] << endl;
	
	//Offset notation
	cout << "Offset Adress[0]: " << *(ArrayPtr) << endl;
	cout << "Offset Value[1]: " << *(ArrayPtr + 1) << endl; // gets next int (type * 1)
	cout << "Offset Value[1]: " << *(ArrayPtr + 2) << endl; // gets second int (type * 2)
}

void Section12::IncrementArrayPtr() const
{
	cout << "This example Iterates arrayptr to display all array elems. Numbers in array are: 1,2,3,4,5" << endl;

	int ArrayNumbers[]{ 1,2,3,4,5 };
	int* ArrayPtr = ArrayNumbers;

	const int ArrayLenght = sizeof(ArrayNumbers) / sizeof(int);
	for (int i = 0; i < ArrayLenght; i++)
	{
		cout << "Array item in index: " << i << " has value of: " << *ArrayPtr++ << endl; //first dereferecing the ptr, then post increment it
	}
}

void Section12::ConstPtrs() const
{
	cout << "This example shows how pointers to const and const ptrs work" << endl;
	int ExampleInt {2137};
	int ExampleInt2 {42};

	const int* PtrToConst {&ExampleInt};
	cout << "const int* PtrToConst =  " << *PtrToConst <<endl;

	//*PtrConst = 33; This produces error as expected
	PtrToConst = &ExampleInt2;

	int* const ConstPtr { &ExampleInt };
	cout << "int* const ConstPtr = " << *ConstPtr << endl;

	*ConstPtr = 33;
	//ConstPtr = &ExampleInt2; This produces error as expected

	const int* const ConstPtrToConst{ &ExampleInt };
	cout << "const int* const ConstPtrToConst = " << *ConstPtr << endl;

	//*ConstPtrToConst = 33;  This produces error as expected
	//ConstPtrToConst = &ExampleInt2; This produces error as expected

}

void Section12::PassByRefPtrExample() const
{
	cout << "This example shows how to pass by ref ptrs (increments ptr value 10x twice)" << endl;
	int BaseIntValue {0};
	cout << "Please enter your base value" << endl;
	SafeCin(BaseIntValue);

	for (size_t i = 0; i < 10; i++)
	{
		PassByRefPtr(&BaseIntValue);
	}

	int* const NewIntPtr {&BaseIntValue};
	cout << "Now doing the same loop for int* const NewIntPtr" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		PassByRefPtr(NewIntPtr);
	}
}

void Section12::PassByRefPtr(int* const IntPtr) const
{
	++*IntPtr;
	cout << "New ptr Value: " << *IntPtr << endl;
}

void Section12::ReturnPtrsExample() const
{
	cout << "This example shows how to returns ptrs out of a function" << endl;
	
	cout << "Please enter ValueA" << endl;
	int ValueA {0};
	SafeCin(ValueA);

	cout << "Please enter ValueB" << endl;
	int ValueB {0};
	SafeCin(ValueB);

	const int* LargerPtr = FindLargerInt(&ValueA, &ValueB);
	cout << "LargerPtr value is: " << *LargerPtr << endl;
	cout << "Now creating array of size of LargerPtr and initializing its values to SmallerPtr" << endl;
	int* const NewArray = CreateArrayPtr(*LargerPtr, ValueB); //returns adress of first element in the array
	
	for (int i = 0; i < *LargerPtr; i++)
	{
		cout << "ArrayElem at " << i << " value is: " << *(NewArray + i) << endl; //Goes to next adress of size int
	}
	delete[] NewArray;

	cout << "\n";
}

const int* Section12::FindLargerInt(const int* IntPtrA, const int* IntPtrB) const
{
	return *IntPtrA > *IntPtrB ? IntPtrA : IntPtrB;
}

int* Section12::CreateArrayPtr(int Size, int InitValue) const
{
	int* const NewArray = new int[Size];

	for (int i = 0; i < Size; i++)
	{
		*(NewArray + i) = InitValue;
	}
	return NewArray;
}

void Section12::PtrSectionChallenge() const
{
	cout << "This example takes two arays and multiplies elems in ArrayA with elems in ArrayB: " << endl;
	int ArrayA[]{1,2,3,4,5};
	int ArrayB[]{10,20,30};
	cout << "Array A: " << endl;
	PrintArrayElemsChallenge(ArrayA, 5);
	cout << "Array B: " << endl;
	PrintArrayElemsChallenge(ArrayB, 3);

	const int* const NewArray = ApplyAllChallenge(ArrayA, 5, ArrayB, 3);
	cout << "NewArray (Array A * Array B)= " << endl;
	PrintArrayElemsChallenge(NewArray, 15);
	
	delete [] NewArray;
	cout << "\n";
}



const int* const Section12::ApplyAllChallenge(const int* const ArrayA, int ArrayASize, const int* const ArrayB, int ArrayBSize) const
{
	const int ArraySize = ArrayASize * ArrayBSize;
	int* const NewArray = new int[ArraySize];
	int IndexesAssigned {0};
	for (int i = 0; i < ArrayASize; i++)
	{
		for (int j = 0; j < ArrayBSize; j++)
		{
			*(NewArray + IndexesAssigned) = ArrayA[i] * ArrayB[j];
			IndexesAssigned++;
		}
	}
		
	return NewArray;
}

void Section12::PrintArrayElemsChallenge(const int* const Array, int ArraySize) const
{
	for (int i = 0; i < ArraySize; i++)
	{
		cout << *(Array + i);
		if (i < ArraySize-1)
		{
			cout << ", ";
		}
	}
	cout << "\n";
}

