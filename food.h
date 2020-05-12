#pragma once


#include"Snake.h"
class Snake;
class Food {
public:
	Food():cnt(0),flash_flag(false),big_flag(false),x(0),y(0),big_x(0),big_y(0),progress_bar(0){}
	void Drawfood(Snake&);
	void Drawbigfood(Snake&);
	int Getcnt();
	void Flashbigfood();
	bool Getbigflag();
	int Getprogress();
private:
	int cnt;
	int x, y;
	int  big_x, big_y;
	int progress_bar;  //½ø¶ÈÌõ
	bool flash_flag;
	bool big_flag;
	friend class Snake;
};
