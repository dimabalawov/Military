#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Vehicle
{
protected:
	double tank;
	double petrol;
	bool isOnBase=0;
public:
	Vehicle() = default;
	Vehicle(double t, double p)
	{
		tank = t;
		petrol = p;
	}
	double getTankVolume()
	{
		return tank;
	}
	double getPetrolAmount()
	{
		return petrol;
	}
	void arrive(Base& a)
	{
		if (isOnBase)
		{
			cout << "The vehicle is already on the base\n";
			return;
		}
		isOnBase = 1;
		a.addPeople(1);
		a.addVehicle(1);
	}
	void leave(Base& a)
	{
		if ((tank - petrol) > a.getPetrol())
		{
			cout << "Vehicle cannot fill up the tank\n";
			return;
		}
		if (!isOnBase)
		{
			cout << "The vehicle is not on thebase\n";
			return;
		}
		if (a.getPeople() == 0)
		{
			cout << "No people on the base\n";
			return;
		}
		while (petrol < tank)
		{
			petrol++;
			a.addPetrol(-1);
		}
		isOnBase = 0;
		a.addPeople(-1);
		a.addVehicle(-1);
	}
};

