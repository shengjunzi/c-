#pragma once
#include<vector>
#include"point1.h"

class Map {
private:
	std::vector<point>initmap;
public:
	Map()
	{
		initmap.emplace_back(point(1, 1));
		initmap.emplace_back(point(2, 1));
		initmap.emplace_back(point(3, 1));
		initmap.emplace_back(point(4, 1));
		initmap.emplace_back(point(5, 1));
		initmap.emplace_back(point(6, 1));
		initmap.emplace_back(point(7, 1));
		initmap.emplace_back(point(8, 1));
		initmap.emplace_back(point(9, 1));
		initmap.emplace_back(point(10, 1));
		initmap.emplace_back(point(11, 1));
		initmap.emplace_back(point(12, 1));
		initmap.emplace_back(point(13, 1));
		initmap.emplace_back(point(14, 1));
		initmap.emplace_back(point(15, 1));
		initmap.emplace_back(point(16, 1));
		initmap.emplace_back(point(17, 1));
		initmap.emplace_back(point(18, 1));
		initmap.emplace_back(point(19, 1));
		initmap.emplace_back(point(20, 1));
		initmap.emplace_back(point(21, 1));
		initmap.emplace_back(point(22, 1));
		initmap.emplace_back(point(23, 1));
		initmap.emplace_back(point(24, 1));
		initmap.emplace_back(point(25, 1));
		initmap.emplace_back(point(26, 1));
		initmap.emplace_back(point(27, 1));
		initmap.emplace_back(point(28, 1));
		initmap.emplace_back(point(29, 1));
		initmap.emplace_back(point(30, 1));
		initmap.emplace_back(point(1, 2));
		initmap.emplace_back(point(30, 2));
		initmap.emplace_back(point(1, 3));
		initmap.emplace_back(point(30, 3));
		initmap.emplace_back(point(1, 4));
		initmap.emplace_back(point(30, 4));
		initmap.emplace_back(point(1, 5));
		initmap.emplace_back(point(30, 5));
		initmap.emplace_back(point(1, 6));
		initmap.emplace_back(point(30, 6));
		initmap.emplace_back(point(1, 7));
		initmap.emplace_back(point(30, 7));
		initmap.emplace_back(point(1, 8));
		initmap.emplace_back(point(30, 8));
		initmap.emplace_back(point(1, 9));
		initmap.emplace_back(point(30, 9));
		initmap.emplace_back(point(1, 10));
		initmap.emplace_back(point(30, 10));
		initmap.emplace_back(point(1, 11));
		initmap.emplace_back(point(30, 11));
		initmap.emplace_back(point(1, 12));
		initmap.emplace_back(point(30, 12));
		initmap.emplace_back(point(1, 13));
		initmap.emplace_back(point(30, 13));
		initmap.emplace_back(point(1, 14));
		initmap.emplace_back(point(30, 14));
		initmap.emplace_back(point(1, 15));
		initmap.emplace_back(point(30, 15));
		initmap.emplace_back(point(1, 16));
		initmap.emplace_back(point(30, 16));
		initmap.emplace_back(point(1, 17));
		initmap.emplace_back(point(30, 17));
		initmap.emplace_back(point(1, 18));
		initmap.emplace_back(point(30, 18));
		initmap.emplace_back(point(1, 19));
		initmap.emplace_back(point(30, 19));
		initmap.emplace_back(point(1, 20));
		initmap.emplace_back(point(30, 20));
		initmap.emplace_back(point(1, 21));
		initmap.emplace_back(point(30, 21));
		initmap.emplace_back(point(1, 22));
		initmap.emplace_back(point(30, 22));
		initmap.emplace_back(point(1, 23));
		initmap.emplace_back(point(30, 23));
		initmap.emplace_back(point(1, 24));
		initmap.emplace_back(point(30, 24));
		initmap.emplace_back(point(1, 25));
		initmap.emplace_back(point(30, 25));
		initmap.emplace_back(point(1, 26));
		initmap.emplace_back(point(30, 26));
		initmap.emplace_back(point(1, 27));
		initmap.emplace_back(point(30, 27));
		initmap.emplace_back(point(1, 28));
		initmap.emplace_back(point(30, 28));
		initmap.emplace_back(point(1, 29));
		initmap.emplace_back(point(30, 29));
		initmap.emplace_back(point(1, 30));
		initmap.emplace_back(point(2, 30));
		initmap.emplace_back(point(3, 30));
		initmap.emplace_back(point(4, 30));
		initmap.emplace_back(point(5, 30));
		initmap.emplace_back(point(6, 30));
		initmap.emplace_back(point(7, 30));
		initmap.emplace_back(point(8, 30));
		initmap.emplace_back(point(9, 30));
		initmap.emplace_back(point(10, 30));
		initmap.emplace_back(point(11, 30));
		initmap.emplace_back(point(12, 30));
		initmap.emplace_back(point(13, 30));
		initmap.emplace_back(point(14, 30));
		initmap.emplace_back(point(15, 30));
		initmap.emplace_back(point(16, 30));
		initmap.emplace_back(point(17, 30));
		initmap.emplace_back(point(18, 30));
		initmap.emplace_back(point(19, 30));
		initmap.emplace_back(point(20, 30));
		initmap.emplace_back(point(21, 30));
		initmap.emplace_back(point(22, 30));
		initmap.emplace_back(point(23, 30));
		initmap.emplace_back(point(24, 30));
		initmap.emplace_back(point(25, 30));
		initmap.emplace_back(point(26, 30));
		initmap.emplace_back(point(27, 30));
		initmap.emplace_back(point(28, 30));
		initmap.emplace_back(point(29, 30));
		initmap.emplace_back(point(30, 30));
	}
	void printinitmap();
	

};
void Map::printinitmap()
{
	for (auto& points : initmap) {
		points.print();
		Sleep(10);
	}
}
