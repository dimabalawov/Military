

#include <iostream>
using namespace std;
#include "Bus.h"
#include "Truck.h"
#include "Vehicle.h"
#include "Base.h"

int main()
{
	Base base;
	Bus a(100,100,20,10);
	Truck b(100, 100, 50, 100);
	Vehicle c(50, 30);
	a.arrive(base);
	b.arrive(base);
	base.Info();
	b.leave(base);
	base.Info();
}

