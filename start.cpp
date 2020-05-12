#include<Windows.h>
#include"start.h"

void start::printfirst() {
	for (auto& point : startsnake) {
		point.print();
		Sleep(speed);

	}
}
void start::printsecond() {
	for (int i = 10; i != 40; ++i)
	{
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(point(i, j));

		startsnake.back().print();
		startsnake.front().clear();
		startsnake.pop_front();
		Sleep(speed);
	}

}
void start::printthird() {
	while (!startsnake.empty() || textsnake.back().GetX() <= 33)
	{
		if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�
		{
			startsnake.front().clear();
			startsnake.pop_front();
		}
		cleantext();//�����������
		printtext();//���Ƹ���λ�ú������
		Sleep(speed);
	}
}
void start::cleantext()
{
	for (auto& points : textsnake)
	{
		if (points.GetX() >= 0)
			points.clear();
		points.change(points.GetX() + 1, points.GetY());
	}
}
void start::printtext() {
	for (auto& points : textsnake)
	{
		if (points.GetX() >= 0)
			points.print();
	}
}