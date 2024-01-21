#ifndef SHIP_HPP
#define SHIP_HPP

#include"Platform.hpp"


class Ship {
public:
	
	Ship(int len):len_(len){}

	void Set_x(int new_x);
	void Set_y(int new_y);
	void Set_len(int new_len);
	

	int Get_x();
	int Get_y();
	int Get_len();
	

	//~Ship();

private:
	int x_;
	int y_;
	int len_;
	
};


#endif // !SHIP_HPP
