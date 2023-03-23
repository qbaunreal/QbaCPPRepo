// Copyright Jakub Urbanek. All Rights Reserved.

#include "Examples4.h"
#include "SharedTemplates.h"


using namespace SharedTemplates;
using namespace std;

void Section15::Exec()
{
	cout << "~~~~~~~~~~~ Section 15 ~~~~~~~~~~~~" << endl;
	/*S15_Inheritance::Exec();*/
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	S15_CopyMoveOperator::Exec();
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S15_Inheritance::Exec()
{
	S15_Base* S15_BaseObj = new S15_Base{};
	delete S15_BaseObj;
	cout << "Constructing inherited obj " << endl;
	S15_Derived* S15_DerivedObj = new S15_Derived{};
	delete S15_DerivedObj;
}

S15_Base::S15_Base()
{
	cout << "Constructing class that is base " << endl;
	PublicFunction();
	cout << "~~~~" << endl;
	PublicVirtualFunction();
	cout << "~~~~" << endl;
	ProtectedFunction();
	cout << "~~~~" << endl;
	ProtectedVirtualFunction();
	cout << "~~~~" << endl;
	PrivateFunction();
	cout << "~~~~" << endl;
	PrivateFunction();
	cout << "~~~~" << endl;
}

S15_Base::~S15_Base()
{
	cout << "Base class destructor" << endl;
}

void S15_Base::PublicFunction()
{
	cout << "PublicFunction called" << endl;
	PublicInt = 1;
	ProtectedInt = 2;
	PrivateInt = 3;
	cout << "Public int: " << PublicInt << endl;
	cout << "ProtectedInt int: " << ProtectedInt << endl;
	cout << "PrivateInt int: " << PrivateInt << endl;
}

void S15_Base::PublicVirtualFunction()
{
	cout << "PublicVirtualFunction called" << endl;
	PublicInt = 4;
	ProtectedInt = 5;
	PrivateInt = 6;
	cout << "Public int: " << PublicInt << endl;
	cout << "ProtectedInt int: " << ProtectedInt << endl;
	cout << "PrivateInt int: " << PrivateInt << endl;
}

void S15_Base::PrintIntValues()
{
	cout << "Public int: " << PublicInt << endl;
	cout << "ProtectedInt int: " << ProtectedInt << endl;
	cout << "PrivateInt int: " << PrivateInt << endl;
}

void S15_Base::ProtectedFunction()
{
	cout << "ProtectedFunction called" << endl;
	PublicInt = 7;
	ProtectedInt = 8;
	PrivateInt = 9;
	PrintIntValues();
}

void S15_Base::ProtectedVirtualFunction()
{
	cout << "ProtectedVirtualFunction called" << endl;
	PublicInt = 10;
	ProtectedInt = 11;
	PrivateInt = 12;
	PrintIntValues();
}
void S15_Base::PrivateFunction()
{
	cout << "PrivateFunction called" << endl;
	PublicInt = 13;
	ProtectedInt = 14;
	PrivateInt = 15;
	PrintIntValues();
}

void S15_Base::PrivateVirtualFunction()
{
	cout << "PrivateFunction called" << endl;
	PublicInt = 16;
	ProtectedInt = 17;
	PrivateInt = 18;
	PrintIntValues();
}

S15_Derived::S15_Derived()
	:S15_Base{} // calling base constructor
{
	cout << "Constructing class that derives " << endl;
	PublicFunction();
	cout << "~~~~" << endl;
	PublicVirtualFunction();
	cout << "~~~~" << endl;
	ProtectedFunction();
	cout << "~~~~" << endl;
	ProtectedVirtualFunction();
	cout << "~~~~" << endl;
	//PrivateFunction();  Private functions are not accesible
	//cout << "~~~~" << endl;
	//PrivateFunction();
	//cout << "~~~~" << endl;
}

S15_Derived::~S15_Derived()
{
	cout << "Derived class destructor" << endl;
}

void S15_Derived::PublicVirtualFunction() 
{
	S15_Base::PublicVirtualFunction();
	PublicInt = -1;
	ProtectedInt = -2;
	// PrivateInt = -3; Private members are not accesible
	PrintIntValues();
}

void S15_Derived::ProtectedVirtualFunction()
{
	S15_Base::ProtectedVirtualFunction();
	PublicInt = -4;
	ProtectedInt = -5;
	/*PrivateInt = -6;*/
	PrintIntValues();
}

void S15_Derived::PrivateVirtualFunction()
{
	/*S15_Base::PrivateVirtualFunction(); Inaccesible */
	PublicInt = -7;
	ProtectedInt = -8;
	/*PrivateInt = -9;*/
	PrintIntValues();
}

void S15_CopyMoveOperator::Exec()
{
	S15_CopyMove_Base* S15_CopyMove_BaseObj = new S15_CopyMove_Base{5};
	delete S15_CopyMove_BaseObj;
	
	S15_CopyMove_Derived* S15_CopyMove_DerivedObj = new S15_CopyMove_Derived{15};
	delete S15_CopyMove_DerivedObj;

	S15_CopyMove_Derived LValueObj {2137};
	S15_CopyMove_Derived AnotherDerivedObj = LValueObj;
	AnotherDerivedObj = 15;
}

S15_CopyMove_Base::S15_CopyMove_Base(int InNumber)
{
	cout << "Base Constuctor: " << InNumber << endl;
	SomeInt = new int;
	*SomeInt = InNumber;
}

S15_CopyMove_Base::~S15_CopyMove_Base()
{
	SomeInt = nullptr;
	delete SomeInt;
}

S15_CopyMove_Base::S15_CopyMove_Base(const S15_CopyMove_Base& Source)
{
	SomeInt = new int;
	*SomeInt = *(Source.SomeInt);
}

S15_CopyMove_Base::S15_CopyMove_Base(S15_CopyMove_Base&& Source) noexcept
	:SomeInt {Source.SomeInt}
{
	Source.SomeInt = nullptr;
	cout << "Move constructor has been called. Int value is: " << *SomeInt << endl;
}

S15_CopyMove_Base& S15_CopyMove_Base::operator=(const S15_CopyMove_Base& Rhs)
{
	cout << "Operator = Copy ctsr - base (LValue) " << endl;
	if (this == &Rhs)
	{
		return *this;
	}

	delete SomeInt;
	SomeInt = Rhs.SomeInt;

	return *this; 
}

S15_CopyMove_Base& S15_CopyMove_Base::operator=(S15_CopyMove_Base&& Rhs) noexcept
{
	cout << "Operator = Move ctsr - base (Rvalue) " << endl;
	if (this == &Rhs)
	{
		return *this;
	}

	delete SomeInt;
	SomeInt = Rhs.SomeInt;

	Rhs.SomeInt = nullptr;
	return *this;
}

S15_CopyMove_Derived::S15_CopyMove_Derived(int Number)
	:S15_CopyMove_Base(Number)
{
	cout << "Derived constructor " << endl;
	cout << "Derived int is: " << *SomeInt << endl;
}

S15_CopyMove_Derived::~S15_CopyMove_Derived()
{
	S15_CopyMove_Base::~S15_CopyMove_Base();
	cout << "Derived destructor " << endl;
}

S15_CopyMove_Derived::S15_CopyMove_Derived(const S15_CopyMove_Derived& Source)
	:S15_CopyMove_Base(Source)
{
	cout << "Derived copy ctr " << endl;
	cout << "Derived int is: " << *SomeInt << endl;
}

S15_CopyMove_Derived::S15_CopyMove_Derived(S15_CopyMove_Derived&& Source) noexcept
	:S15_CopyMove_Base(Source)
{
	cout << "Derived move ctr " << endl;
	cout << "Derived int is: " << *SomeInt << endl;
}

S15_CopyMove_Derived& S15_CopyMove_Derived::operator=(const S15_CopyMove_Derived& Rhs)
{
	cout << "Derived Operator = Copy ctsr - base (LValue) " << endl;

	S15_CopyMove_Base::operator=(Rhs);
	cout << "LValue Some Int: " << *SomeInt << endl;
	return *this;
}

S15_CopyMove_Derived& S15_CopyMove_Derived::operator=(S15_CopyMove_Derived&& Rhs) noexcept
{
	cout << "Derived Operator = Move ctsr - base (Rvalue) " << endl;
	S15_CopyMove_Base::operator=(Rhs);
	cout << "RValue Some Int: " << *SomeInt << endl;
	return *this;
}

void Section16::Exec()
{
	cout << "~~~~~~~~~~~ Section 16 ~~~~~~~~~~~~" << endl;
	Section16_AccountExample::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void Section16_AccountExample::Exec()
{
	S16_Acccount Account;
	cout << "Calling account instances functions " << endl;
	Account.Withdraw();
	Account.NonVirtualFunction();

	S16_SubAccountA SubAccountA;
	cout << "Calling Subaccount instances functions " << endl;
	SubAccountA.Withdraw();
	SubAccountA.NonVirtualFunction();

	cout << "Calling account pointer that points to new SubAccount" << endl;
	S16_Acccount* SubAccountAPtr = new S16_SubAccountA();
	SubAccountAPtr->NonVirtualFunction();
	SubAccountAPtr->Withdraw();
	delete SubAccountAPtr;

	S16_Acccount* SubAccountBPtr = new S16_SubAccountB();
	SubAccountBPtr->Withdraw();
	delete SubAccountBPtr;


	S16_SubAccountA SomeAccount{};
	S16_Acccount& RefToSomeAccount = SomeAccount;

	RefToSomeAccount.Withdraw();

	S16_SubAccountA::WithdrawbyRef(SomeAccount); //references are also dynamically bound

	S16_Shape* CircleShape = new S16_Circle();
	CircleShape->Draw(); //overrided pure virtual
	delete CircleShape;
}

S16_Acccount::~S16_Acccount()
{
	cout << "Virtual Destructor called on Account" << endl;
}

void S16_Acccount::Withdraw()
{
	cout << "Virtual Function called on Account" << endl;
}

void S16_Acccount::WithdrawbyRef(const S16_Acccount& Account)
{
	cout << "This is also dynamically bound" << endl;
}

void S16_Acccount::OverridableFunction()
{
}

void S16_Acccount::NonVirtualFunction()
{
	cout << "Function called on Account" << endl;
}

S16_SubAccountA::~S16_SubAccountA()
{
	cout << "Desrtucting subaccountA" << endl;
}

void S16_SubAccountA::Withdraw()
{
	cout << "Withdrawing money from account A" << endl;
}

void S16_SubAccountA::WithdrawbyRef(const S16_Acccount& Account)
{
	cout << "Withdraw called on subaccount" << endl;
}

void S16_SubAccountA::OverridableFunction()
{
	cout << "Withdraw called on S16_SubAccountA" << endl;
}

void S16_SubAccountA::NonVirtualFunction()
{
	cout << "Function called on SubAccountA" << endl;
}

void S16_SubAccountB::Withdraw()
{
	cout << "Withdrawing money from account B. Can have different logic here" << endl;
}

void S16_SubAccountC::OverridableFunction()
{
	cout << "Withdraw called on S16_SubAccountC" << endl;
}

void Section17::Exec()
{
	cout << "~~~~~~~~~~~ Section 17 ~~~~~~~~~~~~" << endl;
	S17_SmartPtrs::Exec();
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~ End of Section ~~~~~~~~~~~~" << endl << endl;
}

void S17_SmartPtrs::Exec()
{
	UniquePtrExample();
	SharedPtrExample();
	WeakPtrExample();
}

void S17_SmartPtrs::UniquePtrExample()
{
	vector <unique_ptr<int>> UniqPtrVector;

	unique_ptr<int> UniquePtr{ new int {100} };
	*UniquePtr = 200;
	int* TempPtr = UniquePtr.get(); //gets raw ptr
	TempPtr = nullptr;
	delete TempPtr;

	cout << *UniquePtr << endl;
	/*UniqPtrVector.push_back(UniquePtr); cannot copy because of the nature of uniqueptr */
	UniqPtrVector.push_back(move(UniquePtr)); //.. but can move it

	//no need to delete it

	unique_ptr<int> UniquePtr2 = make_unique<int>(100); // another way of creating uniqptr, more efficient since c++14
}

void S17_SmartPtrs::SharedPtrExample()
{
	vector <shared_ptr<int>> SharedPtrVector;
	shared_ptr<int> SharedPtr = make_shared<int>();
	shared_ptr<int> SharedPtr2{ SharedPtr };
	shared_ptr<int> SharedPtr3{ SharedPtr2 };

	cout << "SharedPtr count: " << SharedPtr.use_count() << endl;
	cout << "SharedPtr2 count: " << SharedPtr2.use_count() << endl;
	cout << "SharedPtr3 count: " << SharedPtr3.use_count() << endl;

	cout << "Resetting 1.." << endl;
	SharedPtr.reset();
	cout << "SharedPtr count: " << SharedPtr.use_count() << endl;
	cout << "SharedPtr2 count: " << SharedPtr2.use_count() << endl;
	cout << "SharedPtr3 count: " << SharedPtr3.use_count() << endl;
	
	cout << "Resetting 2.." << endl;
	SharedPtr2.reset();
	cout << "SharedPtr count: " << SharedPtr.use_count() << endl;
	cout << "SharedPtr2 count: " << SharedPtr2.use_count() << endl;
	cout << "SharedPtr3 count: " << SharedPtr3.use_count() << endl;

	SharedPtrVector.push_back(SharedPtr); //can be cpied and moved
}

void Deleter(S17_WeakerClass* RawPtr) 
{
	cout << "Deleter function has been called" << endl;
};

void S17_SmartPtrs::WeakPtrExample()
{
	cout << "WeakPtr creates a weak reference (does not participate in owning whatsoever) : " << endl;

	std::shared_ptr<S17_StrongerClass> Stronger = std::make_shared<S17_StrongerClass>();
	std::shared_ptr<S17_WeakerClass> Weaker = std::make_shared<S17_WeakerClass>();
	Stronger->SetPtrToWeaker(Weaker); 
	Weaker->SetPtrToStronger(Stronger); //circular reference, not having weak ptrs makes it leak (circular reference is not being deleted)

	std::shared_ptr<S17_WeakerClass> DeleterTest {new S17_WeakerClass{}, Deleter};
	std::shared_ptr<S17_WeakerClass> LambdaDelete{ new S17_WeakerClass{},
		[](S17_WeakerClass* Ptr)
		{
			cout << "Calling Delete from lambda" << endl;
			delete Ptr;
		} 
	};


}

S17_StrongerClass::S17_StrongerClass()
{
	cout << "Stronger constructor" << endl;
}

S17_StrongerClass::~S17_StrongerClass()
{
	cout << "Stronger deconstructor" << endl;
}

S17_WeakerClass::S17_WeakerClass()
{
	cout << "Weaker constructor" << endl;
}

S17_WeakerClass::~S17_WeakerClass()
{
	cout << "Weaker deconstructor" << endl;
}
