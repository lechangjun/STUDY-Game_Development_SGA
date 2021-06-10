#include "stdafx.h"


class Animal
{
public:
	virtual void Eat() = 0;
	virtual void Sleep() { cout << "zzzzzzz......" << endl; }
};

class Dog : virtual public Animal
{
public:
	virtual void Bark() { cout << "Woof!" << endl; }
	virtual void Eat() override { cout << "The dog has eaten," << endl; }
};
class Bird : virtual public Animal
{
public:
	virtual void Chirp() { cout << "Chirp!" << endl; }
	virtual void Eat() override { cout << "The bird has eaten." << endl; }
};
class DogBird : public Dog, public Bird
{
public:
	virtual void Eat()
	{
		Dog::Eat();
	}

};
///////////////////////////////////////////////

class MilesEstimator
{
public:
	virtual int GetMilesLeft() const
	{
		return GetMilesPerGallon() * GetGallonLeft();
	}

	virtual void SetGallonLeft(int inValue) { mGallonLeft = inValue; }
	virtual int GetGallonLeft() const { return mGallonLeft; }

private:
	int mGallonLeft;
	virtual int GetMilesPerGallon() const { return 20; }
};

class EfficientCarMilesEstimator : public MilesEstimator
{
private:
	virtual int GetMilesPerGallon() const override { return 35; }
};

////////////////////////////////////////////////////////////////////

class Super
{
public:
	void Go() { cout << "Go() called on Super" << endl; }
};
class Sub : public Super
{
public:
	void Go() { cout << "Go() called on Sub" << endl; }
};
////////////////////////////////////////////////////////////////////////////////

class SuperStatic
{
public:
	static void BeStatic()
	{
		cout << "SuperStatic being static." << endl;
	}
};
class SubStatic : public SuperStatic
{
public:
	static void BeStatic()
	{
		cout << "SubStatic keepin ' it static." << endl;
	}
};



int main()
{
	//DogBird myConfusedAnimal;
	//myConfusedAnimal.Bark();
	//myConfusedAnimal.Chirp();

	//myConfusedAnimal.Eat();
	//myConfusedAnimal.Dog::Eat();

	//myConfusedAnimal.Sleep();


	//MilesEstimator myMilesEstimator;
	//myMilesEstimator.SetGallonLeft(2);
	//cout << "I can go " << myMilesEstimator.GetMilesLeft() << " more miles. " << endl;

	//EfficientCarMilesEstimator myEstimator;
	//myEstimator.SetGallonLeft(2);
	//cout << "I can go" << myEstimator.GetMilesLeft() << "more miles. " << endl;

	//Sub mySub;
	//mySub.Go();

	//Super& ref = mySub;
	//ref.Go();

	SuperStatic::BeStatic();
	SubStatic::BeStatic();

	SubStatic mySubStatic;
	SuperStatic& mySuperStatic = mySubStatic;
	mySubStatic.BeStatic();
	mySuperStatic.BeStatic();
}



