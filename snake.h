#pragma once
#include<deque>
#include"point1.h"
#include"food.h"

class Food;
class Snake {

public:
	enum Direction {UP,DOWN,LEFT,RIGHT};

	Snake()
	{
		snakes.emplace_back(14, 8);
		snakes.emplace_back(15, 8);
		snakes.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	void Initsanke();
	void Move();
	void Normalmove();
	bool OverEdge();
	bool HitItself();
	bool ChangeDirection();
	bool Getfood(const Food&);
	bool GetBigfood(Food&);
private:
	std::deque<point>snakes;
	Direction  direction;
	friend class Food;
};
