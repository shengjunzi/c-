#include"controller.h"
#include<Windows.h>
#include<iostream>
#include"tool.cpp"

void Controller::Start()//开始界面
{
	SetWindowSize(41, 32);//设置窗口大小
	SetColor(2);//设置开始动画颜色
	StartInterface* start = new StartInterface();//动态分配一个StartInterface类start
	start->Action();//开始动画
	delete start;//释放内存空间

	/*设置关标位置，并输出提示语，等待任意键输入结束*/
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}
