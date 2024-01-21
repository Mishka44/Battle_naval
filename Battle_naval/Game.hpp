#ifndef GAME_HPP
#define GAME_HPP

#include "Platform.hpp"
#include "Field.hpp"
#include "Ship.hpp"
#include "Ship_kipper.hpp"

class Game{
public:
	friend bool Check_input(int num1, int num2);

	Game(Field* obj, Field* obj_2, ship_kipper* arr, int num_ships1, int num_ships2 )
		: field_a(obj_2), field_b(obj),ships(arr), count_ship(num_ships1), count_ship2(num_ships2){
		hit_counter = 0;
		hitting_field = 0;
	}
	void generate_bot_ships();
	
	void Battle();

	void attack();

	void Strike(int x, int y);
	void Miss(int x, int y);
	~Game();


private:
	Field* field_a;
	Field* field_b;
	ship_kipper* ships;
	int hit_counter;
	int hitting_field;
	int count_ship;
	int count_ship2;
	
	

};


#endif // !GAME_HPP

