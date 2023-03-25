// Copyright Jakub Urbanek. All Rights Reserved.
#include <memory>
#pragma once

/* Examples4 contains sections 15,16 and 17 of the course*/

/* Inheritance */

class Section15
{
public:
	static void Exec();
};


class S15_Inheritance 
{
public:
	static void Exec();
};

class S15_Base
{
public:
	S15_Base();
	~S15_Base();
	int PublicInt {10};
	void PublicFunction();
	virtual void PublicVirtualFunction();
	void PrintIntValues();

protected:
	int ProtectedInt {10};
	void ProtectedFunction();
	virtual void ProtectedVirtualFunction();

private:
	int PrivateInt {10};
	void PrivateFunction();
	virtual void PrivateVirtualFunction();
};

class S15_Derived : public S15_Base
{
public:
	S15_Derived();
	~S15_Derived();
	virtual void PublicVirtualFunction() override;

protected:
	virtual void ProtectedVirtualFunction() override;

private:
	virtual void PrivateVirtualFunction() override;
};

class S15_CopyMoveOperator
{
public:
	static void Exec();
};

class S15_CopyMove_Base
{
public:
	S15_CopyMove_Base(int InNumber);
	~S15_CopyMove_Base();
	S15_CopyMove_Base(const S15_CopyMove_Base& Source);
	S15_CopyMove_Base(S15_CopyMove_Base&& Source) noexcept;
	S15_CopyMove_Base& operator=(const S15_CopyMove_Base& Rhs);
	S15_CopyMove_Base& operator=(S15_CopyMove_Base&& Rhs) noexcept;

protected:
	int* SomeInt {0};
};


class S15_CopyMove_Derived : S15_CopyMove_Base
{
public:
	S15_CopyMove_Derived(int Number);
	~S15_CopyMove_Derived();

	// Sidenote: If you do not provide them in derived class then they will be called automatically on the "base" classs
	S15_CopyMove_Derived(const S15_CopyMove_Derived& Source);
	S15_CopyMove_Derived(S15_CopyMove_Derived&& Source) noexcept;
	S15_CopyMove_Derived& operator=(const S15_CopyMove_Derived& Rhs);
	S15_CopyMove_Derived& operator=(S15_CopyMove_Derived&& Rhs) noexcept;
};


/* Polymorphism */

class Section16
{
public:
	static void Exec();
};

class Section16_AccountExample
{
public:
	static void Exec();
};

class S16_Acccount
{
public:
	virtual ~S16_Acccount();
	virtual void Withdraw() const;
	static void WithdrawbyRef(const S16_Acccount& Account);
	virtual void OverridableFunction() const;
	void NonVirtualFunction() const;
};


class S16_SubAccountA : public S16_Acccount
{
public:
	~S16_SubAccountA();
	virtual void Withdraw() const;
	static void WithdrawbyRef(const S16_Acccount& Account);
	virtual void OverridableFunction() const override;
	void NonVirtualFunction() const;
};

class S16_SubAccountB : public S16_Acccount
{
public:
	virtual void Withdraw() const;
};


class S16_SubAccountC : public S16_SubAccountA
{
public:
	virtual void OverridableFunction() const final;
};

class S16_SubAccountD final : public S16_SubAccountC
{
public:
	/*virtual void OverridableFunction() override; expected error as the function is final now */
};


class S16_Shape
{
public:
	virtual void Draw() = 0; // pure virtual function, can be used as an interface
	virtual ~S16_Shape() = default;
};

class IShapeMath
{
public:
	inline virtual float GetSurfaceArea() const = 0; 
	inline virtual float GetPerimeter() const  = 0;
	virtual ~IShapeMath() = default;
};

class S16_Square : public S16_Shape, IShapeMath
{
public:
	virtual void Draw() override {/* std::cout << "Square" << std::endl; */};
	inline virtual float GetSurfaceArea() const override { return Width * Height; };
	inline virtual float GetPerimeter() const override { return 2 * Width + 2 * Height; };

private:
	float Width {0};
	float Height {0};
};

class S16_Circle : public S16_Shape, IShapeMath
{
public:
	virtual void Draw() override {/* std::cout << "Circle" << std::endl;*/ };
	inline virtual float GetSurfaceArea() const override { return 3.14 * Radius * Radius; };
	inline virtual float GetPerimeter() const override { return 2 * 3.14 * Radius; };

private:
	float Radius {0};
};

class Section17
{
public:
	static void Exec();
};

class S17_SmartPtrs
{
public:
	static void Exec();
private:
	static void UniquePtrExample();
	static void SharedPtrExample();
	static void WeakPtrExample();
};

class S17_WeakerClass;

class S17_StrongerClass
{
public:
	S17_StrongerClass();
	~S17_StrongerClass();
	inline void SetPtrToWeaker (std::shared_ptr<S17_WeakerClass>& Weaker) { PtrToWeaker = Weaker; };
	std::shared_ptr<S17_WeakerClass> PtrToWeaker;
};

class S17_WeakerClass
{
public:
	S17_WeakerClass();
	~S17_WeakerClass();
	inline void SetPtrToStronger (std::shared_ptr<S17_StrongerClass>& Stronger) { PtrToStronger = Stronger; };
	std::weak_ptr<S17_StrongerClass> PtrToStronger; // having weak_ptr breaks strong relationship
};