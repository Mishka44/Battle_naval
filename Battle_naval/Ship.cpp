#include "Ship.hpp"

void Ship::Set_x(int new_x) {
	x_ = new_x;
}

void Ship::Set_y(int new_y)
{
	y_ = new_y;
}

void Ship::Set_len(int new_len)
{
	len_ = new_len;
}

int Ship::Get_x()
{
	return this->x_;
}

int Ship::Get_y()
{
	return this->y_;
}

int Ship::Get_len()
{
	return this->len_;
}
