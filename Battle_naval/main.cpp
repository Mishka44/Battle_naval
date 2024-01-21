
#include "Field.hpp"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Game.hpp"
#include "Field.hpp"
#include "Ship_kipper.hpp"
#include "Platform.hpp"

int main() {
	Platform::Init();
	Field fil;
	Field fil2;
	int a, b;
	//Platform t;
	//t.Set_ships_count();
	std::cout << "для начала введите количество однопалубных кораблей (в пределах от 1 до 5): ";
	std::cin >> a;
	std::cout << "\n";
	std::cout << "теперь введите количество двупалубных кораблей (в пределах от 1 до 2): ";
	std::cin >> b;
	ship_kipper ships(a, b);
    fil.fill(CellType::TypeQ);
    fil2.fill(CellType::Type0);
    Game game(&fil, &fil2, &ships,1,2);
    game.Battle();
    return 0;
}

