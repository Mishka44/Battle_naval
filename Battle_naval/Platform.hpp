#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>



class Platform {
public:
    static void Init();
    static void CleanScreen();
    static void Sleep(int s);
    void Set_ships_count();
    int get_count1();
    int get_count2();
    void Set_count1(int num);
    void Set_count2(int num);
private:
    int count_1;
    int count_2;
    

};

enum class CellType
{
    None,
    Type0, // 0
    Ship, // 1
    TypeQ, // ?
    Hit, // *
    Miss, // x

};

//std::ostream& operator<<(std::ostream& os, const CellType& c)
//{
//    switch (c) {
//    case CellType::None: os << ' '; break;
//    case CellType::Type0: os << '0'; break;
//    case CellType::Ship: os << '1'; break;
//    case CellType::TypeQ: os << '?'; break;
//    case CellType::Hit: os << '*'; break;
//    case CellType::Miss: os << 'x'; break;
//    }
//    return os;
//}








#endif // !PLATFORM_HPP