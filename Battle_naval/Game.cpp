#include "Game.hpp"

void Game::generate_bot_ships()
{
    short l;
    //бот расставляет корабли
    for (auto& el : ships->getShips())
    {
        if (el->Get_len() == 1) {
            field_a->set(el->Get_x(), el->Get_y(), CellType::Ship);
            Platform::Sleep(200);
        }
        else if (el->Get_len() == 2) {
            int u = 0;
            l = 0;
            while (u != 1) {
                if (el->Get_x() - 1 <= 9 && el->Get_y() - 1 <= 9) {
                    if (field_a->Get(el->Get_x(), el->Get_y())
                        != CellType::Ship && field_a->Get(el->Get_x() - 1, el->Get_y()) != CellType::Ship) {
                        field_a->set(el->Get_x(), el->Get_y(), CellType::Ship);
                        field_a->set(el->Get_x() - 1, el->Get_y(), CellType::Ship);
                        u = 1;
                    }
                }
            }
            Platform::Sleep(200);
        }
    }
}

void Game::Battle()
{
    field_a->fill(CellType::TypeQ);
    field_b->fill(CellType::TypeQ);
    Platform::Sleep(2000);
    Platform::CleanScreen();
    field_a->Show();
    while (this->hit_counter < (this->count_ship+(this->count_ship2)*2) ) {
        this->attack();

    }
    std::cout << "Поздравляем! вы подбили все корабли!" << "\n";
    std::cout << "количетсво ударов: " << this->hitting_field + this->hit_counter << "\n";
    std::cout << "количество попаданий: " << this->hit_counter << "\n";
    std::cout << "спасибо за игру!";
    
    
}

void Game::attack()
{
        int hit_x, hit_y;
        std::cout << "делайте ход, введитекоординаты\n";
        std::cout << "Введите номер столбца:"; std::cin >> hit_x;
        std::cout << "Введите номер строки: "; std::cin >> hit_y;
        if (field_a->Get(hit_x, hit_y) == CellType::Ship) {
            this->Strike(hit_x, hit_y);
        }
        else {
            this->Miss(hit_x, hit_y);
        }
        Platform::CleanScreen();
        field_b->Show();

}

void Game::Strike(int x, int y)
{
    field_b->set(x, y, CellType::Hit);
    std::cout << '\n';
    std::cout << "вы попали!" << "\n";
    this->hit_counter++;
    this->hitting_field++;
}

void Game::Miss(int x, int y)
{
    field_b->set(x, y, CellType::Miss);
    std::cout << "вы промахнулись" << "\n";
    this->hitting_field++;
}
