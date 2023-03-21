// Copyright Jakub Urbanek. All Rights Reserved.

#pragma once
#include <string>
#include <vector>

/* Examples3 contains sections 13-14 of the course*/

/*OOP - Classes and Objects*/
class Section13
{
public:
	Section13();

private:
	void SubClass_Create() const;
	void ConstrDestrTest() const;
	void CopyClassConstr() const;
	void PassObjectByValue(class ConstructorDestructor ConstrObj) const;
};

class Section13_SubClass
{
public:
	void UpdateExampleInt1(int NewValue);

private:
	int ExampleInt1 {3};
};

class ConstructorDestructor
{
public:
	ConstructorDestructor(int NewHealth = 100);
	ConstructorDestructor(int NewHealth, int NewStamina);
	ConstructorDestructor(int NewHealth, int NewStamina, int NewMana);
	ConstructorDestructor(const ConstructorDestructor& Source); //Copy constructor, called when object is copied
	~ConstructorDestructor();

	void SetTestClassHealth(int NewValue) { Health = NewValue; };
private:
	int Health {100};
	int Stamina {100};
	int Mana {100};
};

class Section13_ShallowVSDeepExample 
{
public:
	static void Exec();
private:
	static void DisplayNumberCopyObj(class Section13_ShallowCopy CopiedClass);
	static void DisplayNumberCopyObj(class Section13_DeepCopy CopiedClass);

};

class Section13_ShallowCopy
{
public:
	Section13_ShallowCopy(int SomeNumber);
	~Section13_ShallowCopy();
	Section13_ShallowCopy(const Section13_ShallowCopy& Source);

	void SetPtrValue(int NewValue) { *IntPtr = NewValue; };
	int GetPtrValue() const { return *IntPtr; };

private:
	int* IntPtr;
};

class Section13_DeepCopy
{
public:
	Section13_DeepCopy(int SomeNumber);
	~Section13_DeepCopy();
	Section13_DeepCopy(const Section13_DeepCopy& Source);

	void SetPtrValue(int NewValue) { *IntPtr = NewValue; };
	int GetPtrValue() const { return *IntPtr; };

private:
	int* IntPtr;

};

class Section13_LRValueRefs
{
public:
	static void Exec();

private:
	static void PrintLValueRef(const int& LValue);
	static void PrintRValueRef(const int&& RValue);
};

class Section13_MoveContructor
{
public:
	Section13_MoveContructor(int SomeNumber);
	~Section13_MoveContructor();
	Section13_MoveContructor(const Section13_MoveContructor& Source);
	Section13_MoveContructor(Section13_MoveContructor&& Source) noexcept; //This is a move constructor. Used when passing this obj as RValue

	void SetPtrValue(int NewValue) { *IntPtr = NewValue; };
	int GetPtrValue() const  { return *IntPtr; };

private:
	int* IntPtr;
};

class Section13_StaticClassExamples
{
public:
	static void Exec();
};

class Section13_StaticClassMembers
{
public:
	Section13_StaticClassMembers();
	~Section13_StaticClassMembers();
	static inline int GetNumberOfMembers() { return NumberOfMembers; };
	static void PrintOutVectorMembers();

private:
	static int NumberOfMembers;
	static std::vector<Section13_StaticClassMembers*> VectorOfMembers;
};

class Section13_Friend
{
public:
	static void Exec();

private:
	friend void ConstructorDestructor::SetTestClassHealth(int NewValue);

	// TODO: revisit this example in the future
	ConstructorDestructor* TestClass;
};

class Section13_Challenge
{
public:
	static void Exec();
};

enum MovieRating :int
{
	G,
	PG,
	PG13,
	R,
	NONE
};

class Section13_Movie
{
public:
	Section13_Movie(const std::string& MovieName, MovieRating Rating, int WatchedCount);
	std::string GetMovieName() const { return MovieName; };
	int GetWatchCount() const { return WatchedCount; }
	std::string GetRatingAsString() const;

	void IncrementWatchCount() { ++WatchedCount; };

private:
	std::string MovieName{"None"};
	MovieRating Rating{ MovieRating::NONE };
	int WatchedCount{0};
};


class Section13_Movies
{
public:
	static void AddMovieToCollection(const std::string& MovieName, MovieRating Rating, int WatchedCount);
	static void IncrementWatchCount(const std::string& MovieName);
	static Section13_Movie* FindMovie(const std::string& MovieName);
	static void DisplayAllMovies();
private:
	static std::vector<Section13_Movie*> MoviesCollection;
};

/*Operator overloading*/
class Section14
{
public:
	static void Exec();
};

class Section14_OverloadingStringExample
{
public:
	static void Exec();
};


class Section14_MyString
{
public:

	friend std::ostream& operator<<(std::ostream& OutputStream, const Section14_MyString& Obj);
	friend std::istream& operator>>(std::istream& InputStream, Section14_MyString& Obj);

	Section14_MyString();
	Section14_MyString(const char* String);
	Section14_MyString(const Section14_MyString& Source);
	~Section14_MyString();

	Section14_MyString& operator=(const Section14_MyString& Rhs);
	Section14_MyString& operator=(Section14_MyString&& Rhs) noexcept;
	Section14_MyString operator+(const Section14_MyString& Rhs) const;
	Section14_MyString operator-()const; //makes lowercase
	bool operator==(const Section14_MyString& Rhs) const;

	void Display() const;
	int GetLenght() const;
	const char* GetString() const;
private:
	char* StringPtr;
};