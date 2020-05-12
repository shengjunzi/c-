#include<Windows.h>
#include<iostream>
#include"point1.h"
void SetCursorPosition(const int x, const int y) {
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void point::print()
{

	SetCursorPosition(x, y);
	std::cout << "¡ö";

}
void point::Printcl()
{
	SetCursorPosition(x, y);
	std::cout << "¡ñ";
}
void point::clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}
void point::change(const int x, const int y)
{
	this->x = x;
	this->y = y;
}