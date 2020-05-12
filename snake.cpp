#include"snake.h"
#include<conio.h>
#include<iostream>

void Snake::Initsanke()
{
	for (auto& point : snakes)
	{
		point.Printcl();
	}

}
void Snake::Move()  //蛇增长
{
	switch (direction)
	{
	case Direction::UP:
		snakes.emplace_back(point(snakes.back().GetX(), snakes.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snakes.emplace_back(point(snakes.back().GetX(), snakes.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snakes.emplace_back(point(snakes.back().GetX() - 1, snakes.back().GetY()));
		break;
	case Direction::RIGHT:
		snakes.emplace_back(point(snakes.back().GetX() + 1, snakes.back().GetY()));
		break;
	default:break;

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	snakes.back().Printcl();
}
void Snake::Normalmove()
{
	Move();
	snakes.front().clear();
	snakes.pop_front();
}
bool Snake::OverEdge()
{
	return snakes.back().GetX() < 30 &&
		snakes.back().GetY() < 30 &&
		snakes.back().GetX() > 1 &&
		snakes.back().GetY() > 1;
}
bool Snake::HitItself()
{
	std::deque<point>::size_type cnt = 1;
	point* head = new point(snakes.back().GetX(), snakes.back().GetY());
	
	for (auto& point : snakes)
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snakes.size())
		return true;
	else
		return false;
}
bool Snake::ChangeDirection()
{
	char ch;
	if (kbhit())
	{
		ch = getch();
		switch (ch)
		{

			default:
		   ch = getch();
		   switch (ch)
		   {

		   case 72:
			   if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
				   direction = Direction::UP;
			   break;
		   case 80:
			   if (direction != Direction::UP)
				   direction = Direction::DOWN;
			   break;
		   case 75:
			   if (direction != Direction::RIGHT)
				   direction = Direction::LEFT;
			   break;
		   case 77:
			   if (direction != Direction::LEFT)
				   direction = Direction::RIGHT;
			   break;
		   } 
		   return true;
			case 32:                       //空格
				return false;
			
			}
	}
	return true;

}
bool Snake::Getfood(const Food& cfood)
{
	if (snakes.back().GetX() == cfood.x && snakes.back().GetY() == cfood.y)
		return true;
	else
		return false;
}
bool Snake::GetBigfood(Food& cfood)
{
	if (snakes.back().GetX() == cfood.big_x && snakes.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}
