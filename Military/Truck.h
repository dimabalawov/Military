#pragma once
#include "Vehicle.h"
#include "Base.h"
class Truck:public Vehicle
{
	double goods;
	double max_goods;
public:
	Truck() = default;
	Truck(double t, double p,double g,double maxg)
	{
		Vehicle(t, p);
		goods = g;
		max_goods = maxg;
	}
	double getGoods()
	{
		return goods;
	}
	double getMaxGoods()
	{
		return max_goods;
	}
	void arrive(Base& a)
	{
		if (isOnBase)
		{
			cout << "The vehicle is already on the base\n";
			return;
		}
		isOnBase = 1;
		a.addGoods(goods);
		goods = 0;
		a.addVehicle(1);
		a.addPeople(1);
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
		while (a.getGoods() > 0 && goods < max_goods)
		{
			a.addGoods(-1);
			goods++;
		}
		isOnBase = 0;
		a.addVehicle(-1);
		a.addPeople(-1);
	}
};

