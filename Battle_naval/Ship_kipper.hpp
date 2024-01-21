#ifndef SHIPKIPPER_HPP
#define SHIPKIPPER_HPP
#include "Ship.hpp"
#include "Platform.hpp"


class ship_kipper {
public:
	ship_kipper(int count_1, int count_2);

	void Set_cor();

	const std::vector<Ship*>& getShips() const;
	const int get_size_ship() const;

	~ship_kipper();

private:
	std::vector<Ship*> Ships;

};



#endif // !SHIP_KIPPER_HPP