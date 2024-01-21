#ifndef FIELD_HPP
#define FIELD_HPP

# include "Platform.hpp"
#include "Ship.hpp"

class Field
{
public:
    CellType Get(int x, int y) const;
    void set(int x, int y, const CellType v);
    void fill(const CellType el);
    void Show();

    int get_width() const;
    int get_height() const;
private:
    static const int width = 10;
    static const int height = 10;
    CellType m_field[width][height];
    
};


#endif // !FIELD_HPP