#pragma once
#include<Windows.h>
void SetCursorPosition(const int x, const int y);
class point {
private:
	int x;
	int y;
public:
	point() = default;
	point(const int x, const int y) :x(x), y(y) {};
	bool operator== (const point& points) { return (points.x == this->x) && (points.y == this->y); }
	void print();
	void Printcl();
	void clear();
	int GetX() { return this->x; }
	int GetY() { return this->y; }
	void change(const int x, const int y);
};



