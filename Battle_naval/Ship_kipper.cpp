#include "Ship_kipper.hpp"

ship_kipper::ship_kipper(int count_1, int count_2)
{
	for (size_t i = 0; i < count_1; i++)
	{
		this->Ships.push_back(new Ship(1));
	}
	for (size_t i = 0; i < count_2; i++)
	{
		Ships.push_back(new Ship(2));
	}
}

void ship_kipper::Set_cor()
{
	srand(time(NULL));
	for (auto& el : Ships)
	{
		int TAB = rand() % 10;
		int LINE = rand() % 10;
		el->Set_x(TAB);
		el->Set_y(LINE);
	}
}

const std::vector<Ship*>& ship_kipper::getShips() const
{
	return Ships;
}

const int ship_kipper::get_size_ship() const
{
	return Ships.size();
}

ship_kipper::~ship_kipper()
{
	for (auto e : Ships) {
		delete e;
	}
}
