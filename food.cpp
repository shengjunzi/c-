#include<iostream>
#include<cstdlib>
#include"food.h"

void Food::Drawfood(Snake& csnake)
{
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snakes)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))
				flag = true;
			break;
		}
		if (flag) continue;
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "¡ï";
		++cnt;
		cnt %= 5;
		if (cnt == 0)
		{
			Drawbigfood(csnake);
		}
		break;
	}
}
void Food::Drawbigfood(Snake& csnake)
{
	SetCursorPosition(5, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "-------------------------------------------";
	progress_bar = 42;
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snakes)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
			{
				flag = true;
				break;
			}

		}
		if (flag) continue;
		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "¡ö";
		big_flag = true;
		flash_flag = true;
		break;
	}

}
int Food::Getcnt()
{
	return cnt;
}
void Food::Flashbigfood()
{
	SetCursorPosition(big_x, big_y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	if (flash_flag)
	{
		std::cout << "  ";
		flash_flag = false;
	}
	else
	{
		std::cout << "¡ö";
		flash_flag = true;
	}
	SetCursorPosition(26, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	for (int i = 42; i >= progress_bar; --i)
		std::cout << "\b\b";
	--progress_bar;
	if (progress_bar == 0)
	{
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}

}
bool Food::Getbigflag()
{
	return big_flag;
}
int Food::Getprogress()
{
	return progress_bar;
}