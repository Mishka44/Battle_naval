#include "Game.hpp"

bool Check_input(int num1, int num2) {
    return max(num1, num2) <= 9 && min(num1, num2) >= 0;
}

void Game::generate_bot_ships()
{
    short l;
    //��� ����������� �������
    for (auto& el : ships->getShips())
    {
        if (el->Get_len() == 1) {
            field_a->set(el->Get_x(), el->Get_y(), CellType::Ship);
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
        }
    }
}

void Game::Battle()
{
    /*field_a->fill(CellType::TypeQ);
    field_b->fill(CellType::Type0);*/
    std::cout << "����� ���������� � ������� ���!" << "\n";
    ships->Set_cor();
    generate_bot_ships();

    Platform::Sleep(2000);
    Platform::CleanScreen();
    std::cout << "���� ������� ����" << "\n";
    field_b->Show();
    while (this->hit_counter < (this->count_ship+(this->count_ship2)*2) ) {
        this->attack();
    }
    std::cout << "�����������! �� ������� ��� �������!" << "\n";
    std::cout << "���������� ������: " << this->hitting_field + this->hit_counter << "\n";
    std::cout << "���������� ���������: " << this->hit_counter << "\n";
    std::cout << "������� �� ����!";
    
    
}

void Game::attack()
{
        int hit_x, hit_y;
        std::cout << "\n";
        std::cout << "������� ���, ������� ����������\n";
        std::cout << "������� ����� ������:"; std::cin >> hit_x;
        std::cout << "������� ����� �������: "; std::cin >> hit_y;
        if (Check_input(hit_x, hit_y) == false) {
            std::cout << "�������� ����������, ���������� ��� ���!" << "\n";
            Platform::Sleep(2000);
            Platform::CleanScreen();
            field_b->Show();
            attack();
        }
        if (field_a->Get(hit_x, hit_y) == CellType::Ship) {
            this->Strike(hit_x, hit_y);
            std::cout << "�� ������!" << "\n";
        }
        else {
            this->Miss(hit_x, hit_y);
            std::cout << "�� ������������" << "\n";
        }
        Platform::Sleep(2000);
        Platform::CleanScreen();
        field_b->Show();

}

void Game::Strike(int x, int y)
{
    field_b->set(x, y, CellType::Hit);
    std::cout << '\n';
    this->hit_counter++;
    this->hitting_field++;
}

void Game::Miss(int x, int y)
{
    field_b->set(x, y, CellType::Miss);
    this->hitting_field++;
}


Game::~Game()
{
    delete field_a;
    delete field_b;
    delete ships;
}
