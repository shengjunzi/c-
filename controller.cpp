#include"controller.h"
#include<Windows.h>
#include<iostream>
#include"tool.cpp"

void Controller::Start()//��ʼ����
{
	SetWindowSize(41, 32);//���ô��ڴ�С
	SetColor(2);//���ÿ�ʼ������ɫ
	StartInterface* start = new StartInterface();//��̬����һ��StartInterface��start
	start->Action();//��ʼ����
	delete start;//�ͷ��ڴ�ռ�

	/*���ùر�λ�ã��������ʾ��ȴ�������������*/
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}
