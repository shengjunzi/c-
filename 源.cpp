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
	std::cout << "��ķ���Ϊ��" << score;
	Sleep(30);
	SetCursorPosition(18, 14);
	std::cout << "�Ƿ�����һ��:";
	Sleep(30);
	SetCursorPosition(18, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "������һ�֣�";
	SetCursorPosition(18, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "��ȥѧϰ�ˣ�";
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
				std::cout << "������һ�֣�";
				SetCursorPosition(18, 18);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << "��ȥѧϰ�ˣ�";
				--tmp_key;
			}
			break;
		case 80:
			if (tmp_key<2)
			{
				SetCursorPosition(18, 18);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				std::cout << "��ȥѧϰ�ˣ�";
				SetCursorPosition(18, 16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << "������һ�֣�";
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
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
		
		/*������*/
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
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "�˳���Ϸ";
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
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "���¿�ʼ";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "�˳���Ϸ";
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
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "���¿�ʼ";

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
		if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
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
	system("title ̰����");
	
	
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
	std::cout << "̰������Ϸ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	std::cout << "(���¼�ѡ�񣬻س�ȷ�ϣ�";
	SetCursorPosition(27, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
    std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;

	int ch;
	key = 1;  //ѡ�����ʼ��һ��
	bool flag = false;
	while ((ch = getch()))
	{
		switch (ch)
		{
		case 72: //�Ͻ�
			if (key > 1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "��ͨģʽ";
					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "����ģʽ";
					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "����ģʽ";
					SetCursorPosition(27, 28);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "����ģʽ";
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
					std::cout << "��ͨģʽ";
					

					SetCursorPosition(27, 22);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "��ģʽ";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "��ͨģʽ";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					std::cout << "����ģʽ";
					++key;
					break;

				}

			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		
		SetCursorPosition(0, 31);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}

	switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
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

	/*���Ƶ�ͼ*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Map* init_map = new Map();
	init_map->printinitmap();
	delete init_map;

	/*���Ʋ����*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetCursorPosition(32, 1);
	std::cout << "GREEDY SNAKE";
	SetCursorPosition(33, 2);
	std::cout << " ̰����";
	SetCursorPosition(32, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 4);
	switch (key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:break;
	}
	SetCursorPosition(32, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 7);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << "�ո������ͣ";

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
	std::cout << "�������������Ϸ...";
	SetCursorPosition(18, 10);
	std::cout << "̰������Ϸ";
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