
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
	Platform t;
	//t.Set_ships_count();
	ship_kipper ships(1, 2);
    fil.fill(CellType::TypeQ);
    fil2.fill(CellType::Type0);
    /*fil.Show();*/
    Game game(&fil, &fil2, &ships,1,2);
    game.Battle();
    return 0;
}
    /*Platform::Init();
    Field fil; 
    Field fil2;
    ship_kipper ships(1, 2);
    ships.Set_cor();
    fil.fill(CellType::TypeQ);
    fil2.fill(CellType::TypeQ);
    Bot bot(&ships, &fil);
    bot.generate_bot_ships();
    fil2.Show();*/






//int main()
//{
//    std::cout << "Hello World!\n";
//}

