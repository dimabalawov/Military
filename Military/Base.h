#pragma once
#include <iostream>
using namespace std;
class Base
{
	int people;
	double goods;
	int vehicles;
	double petrol;
public:
	Base()
	{
		people = 0;
		goods = 0;
		vehicles = 0;
		petrol = 0;
	}
	void a(int a)
	{
		petrol += a;
	}
	int getPeople()
	{
		return people;
	}
	double getGoods()
	{
		return goods;
	}
	double getPetrol()
	{
		return petrol;
	}
	int getVehicles()
	{
		return vehicles;
	}
	void addPeople(int p)
	{
		people += p;
	}
	void addGoods(double g)
	{
		goods += g;
	}
	void addVehicle(int v)
	{
		vehicles+=v;
	}
	void addPetrol(double p)
	{
		petrol += p;
	}
	void Info()
	{
		cout << "People on base:" << people << endl;
		cout << "Vehicles on base:" << vehicles << endl;
		cout << "Goods on base:" << goods << endl;
		cout << "Petrol on base:" << petrol << endl;
		cout << "---------------" << endl;
	}
};

