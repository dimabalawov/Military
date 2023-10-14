#pragma once
#include "Vehicle.h"
#include "Base.h"
class Bus :public Vehicle
{
	int max_passengers;
	int passengers;
public:
	Bus() = default;
	Bus(double t, double p, int mp,int pas)
	{
		Vehicle(t, p);
		max_passengers = mp;
		passengers = pas;
	}
	virtual int getMaxPas()
	{
		return max_passengers;
	}
	int getPass()
	{
		return (passengers - 1);
	}
	void arrive(Base& a)
	{
		if (isOnBase)
		{
			cout << "The vehicle is already on the base\n";
			return;
		}
		isOnBase = 1;
		a.addPeople(passengers);
		passengers = 0;
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
			cout << "The vehicle is not onto base\n";
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
		while (a.getPeople() > 0 && passengers < max_passengers)
		{
			a.addPeople(-1);
			passengers++;
		}
		isOnBase = 0;
		a.addVehicle(-1);
	}
};

