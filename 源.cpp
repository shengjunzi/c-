#include<iostream>
#include<time.h>
#include<stdio.h>
#include"start.h"
#include<conio.h>
#include"map.h"
#include"Snake.h"
#include"food.h"
#include<iomanip>
using namespace std;
class Menu {
private:
	int speed;
	int key;
	int score;
public:
	Menu() :speed{ 60 }, key{ 1 }, score{ 0 } {};
	void game() ;
	void select();
	void drawgame();
	int playgame();
	int menu();
	void updatescore(const int&);
	void drawscore();
	int gameover();
	
	
	~Menu() {};
};
void Menu::updatescore(const int& tmp)
{
	score += key * 10 * tmp;
}
void Menu::drawscore()
{
	SetCursorPosition(37, 7);
	std::cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout<<setw(5)<< score;
}
int Menu::gameover()
{
	
	Sleep(500);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	SetCursorPosition(18, 10);
	std::cout << "  GAME OVER!  ";
	Sleep(30);
	SetCursorPosition(18, 12);
	std::cout << "你的分数为：" << score;
	Sleep(30);
	SetCursorPosition(18, 14);
	std::cout << "是否再来一局:";
	Sleep(30);
	SetCursorPosition(18, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "哥再来一局！";
	SetCursorPosition(18, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "哥去学习了！";
	SetCursorPosition(0, 31);
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = getch()))
	{
		switch (ch)
		{
		case 72:
			if (tmp_key>1)
			{
				SetCursorPosition(18, 16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				std::cout << "哥再来一局！";
				SetCursorPosition(18, 18);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << "哥去学习了！";
				--tmp_key;
			}
			break;
		case 80:
			if (tmp_key<2)
			{
				SetCursorPosition(18, 18);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				std::cout << "哥去学习了！";
				SetCursorPosition(18, 16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << "哥再来一局！";
				++tmp_key;
			}
			break;
		case 13:flag = true; break;
		default :break;

		}
		SetCursorPosition(0, 31);
		if (flag) break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	switch (tmp_key)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}

}
int Menu::playgame()
{
	Snake* csnake = new Snake();
	Food* cfood = new Food();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	csnake->Initsanke();
	srand((unsigned)time(NULL));
	cfood->Drawfood(*csnake);
	while (csnake->OverEdge() && csnake->HitItself())
	{
		if (!csnake->ChangeDirection())
		{
			int tmp = menu();
			switch (tmp)
			{
			case 1:break;
			case 2:delete csnake;
				delete cfood;
				return 1;
			case 3:
				delete csnake;
				delete cfood;
				return 2;
			default:break;

			}
		}
		
		
			if (csnake->Getfood(*cfood))
			{
				csnake->Move();
				updatescore(1);
				drawscore();
				cfood->Drawfood(*csnake);
			}
			else
			{
				csnake->Normalmove();
			}
			if (csnake->GetBigfood(*cfood))
			{
				csnake->Move();
				updatescore(cfood->Getprogress()/5);
				drawscore();
			}
			if (cfood->Getbigflag())
			{
				cfood->Flashbigfood();
			}
			Sleep(speed);
		
	}
		
		/*蛇死亡*/
		delete csnake;
		delete cfood;
		int tmp = gameover();
		switch (tmp)
		{
		case 1:return 1;
		case 2:return 2;
		default:return 2;
		}
	
}
int Menu::menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = getch()))
	{
		switch (ch)
		{
		case 72:
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "重新开始";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "退出游戏";
					--tmp_key;
					break;
				}
			}break;
		case 80://DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "重新开始";

					++tmp_key;
					break;
				}
			}
			break;
		case 13://Enter
			flag = true;
			break;
		default:break;
		}
		if (flag)
		{
			break;
		}
		SetCursorPosition(0, 31);
	 }
		if (tmp_key == 1) //选择继续游戏，则将菜单擦除
		{
			SetCursorPosition(32, 19);
			std::cout << "      ";
			SetCursorPosition(34, 21);
			std::cout << "        ";
			SetCursorPosition(34, 23);
			std::cout << "        ";
			SetCursorPosition(34, 25);
			std::cout << "        ";
		}
		return tmp_key;
	
}
void setwindowsize(int cols, int lines)
{
	system("title 贪吃蛇");
	
	
	char cmd[40];
	sprintf_s(cmd, "mode con cols=%2d lines=%2d", cols * 2, lines);
		system(cmd);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}
void Menu::game()
{
	setwindowsize(41, 32);
}
void Menu::select()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(18, 10);
	std::cout << "贪吃蛇游戏";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择，回车确认）";
	SetCursorPosition(27, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
    std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;

	int ch;
	key = 1;  //选中项，初始第一个
	bool flag = false;
	while ((ch = getch()))
	{
		switch (ch)
		{
		case 72: //上建
			if (key > 1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "简单模式";

					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "普通模式";
					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "普通模式";
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "困难模式";
					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "困难模式";
					SetCursorPosition(27, 28);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "炼狱模式";
					--key;
					break;

				}
		
			}
			break;
		case 80:
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "普通模式";
					

					SetCursorPosition(27, 22);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "简单模式";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "普通模式";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "困难模式";
					++key;
					break;

				}

			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		
		SetCursorPosition(0, 31);//将光标置于左下角，避免关标闪烁影响游戏体验
	}

	switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}

}
void Menu::drawgame()
{
	system("cls");

	/*绘制地图*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Map* init_map = new Map();
	init_map->printinitmap();
	delete init_map;

	/*绘制侧边栏*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetCursorPosition(32, 1);
	std::cout << "GREEDY SNAKE";
	SetCursorPosition(33, 2);
	std::cout << " 贪吃蛇";
	SetCursorPosition(32, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 4);
	switch (key)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:break;
	}
	SetCursorPosition(32, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 7);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "方向键移动";
	SetCursorPosition(33, 15);
	std::cout << "空格键键暂停";

}
int main()
{
	Menu menu;
	menu.game();
	start* s = new start();
	s->printfirst();
	s->printsecond();
	s->printthird();
	delete s;
	SetCursorPosition(13, 26);
	std::cout << "按任意键继续游戏...";
	SetCursorPosition(18, 10);
	std::cout << "贪吃蛇游戏";
	SetCursorPosition(13, 27);
	system("pause");

	while (true)
	{
		menu.select();
		menu.drawgame();
		int tmp=menu.playgame();
		if (tmp == 1)
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) break;
		else break;


	}
	
		return 0;
}