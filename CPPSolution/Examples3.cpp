// Copyright Jakub Urbanek. All Rights Reserved.

#pragma warning(disable:4996)

#include "Examples3.h"
#include "SharedTemplates.h"

using namespace SharedTemplates;
using namespace std;

int Section13_StaticClassMembers::NumberOfMembers {0};
std::vector<Section13_StaticClassMembers*> Section13_StaticClassMembers::VectorOfMembers{};
std::vector<Section13_Movie*> Section13_Movies::MoviesCollection{};

Section13::Section13()
{
	cout << "~~~~~~~~~~~ Section 13 ~~~~~~~~~~~~" << endl;
	SubClass_Create();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	ConstrDestrTest();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	CopyClassConstr();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section13_ShallowVSDeepExample::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section13_LRValueRefs::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section13_StaticClassExamples::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section13_Friend::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section13_Challenge::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section13::SubClass_Create() const
{
	Section13_SubClass* NewSubClass = new Section13_SubClass();

	NewSubClass->UpdateExampleInt1(10);
	(*NewSubClass).UpdateExampleInt1(20);
	delete NewSubClass;
}

void Section13_SubClass::UpdateExampleInt1(int NewValue)
{
	cout << "This example updates private ExampleInt and was accessed from other class" << endl;
	cout << "Old value: " << ExampleInt1 << endl;

	ExampleInt1 = NewValue;
	cout << "New value: " << ExampleInt1 << endl;
}

void Section13::ConstrDestrTest() const
{
	ConstructorDestructor* ConstrDestrObj = new ConstructorDestructor(20, 30, 50);
	delete ConstrDestrObj;
}

void Section13::CopyClassConstr() const
{
	cout << "This example shows how to implement a copy contructor " << endl;
	ConstructorDestructor ConstrDestr {10};
	PassObjectByValue(ConstrDestr);
	PassObjectByValue(ConstrDestr);
	PassObjectByValue(ConstrDestr);
}

void Section13::PassObjectByValue(ConstructorDestructor ConstrObj) const
{
	cout << "Passing a copy.. " << endl;
}

ConstructorDestructor::ConstructorDestructor(int NewHealth)
{
	cout << "Setting values by assignment " << endl;
	Health = NewHealth;
	Stamina = 0;
	Mana = 0;
	cout << "Health: " << Health << ", ";
	cout << "Stamina: " << Stamina << ", ";
	cout << "Mana: " << Mana << endl;
}

ConstructorDestructor::ConstructorDestructor(int NewHealth, int NewStamina)
	:ConstructorDestructor{NewHealth,NewStamina, 0}
{
	cout << "This example shows delegating contructors (execututing other constructor with this ones params) " << endl;
	cout << "Can be done only with initialization list " << endl;
}

ConstructorDestructor::ConstructorDestructor(int NewHealth, int NewStamina, int NewMana)
	:Health{ NewHealth }, Stamina{ NewStamina }, Mana{ NewMana }
{
	cout << "This example shows constructor with Initialization Lists " << endl;
	cout << "Health: " << Health << ", ";
	cout << "Stamina: " << Stamina << ", ";
	cout << "Mana: " << Mana << endl;
}

ConstructorDestructor::ConstructorDestructor(const ConstructorDestructor& Source)
	:Health{Source.Health}, Stamina{Source.Stamina}, Mana{Source.Mana}
{
	cout << "Copy constructor has been called " << endl;
	cout << "Health: " << Health << ", ";
	cout << "Stamina: " << Stamina << ", ";
	cout << "Mana: " << Mana << endl;
}


ConstructorDestructor::~ConstructorDestructor()
{
	cout << "Destructor on ConstructorDestructor class obj has been called"  << endl;
}


void Section13_ShallowVSDeepExample::Exec()
{
	cout << "This example shows difference between shallow and deep copy " << endl;
	/*cout << "Shallow: " << endl;
	Section13_ShallowCopy ShallowCopyObj{ 12 };
	DisplayNumberCopyObj(ShallowCopyObj);
	Section13_ShallowCopy ShallowCopyObj2{ ShallowCopyObj };
	ShallowCopyObj2.SetPtrValue(1000);*/

	cout << "Deep: " << endl;
	Section13_DeepCopy DeepCopyObj{ 24 };
	DisplayNumberCopyObj(DeepCopyObj);
	Section13_DeepCopy DeepCopyObj2{ DeepCopyObj };
	DeepCopyObj2.SetPtrValue(213400);
}

void Section13_ShallowVSDeepExample::DisplayNumberCopyObj(Section13_ShallowCopy CopiedClass)
{
	const int AccessedInt = CopiedClass.GetPtrValue();
	cout << "Your Int is: " << AccessedInt << endl;
}

void Section13_ShallowVSDeepExample::DisplayNumberCopyObj(Section13_DeepCopy CopiedClass)
{
	const int AccessedInt = CopiedClass.GetPtrValue();
	cout << "Your Int is: " << AccessedInt << endl;
}

Section13_ShallowCopy::Section13_ShallowCopy(int SomeNumber)
{
	IntPtr = new int;
	SetPtrValue(SomeNumber);
}

Section13_ShallowCopy::~Section13_ShallowCopy()
{
	delete IntPtr;
	cout << "Destructed Shallow Copy obj" << endl;
}

Section13_ShallowCopy::Section13_ShallowCopy(const Section13_ShallowCopy& Source)
	:IntPtr(Source.IntPtr)
{
	cout << "Copy constructor - shallow" << endl;
}

Section13_DeepCopy::Section13_DeepCopy(int SomeNumber)
{
	IntPtr = new int;
	*IntPtr = SomeNumber;
}

Section13_DeepCopy::~Section13_DeepCopy()
{
	delete IntPtr;
	cout << "Destructed Deep Copy obj" << endl;
}

Section13_DeepCopy::Section13_DeepCopy(const Section13_DeepCopy& Source)
{
	IntPtr = new int;
	*IntPtr = *Source.IntPtr;
	cout << "Copy constructor, deep " << endl;
}
////Delegating construction version, because constructor is using new int anyway
//DeepCopy::DeepCopy(const DeepCopy& Source)
//	:DeepCopy{*Source.IntPtr}
//{
//	cout << "Copy constructor, deep " << endl;
//}

void Section13_LRValueRefs::Exec()
{
	cout << "This example shows how to pass LValue and RValue into the function and how move constructor works" << endl;
	
	const int BaseInt {100};
	PrintLValueRef(BaseInt);
	//PrintLValueRef(22); Error: Cannot bind non-const lvalue ref. Works ok it is const

	//PrintRValueRef(BaseInt); Error: an RValue reference cannot be bount to lvalue 
	PrintRValueRef(22);
	
	cout << "Now showing how move constructor works: " << endl;
	vector<Section13_MoveContructor> MoveObjs;
	MoveObjs.push_back(Section13_MoveContructor {2137});
	MoveObjs.push_back(Section13_MoveContructor {1000});
}

void Section13_LRValueRefs::PrintLValueRef(const int& LValue)
{
	cout << "Your Value is: " << LValue << endl;
}

void Section13_LRValueRefs::PrintRValueRef(const int&& RValue)
{
	cout << "Your Value is: " << RValue << endl;
}

Section13_MoveContructor::Section13_MoveContructor(int SomeNumber)
{
	cout << "Constructor: " << SomeNumber << endl;
	IntPtr = new int;
	*IntPtr = SomeNumber;
}

Section13_MoveContructor::~Section13_MoveContructor()
{
	if (IntPtr)
	{
		cout << "Deleting the IntPtr that is: " << *IntPtr << endl;
	}
	else
	{
		cout << "Deleting the IntPtr that is: " << "nullptr" << endl;
	}
	delete IntPtr;
}

Section13_MoveContructor::Section13_MoveContructor(const Section13_MoveContructor& Source)
{
	IntPtr = new int;
	*IntPtr = *(Source.IntPtr);
}

Section13_MoveContructor::Section13_MoveContructor(Section13_MoveContructor&& Source) noexcept
	:IntPtr{Source.IntPtr}
{
	Source.IntPtr = nullptr; // "steals" from originating source - copying it and nullptr source
	cout << "Move constructor has been called. Int value is: " << *IntPtr << endl;
}

void Section13_StaticClassExamples::Exec()
{
	cout << "This example shows how static functions and variables work" << endl;
	
	Section13_StaticClassMembers::PrintOutVectorMembers();
	Section13_StaticClassMembers* Obj1 = new Section13_StaticClassMembers;
	Section13_StaticClassMembers::PrintOutVectorMembers();
	Section13_StaticClassMembers* Obj2 = new Section13_StaticClassMembers;
	Section13_StaticClassMembers::PrintOutVectorMembers();
	delete Obj1;
	Section13_StaticClassMembers::PrintOutVectorMembers();
	delete Obj2;
	Section13_StaticClassMembers::PrintOutVectorMembers();
}

Section13_StaticClassMembers::Section13_StaticClassMembers()
{
	VectorOfMembers.push_back(this);
	cout << "Created an obj " << endl;
	NumberOfMembers++;
}

Section13_StaticClassMembers::~Section13_StaticClassMembers()
{
	const auto IndexOfMember = std::find(VectorOfMembers.begin(), VectorOfMembers.end(), this);
	VectorOfMembers.erase(IndexOfMember);
	cout << "Deleted an obj " << endl;
	NumberOfMembers--;
}

void Section13_StaticClassMembers::PrintOutVectorMembers()
{
	cout << "static int NumberOfMembers: " << NumberOfMembers << endl;
	cout << "VectorOfMembers.size: " << VectorOfMembers.size() << endl;
}

void Section13_Friend::Exec()
{
	//TODO: revisit this later
}

void Section13_Challenge::Exec()
{
	cout << "Running Section 13 challenge - Movies" << endl;
	Section13_Movies::AddMovieToCollection("Pulp Fiction", MovieRating::R, 2);
	Section13_Movies::DisplayAllMovies();
	Section13_Movies::IncrementWatchCount("Pulp Fiction");
	Section13_Movies::DisplayAllMovies();
	Section13_Movies::AddMovieToCollection("Pulp Fiction", MovieRating::R, 2); //check if can add it twice
	Section13_Movies::AddMovieToCollection("Clockwork Orange", MovieRating::R, 3);
	Section13_Movies::IncrementWatchCount("AAA");
	Section13_Movies::IncrementWatchCount("Clockwork Orange");
	Section13_Movies::DisplayAllMovies();
}


void Section13_Movies::AddMovieToCollection(const std::string& MovieName, MovieRating Rating, int WatchedCount)
{
	Section13_Movie* FoundMovie = Section13_Movies::FindMovie(MovieName);
	if (FoundMovie)
	{
		cout << "Cannot add movie that already exists: " << MovieName << endl;
	}
	else
	{
		Section13_Movie* NewMovie = new Section13_Movie{ MovieName, Rating, WatchedCount };
		MoviesCollection.push_back(NewMovie);
	}
}


void Section13_Movies::IncrementWatchCount(const std::string& MovieName)
{
	Section13_Movie* FoundMovie = Section13_Movies::FindMovie(MovieName);
	if (FoundMovie)
	{
		cout << "Incrementing Watch count of " << MovieName << " movie" << endl;
		FoundMovie->IncrementWatchCount();
	}
	else
	{
		cout << "Aborting incrementing movie count due to error" << endl;
	}
}

Section13_Movie::Section13_Movie(const std::string& MovieName, MovieRating Rating, int WatchedCount)
	:MovieName(MovieName),Rating(Rating),WatchedCount(WatchedCount)
{
	cout << "Constructed movie with name: " << this->MovieName << " and watched count: " << this->WatchedCount << endl;
}

Section13_Movie* Section13_Movies::FindMovie(const std::string& MovieName)
{
	for (Section13_Movie* Movie : MoviesCollection)
	{
		const bool bFoundMovie = Movie->GetMovieName() == MovieName;
		
		if (bFoundMovie)
		{
			return Movie;
		}
	}
	cout << "The movie called: " << MovieName << " does not exist in the database." << endl;
	return nullptr;
};

void Section13_Movies::DisplayAllMovies()
{
	cout << "Your movies are: " << endl;
	for (Section13_Movie* Movie : MoviesCollection)
	{
		cout << "~~~~~~ "<< endl;
		cout << "Name: " << Movie->GetMovieName() << endl;
		cout << "Rating: " << Movie->GetRatingAsString() << endl;
		cout << "WatchCount: " << Movie->GetWatchCount() << endl;
	}
	cout << "~~~~~~ " << endl;
}

std::string Section13_Movie::GetRatingAsString() const
{
	switch (Rating)
	{
	case G:
		return "G";
		break;
	case PG:
		return "PG";
		break;
	case PG13:
		return "PG13";
		break;
	case R:
		return "R";
		break;
	case NONE:
		return "Invalid";
		break;
	default:
		return "Invalid";
		break;
	}
}

void Section14::Exec()
{
	cout << "~~~~~~~~~~~ Section 14 ~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	Section14_OverloadingStringExample::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section14_OverloadingStringExample::Exec()
{
	cout << "This example shows how to overload operator " << endl;
	Section14_MyString EmptyString;
	Section14_MyString Jan{ "Jan" };
	Section14_MyString Jan2{ Jan }; //copy cstr

	EmptyString.Display();
	Jan.Display();
	Jan2.Display();

	Jan = "Pawel"; //RValue
	Jan2 = Jan; //LValue
	Jan2 = Section14_MyString{"SomeRValueString"}; //RValue
	EmptyString = Section14_MyString{"AssignedToEmpty"}; //RValue
	Jan.Display();
	Jan2.Display();
	EmptyString.Display();
	Section14_MyString AdditionLowerString = -(Jan2 + EmptyString);
	AdditionLowerString.Display();
	
	cout << "Now pass your string: " << endl;
	Section14_MyString UserInputString;

	//cin >> UserInputString;
	//cout << "Your string is: " << UserInputString;
}

Section14_MyString::Section14_MyString()
	:StringPtr{nullptr}
{
	StringPtr = new char[1];
	*StringPtr = '\0';
}


Section14_MyString::Section14_MyString(const char* String)
	:StringPtr{nullptr}
{
	if (!String)
	{
		StringPtr = new char [1];
		*StringPtr = '\0';
	}
	else
	{
		StringPtr = new char[strlen(String) + 1];
		strcpy(StringPtr, String);
	}
}

Section14_MyString::Section14_MyString(const Section14_MyString& Source) 
	:StringPtr{nullptr}
{
	StringPtr = new char[strlen(Source.StringPtr) + 1];
	strcpy(StringPtr, Source.StringPtr);
}

Section14_MyString::~Section14_MyString() 
{
	delete[] StringPtr;
}

void Section14_MyString::Display() const 
{
	cout << StringPtr << ", lenght: " << GetLenght() <<  endl;
}

int Section14_MyString::GetLenght() const
{
	return strlen(StringPtr);
}

const char* Section14_MyString::GetString() const
{
	return StringPtr;
}

Section14_MyString& Section14_MyString::operator=(const Section14_MyString& Rhs)
{
	cout << "Using overloaded = operator - Copy ctsr" << endl;
	if (this == &Rhs)
	{
		return *this;
	}
	
	delete[] StringPtr;

	StringPtr = new char[strlen(Rhs.StringPtr) + 1];
	strcpy(StringPtr, Rhs.StringPtr);
	
	return *this; //this allows chain assignment s1 = s2 = s3
};

Section14_MyString& Section14_MyString::operator=(Section14_MyString&& Rhs) noexcept
{
	cout << "Using overloaded = operator - Move ctsr" << endl;
	if (this == &Rhs)
	{
		return *this;
	}

	delete[] StringPtr;
	StringPtr = Rhs.StringPtr;
	
	Rhs.StringPtr = nullptr;
	return *this;
}


Section14_MyString Section14_MyString::operator+(const Section14_MyString& Rhs) const
{
	cout << "Using overloaded + operator" << endl;

	const size_t BufferSize = strlen(StringPtr) + strlen(Rhs.StringPtr) + 1;

	char* Buffer = new char[BufferSize];

	strcpy(Buffer, StringPtr);
	strcat(Buffer, Rhs.StringPtr);
		
	Section14_MyString TempString {Buffer};
	delete[] Buffer;
	return TempString;	
}

bool Section14_MyString::operator==(const Section14_MyString& Rhs) const
{
	cout << "Using overloaded == operator" << endl;

	return strcmp(StringPtr, Rhs.StringPtr) == 0 ? true : false;
}

Section14_MyString Section14_MyString::operator-()const
{
	cout << "Using overloaded - operator" << endl;
	char* Buffer = new char[strlen(StringPtr) + 1];
	strcpy(Buffer, StringPtr);
	
	for (size_t i = 0; i < strlen(Buffer); i++)
	{
		Buffer[i] = tolower(Buffer[i]);
	}
	Section14_MyString TempString {Buffer};
	delete[] Buffer;
	return TempString;
}

std::ostream& operator<<(std::ostream& OutputStream, const Section14_MyString& Obj)
{
	OutputStream << Obj.StringPtr;
	return OutputStream;
}

std::istream& operator>>(std::istream& InputStream, Section14_MyString& Obj)
{
	// Need to revisit it in the future, for some reason it does not compile on my current version of MSVC and VS
	//char* Buffer = new char[1000];
	//InputStream >> *Buffer;
	//
	//if (InputStream.get(*Buffer))
	//{
	//	cout << "AAA";
	//}
	//Obj = Section14_MyString{Buffer};

	//delete[] Buffer;
	//return InputStream;
	return InputStream;
}