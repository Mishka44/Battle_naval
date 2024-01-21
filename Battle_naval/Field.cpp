# include "Field.hpp"


std::ostream& operator<<(std::ostream& os, const CellType& c)
{
    switch (c) {
    case CellType::None: os << ' '; break;
    case CellType::Type0: os << '0'; break;
    case CellType::Ship: os << '1'; break;
    case CellType::TypeQ: os << '?'; break;
    case CellType::Hit: os << '*'; break;
    case CellType::Miss: os << 'x'; break;
    }
    return os;
}



CellType Field::Get(int x, int y) const
{
    { return m_field[x][y]; }
}

void Field::set(int x, int y, const CellType v)
{
    { m_field[x][y] = v; };
}

void Field::fill(const CellType el) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            m_field[i][j] = el;
        }
    }
}

void Field::Show(){
        std::cout << "\n";
        std::cout << "\n";
        //создание и заполнение таблиц
        std::cout << ' ';
        for (int y = 0; y < this->get_width(); y++) {
            std::cout << " " << y;
            //отвечает за столбцы первой таблицы
        }

        std::cout << "\n";
        for (int i = 0; i < this->get_width(); i++) {
            std::cout << i;
            for (int j = 0; j < this->get_width(); j++) {
                std::cout << "|" << this->Get(i, j);
            }
            std::cout << "|" << "\n";
        }
}

int Field::get_width() const
{
    return width;
}

int Field::get_height() const
{
    { return height; }
}


