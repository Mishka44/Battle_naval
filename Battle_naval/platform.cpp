#include "Platform.hpp"

void Platform::Init() { setlocale(LC_ALL, "rus"); }
void Platform::CleanScreen() { system("cls"); }
void Platform::Sleep(int s) { ::Sleep(s); }

void Platform::Set_ships_count()
{
	int  tmp1, tmp2;
	std::cout << "����� ���������� � ������� ���!" << "\n";
	std::cout << "��� ������ ������� ���������� ������������ �������� (� �������� �� 1 �� 5): ";
	std::cin >> tmp1;
	std::cout << "\n";
	std::cout << "������ ������� ���������� ����������� �������� (� �������� �� 1 �� 2): ";
	std::cin >> tmp2;
	int tu = 10;
	while (tu != 0) {
		tu = 0;
		if (tmp1 > 5 || tmp2 > 3) {
			tu = 1;
			std::cout << "�������� �������� ��������, ���������� �����";
			Platform::Sleep(2000);
			Platform::CleanScreen();
			Set_ships_count();
		}
		else if (tmp1 < 1 || tmp2 < 0) {
			tu = 1;
			std::cout << "�������� �������� ��������, ���������� �����";
			Platform::Sleep(2000);
			Platform::CleanScreen();
			Set_ships_count();
		}
	}
	this->Set_count1(tmp1);
	this->Set_count1(tmp2);
	std::cout << "�� ������� ����� ��� ������!";
	std::cout << "\n";
}
	


int Platform::get_count1()
{
	return this->count_1;
}

int Platform::get_count2()
{
	return this->count_2;
}

void Platform::Set_count1(int num)
{
	this->count_1 = num;
}

void Platform::Set_count2(int num)
{
	this->count_2 = num;
}







